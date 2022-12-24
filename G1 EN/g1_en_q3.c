#include <stdio.h>
#include <stdlib.h>

struct node{
int  data ; 
struct node * next;
};
void Push(struct node ** headRef, int data){
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = *headRef;
    *headRef = newNode;
}
void print_list(struct node * head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}
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
struct node * splice(struct node * l1, struct node* l2, int k){
    struct node * newList = (struct node*)malloc(sizeof(struct node));
    newList = NULL;
    if(!l1)
        newList = l2;
    else if(!l2){
        newList = l1;
    }
    else{
        int index = 0;
        while(l1 && index < k){
            append(&newList,l1->data);
            index++;
            l1 = l1->next;
        }
        while(l2){
            append(&newList,l2->data);
            l2 = l2->next;
        }
        while(l1){
            append(&newList,l1->data);
            l1 = l1->next;
        }
    }
    return newList;
}
int main(){
    struct node * head = NULL;
    int n;
    do {
        printf("enter a non-negative integer:\n");
        scanf("%d",&n);
    }while(n < 0);
    while(n){
        Push(&head,n%10);
        n/=10;
    }
    print_list(head);
    int k;
    printf("\nenter a number k:\n");
    scanf("%d",&k);
    struct node * l2 = NULL;
    append(&l2,1);
    append(&l2,3);
    append(&l2,5);
    struct node * res = splice(head,l2,3);
    print_list(res);
    return 0;
}