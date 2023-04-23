# Programming Project 2

### Start
At the beginning of the main function, I create a map called `OPERATORS`, mapping the operation names to functions that will evaluate the operands. 

The file `operators.h` includes all of the functions that are referenced in the map. 
### Getting text input 
To get the text input, I use `fstream`. Then, I loop through each line of the input text, assigning the values on each line to the varibles `operation`, `operand1`, and `operand2`. When reading the values into the `ifstream`, I use the hex modifier to turn them into decimal numbers. 

### Functions
In the loop that gets each of the values, I send each operand to the function returned from the OPERATORS map.

Each of the following functions returns `uint32_t` and takes in two `uint32_t`s.
#### ADD
The add function returns the two numbers added together.
#### AND
The and function uses the bitwise operator `&` on the two operands. 
#### SUB
The sub function returns the first operand minus the second operand.
#### ORR
The orr function returns the first operand or-ed with the second, using the bitwise operator `|`.
#### XOR
The xor function uses the bitwise operator `^`.
#### LSL
The lsl function uses the bitwise left shift operator `<<`.
#### ASR
The asr function uses the bitwise right sift operator `>>` with a signed int. 
#### LSR
The lsr function uses the bitwise right shift operator `>>` an unsigned int.

#### NOT
The not function returns only the first operand notted with bitwise operator `~`.

## Updating the flags

To update the zero flag, I check if the length of the operation string is of length 4 and if the ouput is 0. If it is, I set Z equal to 1. Otherwise it says 0.

To update the zero flag, I cast the output to a signed int `int32_t`. Next, I check if the operation string is of length 4 and if the signed output is greater than 0. If both of these are true, then I set N equal to 1. Otherwise it stays 0.# CS219-PA3
