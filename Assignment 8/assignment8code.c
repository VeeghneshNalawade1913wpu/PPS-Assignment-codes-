#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int m1, m2;
    printf("Enter speed of motor 1 and 2: ");
    if (scanf("%d %d", &m1, &m2) != 2) {
        fprintf(stderr, "Please enter two integers.\n");
        return 1;
    }

    int *ptr1 = &m1;
    int *ptr2 = &m2;

    printf("Before swapping\n");
    printf("Motor 1 speed and address: %d %p\n", *ptr1, (void *)ptr1);
    printf("Motor 2 speed and address: %d %p\n", *ptr2, (void *)ptr2);

    swap(ptr1, ptr2);

    printf("After swapping\n");
    printf("Motor 1 speed and address: %d %p\n", *ptr1, (void *)ptr1);
    printf("Motor 2 speed and address: %d %p\n", *ptr2, (void *)ptr2);

    return 0;
}
