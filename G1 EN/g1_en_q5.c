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

int second_min(struct node * head){
    if(!head || head->next == NULL)
        return -1; // no second minimum
    int min1 = head->data , min2 = INT_MAX;
    while(head){
        if(min1 > head->data){
            min2 = min1;
            min1 = head->data;
        }
        else if(min1 != head->data && min2 > head->data)
            min2 = head->data;
        head = head->next;
    }
    return min2;
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
    printf("\nsecond min = %d",second_min(head));
    return 0;
}