/**
BS-AI 
MAMOON AHMED 26K-0003
ASSIGNMENT 02 --------> QUESTION 1
*/
#include <stdio.h>

int main()
{
    int seats[100][100];
    int rows, column, i, j, k;
    int total = 0, available;
    int middle, distance, current_row;
    int count, start = -1;
    int found = 0, booked_row = -1;

    printf("Enter number of rows and seats in each row: ");
    scanf("%d %d", &rows, &column);

    if (rows <= 0 || rows > 100 || column <= 0 || column > 100)
    {
        printf("Invalid dimensions!\n");
        return 0;
    }

    printf("\nEnter seat status for each row:\n");
    printf("0 = Available, 1 = Booked\n");

    for (i = 0; i < rows; i++)
    {
        printf("Row %d: ", i);

        for (j = 0; j < column; j++)
        {
            scanf("%1d", &seats[i][j]);

            while (seats[i][j] != 0 && seats[i][j] != 1)
            {
                printf("Enter 0 or 1: ");
                scanf("%1d", &seats[i][j]);
            }

            if (seats[i][j] == 0)
                total++;

            if (j > 0)
                printf("|");

            printf("%d", seats[i][j]);
        }

        printf("\n");
    }

    // Display seating arrangement
    printf("\nSeating Arrangement:\n");

    for (i = 0; i < rows; i++)
    {
        printf("Row %d: ", i);

        for (j = 0; j < column; j++)
        {
            if (seats[i][j] == 0)
                printf("_");
            else
                printf("X");

            if (j < column - 1)
                printf("|");
        }

        printf("\n");
    }

    // Available seats in each row
    printf("\nAvailable Seats Report:\n");

    for (i = 0; i < rows; i++)
    {
        available = 0;

        for (j = 0; j < column; j++)
        {
            if (seats[i][j] == 0)
                available++;
        }

        printf("Row %d: %d available seats\n", i, available);
    }

    printf("Total available seats: %d\n", total);

    // Input group size
    printf("\nEnter number of customers: ");
    scanf("%d", &k);

    while (k <= 0 || k > column)
    {
        printf("Enter group size from 1 to %d: ", column);
        scanf("%d", &k);
    }

    // Search from the middle row outwards
    middle = rows / 2;

    for (distance = 0; distance < rows && found == 0; distance++)
    {
        // Check the smaller row number first
        current_row = middle - distance;

        if (current_row >= 0)
        {
            count = 0;

            for (j = 0; j < column; j++)
            {
                if (seats[current_row][j] == 0)
                    count++;
                else
                    count = 0;

                if (count == k)
                {
                    start = j - k + 1;
                    booked_row = current_row;
                    found = 1;
                    break;
                }
            }
        }

        // Check the larger row number
        current_row = middle + distance;

        if (distance > 0 && current_row < rows && found == 0)
        {
            count = 0;

            for (j = 0; j < column; j++)
            {
                if (seats[current_row][j] == 0)
                    count++;
                else
                    count = 0;

                if (count == k)
                {
                    start = j - k + 1;
                    booked_row = current_row;
                    found = 1;
                    break;
                }
            }
        }
    }

    // Book seats if a suitable block is found
    if (found == 1)
    {
        printf("\nBooking Successful!\n");
        printf("Allocated row: %d\n", booked_row);
        printf("Allocated seats: ");

        for (j = start; j < start + k; j++)
        {
            printf("%d ", j);
            seats[booked_row][j] = 1;
        }

        total = total - k;

        // Display updated seating arrangement
        printf("\n\nUpdated Seating Arrangement:\n");

        for (i = 0; i < rows; i++)
        {
            printf("Row %d: ", i);

            for (j = 0; j < column; j++)
            {
                if (seats[i][j] == 0)
                    printf("_");
                else
                    printf("X");

                if (j < column - 1)
                    printf("|");
            }

            printf("\n");
        }

        printf("Remaining available seats: %d\n", total);
    }
    else
    {
        printf("\nBooking Unsuccessful!\n");
        printf("No consecutive available seats found.\n");
        printf("The seating arrangement remains unchanged.\n");
    }

    return 0;
}

