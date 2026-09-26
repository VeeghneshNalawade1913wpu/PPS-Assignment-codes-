#include<stdio.h>
int main(){
    int choice;
    do{
        printf("\n1. Say Hello\n2. Exit");
        scanf("%d",&choice);
        if (choice==1)
           printf("Hello\n");
    }while(choice!=2);
    return 0;
}