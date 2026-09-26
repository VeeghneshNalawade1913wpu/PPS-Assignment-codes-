#include<stdio.h>
int main(){
    int n , fact=1 , i=1;
    printf("Enter n");
    scanf("%d", &n);
    while(i<=n){
        fact=fact*i;
        i++;
    }
    printf("Factorial of n numbers = %d",  fact);
 return 0;
}