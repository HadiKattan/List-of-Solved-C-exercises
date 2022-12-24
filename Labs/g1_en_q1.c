#include <stdio.h>
#include <stdlib.h>

struct node{
int  data ; 
struct node * next;
};
void append(struct node ** head, char data){
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node * tmp = *head;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
}

void modify_list(struct node * head){
    int c = 0;
    while(head){
        c += head->data;
        head->data = c;
        head = head->next;
    }
}
void print_list(struct node * head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}
int main(){
    struct node * head = NULL;
    append(&head,1);
    append(&head,3);
    append(&head,5);
    append(&head,6);
    append(&head,4);
    append(&head,8);
    append(&head,9);
    append(&head,8);
    modify_list(head);
    print_list(head);
    return 0;
}
