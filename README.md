<h1 align="center">Stacks, Queues - LIFO, FIFO</h1>
<p align="center">ALX Africa</p>

## Description of the Project

Monty is an interpreter for Monty ByteCode files written in C. Monty ByteCode files have a .m file extension and contain a series of instructions that manipulate a stack and perform various operations. The interpreter reads Monty ByteCode files and executes the instructions accordingly.

### Stack Data Structure

The core of the Monty interpreter revolves around a stack data structure. This stack is implemented as a doubly linked list, represented by the stack_t struct. Each element in the stack is a node in the linked list, storing an integer value (n) and pointers to the previous and next elements.

### Instructions and Opcodes

Monty ByteCode instructions consist of an opcode and an optional argument. The opcode specifies the operation to perform, while the argument, when required, provides additional information for the operation. The interpreter supports a variety of opcodes, each corresponding to a specific action.

Some common opcodes include:

* **push**: Pushes an integer onto the stack.
* **pop**: Removes the top element from the stack.
* **pall**: Prints all the values on the stack.
* **add**, **sub**, **mul**, **div**, **mod**: Perform arithmetic operations on the stack elements.
* **swap**: Swaps the positions of the top two elements.
* **pint**: Prints the value at the top of the stack.

### Execution Flow

1. **Reading the File**: The Monty interpreter takes a Monty ByteCode file as a command-line argument. It reads the file line by line, parsing each line into an opcode and an optional argument.

2. **Execution Loop**: For each instruction in the file, the interpreter executes the corresponding operation. It maintains a stack data structure to store and manipulate values.

3. **Error Handling**: During execution, the interpreter performs error checks, such as verifying the validity of instructions and handling stack underflow or division by zero errors. When an error occurs, it prints an error message and exits with a non-zero status.

4. **Output**: When executing pall or pint instructions, the interpreter prints the values on the stack or the value at the top of the stack, respectively. Output is directed to stdout.

5. **Memory Management**: The interpreter handles memory management for the stack, ensuring that memory is allocated and deallocated properly using malloc and free.

## Compilation & Output

### Compiling the Monty Interpreter

To compile the Monty interpreter, you can use the following gcc command:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
This command compiles all the C source files in your project and produces an executable named monty.

### Running Monty with Monty ByteCode Files

To use the Monty interpreter, you need to run it from the command line with a Monty ByteCode file as an argument. Here's the basic usage:
```
$ ./monty path/to/your/file.m
```
Replace path/to/your/file.m with the actual path to your Monty ByteCode file.

### Error Handling

* No File Argument Provided:
If the user doesn't provide a Monty ByteCode file as an argument, print the following error message:
```
USAGE: monty file
```

* Failed to Open File:
If, for any reason, the interpreter cannot open the specified Monty ByteCode file, print an error message like the following:
```
Error: Can't open file <file>
```

* Unknown Instruction:
If the interpreter encounters an invalid or unknown instruction in the Monty ByteCode file, it should print an error message with the line number and the unknown opcode. For example:
```
L<line_number>: unknown instruction <opcode>
```

* Memory Allocation Failure:
If the interpreter cannot allocate memory (e.g., using malloc) when needed, print the following error message:
```
Error: malloc failed
```

### Output

The Monty interpreter generates output as it executes Monty ByteCode files. The specific output depends on the instructions within the file. Commonly used opcodes include:

* **pall**: Prints all the values on the stack.
* **pint**: Prints the value at the top of the stack.

The output should be directed to stdout, and any error messages should be directed to stderr. This ensures that the output and errors can be easily separated when using command-line redirection.

## Monty Opcodes

* ### `push`

The opcode push pushes an element to the stack.

Usage:
```$ push <int>```

Example:
```
abdessamad@abdessamad:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
abdessamad@abdessamad::~/monty$ ./monty bytecodes/00.m
3
2
1
abdessamad@abdessamad:~/monty$
```

* ### `pall`

The opcode pall prints all the values on the stack, starting from the top of the stack.

Usage:
```$ pall```

Example:
```
abdessamad@abdessamad:~/monty$ cat -e bytecodes/01.m
push 0$
push 1$
push 2$
  push 3$
                   pall$

push 4$

    push 5$
      push    6$

pall$
abdessamad@abdessamad::~/monty$ ./monty bytecodes/01.m
3
2
1
0
6
5
4
3
2
1
0
abdessamad@abdessamad:~/monty$
```

* ### `pint`

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage:
```$ pint```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/02.m
push 1
pint
push 2
pint
push 3
pint
abdessamad@abdessamad::~/monty$ ./monty bytecodes/02.m
1
2
3
abdessamad@abdessamad:~/monty$
```

* ### `pop`

The opcode pop removes the top element of the stack.

Usage:
```$ pop```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/03.m
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
abdessamad@abdessamad::~/monty$ ./monty bytecodes/03.m
3
2
1
2
1
1
abdessamad@abdessamad:~/monty$
```

* ### `swap`

The opcode swap swaps the top two elements of the stack.

Usage:
```$ swap```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/04.m
push 1
push 2
push 3
pall
swap
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/04.m
3
2
1
2
3
1
abdessamad@abdessamad:~/monty$
```

* ### `add`

The opcode add adds the top two elements of the stack.

Usage:
```$ add```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/05.m
push 1
push 2
push 3
pall
add
pall

abdessamad@abdessamad::~/monty$ ./monty bytecodes/05.m
3
2
1
5
1
abdessamad@abdessamad:~/monty$
```

* ### `nop`

The opcode nop doesn’t do anything.

Usage:
```$ nop```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/06.m
push 1
nop
push 2
push 3
pint
nop
push 4
swap
pop
add
pall
nop
abdessamad@abdessamad::~/monty$ ./monty bytecodes/06.m
3
6
1
abdessamad@abdessamad:~/monty$
```

* ### `sub`

The opcode sub subtracts the top element of the stack from the second top element of the stack.

Usage:
```$ sub```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/07.m
push 1
push 2
push 10
push 3
sub
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/07.m
7
2
1
abdessamad@abdessamad:~/monty$
```

* ### `div`

The opcode div divides the second top element of the stack by the top element of the stack.

Usage:
```$ div```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/08.m
push 1
push 2
push 3
pint
nop
push 4
swap
pop
add
push 1
sub
push 2
div
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/08.m
3
2
1
abdessamad@abdessamad:~/monty$
```

* ### `mul`

The opcode mul multiplies the second top element of the stack with the top element of the stack.

Usage:
```$ mul```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/09.m
push 1
push 2
push 3
pint
nop
push 4
swap
pop
add
push 1
sub
push 2
div
push 12
mul
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/09.m
3
24
1
abdessamad@abdessamad:~/monty$
```

* ### `mul`

The opcode mul multiplies the second top element of the stack with the top element of the stack.

Usage:
```$ mul```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/10.m
push 1
push 2
push 3
pint
nop
push 4
swap
pop
add
push 1
sub
push 2
div
push 12
mul
push 9
mod
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/10.m
3
6
1
abdessamad@abdessamad:~/monty$
```

* ### `pchar`

The opcode pchar prints the char at the top of the stack, followed by a new line.

Usage:
```$ pchar```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/11.m
push 72
pchar
abdessamad@abdessamad::~/monty$ ./monty bytecodes/11.m
H
abdessamad@abdessamad:~/monty$
```

* ### `pstr`

The opcode pstr prints the string starting at the top of the stack, followed by a new line.

Usage:
```$ pstr```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/12.m
push 100
push 97
push 109
push 97
push 115
push 115
push 101
push 100
push 98
push 65
pstr
abdessamad@abdessamad::~/monty$ ./monty bytecodes/12.m
Abdessamad
abdessamad@abdessamad:~/monty$
```

* ### `rotl`

The opcode rotl rotates the stack to the top.

Usage:
```$ rotl```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/13.m
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/13.m
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
abdessamad@abdessamad:~/monty$
```

* ### `rotr`

The opcode rotr rotates the stack to the bottom.

Usage:
```$ rotr```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/14.m
push 1 This should not be taken into account
# Comment
push 2
push 3
       # Another comment
#
#Above is an empty comment
pint
nop
push 4
swap
pop
 # Another just below
      #
add
push 1
sub
push 2
div
push 12
mul
push 9
mod
push 0
push 65
pchar
push 66
push 67
push 68
pstr
rotl
push 87
rotr
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/14.m
3
A
DCBA
68
87
67
66
65
0
6
1
abdessamad@abdessamad:~/monty$
```

* ### `stack` and `queue`

The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

The opcode queue sets the format of the data to a queue (FIFO).


Usage:
```$ stack``` or ```$ queue```

Example:
```
abdessamad@abdessamad:~/monty$ cat bytecodes/15.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
abdessamad@abdessamad::~/monty$ ./monty bytecodes/15.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
abdessamad@abdessamad:~/monty$
```

## Acknowledgments

We would like to extend our heartfelt gratitude to the following individuals and organizations for their invaluable support, guidance, and resources throughout the development of this project:

- **ALX Africa** (ALX Software Engineering Program):
  - ALX Africa's rigorous software engineering program provided the foundational knowledge and skills that made this project possible. We are deeply thankful for the education and opportunities provided by ALX.

- **Holberton School**:
  - Holberton School deserves special recognition for their guidance and mentorship. Their commitment to nurturing technical talent has played a significant role in our growth as software engineers.

- **Stack Overflow**:
  - The Stack Overflow community has been a constant source of help and insights, especially when tackling complex memory-related errors. Their collective wisdom has been instrumental in overcoming challenges.

- **Inspiring Projects and Developers**:
  - We draw inspiration from countless open-source projects and the talented developers behind them. Their work has motivated us to strive for excellence in our own endeavors.

This project would not have been possible without the contributions and support of these individuals and institutions. Thank you for being an integral part of our journey.

### Authors

* **Abdessamad HADDOUCHE** <[4bd3ss4m4d](https://github.com/4bd3ss4m4d)>
* **Imrane ALI LAFKIH** <[imranelaf](https://github.com/imranelaf)>
