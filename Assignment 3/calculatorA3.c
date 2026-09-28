#include<stdio.h>
int main(){
    int a,b,choice,result;
    printf("Enter 2 Numbers:");
    scanf("%d %d", &a, &b);
    printf("Enter: 1 for addition\n 2 for subtraction\n 3 for multiplication\n4 for division\n 5 for modulus\n");
    scanf("%d" , &choice);
    switch(choice){
        case 1: result=a+b;
                printf("Addition = %d" , result);
                break;
        case 2: result=a-b;
                printf("Subtraction = %d" , result);
                break;
        case 3: result=a*b;
                printf("Multiplication= %d ", result);
                break;
        case 4: result=a/b;
                printf("Division= %d", result);
                break;
        case 5: result=a%b;
                printf("Modulus= %d", result);
                break;
        default:printf("Invalid");
    }
  return 0;
}