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
| `opcodes_functions.c`  | implements the opcodes.
| `free_list.c`          | frees a list.
| `opcodes_functions2.c` | implements the opcodes.
| `opcodes_functions3.c` | implements the opcodes.

# Examples

* **push, pall:**

> root@????????????:~/monty# cat -e bytecodes/00.m

```
push 1$
push 2$
push 3$
pall$
```

> root@????????????:~/monty# ./monty bytecodes/00.m 

```
3
2
1
```

* **pint:**

> root@????????????:~/monty# cat bytecodes/06.m

```
push 1
pint
push 2
pint
push 3
pint
```
 
> root@????????????:~/monty# ./monty bytecodes/06.m 

```
1
2
3
```

* **pop:**

> root@????????????:~/monty# cat bytecodes/07.m 

```
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
```

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

> root@????????????:~/monty# cat bytecodes/09.m 

```
push 1
push 2
push 3
pall
swap
pall
```

> root@????????????:~/monty# ./monty bytecodes/09.m 

```
3
2
1
2
3
1
```

* **add:**

> root@????????????:~/monty# cat bytecodes/12.m 

```
push 1
push 2
push 3
pall
add
pall

```

> root@????????????:~/monty# ./monty bytecodes/12.m 

```
3
2
1
5
1
```

* **nop:**

> root@????????????:~/monty# cat bytecodes/13.m 

```
nop
push 1
nop
pall
```

> root@????????????:~/monty# ./monty bytecodes/13.m 

```
1
```

* **sub:**

> root@????????????:~/monty# cat bytecodes/19.m

```
push 1
push 2
push 10
push 3
sub
pall
```

> root@????????????:~/monty# ./monty bytecodes/19.m 

```
7
2
1
```

* **div:**

> root@????????????:~/monty# more bytecodes/20.m 

```
push 2
push 3
push 4
pall
div
pall
```

> root@????????????:~/monty# ./monty bytecodes/20.m 

```
4
3
2
0
2
```

* **mul:**

> root@????????????:~/monty# more bytecodes/21.m 

```
push 1
push 2
push 3
pall
mul
pall
```

> root@????????????:~/monty# ./monty bytecodes/21.m 

```
3
2
1
6
1
```

* **mod:**

> root@????????????:~/monty# cat bytecodes/22.m 

```
push 1
push 2
push 3
pall
mod
pall
```

> root@????????????:~/monty# ./monty bytecodes/22.m 

```
3
2
1
2
1
```
