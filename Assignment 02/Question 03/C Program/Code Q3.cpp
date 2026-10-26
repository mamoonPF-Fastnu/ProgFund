
#include <stdio.h>

#define MAX 100

// Function 1: Input temperature readings
void inputReadings(double temp[MAX][MAX], int sensors, int hours)
{
    int i, j;

    for (i = 0; i < sensors; i++)
    {
        printf("\nEnter temperatures for Sensor %d:\n", i + 1);

        for (j = 0; j < hours; j++)
        {
            printf("Hour %d: ", j + 1);
            scanf("%lf", &temp[i][j]);
        }
    }
}

// Function 2: Analyze one sensor and return its average
double analyzeSensor(double readings[], int hours, int sensorNumber)
{
    int i;
    int critical = 0, warning = 0;
    int streak = 0, longestStreak = 0;

    double total = 0;
    double average, highest, lowest;

    highest = readings[0];
    lowest = readings[0];

    for (i = 0; i < hours; i++)
    {
        total = total + readings[i];

        if (readings[i] > highest)
            highest = readings[i];

        if (readings[i] < lowest)
            lowest = readings[i];

        if (readings[i] >= 40)
            critical++;

        if (readings[i] >= 35 && readings[i] < 40)
            warning++;

        if (readings[i] >= 35)
        {
            streak++;

            if (streak > longestStreak)
                longestStreak = streak;
        }
        else
        {
            streak = 0;
        }
    }

    average = total / hours;

    printf("\n--- Sensor %d Report ---\n", sensorNumber);
    printf("Total temperature: %.2f\n", total);
    printf("Average temperature: %.2f C\n", average);
    printf("Highest temperature: %.2f C\n", highest);
    printf("Lowest temperature: %.2f C\n", lowest);
    printf("Critical readings: %d\n", critical);
    printf("Warning readings: %d\n", warning);
    printf("Longest streak: %d hours\n", longestStreak);

    return average;
}

// Function 3: Find the sensor with the highest average
int highestAverageSensor(double averages[], int sensors)
{
    int i;
    int best = 0;

    for (i = 1; i < sensors; i++)
    {
        if (averages[i] > averages[best])
            best = i;
    }

    return best + 1;
}

int main()
{
    double temp[MAX][MAX];
    double averages[MAX];

    int sensors, hours;
    int i, bestSensor;

    printf("Enter number of sensors (1-100): ");
    scanf("%d", &sensors);

    printf("Enter number of hourly readings (1-100): ");
    scanf("%d", &hours);

    if (sensors < 1 || sensors > MAX ||
        hours < 1 || hours > MAX)
    {
        printf("Invalid input!\n");
        return 0;
    }

    inputReadings(temp, sensors, hours);

    for (i = 0; i < sensors; i++)
    {
        averages[i] = analyzeSensor(temp[i], hours, i + 1);
    }

    bestSensor = highestAverageSensor(averages, sensors);

    printf("\n--- Final Report ---\n");
    printf("Sensor with highest average: Sensor %d\n", bestSensor);
    printf("Highest average temperature: %.2f C\n",
           averages[bestSensor - 1]);

    return 0;
}

