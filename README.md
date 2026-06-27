# Arbitrary Precision Calculator (APC)

An Arbitrary Precision Calculator implemented in **C** using a **Doubly Linked List (DLL)**. The project performs arithmetic operations on integers of virtually unlimited size without relying on built-in integer data types.

## Features

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`) using repeated subtraction
- Supports numbers much larger than `int` or `long long`
- One digit is stored in each linked list node
- Dynamic memory allocation
- Input validation
- Handles negative results in subtraction
- Division by zero detection

## Project Structure

```
APC/
│── main.c
│── apc.h
│── dll.c
│── helper.c
│── validation.c
│── addition.c
│── subtraction.c
│── multiplication.c
│── division.c
└── README.md
```

## Data Structure

The project uses a **Doubly Linked List**.

Each node stores a single decimal digit.

```c
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;
```

Example:

```
12345

↓

1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5
```

## Build

Using Makefile:

```bash
make
```

Or manually:

```bash
gcc main.c dll.c validation.c helper.c addition.c subtraction.c multiplication.c division.c -o apc
```

## Usage

```bash
./apc <number1> <operator> <number2>
```

### Examples

Addition

```bash
./apc 12345 '+' 67890
```

Output

```
Result : 80235
```

Subtraction

```bash
./apc 123 '-' 456
```

Output

```
Result : -333
```

Multiplication

```bash
./apc 123 '*' 456
```

Output

```
Result : 56088
```

Division

```bash
./apc 100 '/' 3
```

Output

```
Result : 33
```

## Algorithm Overview

### Addition

- Traverse both lists from the tail
- Add digits with carry
- Insert each result digit at the front of the result list

### Subtraction

- Compare both numbers
- Swap operands if required
- Perform subtraction using borrow
- Remove leading zeros

### Multiplication

- Paper multiplication algorithm
- Multiply each digit individually
- Store intermediate results
- Add intermediate products using the addition function

### Division

- Implemented using repeated subtraction
- Continue subtracting until the dividend becomes smaller than the divisor
- Quotient is maintained as a linked list

## Time Complexity

| Operation | Complexity |
|----------|------------|
| Addition | O(n) |
| Subtraction | O(n) |
| Multiplication | O(n²) |
| Division | Depends on quotient (Repeated Subtraction) |

## Limitations

- Supports only non-negative integer inputs
- Division uses repeated subtraction, making it slow for very large quotients
- Floating-point numbers are not supported
- No expression evaluation (e.g., `(10+20)*5`)

## Future Improvements

- Faster division algorithm
- Support for floating-point numbers
- Support for negative input values
- Modulus (%) operation
- Exponentiation
- GUI-based calculator
- Expression parsing with operator precedence

## Concepts Used

- C Programming
- Doubly Linked List
- Dynamic Memory Allocation
- Pointers
- Command Line Arguments
- Modular Programming
- Memory Management

## Author

**Priyavardhan Musku**

Embedded Systems | C Programming | Data Structures
