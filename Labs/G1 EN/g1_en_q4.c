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

int sum_of_nodes(struct node * head, int k){
    int sum = 0;
    while(head){
        if(!(head->data % k))
            sum += head->data;
        head = head->next;
    }
    return sum;
}
int product_of_nodes(struct node * head, int k){
    int prod = 1;
    while(head){
        if(!(head->data % k))
            prod *= head->data;
        head = head->next;
    }
    return prod;
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
    printf("sum = %d, prod = %d",sum_of_nodes(head,k),product_of_nodes(head,k));
    return 0;
}