## BitTesz.cpp létrehozása Visual_Studio_Codeban

![image-20260127133151307](E:\projects\Books\kepek\image-20260127133151307.png)

Ha sikerült kattints a **new file**_ra....(A mappát te hozd létre amit szeretnél én a **bitTeszt**_mappába fogom tenni)

![image-20260127133350672](E:\projects\Books\kepek\image-20260127133350672.png)

Írd be a fájl nevét....

![image-20260127133432126](E:\projects\Books\kepek\image-20260127133432126.png)

`.cpp` kiterjesztésel

Elsőnek teszteljük le.(Gyors hello_World)

![image-20260127133724467](E:\projects\Books\kepek\image-20260127133724467.png)

```
#include <iostream>

int main(int argc, char const *argv[]) {

    std::cout << "Hello World" << std::endl;

    return 0;
}
```

Nyomd meg a ctrl +shift +ö 

vagy a menuben keresd meg a terminalt és nyisd meg.

![image-20260127134050979](E:\projects\Books\kepek\image-20260127134050979.png)

Eredmény alul látni fogod.....

![image-20260127134121128](E:\projects\Books\kepek\image-20260127134121128.png)

forditsuk elsőnek **miniGW**- vel 

Ellenőrzés.....

`where G++`<br>

`G++ --version`<br>



X (Nem helyes)`# include <iostream>` -> ezt sose írd szóközel mert nem fog lefordulni ..... <br>

szóval <br>` gcc++ bitTest.cpp -o bitTest.exe`

Majd `bitTest.exe `

![image-20260127135729579](E:\projects\Books\kepek\image-20260127135729579.png)

Lefordult a kód

Most MSVC-vel ha windows alatt vagy <br>

`cl.exe bitTest.cpp`

lefordult akkor okés...

És `Clang`-al <br>

írd be cls mindent kitöröl így üres lesz a terminál<br> írd be : <br>

`clang++ bitTest.cpp -o my.exe`<br>

my.exe ha elindul okés ....

(Egyébként a G++ --help, cl.exe /help , clang)

```
E:\projects\vscode\bitTeszt>G++ --help
Usage: G++ [options] file...
Options:
  -pass-exit-codes         Exit with highest error code from a phase.
  --help                   Display this information.
  --target-help            Display target specific command line options (including assembler and linker options).
  --help={common|optimizers|params|target|warnings|[^]{joined|separate|undocumented}}[,...].
                           Display specific types of command line options.
  (Use '-v --help' to display command line options of sub-processes).
  --version                Display compiler version information.
  -dumpspecs               Display all of the built in spec strings.
  -dumpversion             Display the version of the compiler.
  -dumpmachine             Display the compiler's target processor.
  -foffload=<targets>      Specify offloading targets.
  -print-search-dirs       Display the directories in the compiler's search path.
  -print-libgcc-file-name  Display the name of the compiler's companion library.
  -print-file-name=<lib>   Display the full path to library <lib>.
  -print-prog-name=<prog>  Display the full path to compiler component <prog>.
  -print-multiarch         Display the target's normalized GNU triplet, used as
                           a component in the library path.
  -print-multi-directory   Display the root directory for versions of libgcc.
  -print-multi-lib         Display the mapping between command line options and
                           multiple library search directories.
  -print-multi-os-directory Display the relative path to OS libraries.
  -print-sysroot           Display the target libraries directory.
  -print-sysroot-headers-suffix Display the sysroot suffix used to find headers.
  -Wa,<options>            Pass comma-separated <options> on to the assembler.
  -Wp,<options>            Pass comma-separated <options> on to the preprocessor.
  -Wl,<options>            Pass comma-separated <options> on to the linker.
  -Xassembler <arg>        Pass <arg> on to the assembler.
  -Xpreprocessor <arg>     Pass <arg> on to the preprocessor.
  -Xlinker <arg>           Pass <arg> on to the linker.
  -save-temps              Do not delete intermediate files.
  -save-temps=<arg>        Do not delete intermediate files.
  -no-canonical-prefixes   Do not canonicalize paths when building relative
                           prefixes to other gcc components.
  -pipe                    Use pipes rather than intermediate files.
  -time                    Time the execution of each subprocess.
  -specs=<file>            Override built-in specs with the contents of <file>.
  -std=<standard>          Assume that the input sources are for <standard>.
  --sysroot=<directory>    Use <directory> as the root directory for headers
                           and libraries.
  -B <directory>           Add <directory> to the compiler's search paths.
  -v                       Display the programs invoked by the compiler.
  -###                     Like -v but options quoted and commands not executed.
  -E                       Preprocess only; do not compile, assemble or link.
  -S                       Compile only; do not assemble or link.
  -c                       Compile and assemble, but do not link.
  -o <file>                Place the output into <file>.
  -pie                     Create a dynamically linked position independent
                           executable.
  -shared                  Create a shared library.
  -x <language>            Specify the language of the following input files.
                           Permissible languages include: c c++ assembler none
                           'none' means revert to the default behavior of
                           guessing the language based on the file's extension.

Options starting with -g, -f, -m, -O, -W, or --param are automatically
 passed on to the various sub-processes invoked by G++.  In order to pass
 other options on to these processes the -W<letter> options must be used.

For bug reporting instructions, please see:
<https://gcc.gnu.org/bugs/>.

```
Most a **clang++ --help**


```
  -fno-unroll-loops       Turn off loop unroller
  -fno-use-cxa-atexit     Don't use __cxa_atexit for calling destructors
  -fno-use-init-array     Use .ctors/.dtors instead of .init_array/.fini_array
  -fno-verify-intermediate-code
                          Disable verification of LLVM IR
  -fno-visibility-inlines-hidden-static-local-var
                          Disables -fvisibility-inlines-hidden-static-local-var (this is the default on non-darwin targets)
  -fno-xray-function-index
                          Omit function index section at the expense of single-function patching performance
  -fno-zero-initialized-in-bss
                          Don't place zero initialized data in BSS
  -fno-zos-extensions     Do not accept non-standard constructs supported by the z/OS compiler
  -fobjc-arc-exceptions   Use EH-safe code when synthesizing retains and releases in -fobjc-arc
  -fobjc-arc              Synthesize retain and release calls for Objective-C pointers
  -fobjc-avoid-heapify-local-blocks
                          Try to avoid heapifying local blocks
  -fobjc-disable-direct-methods-for-testing
                          Ignore attribute objc_direct so that direct methods can be tested
  -fobjc-encode-cxx-class-template-spec
                          Fully encode c++ class template specialization
  -fobjc-exceptions       Enable Objective-C exceptions
  -fobjc-runtime=<value>  Specify the target Objective-C runtime kind and version
  -fobjc-weak             Enable ARC-style weak references in Objective-C
  -foffload-implicit-host-device-templates
                          Template functions or specializations without host, device and global attributes have implicit host device attributes (CUDA/HIP only)
  -foffload-lto=<value>   Set LTO mode for offload compilation
  -foffload-lto           Enable LTO in 'full' mode for offload compilation
  -foffload-uniform-block Assume that kernels are launched with uniform block sizes (default true for CUDA/HIP and false otherwise)
  -foffload-via-llvm      Use LLVM/Offload as portable offloading runtime.
  -fomit-frame-pointer    Omit the frame pointer from functions that don't need it. Some stack unwinding cases, such as profilers and sanitizers, may prefer specifying -fno-omit-frame-pointer. On many targets, -O1 and higher omit the frame pointer by default. -m[no-]omit-leaf-frame-pointer takes precedence for leaf functions
  -fopenacc               Enable OpenACC
  -fopenmp-extensions     Enable all Clang extensions for OpenMP directives and clauses
  -fopenmp-force-usm      Force behavior as if the user specified pragma omp requires unified_shared_memory.
  -fopenmp-offload-mandatory
                          Do not create a host fallback if offloading to the device fails.
  -fopenmp-simd           Emit OpenMP code only for SIMD-based constructs.
  -fopenmp-target-debug   Enable debugging in the OpenMP offloading device RTL
  -fopenmp-target-jit     Emit code that can be JIT compiled for OpenMP offloading. Implies -foffload-lto=full
  -fopenmp-targets=<value>
                          Specify comma-separated list of triples OpenMP offloading targets to be supported
  -fopenmp-version=<value>
                          Set OpenMP version (e.g. 45 for OpenMP 4.5, 51 for OpenMP 5.1). Default value is 51 for Clang
  -fopenmp                Parse OpenMP pragmas and generate parallel code.
  -foperator-arrow-depth=<value>
                          Maximum number of 'operator->'s to call for a member access
  -foptimization-record-file=<file>
                          Specify the output name of the file containing the optimization remarks. Implies -fsave-optimization-record. On Darwin platforms, this cannot be used with multiple -arch <arch> options.
  -foptimization-record-passes=<regex>
                          Only include passes which match a specified regular expression in the generated optimization record (by default, include all passes)
  -fpack-struct=<value>   Specify the default maximum struct packing alignment
  -fpascal-strings        Recognize and construct Pascal-style string literals
  -fpass-plugin=<dsopath> Load pass plugin from a dynamic shared object file (only with new pass manager).
  -fpatchable-function-entry=<N,M,Section>
                          Generate M NOPs before function entry and N-M NOPs after function entry. If section is specified, use it instead of __patchable_function_entries.
  -fpcc-struct-return     Override the default ABI to return all structs on the stack
  -fpch-codegen           Generate code for uses of this PCH that assumes an explicit object file will be built for the PCH
  -fpch-debuginfo         Generate debug info for types in an object file built from this PCH and do not generate them elsewhere
  -fpch-instantiate-templates
                          Instantiate templates already while building a PCH
  -fpch-validate-input-files-content
                          Validate PCH input files based on content if mtime differs
  -fplugin-arg-<name>-<arg>
                          Pass <arg> to plugin <name>
  -fplugin=<dsopath>      Load the named plugin (dynamic shared object)
  -fprebuilt-implicit-modules
                          Look up implicit modules in the prebuilt module path
  -fprebuilt-module-path=<directory>
                          Specify the prebuilt module path
  -fproc-stat-report=<value>
                          Save subprocess statistics to the given file
  -fproc-stat-report<value>
                          Print subprocess statistics
  -fprofile-arcs          Instrument code to produce gcov data files (*.gcda)
  -fprofile-continuous    Enable continuous instrumentation profiling mode
  -fprofile-exclude-files=<value>
                          Instrument only functions from files where names don't match all the regexes separated by a semi-colon
  -fprofile-filter-files=<value>
                          Instrument only functions from files where names match any regex separated by a semi-colon
  -fprofile-function-groups=<N>
                          Partition functions into N groups and select only functions in group i to be instrumented using -fprofile-selected-function-group
  -fprofile-generate-cold-function-coverage=<directory>
                          Generate instrumented code to collect coverage info for cold functions into <directory>/default.profraw (overridden by LLVM_PROFILE_FILE env var)
  -fprofile-generate-cold-function-coverage
                          Generate instrumented code to collect coverage info for cold functions into default.profraw file (overridden by '=' form of option or LLVM_PROFILE_FILE env var)
  -fprofile-generate=<directory>
                          Generate instrumented code to collect execution counts into <directory>/default.profraw (overridden by LLVM_PROFILE_FILE env var)
  -fprofile-generate      Generate instrumented code to collect execution counts into default.profraw (overridden by LLVM_PROFILE_FILE env var)  
  -fprofile-instr-generate=<file>
                          Generate instrumented code to collect execution counts into <file> (overridden by LLVM_PROFILE_FILE env var)
  -fprofile-instr-generate
                          Generate instrumented code to collect execution counts into default.profraw file (overridden by '=' form of option or LLVM_PROFILE_FILE env var)
  -fprofile-instr-use=<value>
                          Use instrumentation data for profile-guided optimization
  -fprofile-list=<value>  Filename defining the list of functions/files to instrument. The file uses the sanitizer special case list format.     
  -fprofile-remapping-file=<file>
                          Use the remappings described in <file> to match the profile data against names in the program
  -fprofile-sample-accurate
                          Specifies that the sample profile is accurate
  -fprofile-sample-use=<value>
                          Enable sample-based profile guided optimizations
  -fprofile-selected-function-group=<i>
                          Partition functions into N groups using -fprofile-function-groups and select only functions in group i to be instrumented. The valid range is 0 to N-1 inclusive
  -fprofile-update=<method>
                          Set update method of profile counters
  -fprofile-use=<pathname>
                          Use instrumentation data for profile-guided optimization. If pathname is a directory, it reads from <pathname>/default.profdata. Otherwise, it reads from file <pathname>.
  -fprotect-parens        Determines whether the optimizer honors parentheses when floating-point expressions are evaluated
  -fpseudo-probe-for-profiling
                          Emit pseudo probes for sample profiling
  -fptrauth-auth-traps    Enable traps on authentication failures
  -fptrauth-block-descriptor-pointers
                          Enable signing and authentication of block descriptors
  -fptrauth-calls         Enable signing and authentication of all indirect calls
  -fptrauth-elf-got       Enable authentication of pointers from GOT (ELF only)
  -fptrauth-function-pointer-type-discrimination
                          Enable type discrimination on C function pointers
  -fptrauth-indirect-gotos
                          Enable signing and authentication of indirect goto targets
  -fptrauth-init-fini-address-discrimination
                          Enable address discrimination of function pointers in init/fini arrays
  -fptrauth-init-fini     Enable signing of function pointers in init/fini arrays
  -fptrauth-intrinsics    Enable pointer authentication intrinsics
  -fptrauth-objc-class-ro Enable signing and authentication for ObjC class_ro pointers
  -fptrauth-objc-interface-sel
                          Enable signing and authentication of Objective-C object's 'SEL' fields
  -fptrauth-objc-isa      Enable signing and authentication of Objective-C object's 'isa' field
  -fptrauth-returns       Enable signing and authentication of return addresses
  -fptrauth-type-info-vtable-pointer-discrimination
                          Enable type and address discrimination of vtable pointer of std::type_info
  -fptrauth-vtable-pointer-address-discrimination
                          Enable address discrimination of vtable pointers
  -fptrauth-vtable-pointer-type-discrimination
                          Enable type discrimination of vtable pointers
  -frandomize-layout-seed-file=<file>
                          File holding the seed used by the randomize structure layout feature
  -frandomize-layout-seed=<seed>
                          The seed used by the randomize structure layout feature
  -fraw-string-literals   Enable raw string literals
  -freciprocal-math       Allow division operations to be reassociated
  -freg-struct-return     Override the default ABI to return small structs in registers
  -fregister-global-dtors-with-atexit
                          Use atexit or __cxa_atexit to register global destructors
  -fropi                  Generate read-only position independent code (ARM only)
  -frtlib-add-rpath       Add -rpath with architecture-specific resource directory to the linker flags. When --hip-link is specified, also add -rpath with HIP runtime library directory to the linker flags
  -frtlib-defaultlib      On Windows, emit /defaultlib: directives to link compiler-rt libraries (default)
  -frwpi                  Generate read-write position independent code (ARM only)
  -fsafe-buffer-usage-suggestions
                          Display suggestions to update code associated with -Wunsafe-buffer-usage warnings
  -fsample-profile-use-profi
                          Use profi to infer block and edge counts
  -fsanitize-address-destructor=<value>
                          Set the kind of module destructors emitted by AddressSanitizer instrumentation. These destructors are emitted to unregister instrumented global variables when code is unloaded (e.g. via `dlclose()`).
  -fsanitize-address-field-padding=<value>
                          Level of field padding for AddressSanitizer
  -fsanitize-address-globals-dead-stripping
                          Enable linker dead stripping of globals in AddressSanitizer
  -fsanitize-address-outline-instrumentation
                          Always generate function calls for address sanitizer instrumentation
  -fsanitize-address-poison-custom-array-cookie
                          Enable poisoning array cookies when using custom operator new[] in AddressSanitizer
  -fsanitize-address-use-after-return=<mode>
                          Select the mode of detecting stack use-after-return in AddressSanitizer
  -fsanitize-address-use-after-scope
                          Enable use-after-scope detection in AddressSanitizer
  -fsanitize-address-use-odr-indicator
                          Enable ODR indicator globals to avoid false ODR violation reports in partially sanitized programs at the cost of an increase in binary size
  -fsanitize-annotate-debug-info=<value>
                          Annotate sanitizer instrumentation with extra debug info for the specified sanitizers, if supported
  -fsanitize-annotate-debug-info
                          Allow compiler to annotate sanitizer instrumentation with extra debug info for all sanitizers, where supported
  -fsanitize-cfi-canonical-jump-tables
                          Make the jump table addresses canonical in the symbol table
  -fsanitize-cfi-cross-dso
                          Enable control flow integrity (CFI) checks for cross-DSO calls.
  -fsanitize-cfi-icall-experimental-normalize-integers
                          Normalize integers in CFI indirect call type signature checks
  -fsanitize-cfi-icall-generalize-pointers
                          Generalize pointers in CFI indirect call type signature checks
  -fsanitize-coverage-allowlist=<value>
                          Restrict sanitizer coverage instrumentation exclusively to modules and functions that match the provided special case list, except the blocked ones
  -fsanitize-coverage-ignorelist=<value>
                          Disable sanitizer coverage instrumentation for modules and functions that match the provided special case list, even the allowed ones
  -fsanitize-coverage-stack-depth-callback-min=<M>
                          Use callback for max stack depth tracing with minimum stack depth M
  -fsanitize-coverage=<value>
                          Specify the type of coverage instrumentation for Sanitizers
  -fsanitize-hwaddress-abi=<value>
                          Select the HWAddressSanitizer ABI to target (interceptor or platform, default interceptor). This option is currently unused.
  -fsanitize-hwaddress-experimental-aliasing
                          Enable aliasing mode in HWAddressSanitizer
  -fsanitize-ignorelist=<value>
                          Path to ignorelist file for sanitizers
  -fsanitize-kcfi-arity   Embed function arity information into the KCFI patchable function prefix
  -fsanitize-memory-param-retval
                          Enable detection of uninitialized parameters and return values
  -fsanitize-memory-track-origins=<value>
                          Enable origins tracking in MemorySanitizer
  -fsanitize-memory-track-origins
                          Enable origins tracking in MemorySanitizer
  -fsanitize-memory-use-after-dtor
                          Enable use-after-destroy detection in MemorySanitizer
  -fsanitize-memtag-mode=<value>
                          Set default MTE mode to 'sync' (default) or 'async'
  -fsanitize-merge=<value>
                          Allow compiler to merge handlers for specified sanitizers
  -fsanitize-merge        Allow compiler to merge handlers for all sanitizers
  -fsanitize-recover=<value>
                          Enable recovery for specified sanitizers
  -fsanitize-skip-hot-cutoff=<value>
                          Exclude sanitization for the top hottest code responsible for the given fraction of PGO counters (0.0 [default] = skip none; 1.0 = skip all). Argument format: <sanitizer1>=<value1>,<sanitizer2>=<value2>,...
  -fsanitize-stable-abi   Stable  ABI instrumentation for sanitizer runtime. Default: Conventional
  -fsanitize-stats        Enable sanitizer statistics gathering.
  -fsanitize-system-ignorelist=<value>
                          Path to system ignorelist file for sanitizers
  -fsanitize-thread-atomics
                          Enable atomic operations instrumentation in ThreadSanitizer (default)
  -fsanitize-thread-func-entry-exit
                          Enable function entry/exit instrumentation in ThreadSanitizer (default)
  -fsanitize-thread-memory-access
                          Enable memory access instrumentation in ThreadSanitizer (default)
  -fsanitize-trap=<value> Enable trapping for specified sanitizers
  -fsanitize-trap         Enable trapping for all sanitizers
  -fsanitize-undefined-ignore-overflow-pattern=<value>
                          Specify the overflow patterns to exclude from arithmetic sanitizer instrumentation
  -fsanitize-undefined-strip-path-components=<number>
                          Strip (or keep only, if negative) a given number of path components when emitting check metadata.
  -fsanitize=<check>      Turn on runtime checks for various forms of undefined or suspicious behavior. See user manual for available checks     
  -fsave-optimization-record=<format>
                          Generate an optimization record file in a specific format
  -fsave-optimization-record
                          Generate a YAML optimization record file
  -fseh-exceptions        Use SEH style exceptions
  -fseparate-named-sections
                          Use separate unique sections for named sections (ELF Only)
  -fshort-enums           Allocate to an enum type only as many bytes as it needs for the declared range of possible values
  -fshort-wchar           Force wchar_t to be a short unsigned int
  -fshow-overloads=<value>
                          Which overload candidates to show when overload resolution fails. Defaults to 'all'
  -fshow-skipped-includes Show skipped includes in -H output.
  -fsigned-char           char is signed
  -fsized-deallocation    Enable C++14 sized global deallocation functions
  -fsjlj-exceptions       Use SjLj style exceptions
  -fskip-odr-check-in-gmf Skip ODR checks for decls in the global module fragment.
  -fslp-vectorize         Enable the superword-level parallelism vectorization passes
  -fspell-checking-limit=<value>
                          Set the maximum number of times to perform spell checking on unrecognized identifiers (0 = no limit)
  -fsplit-dwarf-inlining  Provide minimal debug info in the object/executable to facilitate online symbolication/stack traces in the absence of .dwo/.dwp files when using Split DWARF
  -fsplit-lto-unit        Enables splitting of the LTO unit
  -fsplit-machine-functions
                          Enable late function splitting using profile information (x86 and aarch64 ELF)
  -fsplit-stack           Use segmented stack
  -fstack-clash-protection
                          Enable stack clash protection
  -fstack-protector-all   Enable stack protectors for all functions
  -fstack-protector-strong
                          Enable stack protectors for some functions vulnerable to stack smashing. Compared to -fstack-protector, this uses a stronger heuristic that includes functions containing arrays of any size (and any type), as well as any calls to alloca or the taking of an address from a local variable
  -fstack-protector       Enable stack protectors for some functions vulnerable to stack smashing. This uses a loose heuristic which considers functions vulnerable if they contain a char (or 8bit integer) array or constant sized calls to alloca , which are of greater size than ssp-buffer-size (default: 8 bytes). All variable sized calls to alloca are considered vulnerable. A function with a stack protector has a guard value added to the stack frame that is checked on function exit. The guard value must be positioned in the stack frame such that a buffer overflow from a vulnerable variable will overwrite the guard value before overwriting the function's return address. The reference stack guard value is stored in a global variable.
  -fstack-size-section    Emit section containing metadata on function stack sizes
  -fstack-usage           Emit .su file containing information on function stack sizes
  -fstandalone-debug      Emit full debug info for all types used by the program
  -fstrict-aliasing       Enable optimizations based on strict aliasing rules
  -fstrict-enums          Enable optimizations based on the strict definition of an enum's value range
  -fstrict-flex-arrays=<n>
                          Enable optimizations based on the strict definition of flexible arrays.
  -fstrict-float-cast-overflow
                          Assume that overflowing float-to-int casts are undefined (default)
  -fstrict-vtable-pointers
                          Enable optimizations based on the strict rules for overwriting polymorphic C++ objects
  -fswift-async-fp=<option>
                          Control emission of Swift async extended frame info
  -fswift-version-independent-apinotes
                          Enable version-independent external API notes support
  -fsycl-device-only      Compile SYCL code for device only
  -fsycl-host-only        Compile SYCL code for host only. Has no effect on non-SYCL compilations
  -fsycl                  Enable SYCL C++ extensions
  -fsyntax-only           Run the preprocessor, parser and semantic analysis stages
  -fsystem-module         Build this module as a system module. Only used with -emit-module
  -ftemplate-backtrace-limit=<value>
                          Set the maximum number of entries to print in a template instantiation backtrace (0 = no limit)
  -ftemplate-depth=<value>
                          Set the maximum depth of recursive template instantiation
  -ftemporal-profile      Generate instrumented code to collect temporal information
  -ftest-coverage         Produce gcov notes files (*.gcno)
  -fthin-link-bitcode=<value>
                          Write minimized bitcode to <file> for the ThinLTO thin link only
  -fthinlto-distributor=<path>
                          Path to the ThinLTO distributor process. If specified, ThinLTO backend compilations will be distributed by LLD
  -fthinlto-index=<value> Perform ThinLTO importing using provided function summary index
  -ftime-report=<value>   (For new pass manager) 'per-pass': one report for each pass; 'per-pass-run': one report for each pass invocation       
  -ftime-trace-granularity=<value>
                          Minimum time granularity (in microseconds) traced by time profiler
  -ftime-trace-verbose<value>
                          Make time trace capture verbose event details (e.g. source filenames). This can increase the size of the output by 2-3 times
  -ftime-trace=<value>    Similar to -ftime-trace. Specify the JSON file or a directory which will contain the JSON file
  -ftime-trace            Turn on time profiler. Generates JSON file based on output filename.
  -ftrap-function=<value> Issue call to specified function rather than a trap instruction
  -ftrapv-handler=<function name>
                          Specify the function to be called on overflow
  -ftrapv                 Trap on integer overflow
  -ftrigraphs             Process trigraph sequences
  -ftrivial-auto-var-init-max-size=<value>
                          Stop initializing trivial automatic stack variables if var size exceeds the specified number of instances (in bytes)   
  -ftrivial-auto-var-init-stop-after=<value>
                          Stop initializing trivial automatic stack variables after the specified number of instances
  -ftrivial-auto-var-init=<value>
                          Initialize trivial automatic stack variables. Defaults to 'uninitialized'
  -funified-lto           Use the unified LTO pipeline
  -funique-basic-block-section-names
                          Use unique names for basic block sections (ELF Only)
  -funique-internal-linkage-names
                          Uniqueify Internal Linkage Symbol Names by appending the MD5 hash of the module path
  -funique-source-file-identifier=<value>
                          Specify the source file identifier for -funique-source-file-names; uses the source file path if not specified
  -funique-source-file-names
                          Allow the compiler to assume that each translation unit has a unique source file identifier (see -funique-source-file-identifier) at link time
  -funroll-loops          Turn on loop unroller
  -funsafe-math-optimizations
                          Allow unsafe floating-point math optimizations which may decrease precision
  -fuse-cuid=<value>      Method to generate ID's for compilation units for single source offloading languages CUDA and HIP: 'hash' (ID's generated by hashing file path and command line options) | 'random' (ID's generated as random numbers) | 'none' (disabled). Default is 'hash'. This option will be overridden by option '-cuid=[ID]' if it is specified.
  -fuse-line-directives   Use #line in preprocessed output
  -fvalidate-ast-input-files-content
                          Compute and store the hash of input files used to build an AST. Files with mismatching mtime's are considered valid if both contents is identical
  -fveclib=<value>        Use the given vector functions library.
                            Note: -fveclib={ArmPL,SLEEF,libmvec} implies -fno-math-errno.
                            Note: -fveclib=libmvec on AArch64 requires GLIBC 2.40 or newer.
  -fvectorize             Enable the loop vectorization passes
  -fverbose-asm           Generate verbose assembly output
  -fverify-intermediate-code
                          Enable verification of LLVM IR
  -fvirtual-function-elimination
                          Enables dead virtual function elimination optimization. Requires -flto=full
  -fvisibility-dllexport=<value>
                          The visibility for dllexport definitions. If Keep is specified the visibility is not adjusted [-fvisibility-from-dllstorageclass]
  -fvisibility-externs-dllimport=<value>
                          The visibility for dllimport external declarations. If Keep is specified the visibility is not adjusted [-fvisibility-from-dllstorageclass]
  -fvisibility-externs-nodllstorageclass=<value>
                          The visibility for external declarations without an explicit DLL storage class. If Keep is specified the visibility is not adjusted [-fvisibility-from-dllstorageclass]
  -fvisibility-from-dllstorageclass
                          Override the visibility of globals based on their final DLL storage class.
  -fvisibility-global-new-delete-hidden
                          Give global C++ operator new and delete declarations hidden visibility
  -fvisibility-global-new-delete=<value>
                          The visibility for global C++ operator new and delete declarations. If 'source' is specified the visibility is not adjusted
  -fvisibility-inlines-hidden-static-local-var
                          When -fvisibility-inlines-hidden is enabled, static variables in inline C++ member functions will also be given hidden visibility by default
  -fvisibility-inlines-hidden
                          Give inline C++ member functions hidden visibility by default
  -fvisibility-ms-compat  Give global types 'default' visibility and global functions and variables 'hidden' visibility by default
  -fvisibility-nodllstorageclass=<value>
                          The visibility for definitions without an explicit DLL storage class. If Keep is specified the visibility is not adjusted [-fvisibility-from-dllstorageclass]
  -fvisibility=<value>    Set the default symbol visibility for all global definitions
  -fwasm-exceptions       Use WebAssembly style exceptions
  -fwhole-program-vtables Enables whole-program vtable optimization. Requires -flto
  -fwinx64-eh-unwindv2=<value>
                          Generate unwind v2 (epilog) information for x64 Windows
  -fwrapv-pointer         Treat pointer overflow as two's complement
  -fwrapv                 Treat signed integer overflow as two's complement
  -fwritable-strings      Store string literals as writable data
  -fxl-pragma-pack        Enable IBM XL #pragma pack handling
  -fxray-always-emit-customevents
                          Always emit __xray_customevent(...) calls even if the containing function is not always instrumented
  -fxray-always-emit-typedevents
                          Always emit __xray_typedevent(...) calls even if the containing function is not always instrumented
  -fxray-always-instrument=<value>
                          DEPRECATED: Filename defining the whitelist for imbuing the 'always instrument' XRay attribute.
  -fxray-attr-list=<value>
                          Filename defining the list of functions/types for imbuing XRay attributes.
  -fxray-function-groups=<value>
                          Only instrument 1 of N groups
  -fxray-ignore-loops     Don't instrument functions with loops unless they also meet the minimum function size
  -fxray-instruction-threshold=<value>
                          Sets the minimum function size to instrument with XRay
  -fxray-instrumentation-bundle=<value>
                          Select which XRay instrumentation points to emit. Options: all, none, function-entry, function-exit, function, custom. Default is 'all'.  'function' includes both 'function-entry' and 'function-exit'.
  -fxray-instrument       Generate XRay instrumentation sleds on function entry and exit
  -fxray-link-deps        Link XRay runtime library when -fxray-instrument is specified (default)
  -fxray-modes=<value>    List of modes to link in by default into XRay instrumented binaries.
  -fxray-never-instrument=<value>
                          DEPRECATED: Filename defining the whitelist for imbuing the 'never instrument' XRay attribute.
  -fxray-selected-function-group=<value>
                          When using -fxray-function-groups, select which group of functions to instrument. Valid range is 0 to fxray-function-groups - 1
  -fxray-shared           Enable shared library instrumentation with XRay
  -fzero-call-used-regs=<value>
                          Clear call-used registers upon function return (AArch64/x86 only)
  -fzos-extensions        Accept some non-standard constructs supported by the z/OS compiler
  -fzvector               Enable System z vector language extension
  -F <value>              Add directory to framework include search path
  --gcc-install-dir=<value>
                          Use GCC installation in the specified directory. The directory ends with path components like 'lib{,32,64}/gcc{,-cross}/$triple/$version'. Note: executables (e.g. ld) used by the compiler are not overridden by the selected GCC installation
  --gcc-toolchain=<value> Specify a directory where Clang can find 'include' and 'lib{,32,64}/gcc{,-cross}/$triple/$version'. Clang will use the GCC installation with the largest version
  --gcc-triple=<value>    Search for the GCC installation with the specified triple.
  -gcodeview-command-line Emit compiler path and command line into CodeView debug information
  -gcodeview-ghash        Emit type record hashes in a .debug$H section
  -gcodeview              Generate CodeView debug information
  -gdwarf-2               Generate source-level debug information with dwarf version 2
  -gdwarf-3               Generate source-level debug information with dwarf version 3
  -gdwarf-4               Generate source-level debug information with dwarf version 4
  -gdwarf-5               Generate source-level debug information with dwarf version 5
  -gdwarf32               Enables DWARF32 format for ELF binaries, if debug information emission is enabled.
  -gdwarf64               Enables DWARF64 format for ELF binaries, if debug information emission is enabled.
  -gdwarf                 Generate source-level debug information with the default dwarf version
  -gembed-source          Embed source text in DWARF debug sections
  -gen-reproducer=<value> Emit reproducer on (option: off, crash (default), error, always)
  -gkey-instructions      Enable Key Instructions, which reduces the jumpiness of debug stepping in optimized C/C++ code in some debuggers. DWARF only. Implies -g.
  -gline-directives-only  Emit debug line info directives only
  -gline-tables-only      Emit debug line number tables only
  -gmodules               Generate debug info with external references to clang modules or precompiled headers
  -gno-codeview-command-line
                          Don't emit compiler path and command line into CodeView debug information
  -gno-embed-source       Restore the default behavior of not embedding source text in DWARF debug sections
  -gno-inline-line-tables Don't emit inline line tables.
  --gpu-bundle-output     Bundle output files of HIP device compilation
  --gpu-instrument-lib=<value>
                          Instrument device library for HIP, which is a LLVM bitcode containing __cyg_profile_func_enter and __cyg_profile_func_exit
  --gpu-max-threads-per-block=<value>
                          Default max threads per block for kernel launch bounds for HIP
  -gpulibc                Link the LLVM C Library for GPUs
  -gsplit-dwarf=<value>   Set DWARF fission mode
  -gstrict-dwarf          Restrict DWARF features to those defined in the specified version, avoiding features from later versions.
  -gz=<value>             DWARF debug sections compression type
  -G <size>               Put objects of at most <size> bytes into small data section (MIPS / Hexagon)
  -g                      Generate source-level debug information
  --help-hidden           Display help for hidden options
  -help                   Display available options
  --hip-device-lib=<value>
                          HIP device library
  --hip-link              Link clang-offload-bundler bundles for HIP
  --hip-path=<value>      HIP runtime installation path, used for finding HIP version and adding HIP include path.
  --hip-version=<value>   HIP version in the format of major.minor.patch
  --hipspv-pass-plugin=<dsopath>
                          path to a pass plugin for HIP to SPIR-V passes.
  --hipstdpar-interpose-alloc
                          Replace all memory allocation / deallocation calls with hipManagedMalloc / hipFree equivalents
  --hipstdpar-path=<value>
                          HIP Standard Parallel Algorithm Acceleration library path, used for finding and implicitly including the library header
  --hipstdpar-prim-path=<value>
                          rocPrim path, required by the HIP Standard Parallel Algorithm Acceleration library, used to implicitly include the rocPrim library
  --hipstdpar-thrust-path=<value>
                          rocThrust path, required by the HIP Standard Parallel Algorithm Acceleration library, used to implicitly include the rocThrust library
  --hipstdpar             Enable HIP acceleration for standard parallel algorithms
  -H                      Show header includes and nesting depth
  -I-                     Restrict all prior -I flags to double-quoted inclusion and remove current directory from include path
  -iapinotes-modules <directory>
                          Add directory to the API notes search path referenced by module name
  -ibuiltininc            Enable builtin #include directories even when -nostdinc is used before or after -ibuiltininc. Using -nobuiltininc after the option disables it
  -idirafter <value>      Add directory to AFTER include search path
  -iframeworkwithsysroot <directory>
                          Add directory to SYSTEM framework search path, absolute paths are relative to -isysroot
  -iframework <value>     Add directory to SYSTEM framework search path
  -ignore-pch             Disable precompiled headers, overrides -emit-pch and -include-pch
  -imacros <file>         Include macros from file before parsing
  -include-pch <file>     Include precompiled header file
  -include <file>         Include file before parsing
  -iprefix <dir>          Set the -iwithprefix/-iwithprefixbefore prefix
  -iquote <directory>     Add directory to QUOTE include search path
  -isysroot <dir>         Set the system root directory (usually /)
  -isystem-after <directory>
                          Add directory to end of the SYSTEM include search path
  -isystem <directory>    Add directory to SYSTEM include search path
  -ivfsoverlay <value>    Overlay the virtual filesystem described by file over the real file system
  -iwithprefixbefore <dir>
                          Set directory to include search path with prefix
  -iwithprefix <dir>      Set directory to SYSTEM include search path with prefix
  -iwithsysroot <directory>
                          Add directory to SYSTEM include search path, absolute paths are relative to -isysroot
  -I <dir>                Add directory to the end of the list of include search paths
  --libomptarget-amdgcn-bc-path=<value>
                          Path to libomptarget-amdgcn bitcode library
  --libomptarget-amdgpu-bc-path=<value>
                          Path to libomptarget-amdgcn bitcode library
  --libomptarget-nvptx-bc-path=<value>
                          Path to libomptarget-nvptx bitcode library
  --libomptarget-spirv-bc-path=<value>
                          Path to libomptarget-spirv bitcode library
  -L <dir>                Add directory to library search path
  -mabi=quadword-atomics  Enable quadword atomics ABI on AIX (AIX PPC64 only). Uses lqarx/stqcx. instructions.
  -mabicalls              Enable SVR4-style position-independent code (Mips only)
  -maix-shared-lib-tls-model-opt
                          For shared library loaded with the main program, change local-dynamic access(es) to initial-exec access(es) at the function level (AIX 64-bit only).
  -maix-small-local-dynamic-tls
                          Produce a faster access sequence for local-dynamic TLS variables where the offset from the TLS base is encoded as an immediate operand (AIX 64-bit only). This access sequence is not used for variables larger than 32KB.
  -maix-small-local-exec-tls
                          Produce a faster access sequence for local-exec TLS variables where the offset from the TLS base is encoded as an immediate operand (AIX 64-bit only). This access sequence is not used for variables larger than 32KB.
  -maix-struct-return     Return all structs in memory (PPC32 only)
  -malign-branch-boundary=<value>
                          Specify the boundary's size to align branches
  -malign-branch=<value>  Specify types of branches to align
  -malign-double          Align doubles to two words in structs (x86 only)
  -maltivec               Enable AltiVec vector initializer syntax
  -mamdgpu-ieee           Sets the IEEE bit in the expected default floating point  mode register. Floating point opcodes that support exception flag gathering quiet and propagate signaling NaN inputs per IEEE 754-2008. This option changes the ABI. (AMDGPU only)
  -mamdgpu-precise-memory-op
                          Enable precise memory mode (AMDGPU only)
  -mannotate-tablejump    Enable annotate table jump instruction to correlate it with the jump table.
  -mapx-features=<value>  Enable features of APX
  -mapx-inline-asm-use-gpr32
                          Enable use of GPR32 in inline assembly for APX
  -march=<value>          For a list of available architectures for the target use '-mcpu=help'
  -marm64x<value>         Link as a hybrid ARM64X image
  -mbackchain             Link stack frames through backchain on System Z
  -mbranch-protection=<value>
                          Enforce targets of indirect branches and function returns
  -mbranches-within-32B-boundaries
                          Align selected branches (fused, jcc, jmp) within 32-byte boundary
  -mcabac                 Enable CABAC instructions
  -mcf-branch-label-scheme=<value>
                          Select label scheme for branch control-flow architecture protection
  -mcmse                  Allow use of CMSE (Armv8-M Security Extensions)
  -mcode-object-version=<value>
                          Specify code object ABI version. Defaults to 6. (AMDGPU only)
  -mconstructor-aliases   Enable emitting complete constructors and destructors as aliases when possible
  -mcpu=<value>           For a list of available CPUs for the target use '-mcpu=help'
  -mcrbits                Control the CR-bit tracking feature on PowerPC. ``-mcrbits`` (the enablement of CR-bit tracking support) is the default for POWER8 and above, as well as for all other CPUs when optimization is applied (-O2 and above).
  -mcrc                   Allow use of CRC instructions (ARM/Mips only)
  -mcumode                Specify CU wavefront execution mode (AMDGPU only)
  -mdaz-ftz               Globally set the denormals-are-zero (DAZ) and flush-to-zero (FTZ) bits in the floating-point control register on program startup
  -mdefault-visibility-export-mapping=<value>
                          Mapping between default visibility and export
  -mdiv32                 Use div.w[u] and mod.w[u] instructions with input not sign-extended.
  -mdouble=<n             Force double to be <n> bits
  -MD                     Write a depfile containing user and system headers
  -meabi <value>          Set EABI type. Default depends on triple)
  -membedded-data         Place constants in the .rodata section instead of the .sdata section even if they meet the -G <size> threshold (MIPS)  
  -menable-experimental-extensions
                          Enable use of experimental RISC-V extensions.
  -mexec-model=<value>    Execution model (WebAssembly only)
  -mexecute-only          Disallow generation of data access to code sections (AArch64/ARM only)
  -mextern-sdata          Assume that externally defined data is in the small data if it meets the -G <size> threshold (MIPS)
  -mfentry                Insert calls to fentry at function entry (x86/SystemZ only)
  -mfix-cmse-cve-2021-35465
                          Work around VLLDM erratum CVE-2021-35465 (ARM only)
  -mfix-cortex-a53-835769 Work around Cortex-A53 erratum 835769 (AArch64 only)
  -mfix-cortex-a53-843419 Work around Cortex-A53 erratum 843419 (AArch64 only)
  -mfix-cortex-a57-aes-1742098
                          Work around Cortex-A57 Erratum 1742098 (ARM only)
  -mfix-cortex-a72-aes-1655431
                          Work around Cortex-A72 Erratum 1655431 (ARM only)
  -mfix-gr712rc           Enable workarounds for GR712RC errata
  -mfix-ut700             Enable workarounds for UT700 errata
  -mfp32                  Use 32-bit floating point registers (MIPS only)
  -mfp64                  Use 64-bit floating point registers (MIPS only)
  -mframe-chain=<value>   Select the frame chain model used to emit frame records (Arm only).
  -mfrecipe               Enable frecipe.{s/d} and frsqrte.{s/d}
  -mfunction-return=<value>
                          Replace returns with jumps to ``__x86_return_thunk`` (x86 only, error otherwise)
  -MF <file>              Write depfile output from -MMD, -MD, -MM, or -M to <file>
  -mgeneral-regs-only     Generate code which only uses the general purpose registers (AArch64/x86 only)
  -mglobal-merge          Enable merging of globals
  -mgpopt                 Use GP relative accesses for symbols known to be in a small data section (MIPS)
  -mguard=<value>         Enable or disable Control Flow Guard checks and guard tables emission
  -MG                     Add missing headers to depfile
  -mharden-sls=<value>    Select straight-line speculation hardening scope (ARM/AArch64/X86 only). <arg> must be: all, none, retbr(ARM/AArch64), blr(ARM/AArch64), comdat(ARM/AArch64), nocomdat(ARM/AArch64), return(X86), indirect-jmp(X86)
  -mhvx-ieee-fp           Enable Hexagon HVX IEEE floating-point
  -mhvx-length=<value>    Set Hexagon Vector Length
  -mhvx-qfloat            Enable Hexagon HVX QFloat instructions
  -mhvx=<value>           Enable Hexagon Vector eXtensions
  -mhvx                   Enable Hexagon Vector eXtensions
  -miamcu                 Use Intel MCU ABI
  -mignore-xcoff-visibility
                          Not emit the visibility attribute for asm in AIX OS or give all symbols 'unspecified' visibility in XCOFF object file  
  -mincremental-linker-compatible
                          (integrated-as) Emit an object file which can be used with an incremental linker
  -mindirect-branch-cs-prefix
                          Add cs prefix to call and jmp to indirect thunk
  -mindirect-jump=<value> Change indirect jump instructions to inhibit speculation
  -mios-version-min=<value>
                          Set iOS deployment target
  -MJ <value>             Write a compilation database entry per input
  -mlam-bh                Enable amswap[_db].{b/h} and amadd[_db].{b/h}
  -mlamcas                Enable amcas[_db].{b/h/w/d}
  -mlasx                  Enable Loongson Advanced SIMD Extension (LASX).
  -mld-seq-sa             Do not generate same-address load-load barrier instructions (dbar 0x700)
  -mlink-builtin-bitcode-postopt
                          Link builtin bitcodes after the optimization pipeline
  -mllvm=<arg>            Alias for -mllvm
  -mllvm <value>          Additional arguments to forward to LLVM's option processing
  -mlocal-sdata           Extend the -G behaviour to object local data (MIPS)
  -mlong-calls            Generate branches with extended addressability, usually via indirect jumps.
  -mlong-double-128       Force long double to be 128 bits
  -mlong-double-64        Force long double to be 64 bits
  -mlong-double-80        Force long double to be 80 bits, padded to 128 bits for storage
  -mlr-for-calls-only     Do not allocate the LR register for general purpose usage, only for calls. (AArch64 only)
  -mlsx                   Enable Loongson SIMD Extension (LSX).
  -mlvi-cfi               Enable only control-flow mitigations for Load Value Injection (LVI)
  -mlvi-hardening         Enable all mitigations for Load Value Injection (LVI)
  -mmacos-version-min=<value>
                          Set macOS deployment target
  -mmadd4                 Enable the generation of 4-operand madd.s, madd.d and related instructions.
  -mmark-bti-property     Add .note.gnu.property with BTI to assembly files (AArch64 only)
  -MMD                    Write a depfile containing user headers
  -mmemops                Enable generation of memop instructions
  -mmlir <value>          Additional arguments to forward to MLIR's option processing
  -mms-bitfields          Set the default structure layout to be compatible with the Microsoft compiler standard
  -mmsa                   Enable MSA ASE (MIPS only)
  -mmt                    Enable MT ASE (MIPS only)
  -MM                     Like -MMD, but also implies -E and writes to stdout by default
  -mno-abicalls           Disable SVR4-style position-independent code (Mips only)
  -mno-amdgpu-precise-memory-op
                          Disable precise memory mode (AMDGPU only)
  -mno-annotate-tablejump Disable annotate table jump instruction to correlate it with the jump table.
  -mno-apx-features=<value>
                          Disable features of APX
  -mno-bti-at-return-twice
                          Do not add a BTI instruction after a setjmp or other return-twice construct (Arm/AArch64 only)
  -mno-constructor-aliases
                          Disable emitting complete constructors and destructors as aliases when possible
  -mno-crc                Disallow use of CRC instructions (Mips only)
  -mno-cumode             Specify WGP wavefront execution mode (AMDGPU only)
  -mno-daz-ftz            Do not globally set the denormals-are-zero (DAZ) and flush-to-zero (FTZ) bits in the floating-point control register on program startup
  -mno-div32              Do not use div.w[u] and mod.w[u] instructions with input not sign-extended.
  -mno-embedded-data      Do not place constants in the .rodata section instead of the .sdata if they meet the -G <size> threshold (MIPS)        
  -mno-execute-only       Allow generation of data access to code sections (AArch64/ARM only)
  -mno-extern-sdata       Do not assume that externally defined data is in the small data if it meets the -G <size> threshold (MIPS)
  -mno-fix-cmse-cve-2021-35465
                          Don't work around VLLDM erratum CVE-2021-35465 (ARM only)
  -mno-fix-cortex-a53-835769
                          Don't work around Cortex-A53 erratum 835769 (AArch64 only)
  -mno-fix-cortex-a53-843419
                          Don't work around Cortex-A53 erratum 843419 (AArch64 only)
  -mno-fix-cortex-a57-aes-1742098
                          Don't work around Cortex-A57 Erratum 1742098 (ARM only)
  -mno-fix-cortex-a72-aes-1655431
                          Don't work around Cortex-A72 Erratum 1655431 (ARM only)
  -mno-fmv                Disable function multiversioning
  -mno-frecipe            Disable frecipe.{s/d} and frsqrte.{s/d}
  -mno-gather             Disable generation of gather instructions in auto-vectorization(x86 only)
  -mno-global-merge       Disable merging of globals
  -mno-gpopt              Do not use GP relative accesses for symbols known to be in a small data section (MIPS)
  -mno-hvx-ieee-fp        Disable Hexagon HVX IEEE floating-point
  -mno-hvx-qfloat         Disable Hexagon HVX QFloat instructions
  -mno-hvx                Disable Hexagon Vector eXtensions
  -mno-implicit-float     Don't generate implicit floating point or vector instructions
  -mno-incremental-linker-compatible
                          (integrated-as) Emit an object file which cannot be used with an incremental linker
  -mno-lam-bh             Disable amswap[_db].{b/h} and amadd[_db].{b/h}
  -mno-lamcas             Disable amcas[_db].{b/h/w/d}
  -mno-lasx               Disable Loongson Advanced SIMD Extension (LASX).
  -mno-ld-seq-sa          Generate same-address load-load barrier instructions (dbar 0x700)
  -mno-local-sdata        Do not extend the -G behaviour to object local data (MIPS)
  -mno-long-calls         Restore the default behaviour of not generating long calls
  -mno-lsx                Disable Loongson SIMD Extension (LSX).
  -mno-lvi-cfi            Disable control-flow mitigations for Load Value Injection (LVI)
  -mno-lvi-hardening      Disable mitigations for Load Value Injection (LVI)
  -mno-madd4              Disable the generation of 4-operand madd.s, madd.d and related instructions.
  -mno-memops             Disable generation of memop instructions
  -mno-movt               Disallow use of movt/movw pairs (ARM only)
  -mno-ms-bitfields       Do not set the default structure layout to be compatible with the Microsoft compiler standard
  -mno-msa                Disable MSA ASE (MIPS only)
  -mno-mt                 Disable MT ASE (MIPS only)
  -mno-neg-immediates     Disallow converting instructions with negative immediates to their negation or inversion.
  -mno-nvj                Disable generation of new-value jumps
  -mno-nvs                Disable generation of new-value stores
  -mno-outline-atomics    Don't generate local calls to out-of-line atomic operations
  -mno-outline            Disable function outlining (AArch64 only)
  -mno-packets            Disable generation of instruction packets
  -mno-pic-data-is-text-relative
                          Don't assume data segments are relative to text segment
  -mno-regnames           Use only register numbers when writing assembly output
  -mno-relax              Disable linker relaxation
  -mno-restrict-it        Allow generation of complex IT blocks.
  -mno-save-restore       Disable using library calls for save and restore
  -mno-scalar-strict-align
                          Allow scalar memory accesses to be unaligned (RISC-V only)
  -mno-scatter            Disable generation of scatter instructions in auto-vectorization(x86 only)
  -mno-scq                Disable sc.q instruction.
  -mno-seses              Disable speculative execution side effect suppression (SESES)
  -mno-stack-arg-probe    Disable stack probes which are enabled by default
  -mno-strict-align       Allow memory accesses to be unaligned (AArch64/LoongArch/RISC-V only)
  -mno-tgsplit            Disable threadgroup split execution mode (AMDGPU only)
  -mno-tls-direct-seg-refs
                          Disable direct TLS access through segment registers
  -mno-tocdata=<value>    Specifies a list of variables to be exempt from the TOC data transformation.
  -mno-tocdata            This is the default. TOC data transformation is not applied to any variables. Only variables specified explicitly in -mtocdata= will have the TOC data transformation.
  -mno-unaligned-access   Force all memory accesses to be aligned (AArch32/MIPSr6 only)
  -mno-unaligned-symbols  Expect external char-aligned symbols to be without ABI alignment (SystemZ only)
  -mno-v8plus             Disable V8+ mode
  -mno-vector-strict-align
                          Allow vector memory accesses to be unaligned (RISC-V only)
  -mno-wavefrontsize64    Specify wavefront size 32 mode (AMDGPU only)
  -mnocrc                 Disallow use of CRC instructions (ARM only)
  -mnop-mcount            Generate mcount/__fentry__ calls as nops. To activate they need to be patched in.
  -mnvj                   Enable generation of new-value jumps
  -mnvs                   Enable generation of new-value stores
  -module-dependency-dir <value>
                          Directory to dump module dependencies to
  -module-file-info       Provide information about a particular module file
  -momit-leaf-frame-pointer
                          Omit frame pointer setup for leaf functions
  -moutline-atomics       Generate local calls to out-of-line atomic operations
  -moutline               Enable function outlining (AArch64 only)
  -mpacked-stack          Use packed stack layout (SystemZ only).
  -mpackets               Enable generation of instruction packets
  -mpad-max-prefix-size=<value>
                          Specify maximum number of prefixes to use for padding
  -mpic-data-is-text-relative
                          Assume data segments are relative to text segment
  -mprefer-vector-width=<value>
                          Specifies preferred vector width for auto-vectorization. Defaults to 'none' which allows target specific decisions.    
  -mprintf-kind=<value>   Specify the printf lowering scheme (AMDGPU only), allowed values are "hostcall"(printing happens during kernel execution, this scheme relies on hostcalls which require system to support pcie atomics) and "buffered"(printing happens after all kernel threads exit, this uses a printf buffer and does not rely on pcie atomic support)
  -MP                     Create phony target for each dependency (other than main file)
  -mqdsp6-compat          Enable hexagon-qdsp6 backward compatibility
  -MQ <value>             Specify name of main file output to quote in depfile
  -mrecip=<value>         Control use of approximate reciprocal and reciprocal square root instructions followed by <n> iterations of Newton-Raphson refinement. <value> = ( ['!'] ['vec-'] ('rcp'|'sqrt') [('h'|'s'|'d')] [':'<n>] ) | 'all' | 'default' | 'none'
  -mrecip                 Equivalent to '-mrecip=all'
  -mrecord-mcount         Generate a __mcount_loc section entry for each __fentry__ call.
  -mregnames              Use full register names when writing assembly output
  -mrelax-all             (integrated-as) Relax all machine instructions
  -mrelax                 Enable linker relaxation
  -mrestrict-it           Disallow generation of complex IT blocks. It is off by default.
  -mrtd                   Make StdCall calling convention the default
  -mrvv-vector-bits=<value>
                          Specify the size in bits of an RVV vector register
  -msave-reg-params       Save arguments passed by registers to ABI-defined stack positions
  -msave-restore          Enable using library calls for save and restore
  -mscalar-strict-align   Force all scalar memory accesses to be aligned (RISC-V only)
  -mscq                   Enable sc.q instruction.
  -mseses                 Enable speculative execution side effect suppression (SESES). Includes LVI control flow integrity mitigations
  -msign-return-address=<value>
                          Select return address signing scope
  -msimd=<value>          Select the SIMD extension(s) to be enabled in LoongArch either 'none', 'lsx', 'lasx'.
  -mskip-rax-setup        Skip setting up RAX register when passing variable arguments (x86 only)
  -msmall-data-limit=<value>
                          Put global and static data smaller than the limit into a special section
  -msoft-float            Use software floating point
  -msse2avx               Specify that the assembler should encode SSE instructions with VEX prefix
  -mstack-alignment=<value>
                          Set the stack alignment
  -mstack-arg-probe       Enable stack probes
  -mstack-probe-size=<value>
                          Set the stack probe size
  -mstack-protector-guard-offset=<value>
                          Use the given offset for addressing the stack-protector guard
  -mstack-protector-guard-reg=<value>
                          Use the given reg for addressing the stack-protector guard
  -mstack-protector-guard-symbol=<value>
                          Use the given symbol for addressing the stack-protector guard
  -mstack-protector-guard=<value>
                          Use the given guard (global, tls) for addressing the stack-protector guard
  -mstackrealign          Force realign the stack at entry to every function
  -mstrict-align          Force all memory accesses to be aligned (AArch64/LoongArch/RISC-V only)
  -msve-streaming-vector-bits=<value>
                          Specify the size in bits of an SVE vector register in streaming mode. Defaults to the vector length agnostic value of "scalable". (AArch64 only)
  -msve-vector-bits=<value>
                          Specify the size in bits of an SVE vector register. Defaults to the vector length agnostic value of "scalable". (AArch64 only)
  -msvr4-struct-return    Return small structs in registers (PPC32 only)
  -mtargetos=<value>      Set the deployment target to be the specified OS and OS version
  -mtgsplit               Enable threadgroup split execution mode (AMDGPU only)
  -mthread-model <value>  The thread model to use. Defaults to 'posix')
  -mtls-dialect=<value>   Which thread-local storage dialect to use for dynamic accesses of TLS variables
  -mtls-direct-seg-refs   Enable direct TLS access through segment registers (default)
  -mtls-size=<value>      Specify bit size of immediate TLS offsets (AArch64 ELF only): 12 (for 4KB) | 24 (for 16MB, default) | 32 (for 4GB) | 48 (for 256TB, needs -mcmodel=large)
  -mtocdata=<value>       Specifies a list of variables to which the TOC data transformation will be applied.
  -mtocdata               All suitable variables will have the TOC data transformation applied
  -mtp=<value>            Thread pointer access method. For AArch32: 'soft' uses a function call, or 'tpidrurw', 'tpidruro' or 'tpidrprw' use the three CP15 registers. 'cp15' is an alias for 'tpidruro'. For AArch64: 'tpidr_el0', 'tpidr_el1', 'tpidr_el2', 'tpidr_el3' or 'tpidrro_el0' use the five system registers. 'elN' is an alias for 'tpidr_elN'.
  -mtune=<value>          Only supported on AArch64, PowerPC, RISC-V, SPARC, SystemZ, and X86
  -MT <value>             Specify name of main file output in depfile
  -multi-lib-config=<file>
                          Path to the YAML configuration file to be used for multilib selection
  -munaligned-access      Allow memory accesses to be unaligned (AArch32/MIPSr6 only)
  -munaligned-symbols     Expect external char-aligned symbols to be without ABI alignment (SystemZ only)
  -mv8plus                Enable V8+ mode, allowing use of 64-bit V9 instructions in 32-bit code
  -mvector-strict-align   Force all vector memory accesses to be aligned (RISC-V only)
  -mvevpu                 Emit VPU instructions for VE
  -MV                     Use NMake/Jom format for the depfile
  -mwavefrontsize64       Specify wavefront size 64 mode (AMDGPU only)
  -mxcoff-build-id=<0xHEXSTRING>
                          On AIX, request creation of a build-id string, "0xHEXSTRING", in the string table of the loader section inside the linked binary
  -mxcoff-roptr           Place constant objects with relocatable address values in the RO data section and add -bforceimprw to the linker flags (AIX only)
  -mzos-hlq-clang=<ClangHLQ>
                          High level qualifier for z/OS C++RT side deck datasets
  -mzos-hlq-csslib=<CsslibHLQ>
                          High level qualifier for z/OS CSSLIB dataset
  -mzos-hlq-le=<LeHLQ>    High level qualifier for z/OS Language Environment datasets
  -mzos-sys-include=<SysInclude>
                          Path to system headers on z/OS
  -mzos-target=<value>    Set the z/OS release of the runtime environment
  -M                      Like -MD, but also implies -E and writes to stdout by default
  --no-cuda-include-ptx=<value>
                          Do not include PTX for the following GPU architecture (e.g. sm_35) or 'all'. May be specified more than once.
  --no-cuda-version-check Don't error out if the detected version of the CUDA install is too low for the requested CUDA gpu architecture.        
  --no-default-config     Disable loading default configuration files
  --no-gpu-bundle-output  Do not bundle output files of HIP device compilation
  -no-hip-rt              Do not link against HIP runtime libraries
  --no-offload-arch=<value>
                          Remove CUDA/HIP offloading device architecture (e.g. sm_35, gfx906) from the list of devices to compile for. 'all' resets the list to its default value.
  --no-offload-inc        Do not add include paths for CUDA/HIP and include the default CUDA/HIP wrapper headers
  --no-offload-new-driver Don't Use the new driver for offloading compilation.
  --no-offloadlib         Do not link device library for CUDA/HIP device compilation
  --no-system-header-prefix=<prefix>
                          Treat all #include paths starting with <prefix> as not including a system header.
  --no-wasm-opt           Disable the wasm-opt optimizer
  -nobuiltininc           Disable builtin #include directories only
  -nohipwrapperinc        Do not include the default HIP wrapper headers and include paths
  -nostdinc++             Disable standard #include directories for the C++ standard library
  -nostdinc               Disable both standard system #include directories and builtin #include directories
  -nostdlibinc            Disable standard system #include directories only
  -ObjC++                 Treat source input files as Objective-C++ inputs
  -ObjC                   Treat source input files as Objective-C inputs
  -object-file-name=<file>
                          Set the output <file> for debug infos
  -Ofast<value>           Deprecated; use '-O3 -ffast-math' for the same behavior, or '-O3' to enable only conforming optimizations
  --offload-arch-tool=<value>
                          Tool used for detecting offloading architectures in the system.
  --offload-arch=<value>  Specify an offloading device architecture for CUDA, HIP, or OpenMP. (e.g. sm_35). If 'native' is used the compiler will detect locally installed architectures. For HIP offloading, the device architecture can be followed by target ID features delimited by a colon (e.g. gfx908:xnack+:sramecc-). May be specified more than once.
  --offload-compress      Compress offload device binaries (HIP only)
  --offload-device-only   Only compile for the offloading device.
  --offload-host-device   Compile for both the offloading host and device (default).
  --offload-host-only     Only compile for the offloading host.
  --offload-inc           Add include paths for CUDA/HIP and include the default CUDA/HIP wrapper headers (default)
  --offload-jobs=<value>  Specify the number of threads to use for device offloading tasks during compilation.
  --offload-link          Use the new offloading linker to perform the link job.
  --offload-new-driver    Use the new driver for offloading compilation.
  --offload-targets=<value>
                          Specify a list of target architectures to use for offloading.
  --offload=<value>       Specify comma-separated list of offloading target triples (CUDA and HIP only)
  --offloadlib            Link device libraries for GPU device compilation
  -o <file>               Write output to <file>
  -pedantic               Warn on language extensions
  -pg                     Enable mcount instrumentation
  -pipe                   Use pipes between commands, when possible
  --precompile            Only precompile the input
  --pretty-sgf            Emit pretty printed symbol graphs
  -print-diagnostic-options
                          Print all of Clang's warning options
  -print-effective-triple Print the effective target triple
  -print-enabled-extensions
                          Print the extensions enabled by the given target and -march/-mcpu options. (AArch64 and RISC-V only)
  -print-file-name=<file> Print the full library path of <file>
  -print-ivar-layout      Enable Objective-C Ivar layout bitmap print trace
  -print-libgcc-file-name Print the library path for the currently used compiler runtime library ("libgcc.a" or "libclang_rt.builtins.*.a")      
  -print-library-module-manifest-path
                          Print the path for the C++ Standard library module manifest
  -print-multi-flags-experimental
                          Print the flags used for selecting multilibs (experimental)
  -print-prog-name=<name> Print the full program path of <name>
  -print-resource-dir     Print the resource directory pathname
  -print-rocm-search-dirs Print the paths used for finding ROCm installation
  -print-runtime-dir      Print the directory pathname containing Clang's runtime libraries
  -print-search-dirs      Print the paths used for finding libraries and programs
  -print-supported-cpus   Print supported cpu models for the given target (if target is not specified,it will print the supported cpus for the default target)
  -print-supported-extensions
                          Print supported -march extensions (RISC-V, AArch64 and ARM only)
  -print-target-triple    Print the normalized target triple
  -print-targets          Print the registered targets
  -pthread                Support POSIX threads in generated code
  --ptxas-path=<value>    Path to ptxas (used for compiling CUDA code)
  -P                      Disable linemarker output in -E mode
  -p                      Enable mcount instrumentation with prof
  -Qn                     Do not emit metadata containing compiler name and version
  -Qunused-arguments      Don't emit warning for unused driver arguments
  -Qy                     Emit metadata containing compiler name and version
  -regcall4               Set __regcall4 as a default calling convention to respect __regcall ABI v.4
  -relocatable-pch        Whether to build a relocatable precompiled header
  -rewrite-legacy-objc    Rewrite Legacy Objective-C source to C++
  -rewrite-objc           Rewrite Objective-C source to C++
  --rocm-device-lib-path=<value>
                          ROCm device library path. Alternative to rocm-path.
  --rocm-path=<value>     ROCm installation path, used for finding and automatically linking required bitcode libraries.
  -Rpass-analysis=<value> Report transformation analysis from optimization passes whose name matches the given POSIX regular expression
  -Rpass-missed=<value>   Report missed transformations by optimization passes whose name matches the given POSIX regular expression
  -Rpass=<value>          Report transformations performed by optimization passes whose name matches the given POSIX regular expression
  -rtlib=<value>          Compiler runtime library to use
  -R<remark>              Enable the specified remark
  -save-stats=<value>     Save llvm statistics.
  -save-stats             Save llvm statistics.
  -save-temps=<value>     Save intermediate compilation results. <arg> can be set to 'cwd' for current working directory, or 'obj' which will save temporary files in the same directory as the final output file
  -save-temps             Alias for --save-temps=cwd
  -serialize-diagnostics <value>
                          Serialize compiler diagnostics to a file
  -shared-libsan          Dynamically link the sanitizer runtime
  --start-no-unused-arguments
                          Don't emit warnings about unused arguments for the following arguments
  -static-libclosure      Generate code for statically linking libclosure (BlocksRuntime)
  -static-libsan          Statically link the sanitizer runtime (Not supported for ASan, TSan or UBSan on darwin)
  -static-openmp          Use the static host OpenMP runtime while linking.
  -std=<value>            Language standard to compile for
  -stdlib++-isystem <directory>
                          Use directory as the C++ standard library include path
  -stdlib=<value>         C++ standard library to use
  -sycl-std=<value>       SYCL language standard to compile for.
  --symbol-graph-dir=<value>
                          Directory in which to emit symbol graphs.
  --system-header-prefix=<prefix>
                          Treat all #include paths starting with <prefix> as including a system header.
  -S                      Only run preprocess and compilation steps
  --target=<value>        Generate code for the given target
  -time                   Time individual commands
  -traditional-cpp        Enable some traditional CPP emulation
  -trigraphs              Process trigraph sequences
  -T <script>             Specify <script> as linker script
  -undef                  undef all system defines
  -unwindlib=<value>      Unwind library to use
  -U <macro>              Undefine macro <macro>
  --verify-debug-info     Verify the binary representation of debug output
  -verify-pch             Load and verify that a pre-compiled header file is not stale
  --version               Print version information
  -vfsoverlay <value>     Overlay the virtual filesystem described by file over the real file system. Additionally, pass this overlay file to the linker if it supports it
  -v                      Show commands to run and use verbose output
  -Wa,<arg>               Pass the comma separated arguments in <arg> to the assembler
  --warning-suppression-mappings=<value>
                          File containing diagnostic suppression mappings. See user manual for file format.
  --wasm-opt              Enable the wasm-opt optimizer (default)
  -Wl,<arg>               Pass the comma separated arguments in <arg> to the linker
  -working-directory <value>
                          Resolve file paths relative to the specified directory
  -Wp,<arg>               Pass the comma separated arguments in <arg> to the preprocessor
  -W<warning>             Enable the specified warning
  -w                      Suppress all warnings
  -Xanalyzer <arg>        Pass <arg> to the static analyzer
  -Xarch_device <arg>     Pass <arg> to the CUDA/HIP device compilation
  -Xarch_host <arg>       Pass <arg> to the CUDA/HIP host compilation
  -Xarch_<arch> <arg>     Pass <arg> to the compilation if the target matches <arch>
  -Xassembler <arg>       Pass <arg> to the assembler
  -Xclang=<arg>           Alias for -Xclang
  -Xclangas=<arg>         Alias for -Xclangas
  -Xclangas <arg>         Pass <arg> to clang -cc1as
  -Xclang <arg>           Pass <arg> to clang -cc1
  -Xcuda-fatbinary <arg>  Pass <arg> to fatbinary invocation
  -Xcuda-ptxas <arg>      Pass <arg> to the ptxas assembler
  -Xlinker <arg>          Pass <arg> to the linker
  -Xoffload-linker<triple> <arg>
                          Pass <arg> to the offload linkers or the ones identified by -<triple>
  -Xopenmp-target=<triple> <arg>
                          Pass <arg> to the target offloading toolchain identified by <triple>.
  -Xopenmp-target <arg>   Pass <arg> to the target offloading toolchain.
  -Xpreprocessor <arg>    Pass <arg> to the preprocessor
  -Xthinlto-distributor=<arg>
                          Pass <arg> to the ThinLTO distributor process. Can be specified multiple times or with comma-separated values.
  -x <language>           Treat subsequent input files as having type <language>
  -z <arg>                Pass -z <arg> to the linker

dxc compatibility options.:
  --dxv-path=<value>      DXIL validator installation path
  -fdx-rootsignature-version=<value>
                          Root Signature Version
  -fspv-extension=<value> Specify the available SPIR-V extensions. If this option is not specified, then all extensions are available.
  -fspv-target-env=<value>
                          Specify the target environment
  -hlsl-entry <value>     Entry point name for hlsl

E:\projects\vscode\bitTeszt>
```

`cl.exe /?`

```
E:\projects\vscode\bitTeszt>cl.exe /?
Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35221 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

                         C/C++ COMPILER OPTIONS


                              -OPTIMIZATION-

/O1 maximum optimizations (favor space) /O2 maximum optimizations (favor speed)
/Ob<n> inline expansion (default n=0)   /Od disable optimizations (default)
/Og enable global optimization          /Oi[-] enable intrinsic functions
/Os favor code space                    /Ot favor code speed
(press <return> to continue)
/Ox optimizations (favor speed)
/favor:<blend|AMD64|INTEL64|ATOM> select processor to optimize for, one of:
    blend - a combination of optimizations for several different x64 processors
    AMD64 - 64-bit AMD processors
    INTEL64 - Intel(R)64 architecture processors
    ATOM - Intel(R) Atom(TM) processors

                             -CODE GENERATION-

/Gu[-] ensure distinct functions have distinct addresses
/Gw[-] separate global variables for linker
/GF enable read-only string pooling     /Gy[-] separate functions for linker
(press <return> to continue)
/GS[-] enable security checks           /GR[-] enable C++ RTTI
/guard:cf[-] enable CFG (control flow guard)
/guard:ehcont[-] enable EH continuation metadata (CET)
/EHs enable C++ EH (no SEH exceptions)  /EHa enable C++ EH (w/ SEH exceptions)
/EHc extern "C" defaults to nothrow
/EHr always generate noexcept runtime termination checks
/fp:<contract|except[-]|fast|precise|strict> choose floating-point model:
    contract - consider floating-point contractions when generating code
    except[-] - consider floating-point exceptions when generating code
    fast - "fast" floating-point model; results are less predictable
    precise - "precise" floating-point model; results are predictable
    strict - "strict" floating-point model (implies /fp:except)
(press <return> to continue)
/Qfast_transcendentals generate inline FP intrinsics even with /fp:except
/Qspectre[-] enable mitigations for CVE 2017-5753
/Qpar[-] enable parallel code generation
/Qpar-report:1 auto-parallelizer diagnostic; indicate parallelized loops
/Qpar-report:2 auto-parallelizer diagnostic; indicate loops not parallelized
/Qvec-report:1 auto-vectorizer diagnostic; indicate vectorized loops
/Qvec-report:2 auto-vectorizer diagnostic; indicate loops not vectorized
/GL[-] enable link-time code generation
/volatile:<iso|ms> choose volatile model:
    iso - Acquire/release semantics not guaranteed on volatile accesses
    ms  - Acquire/release semantics guaranteed on volatile accesses
/GA optimize for Windows Application    /Ge force stack checking for all funcs
(press <return> to continue)
/Gs[num] control stack checking calls   /Gh enable _penter function call
/GH enable _pexit function call         /GT generate fiber-safe TLS accesses
/RTC1 Enable fast checks (/RTCsu)       /RTCc Convert to smaller type checks
/RTCs Stack Frame runtime checking      /RTCu Uninitialized local usage checks
/clr[:option] compile for common language runtime, where option is:
    pure : produce IL-only output file (no native executable code)
    safe : produce IL-only verifiable output file
    netcore : produce assemblies targeting .NET Core runtime
    noAssembly : do not produce an assembly
    nostdlib : ignore the system .NET framework directory when searching for assemblies
    nostdimport : do not import any required assemblies implicitly
    initialAppDomain : enable initial AppDomain behavior of Visual C++ 2002
(press <return> to continue)
    implicitKeepAlive- : turn off implicit emission of System::GC::KeepAlive(this)
    char_t- : turn off metadata support for char8_t, char16_t and char32_t
    ECMAParamArray : use rules specified in ECMA-372/14.6 for overloads with parameter arrays (implied by /clr)
    ECMAParamArray- : use new rules for overloads with parameter arrays (implied by /clr:netcore)
/fsanitize=address Enable address sanitizer codegen
/homeparams Force parameters passed in registers to be written to the stack
/GZ Enable stack checks (/RTCs)         /Gv __vectorcall calling convention
(Preview) /dynamicdeopt Enable dynamic debugging; place deoptimized breakpoints and step in anywhere with on-demand function deoptimization
(Preview) /dynamicdeopt:suffix <suffix> File extension suffix for deoptimized output (default: .alt)
(Preview) /dynamicdeopt:sync Build deoptimized output after optimized output instead of in parallel
/arch:<SSE2|SSE4.2|AVX|AVX2|AVX512|AVX10.x> minimum CPU architecture requirements, one of:
   SSE2 - (default) enable use of instructions available with SSE2-enabled CPUs
(press <return> to continue)
   SSE4.2 - enable use of instructions available with SSE 4.2-enabled CPUs
   AVX - enable use of instructions available with AVX-enabled CPUs
   AVX2 - enable use of instructions available with AVX2-enabled CPUs
   AVX512 - enable use of instructions available with AVX-512-enabled CPUs
   AVX10.x - enable use of instructions available with AVX10.x-enabled CPUs. Valid values of x are 1
/QIntel-jcc-erratum enable mitigations for Intel JCC erratum
/Qspectre-load Enable spectre mitigations for all instructions which load memory
/Qspectre-load-cf Enable spectre mitigations for all control-flow instructions which load memory
/Qspectre-jmp[-] Enable spectre mitigations for unconditional jump instructions
/fpcvt:<IA|BC> FP to unsigned integer conversion compatibility
   IA - results compatible with VCVTTSD2USI instruction
   BC - results compatible with VS2017 and earlier compiler
(press <return> to continue)
/jumptablerdata Place jump tables for switch case statements in .rdata section
/vlen=<256|512> Choose vector length of either 256 or 512 for automatic code-generation
/vlen Choose default vector length based on /arch setting

                              -OUTPUT FILES-

/Fa[file] name assembly listing file    /FA[scu] configure assembly listing
/Fd[file] name .PDB file                /Fe<file> name executable file
/Fm[file] name map file                 /Fo<file> name object file
/Fp<file> name precompiled header file  /Fr[file] name source browser file
/FR[file] name extended .SBR file       /Fi[file] name preprocessed file
/Fd: <file> name .PDB file              /Fe: <file> name executable file
(press <return> to continue)
/Fm: <file> name map file               /Fo: <file> name object file
/Fp: <file> name .PCH file              /FR: <file> name extended .SBR file
/Fi: <file> name preprocessed file
/Ft<dir> location of the header files generated for #import
/doc[file] process XML documentation comments and optionally name the .xdc file

                              -PREPROCESSOR-

/AI<dir> add to assembly search path    /FU<file> import .NET assembly/module
/FU:asFriend<file> import .NET assembly/module as friend
/C don't strip comments                 /D<name>{=|#}<text> define macro
/E preprocess to stdout                 /EP preprocess to stdout, no #line
(press <return> to continue)
/P preprocess to file                   /Fx merge injected code to file
/FI<file> name forced include file      /U<name> remove predefined macro
/u remove all predefined macros         /I<dir> add to include search path
/X ignore "standard places"
/PH generate #pragma file_hash when preprocessing
/PD print all macro definitions

                                -LANGUAGE-

/std:<c++14|c++17|c++20|c++latest> C++ standard version
    c++14 - ISO/IEC 14882:2014 (default)
    c++17 - ISO/IEC 14882:2017
(press <return> to continue)
    c++20 - ISO/IEC 14882:2020
    c++latest - latest draft standard (feature set subject to change)
/std:<c11|c17|clatest> C standard version
    c11 - ISO/IEC 9899:2011
    c17 - ISO/IEC 9899:2018
    clatest - latest draft standard (feature set subject to change)
/permissive[-] enable some nonconforming code to compile
               (feature set subject to change) (off by default in C++20 and later)
/Za disable extensions (not recommended for C++)
/ZW enable WinRT language extensions    /Zs syntax check only
/await enable resumable functions extension
/await:strict enable standard C++20 coroutine support with earlier language versions
(press <return> to continue)
/constexpr:depth<N>     recursion depth limit for constexpr evaluation (default: 512)
/constexpr:backtrace<N> show N constexpr evaluations in diagnostics (default: 10)
/constexpr:steps<N>     terminate constexpr evaluation after N steps (default: 1048576)
/Zi enable debugging information        /Z7 enable old-style debug info
/Zo[-] generate richer debugging information for optimized code (on by default)
/ZH:[MD5|SHA1|SHA_256] hash algorithm for calculation of file checksum in debug info (default: SHA_256)
/Zp[n] pack structs on n-byte boundary  /Zl omit default library name in .OBJ
/vd{0|1|2} disable/enable vtordisp      /vm<x> type of pointers to members
/Zc:arg1[,arg2] language conformance, where arguments can be:
  forScope[-]           enforce Standard C++ for scoping rules
  wchar_t[-]            wchar_t is the native type, not a typedef
  auto[-]               enforce the new Standard C++ meaning for auto
(press <return> to continue)
  trigraphs[-]          enable trigraphs (off by default)
  rvalueCast[-]         enforce Standard C++ explicit type conversion rules
                        (on by default in C++20 or later, implied by /permissive-)
  strictStrings[-]      disable string-literal to [char|wchar_t]*
                        conversion (on by default in C++20 or later, implied by /permissive-)
  implicitNoexcept[-]   enable implicit noexcept on required functions
  threadSafeInit[-]     enable thread-safe local static initialization
  inline[-]             remove unreferenced function or data if it is
                        COMDAT or has internal linkage only (off by default)
  sizedDealloc[-]       enable C++14 global sized deallocation
                        functions (on by default)
  throwingNew[-]        assume operator new throws on failure (off by default)
(press <return> to continue)
  referenceBinding[-]   a temporary will not bind to a non-const
                        lvalue reference (on by default in C++20 or later, implied by /permissive-)
  twoPhase-             disable two-phase name lookup
  ternary[-]            enforce C++11 rules for conditional operator
                        (on by default in C++20 or later, implied by /permissive-)
  noexceptTypes[-]      enforce C++17 noexcept rules (on by default in C++17 or later)
  alignedNew[-]         enable C++17 alignment of dynamically allocated objects (on by default)
  hiddenFriend[-]       enforce Standard C++ hidden friend rules
                        (on by default in C++20 or later, implied by /permissive-)
  externC[-]            enforce Standard C++ rules for 'extern "C"' functions
                        (on by default in C++20 or later, implied by /permissive-)
  lambda[-]             better lambda support by using the newer lambda processor
(press <return> to continue)
                        (on by default in C++20 or later, implied by /permissive-)
  tlsGuards[-]          generate runtime checks for TLS variable initialization (on by default)
  zeroSizeArrayNew[-]   call member new/delete for 0-size arrays of objects (on by default)
  static_assert[-]      strict handling of 'static_assert' (on by default in C++20 or later,
                        implied by /permissive-)
  gotoScope[-]          cannot jump past the initialization of a variable (implied by /permissive-)
  templateScope[-]      enforce Standard C++ template parameter shadowing rules
  enumTypes[-]          enable Standard C++ underlying enum types (off by default)
  checkGwOdr[-]         enforce Standard C++ one definition rule violations
                        when /Gw has been enabled (off by default)
  nrvo[-]               enable optional copy and move elision (on by default in C++20 or later,
                        implied by /permissive- or /O2)
(press <return> to continue)
  __STDC__              define __STDC__ to 1 in C
  __cplusplus[-]        __cplusplus macro reports the supported C++ standard (off by default)
  char8_t[-]            enable C++20 native `u8` literal support as `const char8_t`
                        (on by default in C++20 or later)
  externConstexpr[-]    enable external linkage for constexpr variables in C++
                        (on by default in C++20 or later, implied by /permissive-)
  preprocessor[-]       enable standard conforming preprocessor in C/C++
                        (on by default in C11 or later)
/ZI enable Edit and Continue debug info
/openmp enable OpenMP 2.0 language extensions
/openmp:experimental enable OpenMP 2.0 language extensions plus select OpenMP 3.0+ language extensions
/openmp:llvm OpenMP language extensions using LLVM runtime
(press <return> to continue)

                              -MISCELLANEOUS-

@<file> options response file           /?, /help print this help message
/bigobj generate extended object format /c compile only, no link
/FC use full pathnames in diagnostics   /H<num> max external name length
/J default char type is unsigned
/MP[n] use up to 'n' processes for compilation
/nologo suppress copyright message      /showIncludes show include file names
/Tc<source file> compile file as .c     /Tp<source file> compile file as .cpp
/TC compile all files as .c             /TP compile all files as .cpp
/V<string> set version string           /Yc[file] create .PCH file
(press <return> to continue)
/Yd put debug info in every .OBJ        /Yl[sym] inject .PCH ref for debug lib
/Yu[file] use .PCH file                 /Y- disable all PCH options
/Zm<n> max memory alloc (% of default)  /FS force to use MSPDBSRV.EXE
/source-charset:<iana-name>|.nnnn set source character set
/execution-charset:<iana-name>|.nnnn set execution character set
/utf-8 set source and execution character set to UTF-8
/validate-charset[-] validate UTF-8 files for only legal characters
/fastfail[-] enable fast-fail mode      /JMC[-] enable native just my code
/presetPadding[-] zero initialize padding for stack based class types
/volatileMetadata[-] generate metadata on volatile memory accesses
/sourcelink [file] file containing source link information

(press <return> to continue)
                                -LINKING-

/LD Create .DLL                         /LDd Create .DLL debug library
/LN Create a .netmodule                 /F<num> set stack size
/link [linker options and libraries]    /MD link with MSVCRT.LIB
/MT link with LIBCMT.LIB                /MDd link with MSVCRTD.LIB debug lib
/MTd link with LIBCMTD.LIB debug lib

                              -CODE ANALYSIS-

/analyze[-] Enable native analysis      /analyze:quiet[-] No warning to console
/analyze:log<name> Warnings to file     /analyze:autolog Log to *.pftlog
(press <return> to continue)
/analyze:autolog:ext<ext> Log to *.<ext>/analyze:autolog- No log file
/analyze:WX- Warnings not fatal         /analyze:stacksize<num> Max stack frame
/analyze:max_paths<num> Max paths       /analyze:only Analyze, no code gen

                              -DIAGNOSTICS-

/diagnostics:<args,...> controls the format of diagnostic messages:
             classic   - retains prior format
             column[-] - prints column information
             caret[-]  - prints column and the indicated line of source
/Wall enable all warnings               /w   disable all warnings
/W<n> set warning level (default n=1)
(press <return> to continue)
/Wv:xx[.yy[.zzzzz]] disable warnings introduced after version xx.yy.zzzzz
/WX treat warnings as errors            /WL enable one line diagnostics
/wd<n> disable warning n                /we<n> treat warning n as an error
/wo<n> issue warning n once             /w<l><n> set warning level 1-4 for n
/external:I <path>      - location of external headers
/external:env:<var>     - environment variable with locations of external headers
/external:anglebrackets - treat all headers included via <> as external
/external:W<n>          - warning level for external headers
/external:templates[-]  - evaluate warning level across template instantiation chain
/sdl enable additional security features and warnings
/options:strict unrecognized compiler options are an error

(press <return> to continue)
```

**Beállítások VS-Codehoz:**

c_cpp_properties.json

```
{
  "configurations": [
    {
      "name": "MinGW (g++)",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "compilerPath": "C:/mingw64/bin/g++.exe",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "windows-gcc-x64"
    },
    {
      "name": "MSVC",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "compilerPath": "F:/intelij/vsCommunity/VC/Tools/MSVC/14.44.35207/bin/HostX64/x64/cl.exe",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "windows-msvc-x64"
    },
    {
      "name": "Clang++",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "compilerPath": "C:/Program Files/LLVM/bin/clang++.exe",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "windows-clang-x64"
    },
    {
      "name": "Clang",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "compilerPath": "C:/Program Files/LLVM/bin/clang.exe",
      "cStandard": "c17",
      "cppStandard": "c17",
      "intelliSenseMode": "windows-clang-x64"
    }
  ],
  "version": 4
}
```

launch.json

```
{
    "version": "0.2.0",
    "inputs": [
        {
            "id": "javaMainClass",
            "type": "promptString",
            "description": "Java main class name",
            "default": "HelloWorld"
        },
        {
            "id": "kotlinMainClass",
            "type": "promptString",
            "description": "Kotlin main class name",
            "default": "HelloKt"
        }
    ],
    "configurations": [
        {
            "name": "C: gcc 64-bit debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_c64_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc 64-bit (debug static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C++: g++ 64-bit debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_cpp64_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ 64-bit (debug static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C: gcc 64-bit release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_c64_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc 64-bit (release static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C++: g++ 64-bit release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_cpp64_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ 64-bit (release static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C: gcc 32-bit debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_c32_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc 32-bit (debug static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C: gcc 32-bit release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_c32_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc 32-bit (release static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C++: g++ 32-bit debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_cpp32_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ 32-bit (debug static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C++: g++ 32-bit release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_cpp32_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ 32-bit (release static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: g++ debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (debug dynamic)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: g++ release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (release dynamic)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: g++ debug DLL",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (create DLL debug)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: g++ release DLL",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (create DLL release)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: MSVC 64-bit debug (static)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc64_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC 64-bit release (static)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc64_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC 32-bit debug (static)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc32_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC 32-bit release (static)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc32_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC debug (dynamic)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC release (dynamic)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC debug DLL",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: MSVC release DLL",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_msvc_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "C/C++: clang++ debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (debug static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang++ release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (release static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang++ debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (debug dynamic)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang++ release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (release dynamic)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang++ debug DLL",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (create DLL debug)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang++ release DLL",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (create DLL release)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (debug static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (release static)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (debug dynamic)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (release dynamic)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang debug DLL",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_dynamic_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (create DLL debug)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "C/C++: clang release DLL",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_dynamic_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (create DLL release)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Java: compile and run (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:javaMainClass}",
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole"
        },
        {
            "name": "Java: compile and run (release)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:javaMainClass}",
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "Java: run JAR (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/java_debug.jar"
            ],
            "preLaunchTask": "create Java JAR (debug)"
        },
        {
            "name": "Java: run JAR (release)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/java_release.jar"
            ],
            "preLaunchTask": "create Java JAR (release)"
        },
        {
            "name": "Kotlin: compile and run (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:kotlinMainClass}",
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole",
            "args": []
        },
        {
            "name": "Kotlin: compile and run (release)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:kotlinMainClass}",
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal",
            "args": []
        },
        {
            "name": "Kotlin: run JAR (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/kotlin_debug.jar"
            ],
            "preLaunchTask": "create Kotlin JAR (debug)"
        },
        {
            "name": "Kotlin: run JAR (release)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "bitTeszt",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/kotlin_release.jar"
            ],
            "preLaunchTask": "create Kotlin JAR (release)"
        },
        {
            "name": "Assembly NASM: run (debug)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/asm_output.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link with linker (debug)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Assembly NASM: run (release)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/asm_output.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link with linker (release)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Assembly MASM 32-bit: run (debug)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/masm32_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link MASM 32-bit (debug)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Assembly MASM 32-bit: run (release)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/masm32_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link MASM 32-bit (release)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Assembly MASM 64-bit: run (debug)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/masm64_debug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link MASM 64-bit (debug)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Assembly MASM 64-bit: run (release)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/masm64_release.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link MASM 64-bit (release)",
            "miDebuggerPath": "C:/coding/mingw64/bin/gdb.exe"
        },
        {
            "name": "Python: run script",
            "type": "python",
            "request": "launch",
            "program": "${workspaceFolder}/hello.py",
            "console": "integratedTerminal",
            "cwd": "${workspaceFolder}"
        }
    ]
}
```

settings.json

```
{
  "C_Cpp.clang_format_style": "file",
  "C_Cpp.codeAnalysis.runAutomatically": true,
  "C_Cpp.codeAnalysis.exclude": [],
  "C_Cpp.codeAnalysis.clangTidy.enabled": true,
  "C_Cpp.codeAnalysis.clangTidy.path": "C:/Program Files/LLVM/bin/clang-tidy.exe",
  "C_Cpp.codeAnalysis.clangTidy.checks": [
    "*",
    "-modernize-use-trailing-return-type"
  ],
  "C_Cpp.default.compilerPath": "C:/mingw64/bin/g++.exe",
  "C_Cpp.default.cppStandard": "c++17",
  "C_Cpp.default.cStandard": "c17",
  "C_Cpp.default.intelliSenseMode": "windows-gcc-x64",
  "editor.formatOnSave": true,
  "C_Cpp.formatting": "clangFormat"
}
```

tasks.json

```
{
     "version": "2.0.0",
     "tasks": [
        {
            "label": "compile with gcc 64-bit (debug static)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_c64_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc 64-bit (release static)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-O2",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_c64_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ 64-bit (debug static)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gcc_cpp64_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ 64-bit (release static)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-O2",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gcc_cpp64_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc 32-bit (debug static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\gcc.exe",
            "args": [
                "-g",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_c32_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc 32-bit (release static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\gcc.exe",
            "args": [
                "-O2",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_c32_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ 32-bit (debug static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\g++.exe",
            "args": [
                "-g",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gcc_cpp32_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ 32-bit (release static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\g++.exe",
            "args": [
                "-O2",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gcc_cpp32_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
                 "label": "compile with gcc 64-bit (debug dynamic)",
                 "type": "shell",
                 "command": "gcc",
                 "args": [
                     "-g",
                     "${workspaceFolder}/*.c",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_c64_dynamic_debug.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with gcc 64-bit (release dynamic)",
                 "type": "shell",
                 "command": "gcc",
                 "args": [
                     "-O2",
                     "${workspaceFolder}/*.c",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_c64_dynamic_release.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with g++ 64-bit (debug dynamic)",
                 "type": "shell",
                 "command": "g++",
                 "args": [
                     "-g",
                     "${workspaceFolder}/*.cpp",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_cpp64_dynamic_debug.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with g++ 64-bit (release dynamic)",
                 "type": "shell",
                 "command": "g++",
                 "args": [
                     "-O2",
                     "${workspaceFolder}/*.cpp",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_cpp64_dynamic_release.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with gcc 32-bit (debug dynamic)",
                 "type": "shell",
                 "command": "F:\\intelij\\mingw32\\bin\\gcc.exe",
                 "args": [
                     "-g",
                     "-m32",
                     "${workspaceFolder}/*.c",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_c32_dynamic_debug.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with gcc 32-bit (release dynamic)",
                 "type": "shell",
                 "command": "F:\\intelij\\mingw32\\bin\\gcc.exe",
                 "args": [
                     "-O2",
                     "-m32",
                     "${workspaceFolder}/*.c",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_c32_dynamic_release.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with g++ 32-bit (debug dynamic)",
                 "type": "shell",
                 "command": "F:\\intelij\\mingw32\\bin\\g++.exe",
                 "args": [
                     "-g",
                     "-m32",
                     "${workspaceFolder}/*.cpp",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_cpp32_dynamic_debug.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
                 "label": "compile with g++ 32-bit (release dynamic)",
                 "type": "shell",
                 "command": "F:\\intelij\\mingw32\\bin\\g++.exe",
                 "args": [
                     "-O2",
                     "-m32",
                     "${workspaceFolder}/*.cpp",
                     "-L.",
                     "-lmylib",
                     "-o",
                     "${workspaceFolder}/main_gcc_cpp32_dynamic_release.exe"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$gcc"
                 ]
             },
        {
            "label": "compile with gcc (create DLL debug)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.c",
                "-o",
                "${workspaceFolder}/mylib_c_debug.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_c_debug.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc (create DLL release)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-O2",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.c",
                "-o",
                "${workspaceFolder}/mylib_c_release.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_c_release.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (create DLL debug)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.cpp",
                "-o",
                "${workspaceFolder}/mylib_cpp_debug.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_cpp_debug.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (create DLL release)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-O2",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.cpp",
                "-o",
                "${workspaceFolder}/mylib_cpp_release.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_cpp_release.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc 32-bit (create DLL debug)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\gcc.exe",
            "args": [
                "-g",
                "-m32",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.c",
                "-o",
                "${workspaceFolder}/mylib_c32_debug.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_c32_debug.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc 32-bit (create DLL release)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\gcc.exe",
            "args": [
                "-O2",
                "-m32",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.c",
                "-o",
                "${workspaceFolder}/mylib_c32_release.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_c32_release.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ 32-bit (create DLL debug)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\g++.exe",
            "args": [
                "-g",
                "-m32",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.cpp",
                "-o",
                "${workspaceFolder}/mylib_cpp32_debug.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_cpp32_debug.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ 32-bit (create DLL release)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\g++.exe",
            "args": [
                "-O2",
                "-m32",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.cpp",
                "-o",
                "${workspaceFolder}/mylib_cpp32_release.dll",
                "-Wl,--out-implib,${workspaceFolder}/libmylib_cpp32_release.a"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with MSVC 64-bit (debug static)",
            "type": "shell",
            "command": "F:\\intelij\\vsCommunity\\VC\\Tools\\MSVC\\14.44.35207\\bin\\HostX64\\x64\\cl.exe",
            "args": [
                "/EHsc",
                "/MT",
                "/nologo",
                "/Zi",
                "/Fe:",
                "${workspaceFolder}/main_msvc64_debug.exe",
                "${workspaceFolder}/*.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$msCompile"
            ]
        },
        {
            "label": "compile with MSVC 64-bit (release static)",
            "type": "shell",
            "command": "F:\\intelij\\vsCommunity\\VC\\Tools\\MSVC\\14.44.35207\\bin\\HostX64\\x64\\cl.exe",
            "args": [
                "/EHsc",
                "/MT",
                "/nologo",
                "/O2",
                "/Fe:",
                "${workspaceFolder}/main_msvc64_release.exe",
                "${workspaceFolder}/*.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$msCompile"
            ]
        },
        {
            "label": "compile with MSVC 32-bit (debug static)",
            "type": "shell",
            "command": "F:\\intelij\\vsCommunity\\VC\\Tools\\MSVC\\14.44.35207\\bin\\HostX64\\x86\\cl.exe",
            "args": [
                "/EHsc",
                "/MT",
                "/nologo",
                "/Zi",
                "/Fe:",
                "${workspaceFolder}/main_msvc32_debug.exe",
                "${workspaceFolder}/*.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$msCompile"
            ]
        },
        {
            "label": "compile with MSVC 32-bit (release static)",
            "type": "shell",
            "command": "F:\\intelij\\vsCommunity\\VC\\Tools\\MSVC\\14.44.35207\\bin\\HostX64\\x86\\cl.exe",
            "args": [
                "/EHsc",
                "/MT",
                "/nologo",
                "/O2",
                "/Fe:",
                "${workspaceFolder}/main_msvc32_release.exe",
                "${workspaceFolder}/*.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$msCompile"
            ]
        },
        {
                 "label": "compile with MSVC (debug dynamic)",
                 "type": "shell",
                 "command": "cl.exe",
                 "args": [
                     "/EHsc",
                     "/MD",  // Changed from /MT to /MD for dynamic linking
                     "/nologo",
                     "/Zi",
                     "/Fe:",
                     "${workspaceFolder}/main_msvc_dynamic_debug.exe",
                     "${workspaceFolder}/*.cpp",
                     "mylib.lib"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$msCompile"
                 ]
             },
        {
                 "label": "compile with MSVC (release dynamic)",
                 "type": "shell",
                 "command": "cl.exe",
                 "args": [
                     "/EHsc",
                     "/MD",  // Dynamic linking
                     "/nologo",
                     "/O2",
                     "/Fe:",
                     "${workspaceFolder}/main_msvc_dynamic_release.exe",
                     "${workspaceFolder}/*.cpp",
                     "mylib.lib"
                 ],
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [
                     "$msCompile"
                 ]
             },
        {
            "label": "compile with MSVC (create DLL debug)",
            "type": "shell",
            "command": "cl.exe",
            "args": [
                "/EHsc",
                "/nologo",
                "/LD",  // Create DLL
                "/Zi",  // Debug info
                "/Fe:",
                "${workspaceFolder}/mylib_debug.dll",
                "${workspaceFolder}/dll_example.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$msCompile"
            ]
        },
        {
            "label": "compile with MSVC (create DLL release)",
            "type": "shell",
            "command": "cl.exe",
            "args": [
                "/EHsc",
                "/nologo",
                "/LD",  // Create DLL
                "/O2",  // Optimization
                "/Fe:",
                "${workspaceFolder}/mylib_release.dll",
                "${workspaceFolder}/dll_example.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$msCompile"
            ]
        },
        {
            "label": "compile with clang++ 64-bit (debug static)",
            "type": "shell",
            "command": "clang++",
            "args": [
                "-g",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang64_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ 64-bit (release static)",
            "type": "shell",
            "command": "clang++",
            "args": [
                "-O2",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang64_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ 32-bit (debug static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\clang++.exe",
            "args": [
                "-g",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang32_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ 32-bit (release static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\clang++.exe",
            "args": [
                "-O2",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang32_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
             "label": "compile with clang++ (debug dynamic)",
             "type": "shell",
             "command": "clang++",
             "args": [
                 "-g",
                 "${workspaceFolder}/*.cpp",
                 "-L.",
                 "-lmylib",
                 "-o",
                 "${workspaceFolder}/main_clang_dynamic_debug.exe"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
               ]
           },
        {
             "label": "compile with clang++ (release dynamic)",
             "type": "shell",
             "command": "clang++",
             "args": [
                 "-O2",
                 "${workspaceFolder}/*.cpp",
                 "-L.",
                 "-lmylib",
                 "-o",
                 "${workspaceFolder}/main_clang_dynamic_release.exe"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
               ]
           },
        {
             "label": "compile with clang++ (create DLL debug)",
             "type": "shell",
             "command": "clang++",
             "args": [
                 "-g",
                 "-shared",
                 "-fPIC",
                 "${workspaceFolder}/dll_example.cpp",
                 "-o",
                 "${workspaceFolder}/mylib_debug.dll",
                 "-Wl,--out-implib,${workspaceFolder}/libmylib_debug.a"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
               ]
           },
        {
             "label": "compile with clang++ (create DLL release)",
             "type": "shell",
             "command": "clang++",
             "args": [
                 "-O2",
                 "-shared",
                 "-fPIC",
                 "${workspaceFolder}/dll_example.cpp",
                 "-o",
                 "${workspaceFolder}/mylib_release.dll",
                 "-Wl,--out-implib,${workspaceFolder}/libmylib_release.a"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
               ]
           },
        {
            "label": "compile with clang 64-bit (debug static)",
            "type": "shell",
            "command": "clang",
            "args": [
                "-g",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c64_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang 64-bit (release static)",
            "type": "shell",
            "command": "clang",
            "args": [
                "-O2",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c64_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang 32-bit (debug static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\clang.exe",
            "args": [
                "-g",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c32_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang 32-bit (release static)",
            "type": "shell",
            "command": "F:\\intelij\\mingw32\\bin\\clang.exe",
            "args": [
                "-O2",
                "-m32",
                "-static-libgcc",
                "-static-libstdc++",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c32_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
             "label": "compile with clang (debug dynamic)",
             "type": "shell",
             "command": "clang",
             "args": [
                 "-g",
                 "${workspaceFolder}/*.c",
                 "-L.",
                 "-lmylib",
                 "-o",
                 "${workspaceFolder}/main_clang_c_dynamic_debug.exe"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
             ]
         },
        {
             "label": "compile with clang (release dynamic)",
             "type": "shell",
             "command": "clang",
             "args": [
                 "-O2",
                 "${workspaceFolder}/*.c",
                 "-L.",
                 "-lmylib",
                 "-o",
                 "${workspaceFolder}/main_clang_c_dynamic_release.exe"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
             ]
         },
        {
             "label": "compile with clang (create DLL debug)",
             "type": "shell",
             "command": "clang",
             "args": [
                 "-g",
                 "-shared",
                 "-fPIC",
                 "${workspaceFolder}/dll_example.cpp",
                 "-o",
                 "${workspaceFolder}/mylib_debug.dll",
                 "-Wl,--out-implib,${workspaceFolder}/libmylib_debug.a"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
             ]
         },
        {
             "label": "compile with clang (create DLL release)",
             "type": "shell",
             "command": "clang",
             "args": [
                 "-O2",
                 "-shared",
                 "-fPIC",
                 "${workspaceFolder}/dll_example.cpp",
                 "-o",
                 "${workspaceFolder}/mylib_release.dll",
                 "-Wl,--out-implib,${workspaceFolder}/libmylib_release.a"
             ],
             "group": {
                 "kind": "build",
                 "isDefault": false
             },
             "problemMatcher": [
                 "$gcc"
             ]
         },
        {
            "label": "compile Java (debug)",
            "type": "shell",
            "command": "javac",
            "args": [
                "${workspaceFolder}/*.java"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$javac"
            ]
        },
        {
            "label": "compile Java (release)",
            "type": "shell",
            "command": "javac",
            "args": [
                "-g:none",
                "${workspaceFolder}/*.java"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$javac"
            ]
        },
        {
            "label": "compile Java (debug)",
            "type": "shell",
            "command": "javac",
            "args": [
                "${workspaceFolder}/*.java",
                "-d",
                "${workspaceFolder}/build/java_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$javac"
            ]
        },
        {
            "label": "compile Java (release)",
            "type": "shell",
            "command": "javac",
            "args": [
                "-g:none",
                "${workspaceFolder}/*.java",
                "-d",
                "${workspaceFolder}/build/java_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$javac"
            ]
        },
        {
            "label": "create Java JAR (debug)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/java_debug.jar",
                "-C",
                "${workspaceFolder}/build/java_debug",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "create Java JAR (release)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/java_release.jar",
                "-C",
                "${workspaceFolder}/build/java_release",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "compile Kotlin (debug)",
            "type": "shell",
            "command": "kotlinc",
            "args": [
                "${workspaceFolder}/*.kt",
                "-include-runtime",
                "-d",
                "${workspaceFolder}/build/kotlin_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "compile Kotlin (release)",
            "type": "shell",
            "command": "kotlinc",
            "args": [
                "-no-stdlib",
                "${workspaceFolder}/*.kt",
                "-include-runtime",
                "-d",
                "${workspaceFolder}/build/kotlin_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "create Kotlin JAR (debug)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/kotlin_debug.jar",
                "-C",
                "${workspaceFolder}/build/kotlin_debug",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "create Kotlin JAR (release)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/kotlin_release.jar",
                "-C",
                "${workspaceFolder}/build/kotlin_release",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with NASM (debug)",
            "type": "shell",
            "command": "nasm",
            "args": [
                "-g",
                "-f",
                "win64",
                "${workspaceFolder}/*.asm",
                "-o",
                "${workspaceFolder}/output.obj"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with NASM (release)",
            "type": "shell",
            "command": "nasm",
            "args": [
                "-f",
                "win64",
                "${workspaceFolder}/*.asm",
                "-o",
                "${workspaceFolder}/output.obj"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link with linker (debug)",
            "type": "shell",
            "command": "link",
            "args": [
                "/DEBUG",
                "/SUBSYSTEM:CONSOLE",
                "${workspaceFolder}/output.obj",
                "/OUT:${workspaceFolder}/asm_output.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link with linker (release)",
            "type": "shell",
            "command": "link",
            "args": [
                "/SUBSYSTEM:CONSOLE",
                "${workspaceFolder}/output.obj",
                "/OUT:${workspaceFolder}/asm_output.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "run Python script",
            "type": "shell",
            "command": "python",
            "args": [
                "${workspaceFolder}/*.py"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with MASM (32-bit debug)",
            "type": "shell",
            "command": "ml",
            "args": [
                "/c",
                "/Zi",
                "/Fo${workspaceFolder}/output32.obj",
                "/Fm${workspaceFolder}/output32.map",
                "${workspaceFolder}/*.asm"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with MASM (32-bit release)",
            "type": "shell",
            "command": "ml",
            "args": [
                "/c",
                "/Fo${workspaceFolder}/output32.obj",
                "${workspaceFolder}/*.asm"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with MASM (64-bit debug)",
            "type": "shell",
            "command": "ml64",
            "args": [
                "/c",
                "/Zi",
                "/Fo${workspaceFolder}/output64.obj",
                "/Fm${workspaceFolder}/output64.map",
                "${workspaceFolder}/*.asm"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with MASM (64-bit release)",
            "type": "shell",
            "command": "ml64",
            "args": [
                "/c",
                "/Fo${workspaceFolder}/output64.obj",
                "${workspaceFolder}/*.asm"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link MASM 32-bit (debug)",
            "type": "shell",
            "command": "link",
            "args": [
                "/DEBUG",
                "/SUBSYSTEM:CONSOLE",
                "${workspaceFolder}/output32.obj",
                "/OUT:${workspaceFolder}/masm32_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link MASM 32-bit (release)",
            "type": "shell",
            "command": "link",
            "args": [
                "/SUBSYSTEM:CONSOLE",
                "${workspaceFolder}/output32.obj",
                "/OUT:${workspaceFolder}/masm32_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link MASM 64-bit (debug)",
            "type": "shell",
            "command": "link",
            "args": [
                "/DEBUG",
                "/SUBSYSTEM:CONSOLE",
                "${workspaceFolder}/output64.obj",
                "/OUT:${workspaceFolder}/masm64_debug.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link MASM 64-bit (release)",
            "type": "shell",
            "command": "link",
            "args": [
                "/SUBSYSTEM:CONSOLE",
                "${workspaceFolder}/output64.obj",
                "/OUT:${workspaceFolder}/masm64_release.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        }
    ]
 }
```

ezeket a fájlokat rakd a**`.vscode`** mappába

Ha Linux alatt dolgozol itt vannak a linuxos verziók.....

c_cpp_properties.json

```
{
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: LLVM, IndentWidth: 4, TabWidth: 4, UseTab: Never }",
    "C_Cpp.default.compilerPath": "/usr/bin/gcc",
    "C_Cpp.default.intelliSenseMode": "linux-gcc-x64",
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.cStandard": "c11",
    "C_Cpp.formatting": "clangFormat",
    "C_Cpp.errorSquiggles": "Enabled",
    "C_Cpp.intelliSenseEngine": "Default",
    "C_Cpp.intelliSenseEngineFallback": "Enabled"
}
```

launch.json

```
{
    "version": "0.2.0",
    "inputs": [
        {
            "id": "javaMainClass",
            "type": "promptString",
            "description": "Java main class name",
            "default": "HelloWorld"
        },
        {
            "id": "kotlinMainClass",
            "type": "promptString",
            "description": "Kotlin main class name",
            "default": "HelloKt"
        }
    ],
    "configurations": [
        {
            "name": "C: gcc debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc (debug static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: gcc release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc (release static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: g++ debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gpp_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (debug static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: g++ release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gpp_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (release static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: gcc debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_dynamic_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc (debug dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: gcc release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gcc_dynamic_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with gcc (release dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: g++ debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gpp_dynamic_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (debug dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: g++ release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_gpp_dynamic_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with g++ (release dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: clang debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (debug static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: clang release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (release static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: clang++ debug (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_cpp_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (debug static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: clang++ release (static)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_cpp_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (release static)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: clang debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_dynamic_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (debug dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C: clang release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_c_dynamic_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang (release dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: clang++ debug (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_cpp_dynamic_debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (debug dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "C++: clang++ release (dynamic)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main_clang_cpp_dynamic_release",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "compile with clang++ (release dynamic)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "Assembly: run (debug)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/asm_program",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link with ld (debug)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "Assembly: run (release)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/asm_program",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "link with ld (release)",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "Java: compile and run (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:javaMainClass}",
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole"
        },
        {
            "name": "Java: compile and run (release)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:javaMainClass}",
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal"
        },
        {
            "name": "Java: run JAR (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/java_debug.jar"
            ],
            "preLaunchTask": "create Java JAR (debug)"
        },
        {
            "name": "Java: run JAR (release)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/java_release.jar"
            ],
            "preLaunchTask": "create Java JAR (release)"
        },
        {
            "name": "Kotlin: compile and run (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:kotlinMainClass}",
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole",
            "args": []
        },
        {
            "name": "Kotlin: compile and run (release)",
            "type": "java",
            "request": "launch",
            "mainClass": "${input:kotlinMainClass}",
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal",
            "args": []
        },
        {
            "name": "Kotlin: run JAR (debug)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "internalConsole",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/kotlin_debug.jar"
            ],
            "preLaunchTask": "create Kotlin JAR (debug)"
        },
        {
            "name": "Kotlin: run JAR (release)",
            "type": "java",
            "request": "launch",
            "mainClass": null,
            "projectName": "linux_buildVSC",
            "cwd": "${workspaceFolder}",
            "console": "externalTerminal",
            "args": [],
            "vmArgs": [
                "-jar",
                "${workspaceFolder}/kotlin_release.jar"
            ],
            "preLaunchTask": "create Kotlin JAR (release)"
        },
        {
            "name": "Python: run script",
            "type": "python",
            "request": "launch",
            "program": "${workspaceFolder}/hello.py",
            "console": "integratedTerminal",
            "cwd": "${workspaceFolder}"
        }
    ]
}
```

settings.json

```
{
    "editor.tabSize": 4,
    "editor.insertSpaces": true,
    "editor.detectIndentation": false,
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: LLVM, IndentWidth: 4, TabWidth: 4, UseTab: Never }",
    "C_Cpp.formatting": "clangFormat",
    "C_Cpp.intelliSenseEngine": "Default",
    "C_Cpp.intelliSenseEngineFallback": "Enabled",
    "files.associations": {
        "*.h": "cpp",
        "*.c": "c",
        "*.cpp": "cpp",
        "*.hpp": "cpp"
    },
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.cStandard": "c11",
    "C_Cpp.default.compilerPath": "/usr/bin/gcc",
    "C_Cpp.default.intelliSenseMode": "linux-gcc-x64",
    "C_Cpp.errorSquiggles": "Enabled",
    "extensions.ignoreRecommendations": false,
    "terminal.integrated.defaultProfile.linux": "bash"
}
```

tasks.json

```
{
     "version": "2.0.0",
     "tasks": [
        {
            "label": "compile with gcc (debug static)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc (release static)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-O2",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc (debug dynamic)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_dynamic_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc (release dynamic)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-O2",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_gcc_dynamic_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (debug static)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gpp_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (release static)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-O2",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gpp_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (debug dynamic)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gpp_dynamic_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (release dynamic)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-O2",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_gpp_dynamic_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang (debug static)",
            "type": "shell",
            "command": "clang",
            "args": [
                "-g",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang (release static)",
            "type": "shell",
            "command": "clang",
            "args": [
                "-O2",
                "-static",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ (debug static)",
            "type": "shell",
            "command": "clang++",
            "args": [
                "-g",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang_cpp_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ (release static)",
            "type": "shell",
            "command": "clang++",
            "args": [
                "-O2",
                "-static",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang_cpp_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang (debug dynamic)",
            "type": "shell",
            "command": "clang",
            "args": [
                "-g",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c_dynamic_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang (release dynamic)",
            "type": "shell",
            "command": "clang",
            "args": [
                "-O2",
                "${workspaceFolder}/*.c",
                "-o",
                "${workspaceFolder}/main_clang_c_dynamic_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ (debug dynamic)",
            "type": "shell",
            "command": "clang++",
            "args": [
                "-g",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang_cpp_dynamic_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with clang++ (release dynamic)",
            "type": "shell",
            "command": "clang++",
            "args": [
                "-O2",
                "${workspaceFolder}/*.cpp",
                "-o",
                "${workspaceFolder}/main_clang_cpp_dynamic_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc (create shared library debug)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.c",
                "-o",
                "${workspaceFolder}/libmylib_debug.so"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with gcc (create shared library release)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-O2",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.c",
                "-o",
                "${workspaceFolder}/libmylib_release.so"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (create shared library debug)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.cpp",
                "-o",
                "${workspaceFolder}/libmylib_cpp_debug.so"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "compile with g++ (create shared library release)",
            "type": "shell",
            "command": "g++",
            "args": [
                "-O2",
                "-shared",
                "-fPIC",
                "${workspaceFolder}/dll_example.cpp",
                "-o",
                "${workspaceFolder}/libmylib_cpp_release.so"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "assemble with NASM (debug)",
            "type": "shell",
            "command": "nasm",
            "args": [
                "-g",
                "-f",
                "elf64",
                "${workspaceFolder}/*.asm",
                "-o",
                "${workspaceFolder}/output.o"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "assemble with NASM (release)",
            "type": "shell",
            "command": "nasm",
            "args": [
                "-f",
                "elf64",
                "${workspaceFolder}/*.asm",
                "-o",
                "${workspaceFolder}/output.o"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link with ld (debug)",
            "type": "shell",
            "command": "ld",
            "args": [
                "-g",
                "-o",
                "${workspaceFolder}/asm_program",
                "${workspaceFolder}/output.o"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "link with ld (release)",
            "type": "shell",
            "command": "ld",
            "args": [
                "-o",
                "${workspaceFolder}/asm_program",
                "${workspaceFolder}/output.o"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "compile Java (debug)",
            "type": "shell",
            "command": "javac",
            "args": [
                "${workspaceFolder}/*.java",
                "-d",
                "${workspaceFolder}/build/java_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$javac"
            ]
        },
        {
            "label": "compile Java (release)",
            "type": "shell",
            "command": "javac",
            "args": [
                "-g:none",
                "${workspaceFolder}/*.java",
                "-d",
                "${workspaceFolder}/build/java_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": [
                "$javac"
            ]
        },
        {
            "label": "create Java JAR (debug)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/java_debug.jar",
                "-C",
                "${workspaceFolder}/build/java_debug",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "create Java JAR (release)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/java_release.jar",
                "-C",
                "${workspaceFolder}/build/java_release",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "compile Kotlin (debug)",
            "type": "shell",
            "command": "kotlinc",
            "args": [
                "${workspaceFolder}/*.kt",
                "-include-runtime",
                "-d",
                "${workspaceFolder}/build/kotlin_debug"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "compile Kotlin (release)",
            "type": "shell",
            "command": "kotlinc",
            "args": [
                "-no-stdlib",
                "${workspaceFolder}/*.kt",
                "-include-runtime",
                "-d",
                "${workspaceFolder}/build/kotlin_release"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "create Kotlin JAR (debug)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/kotlin_debug.jar",
                "-C",
                "${workspaceFolder}/build/kotlin_debug",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "create Kotlin JAR (release)",
            "type": "shell",
            "command": "jar",
            "args": [
                "cvf",
                "${workspaceFolder}/kotlin_release.jar",
                "-C",
                "${workspaceFolder}/build/kotlin_release",
                "."
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        },
        {
            "label": "run Python script",
            "type": "shell",
            "command": "python3",
            "args": [
                "${workspaceFolder}/*.py"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": []
        }
    ]
 }
```

ezek a .json fájlok megtalálthatóak itt is... egyben <br>

[SettingVSCODE-WIN-LINUX/C_make.md at main · AtiBexx/SettingVSCODE-WIN-LINUX](https://github.com/AtiBexx/SettingVSCODE-WIN-LINUX/blob/main/C_make.md)

**C_Make ha kellene....**

    1. CMake telepítése

   - Windows: Letölthető innen: https://cmake.org/download/
   - Linux: sudo apt install cmake (Ubuntu/Debian) vagy megfelelő csomag a disztribúciódnak

    2. CMakeLists.txt létrehozása
    
    A projekt gyökérkönyvtárában létre kell hoznod egy CMakeLists.txt fájlt, amely leírja, hogyan épüljön a
    projekt:

```
 cmake_minimum_required(VERSION 3.10)
 project(MyProject)

 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_C_STANDARD 11)

 # For C files
 file(GLOB C_SOURCES "*.c")
 add_executable(my_c_app ${C_SOURCES})


 # For C++ files
 file(GLOB CPP_SOURCES "*.cpp")
 add_executable(my_cpp_app ${CPP_SOURCES})

 # For shared library
 add_library(mylib SHARED dll_example.c)

 # For assembly (if needed)
 enable_language(ASM_NASM)
 file(GLOB ASM_SOURCES "*.asm")
 add_executable(my_asm_app ${ASM_SOURCES})
```

    3. VSCode beállítások CMake-hez

**A VSCode-hoz telepíteni kell a "CMake Tools" kiegészítőt, amely integrálja a CMake-et a szerkesztőbe.**

    4. CMake konfiguráció VSCode-hoz
    
    A .vscode/settings.json fájlban beállíthatod a CMake elérési útját:

```
 {
     "cmake.cmakePath": "/usr/bin/cmake",  // Linux
     "cmake.configureSettings": {
         "CMAKE_BUILD_TYPE": "Debug"
     }
 }
```

    5. CMake használata

   - A projektben a CMakeLists.txt fájl alapján a CMake generálja a megfelelő build fájlokat (pl. Makefile
     Linuxon, vagy Visual Studio solution Windowson)
   - A CMake Tools kiegészítő gombokat biztosít a configure, build és debug műveletekhez

  Ez lényegesen rugalmasabb, mint a korábban konfigurált egyedi fordítási feladatok, mivel lehetővé teszi a
  komplex projektstruktúrák kezelését, függőségek feloldását, és platformfüggetlen build konfigurációt.

Akkor a kód:

```
/*
 *BitTeszt
 *Ez a kód inicializál 2 változót ,és kiírja
 *~ , & | és a ^ müveleteket
 * George Boole igazságtáblája
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <limits>

int main(int argc, const char **argv)
{

    // a kimenet beállítása hexaDecimálisra
    // unsetf = kikakpcsolja a decimális kiírást
    // setf = bekapcsolja a hexadecimális kimenetet
    /* Régi C++ stílus : kézi flag-kezelés
    std::cout.unsetf(std::cout.dec);
    std::cout.setf(std::cout.hex);
    */
    // ujabb stílus
    std::cout << std::dec;
    std::cout << std::hex;
    // Két argumentum iniciaéizálása
    int argc1 = 0x78ABCDEF;
    int argc2 = 0x12345678;

    // NOT operátor végrehajtása
    // Minden bitet megfordít
    // Ha 1, akkor 0, ha 0, akkor 1
    // pl 1101(13) lesz 0010  (2) decimálisan
    std::cout << " argc1 = 0x" << argc1 << std::endl;
    std::cout << "~argc1 = 0x" << ~argc1 << std::endl;
    std::cout << " argc2 = 0x" << argc2 << std::endl;
    std::cout << "~argc2 = 0x" << ~argc2 << std::endl;

    // kétoperandosú operátorok végrehajtása

    //& -AND és
    // Csak akkor 1 egy bit, ha MINDKETTŐ 1
    /*Igazságtábla:
    1 & 1 = 1
    1 & 0 = 0
    0 & 1 = 0
    0 & 0 = 0
     */
    std::cout << "0x" << argc1 << "\n"
              << "& 0x" << argc2 << "\n"
              << " ---------" << "\n"
              << "0x" << (argc1 & argc2) << "\n"
              << std::endl;

    //| -OR vagy
    // Elég ha az egyik 1
    /*Igazságtábla:
    1 | 1 = 1
    1 | 0 = 1
    0 | 1 = 1
    0 | 0 = 0
    */
    std::cout << "0x" << argc1 << "\n"
              << "| 0x" << argc2 << "\n"
              << " ---------" << "\n"
              << "0x" << (argc1 | argc2) << "\n"
              << std::endl;

    //^ — XOR (kizáró VAGY)
    // Csak akkor 1, ha KÜLÖNBÖZNEK
    // Az azonos bitek „kioltják” egymást
    /*
    Igazságtábla:
    1 ^ 1 = 0
    1 ^ 0 = 1
    0 ^ 1 = 1
    0 ^ 0 = 0
    */
    std::cout << "0x" << argc1 << "\n"
              << "^ 0x" << argc2 << "\n"
              << " ---------" << "\n"
              << "0x" << (argc1 ^ argc2) << "\n"
              << std::endl;

    std::cout << "A kilpéshez nyomd meg az Entert...." << std::endl;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //  Mivel nem kértünk be adatot ezért semmi nem maradt a pufferben
    //  Nem kell üríteni a puffert mert akkor 2 db entert fog várni
    std::cin.get();
    return 0;
}
```

//OUTPUT KIMENET

```
 argc1 = 0x78abcdef
~argc1 = 0x87543210
 argc2 = 0x12345678
~argc2 = 0xedcba987
0x78abcdef
& 0x12345678
 ---------
0x10204468

0x78abcdef
| 0x12345678
 ---------
0x7abfdfff

0x78abcdef
^ 0x12345678
 ---------
0x6a9f9b97

A kilpéshez nyomd meg az Entert....
```

```
/* Régi C++ stílus : kézi flag-kezelés
    std::cout.unsetf(std::cout.dec);
    std::cout.setf(std::cout.hex);
```

**Flag**: **Kapcsoló (BitKapcsoló)**

**Flag = kapcsoló (mentális modell)**

A `std::cout` belsejében van egy csomó **bitkapcsoló**:

```
[ dec ][ hex ][ oct ][ showbase ][ uppercase ] ...
```

Ezek **flag-ek**.
 Egy flag:

- **0** → kikapcsolva
- **1** → bekapcsolva

Ez szó szerint egy **bitmaszk**.

------

**„Kézi flag-kezelés” – mit jelent?**

Ez:

```
std::cout.unsetf(std::cout.dec);
std::cout.setf(std::cout.hex);
```

= te mondod meg **pontosan**, melyik bit:

- kapcsoljon KI
- kapcsoljon BE

Olyan, mintha ezt csinálnád:

```
flags &= ~DEC;
flags |= HEX;
```

**te felelsz érte**, hogy ne maradjon rossz kombináció

**„Új stílus” – mi történik valójában?**

Ez:

```
std::cout << std::hex;
```

**Ugyanazokat a flag-eket állítja**,
 **csak a könyvtár csinálja helyetted**.

### Kézi mód

Olyan, mintha egy elektromos szekrényben:

- külön-külön felkapcsolod a biztosítékokat
- figyelned kell, nehogy kettő egyszerre legyen fent

### Manipulátor

Olyan, mint egy **programkapcsoló**:

- „HEX mód”
- a rendszer **rendbe teszi a többieket**

## Fordítás C-makel

 1. Lépj be a projekt mappájába:

     1 cd E:\projects\vscode\bitTeszt

    2. Hozz létre egy build könyvtárat:

     1 mkdir build
     2 cd build

    3. Generáld a fordítási fájlokat:

     1 cmake .. -DCMAKE_BUILD_TYPE=Release
    (Vagy Debug típusú build-hez.)

    4. Fordítsd a projektet:

     1 cmake --build .
    
    -----

 **Release** **verzió generálása:**

```
cmake -S . -B build_release -DCMAKE_BUILD_TYPE=Release
```

​    **Debug verzió generálása:**

```
 cmake -S . -B build_debug -DCMAKE_BUILD_TYPE=Debug
```

**CMakeLists.txt** ->

```
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

```

