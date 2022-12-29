#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
struct student{
    char name[20]; 
    int grade;
};

void stat(struct student stds[], int size){
    int i;
    int nb = 0, sum = 0;
    for(i=0;i<size;i++){
        sum += stds[i].grade;
        nb++;
    }
    float avg = (float)sum/nb;
    printf("class avg is : %f\n",avg);
    for(i=0;i<size;i++){
        if(stds[i].grade >= avg)
            printf("%s, %d\n",stds[i].name,stds[i].grade);
    }
}
int main(){
    struct student s1 = {"Sisi",90};
    struct student s2 = {"fifi",23};
    struct student s3 = {"kiki",45};
    struct student s4 = {"mimi",66};
    struct student s5 = {"riri",33};
    struct student s6 = {"lili",70};
    struct student stds[] = {s1,s2,s3,s4,s5,s6};
    stat(stds,6);
    return 0;
}