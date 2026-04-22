cmake_minimum_required(VERSION 3.10)
project(MegaProject LANGUAGES C CXX ASM_NASM)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler-specific settings
if(MSVC)
    # Microsoft Visual C++ settings
    set(CMAKE_C_FLAGS_DEBUG "/Od /Zi /DDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "/O2 /DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi /DDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    # GCC or Clang settings
    set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()

# Find programs for other languages
find_program(JAVA_COMPILER NAMES javac)
find_program(JAVA_RUNTIME NAMES java)
find_program(KOTLIN_COMPILER NAMES kotlinc)
find_program(PYTHON_INTERPRETER NAMES python3 python)
find_program(CSHARP_COMPILER NAMES dotnet csc)

# Collect source files
file(GLOB C_SOURCES "*.c")
file(GLOB CPP_SOURCES "*.cpp")
file(GLOB ASM_SOURCES "*.asm")

# Add executables for C/C++
if(C_SOURCES)
    add_executable(c_app ${C_SOURCES})
    install(TARGETS c_app
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )
endif()

if(CPP_SOURCES)
    add_executable(cpp_app ${CPP_SOURCES})
    install(TARGETS cpp_app
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )
endif()

# Add shared library if dll_example.c/cpp exists
if(EXISTS "${CMAKE_SOURCE_DIR}/dll_example.c")
    add_library(mylib_c SHARED dll_example.c)
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/dll_example.cpp")
    add_library(mylib_cpp SHARED dll_example.cpp)
endif()

# Assembly support
if(ASM_SOURCES AND CMAKE_ASM_NASM_COMPILER)
    enable_language(ASM_NASM)
    add_executable(asm_app ${ASM_SOURCES})
endif()

# Custom targets for other languages
if(JAVA_COMPILER)
    # Java compilation and execution
    file(GLOB JAVA_SOURCES "*.java")
    if(JAVA_SOURCES)
        add_custom_target(java_compile ALL
            COMMAND ${JAVA_COMPILER} -d ${CMAKE_BINARY_DIR}/java_classes ${JAVA_SOURCES}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Compiling Java sources..."
        )
        
        add_custom_target(java_run
            COMMAND ${JAVA_RUNTIME} -cp ${CMAKE_BINARY_DIR}/java_classes HelloWorld
            DEPENDS java_compile
            COMMENT "Running Java application..."
        )
    endif()
endif()

if(KOTLIN_COMPILER)
    # Kotlin compilation and execution
    file(GLOB KT_SOURCES "*.kt")
    if(KT_SOURCES)
        add_custom_target(kotlin_compile ALL
            COMMAND ${KOTLIN_COMPILER} -include-runtime -d ${CMAKE_BINARY_DIR}/kotlin_app.jar ${KT_SOURCES}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Compiling Kotlin sources..."
        )
        
        add_custom_target(kotlin_run
            COMMAND ${JAVA_RUNTIME} -jar ${CMAKE_BINARY_DIR}/kotlin_app.jar
            DEPENDS kotlin_compile
            COMMENT "Running Kotlin application..."
        )
    endif()
endif()

if(PYTHON_INTERPRETER)
    # Python execution
    file(GLOB PYTHON_SOURCES "*.py")
    if(PYTHON_SOURCES)
        foreach(py_file ${PYTHON_SOURCES})
            get_filename_component(target_name ${py_file} NAME_WE)
            add_custom_target(python_${target_name}_run
                COMMAND ${PYTHON_INTERPRETER} ${py_file}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Running Python script ${py_file}..."
            )
        endforeach()
    endif()
endif()

if(CSHARP_COMPILER)
    # C# compilation (using dotnet or csc)
    file(GLOB CS_SOURCES "*.cs")
    if(CS_SOURCES)
        if(${CSHARP_COMPILER} STREQUAL "dotnet")
            add_custom_target(csharp_build ALL
                COMMAND dotnet new console -n csharp_app --force
                COMMAND dotnet add csharp_app/csharp_app.csproj reference ${CS_SOURCES}
                COMMAND dotnet build csharp_app
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                COMMENT "Building C# application..."
            )
            
            add_custom_target(csharp_run
                COMMAND dotnet run --project csharp_app
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                DEPENDS csharp_build
                COMMENT "Running C# application..."
            )
        else()
            add_custom_target(csharp_compile ALL
                COMMAND ${CSHARP_COMPILER} /out:${CMAKE_BINARY_DIR}/csharp_app.exe ${CS_SOURCES}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Compiling C# sources..."
            )
        endif()
    endif()
endif()

# Custom target to run all applications
add_custom_target(run_all
    COMMENT "Running all applications..."
)

if(TARGET c_app)
    add_dependencies(run_all c_app)
endif()

if(TARGET cpp_app)
    add_dependencies(run_all cpp_app)
endif()

if(JAVA_COMPILER AND TARGET java_run)
    add_dependencies(run_all java_run)
endif()

if(KOTLIN_COMPILER AND TARGET kotlin_run)
    add_dependencies(run_all kotlin_run)
endif()

# Set build types
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")

# Print build info
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
if(CMAKE_ASM_NASM_COMPILER)
    message(STATUS "ASM compiler: ${CMAKE_ASM_NASM_COMPILER}")
endif()
message(STATUS "Java compiler: ${JAVA_COMPILER}")
message(STATUS "Kotlin compiler: ${KOTLIN_COMPILER}")
message(STATUS "Python interpreter: ${PYTHON_INTERPRETER}")
message(STATUS "C# compiler: ${CSHARP_COMPILER}")

