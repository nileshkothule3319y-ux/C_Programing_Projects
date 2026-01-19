#include <stdio.h>   // For printf()
#include <unistd.h>  // For sleep()
#include <stdlib.h>  // For rand(), srand()
#include <time.h>    // For time()

/* Length of the progress bar */
const int BAR_len = 50;

/* Total number of tasks */
const int Max_task = 5;

/* Structure to store task information */
typedef struct
{
    int id;        // Task ID number
    int progress;  // Current progress (0 to 100)
    int step;      // Speed of progress increment
} Task;

/* Function declarations */
void BAR_function(Task task);
void screen_clear(void);

int main()
{
    /* Array of tasks */
    Task task[Max_task];

    /* Seed random number generator */
    srand(time(NULL));

    /* Initialize all tasks */
    for (int i = 0; i < Max_task; i++)
    {
        task[i].id = i + 1;            // Assign task ID
        task[i].progress = 0;          // Start progress at 0%
        task[i].step = rand() % 5 + 1; // Random speed (1 to 5)
    }

    int Task_incomplet = 1;  // Flag to check if any task is incomplete

    /* Loop until all tasks reach 100% */
    while (Task_incomplet)
    {
        Task_incomplet = 0;   // Assume all tasks are complete
        screen_clear();       // Clear terminal screen

        /* Update and display each task */
        for (int i = 0; i < Max_task; i++)
        {
            task[i].progress += task[i].step; // Increase progress

            /* Limit progress to maximum 100% */
            if (task[i].progress > 100)
            {
                task[i].progress = 100;
            }
            /* If any task is still incomplete, continue loop */
            else if (task[i].progress < 100)



    



