#include<stdio.h>
int main(){
   int r,c,i,j;

   printf("Enter rows and columns:");
   scanf("%d %d" , &r ,&c);
   
   int A[r][c] , B[r][c] , Sum[r][c];

   printf("Enter elements for Matrix A");
   for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        scanf("%d", &A[i][j]);       
      }
   }

    printf("\nMatrix A=\n");
    for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        printf("%d", A[i][j]);       
      }
    printf("\n");
   }
    
   printf("Enter elements for Matrix B");
   for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        scanf("%d", &B[i][j]);       
      }
   }

   printf("\nMatrix B=\n");
    for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        printf("%d", B[i][j]);       
      }
    printf("\n");
   }

   for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        Sum[i][j]= A[i][j]+B[i][j];      
    }
   }

   printf("\nSum of Matrix A and B\n");
   for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        printf("%d", Sum[i][j]);       
      }
      printf("\n");
   }
   return 0;
}