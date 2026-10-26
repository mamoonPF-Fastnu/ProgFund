
#include <stdio.h>

// Function 1: Input and validate festival days
int getValidDays()
{
    int days;

    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);

    while (days < 1 || days > 7)
    {
        printf("Invalid input! Enter days from 1 to 7: ");
        scanf("%d", &days);
    }

    return days;
}

// Function 2: Calculate sales for one day
float calculateDailySales(int dayNumber)
{
    int orders, i;
    float amount, total = 0, average, highest = 0;

    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);

    while (orders < 1)
    {
        printf("Enter at least 1 order: ");
        scanf("%d", &orders);
    }

    for (i = 1; i <= orders; i++)
    {
        printf("Enter amount for Order %d: ", i);
        scanf("%f", &amount);

        while (amount <= 0)
        {
            printf("Invalid amount! Enter an amount greater than 0: ");
            scanf("%f", &amount);
        }

        total = total + amount;

        if (amount > highest)
            highest = amount;
    }

    average = total / orders;

    printf("Total sales: Rs. %.2f\n", total);
    printf("Average order amount: Rs. %.2f\n", average);
    printf("Highest order amount: Rs. %.2f\n", highest);

    return total;
}

// Function 3: Find the day with the highest sales
int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i;
    int bestDay = 0;

    for (i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[bestDay])
            bestDay = i;
    }

    return bestDay + 1;
}

// Function 4: Display the sales bar chart
void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j;
    int stars;

    printf("\n--- Daily Sales Bar Chart ---\n");
    printf("(Each * represents Rs. 100)\n");

    for (i = 0; i < numberOfDays; i++)
    {
        stars = (int)(dailySales[i] / 100);

        printf("Day %d: ", i + 1);

        for (j = 1; j <= stars; j++)
        {
            printf("*");
        }

        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

int main()
{
    float dailySales[7];
    float festivalTotal = 0;
    int days, i, highestDay;

    // Get valid festival duration
    days = getValidDays();

    // Process each festival day
    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);

        festivalTotal = festivalTotal + dailySales[i];
    }

    // Display festival summary
    highestDay = findHighestSalesDay(dailySales, days);

    printf("\n--- Festival Sales Summary ---\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", highestDay);
    printf("Highest daily sales: Rs. %.2f\n",
           dailySales[highestDay - 1]);

    // Display bar chart
    displayBarChart(dailySales, days);

    return 0;
}

