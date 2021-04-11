# HSH - Holberton shell
![enter image description here](https://blog.desdelinux.net/wp-content/uploads/2019/01/bash-logo.jpg.webp)

Holberton shell, or simply hsh, is a simple command line prompt that is made for a project at the end of the first trimester. It consists in a basic shell which can run programs and built-in commands.
It´s inspired in other shells like bash or sh but not with the best optimization. Besides, if you want to try it, you can clone the repo, compile it and give us your opinion .


# Example
`./hsh` Executes the shell and shows us the prompt waiting for an input.
Output: `($) _`

# Features

 - Shows a prompt and wait the user enter a command. When a command ends the execution the prompt shows again.
 - Search for commands in the `PATH` directories (can execute commands with a absolute PATH).
 - Handle errors.
 - Handle end-of-file condition (Ctrl + D).
 - Handle comments `#`.
 - Handle commands with arguments.
 - Support built-in function exit with and without an status.
 - Handle the Ctrl + C condition to not kill the shell.

## Built-in Functions

 - `exit [status]` exit the shell with exit code given in status.
 - `env` print all environment variables.

# Files

 - AUTHORS : List with names and emails of the creators of the program.
 - README.md : The file you are reading in this moment.
 - aux.c :  File containing auxiliary functions like count_sep or parser.
 - aux_1.c : File containing more auxiliary functions like _which.
 - holberton.h : Header file.
 - hsh : Executable file of the shell (precompiled).
 - man_1_simple_shell : Man file for this shell.
 - simple_shell.c : File containing main and complementary functions.
 - string_handlers.c : File containing functions to handle strings like _strcpy or _strlen.
 - string_handlers_1.c : File containing more functions to handle strings like _atoi or _puts.

# Compilation
If you want to compile this beautiful project by your own, you need to compile it with the next command: ``gcc -Wall -Werror -Wextra -pedantic *.c -o hsh``.

# Authors

 - Francisco Calixto : https://github.com/Francisco-Calixto-HolbertonSchool
 - Diego Varela : https://github.com/dieg0varela


