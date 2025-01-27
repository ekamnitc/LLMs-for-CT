import os
import openai

# Set your OpenAI API key
openai.api_key = "Replace with your OpenAI API key"  # Replace with your OpenAI API key

def generate_unit_tests(program_code):
    """
    Generate a suite of 10 unit tests for the given C++ program using GPT-3.5-turbo.
    """
    prompt = f"""Given the following C++ program, generate a suite of 5 unit tests
    that validate its functionality. Provide the test cases in a format suitable
    for Google Test framework, and include any necessary header files in the output.
    Ensure that only descriptive or non-executable lines are commented.

    Program:
    {program_code}
    """
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "system", "content": "You are a code generation assistant."},
            {"role": "user", "content": prompt}
        ]
    )
    return response['choices'][0]['message']['content']

def process_programs(cpp_dir, test_dir, header_dir):
    """
    Process C++ programs to generate unit tests and header files using GPT-3.5-turbo.
    """
    os.makedirs(test_dir, exist_ok=True)  # Ensure the test directory exists
    os.makedirs(header_dir, exist_ok=True)  # Ensure the header directory exists

    for cpp_file in os.listdir(cpp_dir):  # Iterate through all files in the source directory
        if cpp_file.endswith(".cpp"):  # Process only .cpp files
            cpp_path = os.path.join(cpp_dir, cpp_file)

            # Read the C++ program
            with open(cpp_path, "r") as file:
                cpp_code = file.read()

            # Generate unit tests using GPT
            unit_tests = generate_unit_tests(cpp_code)

            # Separate header and source content
            header_content = []
            source_content = []

            for line in unit_tests.splitlines():
                if line.strip().startswith("#include"):
                    source_content.append(line)
                elif ".h" in line:  # Identify header file content
                    header_content.append(line)
                elif "TEST(" in line or "{" in line or "}" in line:  # Valid C++ syntax
                    source_content.append(line)
                elif line.strip():  # Descriptive text or non-executable
                    source_content.append(f"// {line}")
                else:
                    source_content.append(line)

            # Save header files if any
            if header_content:
                header_file_name = cpp_file.replace(".cpp", ".h")
                header_file_path = os.path.join(header_dir, header_file_name)
                with open(header_file_path, "w") as file:
                    file.write("\n".join(header_content))
                print(f"Generated header file: {header_file_path}")

            # Save the unit test source file
            test_file = os.path.join(test_dir, cpp_file.replace(".cpp", "_test.cpp"))
            with open(test_file, "w") as file:
                file.write("\n".join(source_content))
            print(f"Generated unit test file: {test_file}")

# Main execution block
if __name__ == "__main__":
    # Specify paths for C++ programs and test case output directories
    cpp_directory = "/Test-Programs"  # Replace with the path to your C++ programs
    test_directory = "/Test-Programs-UniTests"  # Replace with the path to save test cases
    header_directory = "/Test-Headers"  # Replace with the path to save header files

    # Call the function to process programs
    process_programs(cpp_directory, test_directory, header_directory)
