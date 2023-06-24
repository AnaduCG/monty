# 0x19. C - Stacks, Queues - LIFO, FIFO
ALX software engineering group project on Stacks, Queues - LIFO, FIFO using C prigramming language


This project is an interpreter for Monty ByteCodes files. Monty is a scripting language that first compiles into Monty byte codes, similar to Python. It operates on a unique stack and provides specific instructions to manipulate it.

# Compilation & Output

To compile the code, use the following command:
```$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```
The output are to be printed on stdout (standard output), and any error message to be printed on stderr (standard error).

# Monty Byte Code Files

Monty byte code files have the extension `.m`. Each file contains Monty byte codes with one instruction per line. The opcode and its argument can have any number of spaces before or after them. Blank lines are allowed, and any additional text after the opcode or its argument is ignored.

###  Example:
```push 0
push 1
push 2
  push 3
                   pall    
push 4
    push 5    
      push    6        
pall
```

# The Monty Program
The Monty program is used as follows:

````Usage: monty file````

- `file` is the path to the file containing Monty byte code.
If no file or more than one argument is provided, the program will print the error message:
``USAGE: monty file``

and exit with status `EXIT_FAILURE`.

If the specified file cannot be opened, the program will print the error message:

```Error: Can't open file <file>```
where `<file>` is the name of the file, and exit with status EXIT_FAILURE.

If the file contains an invalid instruction, the program will print the error message:
`L<line_number>: unknown instruction <opcode>`
where `<line_number>` is the line number where the instruction appears, and exit with status `EXIT_FAILURE`. Line numbers always start at 1.

The Monty program executes the bytecodes line by line and stops under the following conditions:
- It successfully executes every line of the file.
- It encounters an error in the file.
- An error occurs during execution.

If the program is unable to allocate memory using malloc, it will print the error message:
```Error: malloc failed```