#include <stdio.h>

struct Robot
{
    int id;
    char type[30];
    float capacity, load, time;
};

int main(void)
{
    struct Robot r[100];
    int n, i;
    float utilization;

    printf("Enter the number of robots: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter ID, type, capacity, load and time:\n");
        scanf("%d %29s %f %f %f", &r[i].id, r[i].type,
              &r[i].capacity, &r[i].load, &r[i].time);
    }

    printf("\n%-4s %-15s %8s %7s %6s %8s  %s\n",
           "ID", "Type", "Capacity", "Load", "Time",
           "Util.(%)", "Status");

    for (i = 0; i < n; i++)
    {
        utilization = (r[i].load / r[i].capacity) * 100;

        printf("%-4d %-15s %8.2f %7.2f %6.2f %8.2f  ",
               r[i].id, r[i].type, r[i].capacity,
               r[i].load, r[i].time, utilization);

        if (r[i].load > r[i].capacity)
            printf("Overloaded\n");
        else
            printf("Within Limit\n");
    }

    return 0;
}