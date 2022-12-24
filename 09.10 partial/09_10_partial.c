#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

struct node{char data ; struct node * next;};
struct Point {
    float x,y;
};
struct Circle {
    float radius;
    struct Point p;
};

int is_inside(struct Circle c1, struct Circle c2){
    // check if c1 is inside c2
    float r2 = c2.radius;
    float distance = sqrt(pow(c1.p.x-c2.p.x,2) +  pow(c1.p.y-c2.p.y,2));
    // printf("%f",(r2 - (distance + c1.radius)));
    if ((r2 - (distance + c1.radius)) >= 0)
        return 1;
    return 0;
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
struct node* concat(struct node * head1,struct node * head2){
    
    struct node * tmp = head1;
    struct node * newList = (struct node *)malloc(sizeof(struct node));
    while(tmp){
        append(&newList,tmp->data);
        tmp = tmp->next;
    }
    tmp = head2;
    while(tmp){
        append(&newList,tmp->data);
        tmp = tmp->next;
    }
    return newList;
}
int main(){
    struct Circle c1,c2;
    c1.p.x = 0.0; c1.p.y = 0.0;
    c1.radius = 5.0;
    c2.p.x = 0.0; c2.p.y = 0.0;
    c2.radius = 5.0;
    printf("is inside ? %d",is_inside(c2,c1));

    struct node * head1 =NULL,*head2=NULL;
    append(&head1,'a');
    // append(&head1,'b');
    append(&head2,'c');
    struct node * newList = concat(head1,head2);
    while(head1){
        printf("%c ",head1->data);
        head1 = head1->next;
    }
    return 0;
}