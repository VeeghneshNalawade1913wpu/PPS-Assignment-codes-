

#include <stdio.h>

struct Wheel
{
    int id, defect, status;
    float original, current, wear, temperature, vibration;
    float reduction, percent;
};

struct Track
{
    int id, defect, status;
    float deformation;
};


void printWheel(struct Wheel w, char status[])
{
    printf("\n----------------------------------------------------\n");
    printf("WHEEL %d\n", w.id);
    printf("Status               : %s\n", status);
    printf("Original diameter    : %.2f mm\n", w.original);
    printf("Current diameter     : %.2f mm\n", w.current);
    printf("Diameter reduction   : %.2f mm\n", w.reduction);
    printf("Diameter-based wear  : %.2f%%\n", w.percent);
    printf("Measured wheel wear  : %.2f mm\n", w.wear);
    printf("Axle temperature     : %.2f C\n", w.temperature);
    printf("Vibration            : %.2f mm/s\n", w.vibration);
    if (w.defect == 1)
        printf("Ultrasonic defect    : Detected\n");
    else
        printf("Ultrasonic defect    : None\n");
    if (w.temperature >= 80)
        printf("ALERT: Axle temperature is above the normal range.\n");
    if (w.vibration >= 4.5f)
        printf("ALERT: Vibration is above the normal range.\n");
}

int main(void)
{
    struct Wheel w[50];
    struct Track t[50];
    char status[3][25] = {"Acceptable", "Maintenance Required", "Critical"};
    int nw, nt, i, j, id, found, level, maximum = 0;
    int wheelCount = 0, trackCount = 0;

    printf("\n====================================================\n");
    printf("     SMART RAILWAY INSPECTION SYSTEM\n");
    printf("Group 6, Batch 3\n");
    printf("Classroom demo: inspection limits are assumed.\n");
    printf("====================================================\n");
    printf("Enter one number at each prompt.\n");

    printf("Enter number of wheel assemblies (0-50): ");
    if (scanf("%d", &nw) != 1 || nw < 0 || nw > 50)
    {
        printf("Invalid wheel count.\n");
        return 1;
    }

    for (i = 0; i < nw; i++)
    {
        printf("\n--- Wheel %d of %d ---\n", i + 1, nw);
        printf("\nWheel ID                : ");
        if (scanf("%d", &w[i].id) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nOriginal diameter (mm)  : ");
        if (scanf("%f", &w[i].original) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nCurrent diameter (mm)   : ");
        if (scanf("%f", &w[i].current) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nMeasured wear (mm)      : ");
        if (scanf("%f", &w[i].wear) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nAxle temperature (C)    : ");
        if (scanf("%f", &w[i].temperature) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nVibration (mm/s)        : ");
        if (scanf("%f", &w[i].vibration) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nDefect (0=no, 1=yes)    : ");
        if (scanf("%d", &w[i].defect) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        if (w[i].id <= 0 || !(w[i].original > 0 && w[i].original <= 2000 &&
            w[i].current > 0 && w[i].current <= w[i].original &&
            w[i].wear >= 0 && w[i].wear <= 100 &&
            w[i].temperature >= -50 && w[i].temperature <= 300 &&
            w[i].vibration >= 0 && w[i].vibration <= 100) ||
            (w[i].defect != 0 && w[i].defect != 1))
        {
            printf("Invalid wheel readings.\n");
            return 1;
        }
        for (j = 0; j < i; j++)
            if (w[i].id == w[j].id)
            {
                printf("Duplicate wheel ID.\n");
                return 1;
            }

       
        w[i].reduction = w[i].original - w[i].current;
        w[i].percent = w[i].reduction / w[i].original * 100;
        if (w[i].percent >= 5 || w[i].wear >= 6 ||
            w[i].temperature >= 100 || w[i].vibration >= 7.1f || w[i].defect == 1)
            w[i].status = 2;
        else if (w[i].percent >= 2 || w[i].wear >= 3 ||
                 w[i].temperature >= 80 || w[i].vibration >= 4.5f)
            w[i].status = 1;
        else
            w[i].status = 0;

        if (w[i].status != 0)
            wheelCount++;
    }

    
    printf("\nEnter number of track sections (0-50): ");
    if (scanf("%d", &nt) != 1 || nt < 0 || nt > 50)
    {
        printf("Invalid track count.\n");
        return 1;
    }
    for (i = 0; i < nt; i++)
    {
        printf("\n--- Track %d of %d ---\n", i + 1, nt);
        printf("\nTrack ID                : ");
        if (scanf("%d", &t[i].id) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nDeformation (mm)        : ");
        if (scanf("%f", &t[i].deformation) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        printf("\nDefect (0=no, 1=yes)    : ");
        if (scanf("%d", &t[i].defect) != 1)
        {
            printf("Please restart and enter numeric values.\n");
            return 1;
        }
        if (t[i].id <= 0 || !(t[i].deformation >= 0 && t[i].deformation <= 100) ||
            (t[i].defect != 0 && t[i].defect != 1))
        {
            printf("Invalid track readings.\n");
            return 1;
        }
        for (j = 0; j < i; j++)
            if (t[i].id == t[j].id)
            {
                printf("Duplicate track ID.\n");
                return 1;
            }
        if (t[i].deformation >= 10 || t[i].defect == 1)
            t[i].status = 2;
        else if (t[i].deformation >= 5)
            t[i].status = 1;
        else
            t[i].status = 0;
        if (t[i].status != 0)
            trackCount++;
        if (t[i].deformation > t[maximum].deformation)
            maximum = i;
    }

    printf("\n================ WHEEL REPORT ================\n");
    if (nw == 0)
        printf("No wheel assemblies entered.\n");
    for (i = 0; i < nw; i++)
        printWheel(w[i], status[w[i].status]);

    printf("\n================ TRACK REPORT ================\n");
    for (i = 0; i < nt; i++)
    {
        printf("\nTRACK %d\n", t[i].id);
        printf("Status               : %s\n", status[t[i].status]);
        printf("Deformation          : %.2f mm\n", t[i].deformation);
        if (t[i].defect == 1)
            printf("Ultrasonic defect    : Detected\n");
        else
            printf("Ultrasonic defect    : None\n");
    }
    if (nt > 0)
    {
        printf("\nMaximum deformation  : %.2f mm\n", t[maximum].deformation);
        printf("Track ID(s)          :");
        for (i = 0; i < nt; i++)
            if (t[i].deformation == t[maximum].deformation)
                printf(" %d", t[i].id);
        printf("\n");
    }
    else
        printf("No track sections entered.\n");

    printf("\n============= INSPECTION SUMMARY =============\n");
    printf("Wheels to inspect    : %d\n", wheelCount);
    printf("Tracks to inspect    : %d\n", trackCount);
    printf("TOTAL TO INSPECT     : %d\n", wheelCount + trackCount);

    
    printf("\n================ WHEEL SEARCH ================\n");
    printf("Enter wheel ID: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid search ID.\n");
        return 1;
    }
    found = 0;
    for (i = 0; i < nw; i++)
        if (w[i].id == id)
        {
            printWheel(w[i], status[w[i].status]);
            found = 1;
            break;
        }
    if (found == 0)
        printf("Wheel ID not found.\n");

    printf("\n========= MAINTENANCE PRIORITY REPORT =========\n");
    for (level = 2; level >= 1; level--)
    {
        printf("\nPriority %d: %s\n", 3 - level, status[level]);
        found = 0;
        for (i = 0; i < nw; i++)
            if (w[i].status == level)
            {
                printf("  Wheel %d\n", w[i].id);
                found = 1;
            }
        for (i = 0; i < nt; i++)
            if (t[i].status == level)
            {
                printf("  Track %d\n", t[i].id);
                found = 1;
            }
        if (found == 0)
            printf("  None\n");
    }
    printf("\nInspection report complete.\n");
    return 0;
}
