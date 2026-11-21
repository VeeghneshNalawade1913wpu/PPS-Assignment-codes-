#include <math.h>
#include <stdio.h>

#define LOG_FILE "navigation_log.csv"
#define OBSTACLE_DISTANCE_CM 20.0

int main(void)
{
    const char *directions[] = {"", "North", "East", "South", "West"};
    double distance;
    int x, y, direction;

    printf("Directions: 1=North, 2=East, 3=South, 4=West\n");
    printf("Enter distance (cm), obstacle X, obstacle Y, and direction: ");
    fflush(stdout);
    if (scanf("%lf %d %d %d", &distance, &x, &y, &direction) != 4 ||
        !isfinite(distance) || distance < 0 ||
        direction < 1 || direction > 4) {
        printf("Invalid input. Enter a distance, two coordinates, and a direction from 1 to 4.\n");
        return 1;
    }

   
    FILE *log = fopen(LOG_FILE, "a+");
    if (log == NULL) {
        printf("Could not open %s.\n", LOG_FILE);
        return 1;
    }

    int obstacle = distance <= OBSTACLE_DISTANCE_CM;
    int previous_count = 0;
    int blocked[5] = {0};
    double past_distance;
    int past_x, past_y, past_direction, past_obstacle;
    int fields_read;

    
    rewind(log);
    while ((fields_read = fscanf(log, "%lf,%d,%d,%d,%d", &past_distance,
                                 &past_x, &past_y, &past_direction,
                                 &past_obstacle)) == 5) {
        if (past_obstacle == 1 && past_x == x && past_y == y &&
            past_direction >= 1 && past_direction <= 4) {
            previous_count++;
            blocked[past_direction] = 1;
        }
    }
    if (fields_read != EOF || ferror(log)) {
        printf("Could not read %s.\n", LOG_FILE);
        fclose(log);
        return 1;
    }

   
    int written = fprintf(log, "%.17g,%d,%d,%d,%d\n", distance, x, y, direction, obstacle);
    int result = fclose(log);
    if (written < 0 || result == EOF) {
        printf("Could not save the reading to %s.\n", LOG_FILE);
        return 1;
    }

    if (!obstacle) {
        printf("Path clear. Continue %s.\n", directions[direction]);
        return 0;
    }

    printf("Obstacle at (%d, %d). Total detections: %d.\n",
           x, y, previous_count + 1);
    if (previous_count > 0) {
        printf("Repeated obstacle.\n");
    }

   
    int turns[] = {1, 3, 2};
    for (int i = 0; i < 3; i++) {
        int alternative = direction + turns[i];
        if (alternative > 4) {
            alternative = alternative - 4;
        }
        if (!blocked[alternative]) {
            printf("Suggested direction: %s. Check that the path is clear.\n",
                   directions[alternative]);
            return 0;
        }
    }
    printf("All alternative directions were blocked here before. Stop and rescan.\n");
    return 0;
}
