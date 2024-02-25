# Simple Shell Project

This repository contains the implementation of a simple UNIX command line interpreter as part of the ALX Software Engineering curriculum. The project is based on the requirements outlined in the task descriptions provided by ALX.

## Project Overview

The Simple Shell project is a group project to be completed in teams of two people. It involves writing a basic UNIX command line interpreter in the C programming language. The shell should be able to execute commands entered by the user and display the output accordingly. Additionally, it should handle errors gracefully and support basic built-in functionalities such as `exit` and `env`.

## Contributors

This project was completed by the following individuals:

- Azeddine Chakir
- Youssef Oumouni

## Project Timeline

- Project Start Date: February 14, 2024 4:00 AM
- Project End Date: February 29, 2024 4:00 AM
- Checker Release Date: February 27, 2024 11:12 PM

## Learning Objectives

Upon completion of this project, the contributors are expected to demonstrate understanding of the following concepts without relying on external resources:

- General knowledge about UNIX operating system design and development
- Implementation details of the UNIX shell
- Process management and execution
- Environment manipulation
- Error handling and debugging techniques

## Requirements

### General

- Allowed Editors: vi, vim, emacs
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- All files must end with a new line
- Your code should use the Betty style and pass the checks
- No memory leaks allowed
- Maximum of 5 functions per file
- All header files should be include guarded
- Use system calls only when necessary

### Output

- The shell should have the same output and error handling behavior as `/bin/sh`
- Error messages should display the name of the program (`argv[0]`)

### Allowed Functions and System Calls

A list of allowed functions and system calls is provided in the project documentation.

## Tasks

The project is divided into multiple tasks, each building upon the previous one to incrementally develop the functionality of the shell. These tasks include implementing basic command execution, handling command line arguments, managing the `PATH`, implementing built-in commands like `exit` and `env`, and more.

## How to Use

To use the simple shell, compile the source files using the provided compilation command and run the resulting executable. The shell can be used in interactive mode by running `./hsh` and typing commands directly, or in non-interactive mode by piping commands into the shell executable.

## Credits

- Original project idea and guidance: Julien Barbier
- ALX Curriculum: [ALX](https://intranet.alxswe.com)

## License

This project is licensed under the ALX License. All rights reserved by ALX.

