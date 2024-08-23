# C Refresher for CMSC 125 (Work-in-Progress)

This document discusses some topics in C programming, data structures, and machine organization that you will 
need for CMSC 125. We assume that you know the basics of C and you know how to build 
C programs using GCC in a linux environment. 

Please read first 7etsuo's [C Programming Reference](https://x.com/7etsuo/article/1822539624398614681) article hosted on X. A wget'ed copy is availabe [here](https://github.com/CMSC125-ICS-UPLB/c-refresher/tree/main/7etsuo-c-reference) in case the article is pulled out in the future. The article contents are what we need in CMSC 125. 

Other topics not covered in 7etsuo's article will be discussed here.

# Table of Contents

1. [Hexadecimal Notation](#hexadecimal-notation)
1. [Bitwise Operators](#bitwise-operators)
1. [Functions](#functions)
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

## Files

## Linked Lists

Linked Lists are dynamic data structures that use pointers that links the nodes together.
A simple node definition is shown below. 
```C
struct node {
   int data; /*data*/
   struct node *next;  /* pointer to the next node */
};

```

A common operation is to print the contents of a linked list. The function below demontrates this.

```C
void print_list(struct node *p){
   struct node *tmp=p;
   while (tmp != NULL){
      printf("%d ",tmp->data);
      tmp = tmp->next;
   }
}
```

Memory for nodes are allocated using malloc(). The code below creates three nodes, links them together, then prints the list.

```C

   /* Create the nodes and save the pointers */
   struct node *n1 = (struct node *)malloc(sizeof(struct node));
   struct node *n2 = (struct node *)malloc(sizeof(struct node));
   struct node *n3 = (struct node *)malloc(sizeof(struct node));

   /* pointer to the start of the list */
   struct node *head;

   n1->data = 1;
   n1->next = n2;

   n2->data = 2;
   n2->next = n3;

   n3->data = 3;
   n3->next = NULL;    /* next field of the last node is set to NULL */

   /* set the start of the head of the list to node 1 */
   head = n1;

   print_list(head);

```

One operation on linked lists is to add a node at the head of the list. The following function shows this. The function assumes a non-empty list and a node has been allocated. Observe the head is a pointer to a pointer. This is needed for the changes to take effect after the call.

```C

struct node *n4 = (struct node *)malloc(sizeof(struct node));

...

void insert_at_head(struct node **head, struct node *node){
   node->next = *head;
   *head = node;
}

...

n4->data = 4;
n4->next = NULL;

/* note that we pass the address of head during the call*/
insert_at_head(&head,n4);
print_list(head);


```

Another operation on linked list is searching. The code below shows a search function. It returns 1 if the data is found, 0 if not.

```C
int search(struct node *head, int data){
   struct node *tmp=head;
   while (tmp != NULL) {
      if (tmp->data == data)
         return 1;
      tmp = tmp->next;
   }
   return 0;
}

...

if (search(head,3)){
   printf("found");
}else{
   printf("not found");
}

/* will print 'not found' since 5 is not in the list */
if (search(head,5)){
   printf("found");
}else{
   printf("not found");
}

```


The last common operation is deleting a node. The code below searches for the data of it exists then deletes the node.

```C
void delete(struct node **head, int data){
   struct node *target=*head;
   struct node *prev;

   while (target != NULL) {
      if (target->data != data){
         prev=target;
         target=target->next;
      }else if (target->data == data){
         if (target == *head)
            *head = target->next;
         else
            prev->next=target->next;
         free(target);
         break;
      }
   }
}


...

delete(&head, 2);
print_list(head);


```


Source Code: [linkedlist01.c](./linkedlist01.c)



