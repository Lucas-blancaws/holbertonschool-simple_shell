# 🐚 simple_shell

---

## 📖 Description

**`simple_shell`** is a simple implementation of a Unix shell in C, developed as part of the **Holberton School** curriculum.  
It allows the execution of commands, management of environment variables, and supports both interactive and non-interactive modes.

---

## 🚀 Features

- 🔹 Execution of standard Unix commands (`ls`, `pwd`, etc.)
- 🔹 Automatic search in the `PATH`
- 🔹 Support for interactive mode (with prompt `#cisfun$`)
- 🔹 Non-interactive mode via redirection or piping
- 🔹 Built-in commands:
  - `exit`: exits the shell
  - `env`: displays environment variables
  - `setenv`: adds or modifies an environment variable
  - `unsetenv`: removes an environment variable
- 🔹 Error handling: returns status code `127` if command is not found


---
## REQUIREMENTS
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
---
## AUTHORIZED FUNCTIONS
- all functions from string.h
- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- printf
- fprintf
- vfprintf
- sprintf
- putchar
- read
- readdir
- signal
- stat (__xstat)
- lstat (__lxstat)
- fstat (__fxstat)
- strtok
- wait
- waitpid
- wait3
- wait4
- write

---

## 💡 Usage

### Mode interactive
```bash
./hsh
#cisfun$ ls
```

### Mode non-interactive
```bash
echo "ls -l" | ./hsh
```

### Exit the shell
```bash
#cisfun$ exit
```

---

## 🔍 Examples

```bash
#cisfun$ ls
README.md  main.c  shell.c  ...

#cisfun$ /bin/echo Hello World
Hello World

#cisfun$ command404
./hsh: command404: not found
```
---

## 🧪 Testing

### Test simple
```bash
echo "ls -l" | ./hsh
```

### Memory Test with Valgrind
```bash
valgrind --leak-check=full ./hsh
```

## Expected Output :
```
== All heap blocks were freed -- no leaks are possible
```
---
## 🗺️ Flowchart 
![Logo de mon projet](Images/FLOWCHART.jpg)

## 🧑‍💼 Authors

- **BLANC-PORTIER LUCAS**  
- **ROMANELLI Alcinoe**

---
