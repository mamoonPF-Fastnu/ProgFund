/**
BS-AI 
MAMOON AHMED 26K-0003
ASSIGNMENT 02 --------> QUESTION 2
*/

#include <stdio.h>

int sumDivisors(int x)
{
    int i, sum = 0;

    for (i = 1; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            sum = sum + i;
        }
    }

    return sum;
}

int main()
{
    int n, i, j;
    int sum1, sum2;
    int pairs = 0;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter a positive number.\n");
        return 0;
    }

    printf("\nAmicable pairs up to %d:\n", n);

    for (i = 2; i <= n; i++)
    {
        sum1 = sumDivisors(i);
        j = sum1;

        if (j > i && j <= n)
        {
            sum2 = sumDivisors(j);

            if (sum2 == i)
            {
                printf("(%d, %d)\n", i, j);
                pairs++;
            }
        }
    }

    if (pairs == 0)
    {
        printf("No amicable pairs found.\n");
    }

    printf("Total amicable pairs: %d\n", pairs);

    return 0;
}

