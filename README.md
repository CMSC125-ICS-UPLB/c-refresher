# C Refresher for CMSC 125 (Work-in-Progress)

This document discusses some topics in C programming, data structures, and machine organization that you will 
need for CMSC 125. We assume that you know the basics of C and you know how to build 
C programs using GCC in a linux environment. 

Please read first 7etsuo's [C Programming Reference](https://x.com/7etsuo/article/1822539624398614681) article hosted on X. A wget'ed copy is availabe [here](https://github.com/CMSC125-ICS-UPLB/c-refresher/tree/main/7etsuo-c-reference). 

Other topics not covered in 7etsuo's article will be discussed below.

# Table of Contents

1. [Hexadecimal Notation](#hexadecimal-notation)
1. [Bitwise Operators](#bitwise-operators)
1. [Files](#files)
1. [Linked Lists](#linked-lists)

## Hexadecimal Notation

Hexadecimal notation is often used in presenting memory addresses and binary data. 
It uses the following symbols (16 in total) to represent 
a number: `0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F` . To indicate that a number is in hexadecimal it is usually prepended with `0x`. For example: `0x00001000` is a 32-bit number equivalent to `4096` in decimal and `0000 0000 0000 0000 0001 0000 0000 0000` in binary. Each digit in hex notation represent four bits.

```C
//hex.c
#include <stdio.h>
unsigned int s = 0xABF5; //1010 1011 1111 0101  in binary
int main(){
    printf("%u %X\n",s,s);
}
```

## Bitwise Operators

## Functions

## Arrays

## Pointers

## Strings

## Files

## Structures

## Linked Lists








