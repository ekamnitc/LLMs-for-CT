# LLMs-for-Code Translation
Here is the replication package for the work - "Code Translation via Iterative Control Flow Graph Isomorphism: Emerging Results and Future Scope".
The users must follow the following steps to run the replicaion package.
# Installing or Upgrading the OpenAI Python Library
Upgrade the OpenAI library to the latest version:
Running the command below ensures you are using the latest version of the OpenAI library with the newest features and bug fixes.
!pip install --upgrade openai

# Install a specific version of the OpenAI library:
If your project requires a specific version (e.g., 0.28), you can install it directly using this command:
pip install openai==0.28

# Installation of Graphviz and PyGraphviz
To work with PyGraphviz, a Python interface to the Graphviz graph visualization software, the following steps ensure proper installation of the required dependencies and the library:

## Install Graphviz and its development headers:
Graphviz is a graph visualization tool, and the libgraphviz-dev package provides development libraries and headers needed for compiling PyGraphviz.
!apt install graphviz libgraphviz-dev

## Install PyGraphviz with custom include and library paths:
PyGraphviz requires access to Graphviz’s include and library files. Specifying these paths during installation ensures that the library can properly locate Graphviz dependencies.
!pip install pygraphviz --install-option="--include-path=/usr/include/graphviz" --install-option="--library-path=/usr/lib/graphviz/"

## Installing PyGraphviz
The PyGraphviz library is a Python interface to the Graphviz graph visualization software. To install it, use the following command:
!pip install pygraphviz
Ensure that Graphviz and its development headers (graphviz and libgraphviz-dev) are installed before running this command. Use the following for Ubuntu-based systems:
sudo apt install graphviz libgraphviz-dev

If the default installation fails, you may need to specify the paths to Graphviz’s include and library directories explicitly (as shown earlier with --install-option).

# Translating C++ to C Using Control Flow Graph (CFG) Analysis
The program CT-ICFGI.py automates the translation of C++ programs to C using OpenAI's GPT-3.5-turbo while iteratively refining the output based on mismatches in the Control Flow Graphs (CFGs) of the source and translated programs. The process evaluates the logical equivalence of both programs by comparing their CFGs and ensures accurate translation through iterative refinements. Please note that, in the CT-ICFGI.py, those who would like to run the program, they must insert their **openai.api_key**. This is important, because, the GPT-turbo-3.5 is available on the subscription based. 

## Translation Process
**Input:** A directory containing C++ programs (.cpp files).
**Translation:** Each C++ program is translated to C using GPT-3.5-turbo.
**CFG Generation:** The program generates CFGs for both C++ and translated C programs using GCC/G++ with the -fdump-tree-cfg-graph flag.
**Graph Comparison:** Extracts basic block and edge information from the CFGs. Then, it will compares the structure and logic of source and translated CFGs to identify mismatches.
**Iterative Refinement:** If mismatches are detected:
A feedback request is constructed in the same program to refine the translation. The refined translation is processed, and the CFG comparison is repeated.
**Stop Condition:** Iteration stops if no mismatches are found or after a maximum of 10 iterations.

## Output
**Translated C Programs:** Saved in the TranslatedPrograms directory.
**Control Flow Graphs (CFGs):** Saved in the CFGs/C++ and CFGs/C directories as DOT files.
**Summary Report:** An Excel file (TestSummary.xlsx) containing: Program name, Iteration count Basic block and edge counts for both C++ and C CFGs, Matched nodes, and Mismatched nodes and edges.

## Example Directory Structure
/CPP-Programs/          # Input directory containing C++ programs
TranslatedPrograms/                         # Output directory for translated C programs
CFGs/
  ├── C++/                                  # CFG DOT files for C++ programs
  └── C/                                    # CFG DOT files for translated C programs
TestSummary.xlsx                            # Summary report

## How to Run
Place your C++ programs (.cpp files) in the specified input directory (e.g., /CPP-Programs).
Run the script. It will process all .cpp files, generate CFGs, and iteratively refine translations as needed.
Check the TestSummary.xlsx file for a summary of the results.
