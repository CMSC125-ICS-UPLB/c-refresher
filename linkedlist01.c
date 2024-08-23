#include <stdio.h>
#include <stdlib.h>


struct node {
 
 int data;
   struct node *next;
};


void print_list(struct node *head){
   struct node *tmp=head;
   while (tmp != NULL){
      printf("%d ",tmp->data);
      tmp = tmp->next;
   }
}


void insert_at_head(struct node **head, struct node *node){
   node->next = *head;
   *head = node;
}

int main(){

   struct node *n1 = (struct node *)malloc(sizeof(struct node));
   struct node *n2 = (struct node *)malloc(sizeof(struct node));
   struct node *n3 = (struct node *)malloc(sizeof(struct node));
   struct node *n4 = (struct node *)malloc(sizeof(struct node));

   struct node *head;

   n1->data = 1;
   n1->next = n2;

   n2->data = 2;
   n2->next = n3;

   n3->data = 3;
   n3->next = NULL;


   head = n1;

   print_list(head);


   n4->data = 4;
   n4->next = NULL;

   insert_at_head(&head,n4);
   print_list(head);



   free(n1);
   free(n2);
   free(n3);

   return 0;

}

