#include <stdio.h>
#include <stdlib.h>


struct node {
 
 int data;
   struct node *next;
};


void print_list(struct node *p){
   struct node *tmp=p;
   while (tmp != NULL){
      printf("%d ",tmp->data);
      tmp = tmp->next;
   }
}

int main(){

   struct node *n1 = (struct node *)malloc(sizeof(struct node));
   struct node *n2 = (struct node *)malloc(sizeof(struct node));
   struct node *n3 = (struct node *)malloc(sizeof(struct node));

   struct node *head;

   n1->data = 1;
   n1->next = n2;

   n2->data = 2;
   n2->next = n3;

   n3->data = 3;
   n3->next = NULL;


   head = n1;

   print_list(head);

   free(n1);
   free(n2);
   free(n3);

   return 0;

}

