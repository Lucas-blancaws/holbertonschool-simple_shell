Simple Shell
Description

This project is a simple UNIX command interpreter written in C.
It replicates basic functionalities of a shell such as executing commands from the PATH, handling arguments, and supporting built-in commands like exit and env.

The purpose of this project is to understand how a shell works “under the hood” by learning about processes, system calls, environment variables, and parsing user input.

Features

Displays a prompt ($ ) and waits for the user to type a command.

Executes commands found in the system PATH.

Handles command arguments.

Built-in commands:

exit → exits the shell.

env → prints the current environment.

Handles end-of-file (Ctrl+D).

Error handling: prints an error message when a command is not found.

Compilation

Compile with:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage

Start the shell:

./hsh


Example session:

$ ls -l
total 4
-rwxr-xr-x 1 user user 12345 Aug 18 10:00 hsh
$ pwd
/home/user/simple_shell
$ env
PATH=/usr/bin:/bin
HOME=/home/user
...
$ exit

Files

main.c → main loop, input parsing, and command execution.

shell.h → header file with function prototypes and macros.

Requirements

All files are compiled on Ubuntu 20.04 LTS.

Code follows the Betty style guide.

No memory leaks.

Authors

Théa PROLONGEAU

Lucas Blancportier