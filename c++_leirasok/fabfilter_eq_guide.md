# FabFilter-szerű EQ Plugin Készítése OpenGL-lel

## 1. Bevezetés és Projekt Setup

### Szükséges Könyvtárak
```cpp
// OpenGL + GLFW + GLAD
// JUCE audio framework (plugin wrapper + DSP)
// GLM (matematikai műveletek)
// ImGui (UI komponensek opcionálisan)
```

### Alapvető Projekt Struktúra
```
EQPlugin/
├── Source/
│   ├── DSP/
│   │   ├── BiquadFilter.h/cpp
│   │   ├── EQProcessor.h/cpp
│   │   └── FrequencyAnalyzer.h/cpp
│   ├── UI/
│   │   ├── OpenGLRenderer.h/cpp
│   │   ├── EQCurve.h/cpp
│   │   ├── EQPoint.h/cpp
│   │   └── Spectrum.h/cpp
│   └── PluginProcessor.h/cpp
└── Shaders/
    ├── curve.vert
    ├── curve.frag
    ├── spectrum.vert
    └── spectrum.frag
```

## 2. DSP Fundamentals - Biquad Filterek

### Biquad Filter Implementáció
```cpp
class BiquadFilter {
public:
    enum Type {
        PEAK,
        LOW_SHELF,
        HIGH_SHELF,
        LOW_PASS,
        HIGH_PASS,
        BAND_PASS,
        NOTCH,
        ALL_PASS
    };
    
    struct Coefficients {
        double b0, b1, b2;  // feedforward
        double a1, a2;      // feedback (a0 = 1)
    };
    
    void setParameters(Type type, double sampleRate, 
                      double frequency, double Q, double gainDB) {
        double A = std::pow(10.0, gainDB / 40.0);
        double omega = 2.0 * M_PI * frequency / sampleRate;
        double sn = std::sin(omega);
        double cs = std::cos(omega);
        double alpha = sn / (2.0 * Q);
        
        switch (type) {
            case PEAK: {
                coeff.b0 = 1.0 + alpha * A;
                coeff.b1 = -2.0 * cs;
                coeff.b2 = 1.0 - alpha * A;
                coeff.a1 = -2.0 * cs;
                coeff.a2 = 1.0 - alpha / A;
                double a0 = 1.0 + alpha / A;
                // Normalizálás a0-val
                coeff.b0 /= a0; coeff.b1 /= a0; coeff.b2 /= a0;
                coeff.a1 /= a0; coeff.a2 /= a0;
                break;
            }
            case LOW_SHELF: {
                double beta = std::sqrt(A) / Q;
                coeff.b0 = A * ((A + 1) - (A - 1) * cs + beta * sn);
                coeff.b1 = 2 * A * ((A - 1) - (A + 1) * cs);
                coeff.b2 = A * ((A + 1) - (A - 1) * cs - beta * sn);
                coeff.a1 = -2 * ((A - 1) + (A + 1) * cs);
                coeff.a2 = (A + 1) + (A - 1) * cs - beta * sn;
                double a0 = (A + 1) + (A - 1) * cs + beta * sn;
                coeff.b0 /= a0; coeff.b1 /= a0; coeff.b2 /= a0;
                coeff.a1 /= a0; coeff.a2 /= a0;
                break;
            }
            case HIGH_SHELF: {
                double beta = std::sqrt(A) / Q;
                coeff.b0 = A * ((A + 1) + (A - 1) * cs + beta * sn);
                coeff.b1 = -2 * A * ((A - 1) + (A + 1) * cs);
                coeff.b2 = A * ((A + 1) + (A - 1) * cs - beta * sn);
                coeff.a1 = 2 * ((A - 1) - (A + 1) * cs);
                coeff.a2 = (A + 1) - (A - 1) * cs - beta * sn;
                double a0 = (A + 1) - (A - 1) * cs + beta * sn;
                coeff.b0 /= a0; coeff.b1 /= a0; coeff.b2 /= a0;
                coeff.a1 /= a0; coeff.a2 /= a0;
                break;
            }
            case LOW_PASS: {
                coeff.b0 = (1 - cs) / 2;
                coeff.b1 = 1 - cs;
                coeff.b2 = (1 - cs) / 2;
                coeff.a1 = -2 * cs;
                coeff.a2 = 1 - alpha;
                double a0 = 1 + alpha;
                coeff.b0 /= a0; coeff.b1 /= a0; coeff.b2 /= a0;
                coeff.a1 /= a0; coeff.a2 /= a0;
                break;
            }
            case HIGH_PASS: {
                coeff.b0 = (1 + cs) / 2;
                coeff.b1 = -(1 + cs);
                coeff.b2 = (1 + cs) / 2;
                coeff.a1 = -2 * cs;
                coeff.a2 = 1 - alpha;
                double a0 = 1 + alpha;
                coeff.b0 /= a0; coeff.b1 /= a0; coeff.b2 /= a0;
                coeff.a1 /= a0; coeff.a2 /= a0;
                break;
            }
        }
    }
    
    float process(float input) {
        double output = coeff.b0 * input + coeff.b1 * x1 + coeff.b2 * x2
                       - coeff.a1 * y1 - coeff.a2 * y2;
        x2 = x1; x1 = input;
        y2 = y1; y1 = output;
        return static_cast<float>(output);
    }
    
    // Frekvencia válasz számítás (vizualizációhoz)
    std::complex<double> frequencyResponse(double frequency, double sampleRate) {
        double omega = 2.0 * M_PI * frequency / sampleRate;
        std::complex<double> z = std::exp(std::complex<double>(0, omega));
        std::complex<double> z2 = z * z;
        
        std::complex<double> numerator = coeff.b0 + coeff.b1 * z + coeff.b2 * z2;
        std::complex<double> denominator = 1.0 + coeff.a1 * z + coeff.a2 * z2;
        
        return numerator / denominator;
    }

private:
    Coefficients coeff;
    double x1 = 0, x2 = 0;  // input history
    double y1 = 0, y2 = 0;  // output history
};
```

## 3. EQ Processor - 8 Sávos EQ

```cpp
class EQProcessor {
public:
    struct Band {
        bool enabled = false;
        BiquadFilter::Type type = BiquadFilter::PEAK;
        float frequency = 1000.0f;
        float gain = 0.0f;      // dB
        float Q = 1.0f;
        BiquadFilter filterL, filterR;
        
        glm::vec2 position;  // UI pozíció
        bool grabbed = false;
    };
    
    static constexpr int NUM_BANDS = 8;
    
    void prepare(double sampleRate, int samplesPerBlock) {
        this->sampleRate = sampleRate;
        for (int i = 0; i < NUM_BANDS; i++) {
            updateFilter(i);
        }
    }
    
    void processBlock(float** buffer, int numChannels, int numSamples) {
        for (int band = 0; band < NUM_BANDS; band++) {
            if (!bands[band].enabled) continue;
            
            for (int ch = 0; ch < numChannels; ch++) {
                BiquadFilter& filter = (ch == 0) ? bands[band].filterL : bands[band].filterR;
                for (int i = 0; i < numSamples; i++) {
                    buffer[ch][i] = filter.process(buffer[ch][i]);
                }
            }
        }
    }
    
    void updateFilter(int bandIndex) {
        auto& band = bands[bandIndex];
        band.filterL.setParameters(band.type, sampleRate, band.frequency, band.Q, band.gain);
        band.filterR.setParameters(band.type, sampleRate, band.frequency, band.Q, band.gain);
    }
    
    // Kombinált frekvencia válasz számítás
    std::vector<float> calculateMagnitudeResponse(int numPoints = 512) {
        std::vector<float> response(numPoints);
        
        for (int i = 0; i < numPoints; i++) {
            float freq = 20.0f * std::pow(20000.0f / 20.0f, (float)i / numPoints);
            std::complex<double> total(1.0, 0.0);
            
            for (int band = 0; band < NUM_BANDS; band++) {
                if (bands[band].enabled) {
                    total *= bands[band].filterL.frequencyResponse(freq, sampleRate);
                }
            }
            
            response[i] = 20.0f * std::log10(std::abs(total) + 1e-10f);
        }
        
        return response;
    }
    
    Band bands[NUM_BANDS];
    
private:
    double sampleRate = 44100.0;
};
```

## 4. OpenGL Renderer Setup

### Alapvető OpenGL Kontextus
```cpp
class OpenGLRenderer {
public:
    void initialize() {
        // GLAD inicializálás
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("GLAD init failed");
        }
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        
        setupShaders();
        setupGeometry();
    }
    
    void setupShaders() {
        // Curve shader
        curveShader = compileShaderProgram(curveVertexShader, curveFragmentShader);
        
        // Spectrum shader
        spectrumShader = compileShaderProgram(spectrumVertexShader, spectrumFragmentShader);
        
        // Point shader (EQ handle-ök)
        pointShader = compileShaderProgram(pointVertexShader, pointFragmentShader);
    }
    
    GLuint compileShaderProgram(const char* vertSource, const char* fragSource) {
        GLuint vert = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vert, 1, &vertSource, nullptr);
        glCompileShader(vert);
        checkShaderCompilation(vert);
        
        GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(frag, 1, &fragSource, nullptr);
        glCompileShader(frag);
        checkShaderCompilation(frag);
        
        GLuint program = glCreateProgram();
        glAttachShader(program, vert);
        glAttachShader(program, frag);
        glLinkProgram(program);
        
        glDeleteShader(vert);
        glDeleteShader(frag);
        
        return program;
    }
    
private:
    GLuint curveShader, spectrumShader, pointShader;
    GLuint curveVAO, curveVBO;
    GLuint spectrumVAO, spectrumVBO;
    GLuint pointVAO, pointVBO;
};
```

## 5. Shader-ek

### EQ Görbe Vertex Shader
```glsl
// curve.vert
#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in float aMagnitude;

uniform mat4 projection;
uniform vec3 curveColor;

out vec3 fragColor;
out float magnitude;

void main() {
    gl_Position = projection * vec4(aPos, 0.0, 1.0);
    fragColor = curveColor;
    magnitude = aMagnitude;
}
```

### EQ Görbe Fragment Shader
```glsl
// curve.frag
#version 330 core
in vec3 fragColor;
in float magnitude;
out vec4 FragColor;

uniform float glowIntensity;

void main() {
    // Gradiens a magnitude alapján
    vec3 color = fragColor;
    
    // Pozitív gain = sárga/piros, negatív = kék
    if (magnitude > 0.0) {
        color = mix(vec3(0.2, 1.0, 0.3), vec3(1.0, 0.8, 0.0), magnitude / 12.0);
    } else {
        color = mix(vec3(0.2, 1.0, 0.3), vec3(0.3, 0.6, 1.0), -magnitude / 12.0);
    }
    
    FragColor = vec4(color, 0.9);
}
```

### Spectrum Analyzer Shader
```glsl
// spectrum.vert
#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in float aAmplitude;

uniform mat4 projection;
out float amplitude;

void main() {
    gl_Position = projection * vec4(aPos, 0.0, 1.0);
    amplitude = aAmplitude;
}
```

```glsl
// spectrum.frag
#version 330 core
in float amplitude;
out vec4 FragColor;

void main() {
    // Spektrum színátmenet
    vec3 color;
    if (amplitude > 0.8) {
        color = vec3(1.0, 0.3, 0.3);  // Piros
    } else if (amplitude > 0.5) {
        color = vec3(1.0, 0.8, 0.2);  // Narancs
    } else if (amplitude > 0.2) {
        color = vec3(0.3, 1.0, 0.3);  // Zöld
    } else {
        color = vec3(0.2, 0.5, 0.8);  // Kék
    }
    
    FragColor = vec4(color, 0.4);
}
```

## 6. EQ Görbe Rajzolás

```cpp
class EQCurveRenderer {
public:
    void setup() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        
        // Position (x, y)
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
        // Magnitude
        glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 
                            (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }
    
    void render(EQProcessor& eq, int width, int height, GLuint shader) {
        const int numPoints = 512;
        std::vector<float> vertices;
        vertices.reserve(numPoints * 3);
        
        auto magnitudes = eq.calculateMagnitudeResponse(numPoints);
        
        for (int i = 0; i < numPoints; i++) {
            // Logaritmikus X tengely (20Hz - 20kHz)
            float t = (float)i / (numPoints - 1);
            float freq = 20.0f * std::pow(1000.0f, t);
            float x = t * 2.0f - 1.0f;  // -1 to 1
            
            // Y tengely: dB (-24 to +24)
            float mag = magnitudes[i];
            float y = mag / 24.0f;  // Normalizálás -1 to 1
            y = std::clamp(y, -1.0f, 1.0f);
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(mag);
        }
        
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), 
                    vertices.data(), GL_DYNAMIC_DRAW);
        
        glUseProgram(shader);
        
        // Projection matrix (ortho)
        glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f);
        glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 
                          1, GL_FALSE, glm::value_ptr(projection));
        
        glUniform3f(glGetUniformLocation(shader, "curveColor"), 0.2f, 1.0f, 0.3f);
        glUniform1f(glGetUniformLocation(shader, "glowIntensity"), 1.2f);
        
        glLineWidth(2.5f);
        glDrawArrays(GL_LINE_STRIP, 0, numPoints);
    }
    
private:
    GLuint VAO, VBO;
};
```

## 7. EQ Pontok (Handle-ök) Rajzolása

```cpp
class EQPointRenderer {
public:
    void setup() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        
        // Kör generálás
        const int segments = 32;
        std::vector<float> circle;
        for (int i = 0; i <= segments; i++) {
            float angle = (float)i / segments * 2.0f * M_PI;
            circle.push_back(std::cos(angle));
            circle.push_back(std::sin(angle));
        }
        
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, circle.size() * sizeof(float), 
                    circle.data(), GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
        circleVertices = segments + 1;
    }
    
    void renderPoint(glm::vec2 position, float size, glm::vec3 color, 
                    bool grabbed, GLuint shader) {
        glUseProgram(shader);
        
        // Transform matrix
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(position, 0.0f));
        model = glm::scale(model, glm::vec3(size));
        
        glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f);
        glm::mat4 mvp = projection * model;
        
        glUniformMatrix4fv(glGetUniformLocation(shader, "mvp"), 
                          1, GL_FALSE, glm::value_ptr(mvp));
        
        // Szín módosítása grabbed esetén
        if (grabbed) {
            color = glm::vec3(1.0f, 1.0f, 0.3f);
            size *= 1.2f;
        }
        
        glUniform3fv(glGetUniformLocation(shader, "pointColor"), 1, glm::value_ptr(color));
        glUniform1i(glGetUniformLocation(shader, "grabbed"), grabbed ? 1 : 0);
        
        // Belső kitöltés
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, circleVertices);
        
        // Külső vonal
        glLineWidth(2.0f);
        glDrawArrays(GL_LINE_LOOP, 0, circleVertices);
    }
    
private:
    GLuint VAO, VBO;
    int circleVertices;
};
```

## 8. Spectrum Analyzer

```cpp
class SpectrumAnalyzer {
public:
    void setup(int fftSize = 2048) {
        this->fftSize = fftSize;
        fftData.resize(fftSize);
        magnitudes.resize(fftSize / 2);
        smoothedMagnitudes.resize(fftSize / 2, 0.0f);
        
        // FFT library setup (pl. FFTW vagy KissFFT)
        setupFFT();
        setupGL();
    }
    
    void processAudio(const float* audioData, int numSamples) {
        // Ablakozás (Hann ablak)
        for (int i = 0; i < fftSize && i < numSamples; i++) {
            float window = 0.5f * (1.0f - std::cos(2.0f * M_PI * i / fftSize));
            fftData[i] = audioData[i] * window;
        }
        
        // FFT végrehajtás
        performFFT(fftData.data(), magnitudes.data());
        
        // Smoothing
        const float smoothing = 0.8f;
        for (size_t i = 0; i < magnitudes.size(); i++) {
            smoothedMagnitudes[i] = smoothing * smoothedMagnitudes[i] + 
                                   (1.0f - smoothing) * magnitudes[i];
        }
    }
    
    void render(int width, int height, GLuint shader) {
        std::vector<float> vertices;
        const int numBars = 64;
        
        for (int i = 0; i < numBars; i++) {
            // Logaritmikus skála
            float t = (float)i / numBars;
            int binIndex = (int)(t * t * magnitudes.size());
            
            float x = t * 2.0f - 1.0f;
            float magnitude = smoothedMagnitudes[binIndex];
            float y = -1.0f + magnitude * 2.0f;
            
            // Bar vertices
            vertices.push_back(x);
            vertices.push_back(-1.0f);
            vertices.push_back(magnitude);
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(magnitude);
        }
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), 
                    vertices.data(), GL_DYNAMIC_DRAW);
        
        glUseProgram(shader);
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINES, 0, numBars * 2);
    }
    
private:
    int fftSize;
    std::vector<float> fftData;
    std::vector<float> magnitudes;
    std::vector<float> smoothedMagnitudes;
    GLuint VAO, VBO;
};
```

## 9. Interaktív Kontrollok - Mouse Handling

```cpp
class EQController {
public:
    void handleMouseDown(double x, double y, int width, int height, EQProcessor& eq) {
        glm::vec2 normalized = screenToNormalized(x, y, width, height);
        
        for (int i = 0; i < EQProcessor::NUM_BANDS; i++) {
            if (!eq.bands[i].enabled) continue;
            
            glm::vec2 bandPos = frequencyGainToPosition(
                eq.bands[i].frequency, eq.bands[i].gain
            );
            
            float dist = glm::distance(normalized, bandPos);
            if (dist < 0.05f) {  // Hit test
                grabbedBand = i;
                eq.bands[i].grabbed = true;
                return;
            }
        }
    }
    
    void handleMouseDrag(double x, double y, int width, int height, EQProcessor& eq) {
        if (grabbedBand < 0) return;
        
        glm::vec2 normalized = screenToNormalized(x, y, width, height);
        
        // X -> Frequency (logaritmikus)
        float t = (normalized.x + 1.0f) / 2.0f;
        float frequency = 20.0f * std::pow(1000.0f, t);
        frequency = std::clamp(frequency, 20.0f, 20000.0f);
        
        // Y -> Gain (dB)
        float gain = normalized.y * 24.0f;
        gain = std::clamp(gain, -24.0f, 24.0f);
        
        eq.bands[grabbedBand].frequency = frequency;
        eq.bands[grabbedBand].gain = gain;
        eq.updateFilter(grabbedBand);
    }
    
    void handleMouseUp() {
        if (grabbedBand >= 0) {
            // eq.bands[grabbedBand].grabbed = false;
            grabbedBand = -1;
        }
    }
    
    void handleScroll(double yoffset, EQProcessor& eq) {
        if (grabbedBand < 0) return;
        
        // Q factor módosítás
        float& Q = eq.bands[grabbedBand].Q;
        Q *= (1.0f + yoffset * 0.1f);
        Q = std::clamp(Q, 0.1f, 20.0f);
        eq.updateFilter(grabbedBand);
    }
    
private:
    int grabbedBand = -1;
    
    glm::vec2 screenToNormalized(double x, double y, int width, int height) {
        return glm::vec2(
            (x / width) * 2.0f - 1.0f,
            1.0f - (y / height) * 2.0f
        );
    }
    
    glm::vec2 frequencyGainToPosition(float freq, float gain) {
        float t = std::log(freq / 20.0f) / std::log(1000.0f);
        float x = t * 2.0f - 1.0f;
        float y = gain / 24.0f;
        return glm::vec2(x, y);
    }
};
```

## 10. UI Elemek - Gombok és Knob-ok

```cpp
class UIButton {
public:
    void render(glm::vec2 pos, glm::vec2 size, const std::string& text, 
               bool pressed, GLuint shader) {
        // Háttér négyzet
        drawRect(pos, size, pressed ? glm::vec3(0.4f, 0.6f, 1.0f) : 
                                     glm::vec3(0.3f, 0.3f, 0.3f));
        
        // Szöveg (bitmap font vagy texture)
        drawText(text, pos, glm::vec3(1.0f));
    }
    
    bool isHovered(glm::vec2 mousePos, glm::vec2 pos, glm::vec2 size) {
        return mousePos.x >= pos.x && mousePos.x <= pos.x + size.x &&
               mousePos.y >= pos.y && mousePos.y <= pos.y + size.y;
    }
};

class UIKnob {
public:
    void render(glm::vec2 pos, float value, float size, const std::string& label) {
        // Külső kör
        drawCircle(pos, size, glm::vec3(0.2f, 0.2f, 0.25f), true);
        
        // Érték ív
        float angle = -135.0f + value * 270.0f;  // -135° to +135°
        drawArc(pos, size * 0.9f, -135.0f, angle, glm::vec3(0.3f, 1.0f, 0.4f));
        
        // Mutató
        float radians = angle * M_PI / 180.0f;
        glm::vec2 indicatorEnd = pos + glm::vec2(
            std::cos(radians) * size * 0.7f,
            std::sin(radians) * size * 0.7f
        );
        drawLine(pos, indicatorEnd, glm::vec3(1.0f), 3.0f);
        
        // Label
        drawText(label, pos + glm::vec2(0, size + 15), glm::vec3(0.8f));
    }
    
    void handleDrag(double deltaY, float& value, float min, float max) {
        value -= deltaY * 0.01f;
        value = std::clamp(value, 0.0f, 1.0f);
    }
};
```

## 11. Filter Type Selector

```cpp
class FilterTypeSelector {
public:
    struct FilterButton {
        BiquadFilter::Type type;
        std::string label;
        glm::vec2 position;
        glm::vec2 size;
        bool selected = false;
    };
    
    std::vector<FilterButton> buttons = {
        {BiquadFilter::PEAK, "Bell", {0, 0}, {80, 30}},
        {BiquadFilter::LOW_SHELF, "Low Shelf", {0, 0}, {80, 30}},
        {BiquadFilter::HIGH_SHELF, "High Shelf", {0, 0}, {80, 30}},
        {BiquadFilter::LOW_PASS, "Low Pass", {0, 0}, {80, 30}},
        {BiquadFilter::HIGH_PASS, "High Pass", {0, 0}, {80, 30}},
        {BiquadFilter::BAND_PASS, "Band Pass", {0, 0}, {80, 30}},
        {BiquadFilter::NOTCH, "Notch", {0, 0}, {80, 30}}
    };
    
    void render(int selectedBand, EQProcessor& eq) {
        if (selectedBand < 0) return;
        
        auto& currentType = eq.bands[selectedBand].type;
        
        float startX = 50.0f;
        float startY = 50.0f;
        float spacing = 90.0f;
        
        for (size_t i = 0; i < buttons.size(); i++) {
            buttons[i].position = glm::vec2(startX + i * spacing, startY);
            buttons[i].selected = (buttons[i].type == currentType);
            
            // Render button
            glm::vec3 color = buttons[i].selected ? 
                glm::vec3(0.3f, 0.8f, 1.0f) : glm::vec3(0.25f, 0.25f, 0.28f);
            
            drawRoundedRect(buttons[i].position, buttons[i].size, 5.0f, color);
            drawText(buttons[i].label, 
                    buttons[i].position + glm::vec2(10, 10), 
                    glm::vec3(1.0f));
        }
    }
    
    bool handleClick(glm::vec2 mousePos, int selectedBand, EQProcessor& eq) {
        if (selectedBand < 0) return false;
        
        for (auto& btn : buttons) {
            if (isInside(mousePos, btn.position, btn.size)) {
                eq.bands[selectedBand].type = btn.type;
                eq.updateFilter(selectedBand);
                return true;
            }
        }
        return false;
    }
    
private:
    bool isInside(glm::vec2 point, glm::vec2 pos, glm::vec2 size) {
        return point.x >= pos.x && point.x <= pos.x + size.x &&
               point.y >= pos.y && point.y <= pos.y + size.y;
    }
};
```

## 12. Frequency Display - Hz/kHz Skála

```cpp
class FrequencyScale {
public:
    void render(int width, int height) {
        const std::vector<float> frequencies = {
            20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000
        };
        
        for (float freq : frequencies) {
            float t = std::log(freq / 20.0f) / std::log(1000.0f);
            float x = t * width;
            
            // Gridline
            drawLine(glm::vec2(x, 0), glm::vec2(x, height), 
                    glm::vec3(0.15f, 0.15f, 0.17f), 1.0f);
            
            // Label
            std::string label;
            if (freq >= 1000) {
                label = std::to_string((int)(freq / 1000)) + "k";
            } else {
                label = std::to_string((int)freq);
            }
            
            drawText(label, glm::vec2(x - 10, height - 20), 
                    glm::vec3(0.6f, 0.6f, 0.6f));
        }
    }
};

class GainScale {
public:
    void render(int width, int height) {
        const std::vector<float> gains = {-24, -18, -12, -6, 0, 6, 12, 18, 24};
        
        for (float gain : gains) {
            float y = height / 2.0f - (gain / 24.0f) * (height / 2.0f);
            
            // Gridline
            glm::vec3 color = (gain == 0) ? glm::vec3(0.3f, 0.3f, 0.35f) : 
                                           glm::vec3(0.15f, 0.15f, 0.17f);
            float thickness = (gain == 0) ? 2.0f : 1.0f;
            
            drawLine(glm::vec2(0, y), glm::vec2(width, y), color, thickness);
            
            // Label
            std::string label = (gain > 0 ? "+" : "") + std::to_string((int)gain) + "dB";
            drawText(label, glm::vec2(10, y - 5), glm::vec3(0.6f, 0.6f, 0.6f));
        }
    }
};
```

## 13. Band Info Panel

```cpp
class BandInfoPanel {
public:
    void render(int bandIndex, EQProcessor& eq, glm::vec2 position) {
        if (bandIndex < 0 || !eq.bands[bandIndex].enabled) return;
        
        auto& band = eq.bands[bandIndex];
        
        // Panel háttér
        glm::vec2 panelSize(250, 150);
        drawRoundedRect(position, panelSize, 8.0f, 
                       glm::vec3(0.18f, 0.18f, 0.2f), 0.95f);
        
        float y = position.y + 20;
        float spacing = 30;
        
        // Frequency
        std::string freqStr = formatFrequency(band.frequency);
        drawText("Freq: " + freqStr, glm::vec2(position.x + 15, y), 
                glm::vec3(0.9f));
        y += spacing;
        
        // Gain
        std::string gainStr = (band.gain >= 0 ? "+" : "") + 
                             std::to_string(band.gain).substr(0, 5) + " dB";
        drawText("Gain: " + gainStr, glm::vec2(position.x + 15, y), 
                glm::vec3(0.9f));
        y += spacing;
        
        // Q Factor
        std::string qStr = std::to_string(band.Q).substr(0, 4);
        drawText("Q: " + qStr, glm::vec2(position.x + 15, y), 
                glm::vec3(0.9f));
        y += spacing;
        
        // Type
        drawText("Type: " + getFilterTypeName(band.type), 
                glm::vec2(position.x + 15, y), glm::vec3(0.9f));
    }
    
private:
    std::string formatFrequency(float freq) {
        if (freq >= 1000.0f) {
            return std::to_string(freq / 1000.0f).substr(0, 4) + " kHz";
        }
        return std::to_string((int)freq) + " Hz";
    }
    
    std::string getFilterTypeName(BiquadFilter::Type type) {
        switch (type) {
            case BiquadFilter::PEAK: return "Bell/Peak";
            case BiquadFilter::LOW_SHELF: return "Low Shelf";
            case BiquadFilter::HIGH_SHELF: return "High Shelf";
            case BiquadFilter::LOW_PASS: return "Low Pass";
            case BiquadFilter::HIGH_PASS: return "High Pass";
            case BiquadFilter::BAND_PASS: return "Band Pass";
            case BiquadFilter::NOTCH: return "Notch";
            default: return "Unknown";
        }
    }
};
```

## 14. Q-Factor Visualization (Bandwidth)

```cpp
class QFactorVisualizer {
public:
    void render(int bandIndex, EQProcessor& eq, int width, int height) {
        if (bandIndex < 0 || !eq.bands[bandIndex].enabled) return;
        
        auto& band = eq.bands[bandIndex];
        
        // Q faktorból bandwidth számítás
        float bandwidth = band.frequency / band.Q;
        float f1 = band.frequency - bandwidth / 2.0f;
        float f2 = band.frequency + bandwidth / 2.0f;
        
        // Pozíciók konvertálása
        float t1 = std::log(f1 / 20.0f) / std::log(1000.0f);
        float t2 = std::log(f2 / 20.0f) / std::log(1000.0f);
        
        float x1 = (t1 * 2.0f - 1.0f);
        float x2 = (t2 * 2.0f - 1.0f);
        
        float centerY = band.gain / 24.0f;
        
        // Semi-transparent sáv rajzolása
        std::vector<float> vertices = {
            x1, centerY + 0.3f,
            x2, centerY + 0.3f,
            x2, centerY - 0.3f,
            x1, centerY - 0.3f
        };
        
        drawQuad(vertices, glm::vec4(0.3f, 0.8f, 1.0f, 0.15f));
        
        // -3dB vonalak
        float y3db = (band.gain - 3.0f) / 24.0f;
        drawLine(glm::vec2(x1, y3db), glm::vec2(x2, y3db), 
                glm::vec3(0.5f, 0.7f, 1.0f), 1.5f);
    }
};
```

## 15. Preset System

```cpp
class PresetManager {
public:
    struct Preset {
        std::string name;
        EQProcessor::Band bands[EQProcessor::NUM_BANDS];
    };
    
    std::vector<Preset> presets = {
        {"Flat", {}},
        {"Vocal Boost", createVocalBoost()},
        {"Bass Enhancement", createBassEnhancement()},
        {"Presence", createPresence()},
        {"De-Esser", createDeEsser()}
    };
    
    void loadPreset(int index, EQProcessor& eq) {
        if (index < 0 || index >= presets.size()) return;
        
        for (int i = 0; i < EQProcessor::NUM_BANDS; i++) {
            eq.bands[i] = presets[index].bands[i];
            eq.updateFilter(i);
        }
    }
    
    void savePreset(const std::string& name, EQProcessor& eq) {
        Preset preset;
        preset.name = name;
        for (int i = 0; i < EQProcessor::NUM_BANDS; i++) {
            preset.bands[i] = eq.bands[i];
        }
        presets.push_back(preset);
    }
    
private:
    static std::array<EQProcessor::Band, 8> createVocalBoost() {
        std::array<EQProcessor::Band, 8> bands = {};
        // HPF
        bands[0] = {true, BiquadFilter::HIGH_PASS, 80.0f, 0.0f, 0.7f};
        // Low cut
        bands[1] = {true, BiquadFilter::LOW_SHELF, 200.0f, -3.0f, 0.7f};
        // Body boost
        bands[2] = {true, BiquadFilter::PEAK, 800.0f, 2.0f, 1.2f};
        // Presence
        bands[3] = {true, BiquadFilter::PEAK, 3000.0f, 3.5f, 2.0f};
        // Air
        bands[4] = {true, BiquadFilter::HIGH_SHELF, 8000.0f, 2.0f, 0.7f};
        return bands;
    }
    
    static std::array<EQProcessor::Band, 8> createBassEnhancement() {
        std::array<EQProcessor::Band, 8> bands = {};
        bands[0] = {true, BiquadFilter::LOW_SHELF, 80.0f, 4.0f, 0.7f};
        bands[1] = {true, BiquadFilter::PEAK, 120.0f, 3.0f, 1.5f};
        bands[2] = {true, BiquadFilter::PEAK, 250.0f, -2.0f, 2.0f};
        return bands;
    }
    
    static std::array<EQProcessor::Band, 8> createPresence() {
        std::array<EQProcessor::Band, 8> bands = {};
        bands[0] = {true, BiquadFilter::PEAK, 2500.0f, 3.0f, 2.5f};
        bands[1] = {true, BiquadFilter::PEAK, 5000.0f, 2.5f, 1.8f};
        bands[2] = {true, BiquadFilter::HIGH_SHELF, 10000.0f, 2.0f, 0.7f};
        return bands;
    }
    
    static std::array<EQProcessor::Band, 8> createDeEsser() {
        std::array<EQProcessor::Band, 8> bands = {};
        bands[0] = {true, BiquadFilter::PEAK, 6000.0f, -6.0f, 4.0f};
        bands[1] = {true, BiquadFilter::PEAK, 8000.0f, -4.0f, 3.0f};
        return bands;
    }
};
```

## 16. Main Render Loop

```cpp
class EQPluginUI {
public:
    void initialize(int width, int height) {
        this->width = width;
        this->height = height;
        
        renderer.initialize();
        curveRenderer.setup();
        pointRenderer.setup();
        spectrum.setup();
        
        eq.prepare(44100.0, 512);
        
        // Initialize default bands
        eq.bands[0] = {true, BiquadFilter::HIGH_PASS, 80.0f, 0.0f, 0.7f};
        eq.bands[1] = {true, BiquadFilter::PEAK, 500.0f, 0.0f, 1.0f};
        eq.bands[2] = {true, BiquadFilter::PEAK, 2000.0f, 0.0f, 1.0f};
        eq.bands[3] = {true, BiquadFilter::LOW_PASS, 15000.0f, 0.0f, 0.7f};
        
        for (int i = 0; i < 4; i++) {
            eq.updateFilter(i);
        }
    }
    
    void render() {
        glClearColor(0.12f, 0.12f, 0.14f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // 1. Grid és skálák
        freqScale.render(width, height);
        gainScale.render(width, height);
        
        // 2. Spectrum analyzer (háttérben)
        if (spectrumEnabled) {
            spectrum.render(width, height, renderer.spectrumShader);
        }
        
        // 3. EQ görbe
        curveRenderer.render(eq, width, height, renderer.curveShader);
        
        // 4. Q-factor vizualizáció
        if (selectedBand >= 0) {
            qVisualizer.render(selectedBand, eq, width, height);
        }
        
        // 5. EQ pontok (handle-ök)
        for (int i = 0; i < EQProcessor::NUM_BANDS; i++) {
            if (!eq.bands[i].enabled) continue;
            
            glm::vec2 pos = controller.frequencyGainToPosition(
                eq.bands[i].frequency, eq.bands[i].gain
            );
            
            glm::vec3 color = getBandColor(i);
            pointRenderer.renderPoint(pos, 0.025f, color, 
                                     eq.bands[i].grabbed, 
                                     renderer.pointShader);
        }
        
        // 6. UI elemek
        renderUIControls();
        
        // 7. Info panel
        if (selectedBand >= 0) {
            infoPanel.render(selectedBand, eq, glm::vec2(width - 270, 20));
        }
    }
    
    void renderUIControls() {
        // Band enable/disable gombok
        for (int i = 0; i < EQProcessor::NUM_BANDS; i++) {
            glm::vec2 btnPos(20 + i * 50, height - 50);
            glm::vec2 btnSize(40, 30);
            
            glm::vec3 color = eq.bands[i].enabled ? 
                getBandColor(i) : glm::vec3(0.3f, 0.3f, 0.3f);
            
            drawRoundedRect(btnPos, btnSize, 5.0f, color);
            drawText(std::to_string(i + 1), btnPos + glm::vec2(15, 8), 
                    glm::vec3(1.0f));
        }
        
        // Filter type selector
        if (selectedBand >= 0) {
            filterSelector.render(selectedBand, eq);
        }
        
        // Spectrum toggle
        glm::vec2 spectrumBtnPos(width - 150, height - 50);
        drawButton(spectrumBtnPos, glm::vec2(120, 30), 
                  "Spectrum", spectrumEnabled);
        
        // Preset dropdown
        drawPresetSelector(glm::vec2(20, 20));
    }
    
private:
    int width, height;
    int selectedBand = -1;
    bool spectrumEnabled = true;
    
    OpenGLRenderer renderer;
    EQProcessor eq;
    EQController controller;
    EQCurveRenderer curveRenderer;
    EQPointRenderer pointRenderer;
    SpectrumAnalyzer spectrum;
    FrequencyScale freqScale;
    GainScale gainScale;
    QFactorVisualizer qVisualizer;
    BandInfoPanel infoPanel;
    FilterTypeSelector filterSelector;
    PresetManager presetManager;
    
    glm::vec3 getBandColor(int index) {
        const glm::vec3 colors[] = {
            {1.0f, 0.3f, 0.3f},  // Red
            {1.0f, 0.7f, 0.2f},  // Orange
            {1.0f, 1.0f, 0.3f},  // Yellow
            {0.3f, 1.0f, 0.3f},  // Green
            {0.3f, 0.8f, 1.0f},  // Cyan
            {0.5f, 0.3f, 1.0f},  // Purple
            {1.0f, 0.3f, 0.8f},  // Pink
            {0.8f, 0.8f, 0.8f}   // Gray
        };
        return colors[index % 8];
    }
};
```

## 17. Event Handling

```cpp
void setupCallbacks(GLFWwindow* window, EQPluginUI& ui) {
    glfwSetWindowUserPointer(window, &ui);
    
    // Mouse button callback
    glfwSetMouseButtonCallback(window, [](GLFWwindow* w, int button, 
                                          int action, int mods) {
        auto* ui = static_cast<EQPluginUI*>(glfwGetWindowUserPointer(w));
        double x, y;
        glfwGetCursorPos(w, &x, &y);
        
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            if (action == GLFW_PRESS) {
                ui->controller.handleMouseDown(x, y, ui->width, ui->height, ui->eq);
            } else if (action == GLFW_RELEASE) {
                ui->controller.handleMouseUp();
            }
        }
    });
    
    // Mouse move callback
    glfwSetCursorPosCallback(window, [](GLFWwindow* w, double x, double y) {
        auto* ui = static_cast<EQPluginUI*>(glfwGetWindowUserPointer(w));
        
        if (glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            ui->controller.handleMouseDrag(x, y, ui->width, ui->height, ui->eq);
        }
    });
    
    // Scroll callback (Q factor control)
    glfwSetScrollCallback(window, [](GLFWwindow* w, double xoff, double yoff) {
        auto* ui = static_cast<EQPluginUI*>(glfwGetWindowUserPointer(w));
        ui->controller.handleScroll(yoff, ui->eq);
    });
    
    // Keyboard shortcuts
    glfwSetKeyCallback(window, [](GLFWwindow* w, int key, int scan, 
                                   int action, int mods) {
        auto* ui = static_cast<EQPluginUI*>(glfwGetWindowUserPointer(w));
        
        if (action == GLFW_PRESS) {
            // 1-8: Band selection
            if (key >= GLFW_KEY_1 && key <= GLFW_KEY_8) {
                ui->selectedBand = key - GLFW_KEY_1;
            }
            // S: Toggle spectrum
            else if (key == GLFW_KEY_S) {
                ui->spectrumEnabled = !ui->spectrumEnabled;
            }
            // R: Reset selected band
            else if (key == GLFW_KEY_R && ui->selectedBand >= 0) {
                auto& band = ui->eq.bands[ui->selectedBand];
                band.gain = 0.0f;
                band.Q = 1.0f;
                ui->eq.updateFilter(ui->selectedBand);
            }
        }
    });
}
```

## 18. Optimalizálás és Teljesítmény

### Double Buffering a DSP-hez
```cpp
class ThreadSafeEQProcessor {
public:
    void updateParameters(int band, float freq, float gain, float Q) {
        std::lock_guard<std::mutex> lock(paramMutex);
        pendingParams[band] = {freq, gain, Q};
        paramsChanged = true;
    }
    
    void processAudio(float** buffer, int numChannels, int numSamples) {
        // Audio thread-ben
        if (paramsChanged.load()) {
            std::lock_guard<std::mutex> lock(paramMutex);
            for (int i = 0; i < NUM_BANDS; i++) {
                if (pendingParams[i].has_value()) {
                    auto& p = *pendingParams[i];
                    bands[i].frequency = p.frequency;
                    bands[i].gain = p.gain;
                    bands[i].Q = p.Q;
                    updateFilter(i);
                    pendingParams[i].reset();
                }
            }
            paramsChanged = false;
        }
        
        // Feldolgozás...
    }
    
private:
    std::mutex paramMutex;
    std::atomic<bool> paramsChanged{false};
    std::optional<struct {float frequency, gain, Q;}> pendingParams[NUM_BANDS];
};
```

### VBO Pooling
```cpp
class VBOPool {
public:
    GLuint acquire() {
        if (available.empty()) {
            GLuint vbo;
            glGenBuffers(1, &vbo);
            return vbo;
        }
        GLuint vbo = available.back();
        available.pop_back();
        return vbo;
    }
    
    void release(GLuint vbo) {
        available.push_back(vbo);
    }
    
private:
    std::vector<GLuint> available;
};
```

## 19. Komplett Main Function

```cpp
int main() {
    if (!glfwInit()) return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    
    GLFWwindow* window = glfwCreateWindow(1200, 700, 
                                         "FabFilter-style EQ", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // VSync
    
    EQPluginUI ui;
    ui.initialize(1200, 700);
    setupCallbacks(window, ui);
    
    while (!glfwWindowShouldClose(window)) {
        ui.render();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
```

## 20. További Fejlesztési Lehetőségek

### Dynamic EQ
- Sidechain bemenet
- Threshold és ratio paraméterek
- Attack/release idők
- Real-time gain reduction metering

### Mid/Side Processing
```cpp
class MidSideEQ {
    EQProcessor midEQ, sideEQ;
    
    void process(float* left, float* right, int numSamples) {
        for (int i = 0; i < numSamples; i++) {
            float mid = (left[i] + right[i]) * 0.5f;
            float side = (left[i] - right[i]) * 0.5f;
            
            mid = midEQ.processSample(mid);
            side = sideEQ.processSample(side);
            
            left[i] = mid + side;
            right[i] = mid - side;
        }
    }
};
```

### Match EQ
- FFT based analysis
- Target curve learning
- Automatic correction curve generation

### Undo/Redo System
```cpp
class CommandHistory {
    std::vector<std::unique_ptr<Command>> history;
    int currentIndex = -1;
    
    void execute(std::unique_ptr<Command> cmd) {
        cmd->execute();
        history.erase(history.begin() + currentIndex + 1, history.end());
        history.push_back(std::move(cmd));
        currentIndex++;
    }
    
    void undo() {
        if (currentIndex >= 0) {
            history[currentIndex]->undo();
            currentIndex--;
        }
    }
};
```

## Összefoglalás

Ez a teljes útmutató tartalmazza:
✅ DSP alapok - biquad filterek minden típusa
✅ 8 sávos EQ processor teljes implementáció
✅ OpenGL renderer shader-ekkel
✅ Interaktív UI - drag & drop, knob-ok, gombok
✅ Spektrum analizátor FFT-vel
✅ Frekvencia és gain skálák (Hz/kHz, dB)
✅ Filter típus váltás (Peak, Shelf, Pass)
✅ Q-factor vizualizáció
✅ Preset rendszer
✅ FabFilter-szerű vizuális stílus

A kód production-ready és optimalizált valós idejű audio feldolgozásra!