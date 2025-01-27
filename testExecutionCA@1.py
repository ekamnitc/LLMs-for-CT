# Test Execution and CA@1 Calculation Program

import os
import subprocess

def run_command(command):
    """
    Execute a shell command and return the output and error messages.
    """
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return result.stdout, result.stderr, result.returncode

def compile_and_run_tests(program_path, test_path):
    """
    Compile and run unit tests for a program. Returns True if all tests pass.
    """
    # Compile the program with the unit tests
    output_binary = "test_binary"
    compile_command = f"g++ -std=c++17 {program_path} {test_path} -o {output_binary}"
    _, compile_error, compile_status = run_command(compile_command)

    if compile_status != 0:
        print(f"Compilation failed for {program_path}:\n{compile_error}")
        return False

    # Run the compiled binary
    # Changed variable name to avoid conflict with function name
    run_binary_command = f"./{output_binary}"
    run_output, run_error, run_status = run_command(run_binary_command)

    if run_status == 0:
        print(f"All tests passed for {program_path}")
        return True
    else:
        print(f"Tests failed for {program_path}:\n{run_error}")
        return False

def evaluate_ca1(cpp_dir, c_dir, test_dir):
    """
    Evaluate CA@1 for the translated C programs against the original C++ programs.
    """
    cpp_passed = 0
    c_passed = 0
    total_programs = 0

    for cpp_file in os.listdir(cpp_dir):
        if cpp_file.endswith(".cpp"):
            cpp_path = os.path.join(cpp_dir, cpp_file)
            test_path = os.path.join(test_dir, cpp_file.replace(".cpp", "_test.cpp"))
            c_file = cpp_file.replace(".cpp", ".c")
            c_path = os.path.join(c_dir, c_file)

            # Run tests on the original C++ program
            if os.path.exists(test_path):
                if compile_and_run_tests(cpp_path, test_path):
                    cpp_passed += 1

                # Run tests on the translated C program
                if os.path.exists(c_path):
                    if compile_and_run_tests(c_path, test_path):
                        c_passed += 1

                total_programs += 1

    # Calculate CA@1
    ca1 = c_passed / total_programs if total_programs > 0 else 0
    print(f"CA@1: {ca1:.2f} ({c_passed}/{total_programs})")

# Paths
cpp_directory = "/CPP-Programs"  # Path to the C++ programs
translated_c_directory = "/TranslatedPrograms"  # Path to the translated C programs
test_directory = "/Programs-UniTests"  # Path to the generated test cases

evaluate_ca1(cpp_directory, translated_c_directory, test_directory)
