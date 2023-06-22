# Stacks, Queues - LIFO, FIFO

The aim of this project is to learn about LIFO, FIFO, stack, and queue mean, and when to use them. What are the common implementations of stacks and queues. What are the most common use cases of stacks and queues. What is the proper way to use global variables?

# Technologies

Tested on Ubuntu 20.04 LTS.

C files are complied using gcc 9.4.0.

C files are written according to the GNU C89 dialect, which includes some extensions beyond the standard C89.

# Compilation

gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

# Files

All of the following files are programs written in C:

| Filename               | Description
|:----------------------:| -------------------------------------------------------------------------------------------------------
| `monty.c` 		 | main function for monty.
| `monty.h`              | header file containing all libraries, object-like macros, global variables, structures and prototypes.
| `read_file.c`          | read a file and execute commands.
| `split_line.c`         | splits line to opcode and argument.
| `get_function.c`       | gets a corresponding function based on the opcode given.
| `opcodes_functions.c ` | implements the opcodes.
| `free_list.c`          | frees a list.

# Examples

* **push, pall:**

> root@????????????:~/monty# ./monty bytecodes/00.m 

```
3
2
1
```

* **pint:**

> root@????????????:~/monty# ./monty bytecodes/06.m 

```
1
2
3
```

* **pop:**

> root@????????????:~/monty# ./monty bytecodes/07.m 

```
3
2
1
2
1
1
```

* **swap:**

> root@????????????:~/monty# ./monty bytecodes/09.m 

```
3
2
1
2
3
1
```
