# This is the program to translate C++ to C by iteratively propagating the error information

import os
import sys
# Explicitly add the include and library paths to sys.path
sys.path.append('/usr/include/graphviz')
sys.path.append('/usr/lib/graphviz')

import pandas as pd
import subprocess
import networkx as nx
from pygraphviz import AGraph
import openai

# Function to run shell commands
def run_command(command):
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return result.stdout, result.stderr

# Function to generate CFG using GCC/G++
def generate_cfg(file_path, lang):
    output_dir = f"CFGs/{lang}"
    os.makedirs(output_dir, exist_ok=True)
    base_name = os.path.basename(file_path).split('.')[0]
    if lang == "C++":
        command = f"g++ -fdump-tree-cfg-graph {file_path} -o {output_dir}/{base_name}" # Changed -fdump-tree-all-graph to -fdump-tree-cfg-graph
    elif lang == "C":
        command = f"gcc -fdump-tree-cfg-graph {file_path} -o {output_dir}/{base_name}" # Changed -fdump-tree-all-graph to -fdump-tree-cfg-graph
    stdout, stderr = run_command(command) # Capture stdout and stderr
    print(f"GCC/G++ output (stdout):\n{stdout}") # Print stdout for debugging
    print(f"GCC/G++ output (stderr):\n{stderr}") # Print stderr for debugging
    if lang == "C++":
        path = "cpp"
    else:
        path = "c"
    # Updated the expected .dot file name pattern to reflect the new command's output
    return f"{output_dir}/{base_name}.{path}.015t.cfg.dot"
    if os.path.exists(dot_file):
        # Convert DOT to PNG
        graph = AGraph(dot_file)
        png_file = f"{output_dir}/{base_name}.png"
        graph.draw(png_file, prog='dot', format='png')
        return dot_file, png_file
    else:
        print(f"Error: DOT file not generated for {file_path}. Check GCC/G++ output.")
        return None, None

# Function to extract basic block and edge information
def extract_bb_and_edges(dot_file):
    graph = AGraph(dot_file)
    nodes = graph.nodes()
    edges = graph.edges()
    return len(nodes), len(edges)

# Function to compare two CFGs
def compare_cfgs(dot_file1, dot_file2):
    """
    Compare two CFGs based on the logic within their basic blocks and the structure of their edges.

    :param dot_file1: Path to the first DOT file (source program CFG).
    :param dot_file2: Path to the second DOT file (translated program CFG).
    :return: Tuple (matched_nodes, total_edges1, total_edges2)
    """
    # Read the graphs
    graph1 = nx.drawing.nx_agraph.read_dot(dot_file1)
    graph2 = nx.drawing.nx_agraph.read_dot(dot_file2)

    # Extract normalized logic for basic block content
    def extract_normalized_logic(node_data):
        content = node_data.get('label', '').strip()
        # Normalize the content by removing variable names, whitespace, and register-specific data
        normalized_content = (
            content.replace('\n', ' ')
                   .replace('\\l', ' ')
                   .replace('{', '')
                   .replace('}', '')
                   .strip()
        )
        return normalized_content

    # Define a custom node-matching function
    def node_match(n1, n2):
        return extract_normalized_logic(n1) == extract_normalized_logic(n2)

    # Use a DiGraphMatcher with the custom node-matching logic
    matcher = nx.isomorphism.DiGraphMatcher(graph1, graph2, node_match=node_match)

    # Count matched nodes
    matched_nodes = sum(1 for _ in matcher.mapping.items())

    return matched_nodes, graph1.number_of_edges(), graph2.number_of_edges()

# Function to translate C++ to C using GPT-3.5-turbo
def translate_cpp_to_c(code):
    openai.api_key = "Please insert your OpenAI API Key"  # Replace with your OpenAI API key
    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "system", "content": "You are a helpful code translator."},
            {"role": "user", "content": f"Translate the following C++ code to C:\n\n{code}"}
        ]
    )
    return response['choices'][0]['message']['content']

# Main logic
def process_programs(cpp_dir):
    summary_file = "TestSummary.xlsx"
    os.makedirs("TranslatedPrograms", exist_ok=True)
    os.makedirs("CFGs/C++", exist_ok=True)
    os.makedirs("CFGs/C", exist_ok=True)

    # Create a DataFrame to store results
    columns = ["Program", "Iteration", "C++ BBs", "C++ Edges", "C BBs", "C Edges",
               "Matched Nodes", "Mismatched Nodes", "Mismatched Edges"]
    summary_data = []

    #with open(summary_file, "w") as summary:
    for cpp_file in os.listdir(cpp_dir):
        if not cpp_file.endswith(".cpp"):
            continue

        cpp_path = os.path.join(cpp_dir, cpp_file)
        base_name = os.path.splitext(cpp_file)[0]

        # Translate C++ to C
        with open(cpp_path, "r") as f:
            cpp_code = f.read()
        translated_c = translate_cpp_to_c(cpp_code)

        c_path = f"TranslatedPrograms/{base_name}.c"
        with open(c_path, "w") as f:
            f.write(translated_c)

        iteration = 1
        while True:
            # Generate CFGs
            cpp_cfg = generate_cfg(cpp_path, "C++")
            c_cfg = generate_cfg(c_path, "C")

            # Extract BB and edge information
            cpp_bb, cpp_edges = extract_bb_and_edges(cpp_cfg)
            c_bb, c_edges = extract_bb_and_edges(c_cfg)

            # summary.write(f"Program: {cpp_file}\n")
            # summary.write(f"C++ BBs: {cpp_bb}, Edges: {cpp_edges}\n")
            # summary.write(f"C BBs: {c_bb}, Edges: {c_edges}\n")

            # Compare CFGs
            matched_nodes, cpp_total_edges, c_total_edges = compare_cfgs(cpp_cfg, c_cfg)
            mismatched_nodes = cpp_bb - matched_nodes
            mismatched_edges = cpp_total_edges - c_total_edges

            # Append data to the summary
            summary_data.append([cpp_file, iteration, cpp_bb, cpp_edges, c_bb, c_edges,
                                matched_nodes, mismatched_nodes, mismatched_edges])

            # summary.write(f"Matched Nodes: {matched_nodes}, Mismatched Nodes: {mismatched_nodes}\n")
            # summary.write(f"Mismatched Edges: {mismatched_edges}\n\n")
            # Stop iteration if no mismatches or degraded results

            if mismatched_nodes <= 0 or iteration > 10:  # Adjust iteration cap as needed
                break
            # Propagate mismatched info (for GPT refinement, optional step)
            # if mismatched_nodes > 0 or mismatched_edges > 0:
            refinement_request = f"The translation of the following C++ code resulted in mismatched control flow graphs. Please note that, focus on generating BBs and corresponding control flows for the logic of the source program. Avoid generating BBs and correspondig control flows for the high-level abstraction. Please refine the translation to fix the issues:\n\n{cpp_code}\n\nMismatched Nodes: {mismatched_nodes}, Mismatched Edges: {mismatched_edges}"
            refined_translation = translate_cpp_to_c(refinement_request)

            with open(c_path, "w") as f:
                f.write(refined_translation)

            iteration += 1

    # Save summary data to Excel
    df = pd.DataFrame(summary_data, columns=columns)
    df.to_excel(summary_file, index=False)
    print(f"Summary saved to {summary_file}")

if __name__ == "__main__":
    cpp_directory = "/content/sample_data/CPP-Programs"  # Replace with the path to your C++ programs
    process_programs(cpp_directory)
