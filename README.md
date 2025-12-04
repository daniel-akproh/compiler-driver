# compiler-driver
A basic compiler driver. This software is an intermediary project to my compiler-building project.

# Scope
The reason I wanted to write a driver is because a compiler isnt very useful on its own because there are many different stages a program passes through before reaching the binary stage, I learned. so this driver is to automate the compilation process as the program gets shaped into binary. 

# Requirements

The driver should convert a source file to an executable in three steps: 

1) run the command `gcc -E -P INPUT_FILE -o PREPROCESSED_FILE` to preprocess the file where the -E option tells GCC to run only the preprocesor and not the subsequent steps of the compilation process. The PREPROCESSED_FILE should have a .i file extension

2) compile the preprocessed source file and output an ssembly file with a .s extensionthen delete the preprocessed file when finished

3) Assemble and link the assembly file to produce an executable, using the command `gcc ASSEMBLY_FILE -o OUTPUT_FILE` then the assembly file should be deleted when no longer useful

4) The compiler driver must have a specific command line interface so that a test_scompiler script can run it 

5) the compiler driver must be a command line program that accepts a path to a C source file as its only argument. If this command succeeds, it must produce an executable in the same directory as the input file, with the smae name (minus the file extension). In other words, if we run `./ MY_COMPILER/path/to/program.c`, it should produce an executable at `/path/to/program` and terminate with an exit code of `0`.

6) If the compiler fails, the compiler driver should return a nonzero exit code and shouldn't write any assembly or executable files; that's how test_compiler verifies that the compiler catches errors in invalid programs.

5) Finally, the compiler driver should support the following options, which test_compiler uses to test intermediate stages:
   - `--lex` which directs it to run the lexer, but stop before parsing
   - `--parse` which directs it to run the lexer and parser, but stop before assembly generation
   - `--codegen` which directs it to perform lexing, and assembly generation, but stop before code emission None of these option should produce any output files and all should terminate with an exit code of 0 if they don't hit any errors. We might also want to add a -S option that directs the compiler to emit an assembly file, but not assemble nor link it.
   
7) the test_compiler script should be implemented as well based on the above requirements
