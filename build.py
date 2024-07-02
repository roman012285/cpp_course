#!/usr/bin/env python

import os
import subprocess
import sys
import argparse

#for example ./build.py -dir exercise

def build_directory(exercise_name):
    base_dir = 'exercises'
    directory = os.path.join(base_dir, exercise_name)
    header_dir = os.path.join(directory, 'Header')
    source_dir = os.path.join(directory, 'Source')
    
    # Check if the specified directories exist
    if not os.path.isdir(header_dir) or not os.path.isdir(source_dir):
        print(f"Error: Specified exercise '{exercise_name}' does not have the required 'header' and 'source' subdirectories.")
        sys.exit(1)
    
    # Create the output directory if it doesn't exist
    output_dir = os.path.join(directory, 'build')
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    # Gather all the source files
    cpp_files = [os.path.join(source_dir, f) for f in os.listdir(source_dir) if f.endswith('.cpp')]
    
    # Create a list of object files to be generated
    obj_files = [os.path.join(output_dir, os.path.splitext(os.path.basename(f))[0] + '.o') for f in cpp_files]
    
    # Compile each .cpp file into .o object file
    for cpp_file, obj_file in zip(cpp_files, obj_files):
        compile_command = [
            'g++', '-c', '-o', obj_file, cpp_file, '-I', header_dir
        ]
        print(f"Compiling {cpp_file}...")
        subprocess.run(compile_command, check=True)
    
    # Link all object files into a single executable
    executable = os.path.join(output_dir, 'main')
    link_command = ['g++', '-o', executable] + obj_files
    print(f"Linking to create executable {executable}...")
    subprocess.run(link_command, check=True)
    
    print("Build completed successfully.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Build C++ exercises.')
    parser.add_argument('-dir', type=str, required=True, help='Name of the exercise directory (e.g., exercise0)')
    args = parser.parse_args()
    
    exercise_name = args.dir
    build_directory(exercise_name)
