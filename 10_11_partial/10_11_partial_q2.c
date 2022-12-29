#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
struct node{ 
    char c;
    struct node* next; 
};
void Push(struct node ** headRef, int data){
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->c = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
    
}
void Pop(struct node ** head){
    if(!*head)
    return ;
    struct node * tmp = *head;
    *head = (*head)->next;
    free(tmp);
}
void del1over2(struct node **head){
    if(*head)
    Pop(head);
    struct node * tmp = (*head);
    while(tmp && tmp->next){
        Pop(&(tmp->next));
        tmp = tmp->next;
    }
}

void insertB4(struct node **head, char c1, char c2){
    if(*head && (*head)->c == c1){
        Push(head,c2);
        return ;
    }
    struct node * tmp = *head;
    while(tmp && tmp->next){
        if(tmp->next->c == c1){
        Push(&(tmp->next),c2);
        return;
        }
        tmp = tmp->next;
    }
}
void print_list(struct node * head){
    while(head){
        printf("%c ",head->c);
        head = head->next;
    }
}
int main(){
    struct node * head = NULL;
    Push(&head,'f');
    Push(&head,'y');
    Push(&head,'a');
    Push(&head,'u');
    Push(&head,'k');
    Push(&head,'c');
    del1over2(&head);
    insertB4(&head,'a','t');
    print_list(head);
    return 0;
}