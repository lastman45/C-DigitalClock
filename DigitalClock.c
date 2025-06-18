#include <stdio.h>
#include <windows.h> // For Sleep function

int main()
{
    int hours, minutes, seconds;
    int d = 1000; // Delay in milliseconds to be used in function sleep
    printf("Enter time in HH:MM:SS format\n");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
    {
        printf("Invalid time format\n");
        exit(0);
    }
    while (1)
    {
        seconds++;
        if (seconds > 59)
        {
            seconds = 0;
            minutes++;
        }
        if (minutes > 59)
        {
            minutes = 0;
            hours++;
        }
        if (hours > 23)
        {
            hours = 0;
            printf("\nNew Day Started\n");
        }
        printf("\nClock");
        printf("\n%02d:%02d:%02d", hours, minutes, seconds);
        Sleep(d);       // Sleep for 1000 milliseconds (1 second)
        system("cls");  // Clear the console screen
        fflush(stdout); // Ensure the output is displayed immediately
    }
    return 0;
}