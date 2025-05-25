#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to calculate average points
float average_points(int arr[], int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];
    }
    return sum / (float)n;
}

// Function to print students below group average
void print_below_group_average(char student_name[5][10], float averages[5], float group_avg) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (averages[i] < group_avg) 
        {
            // Capitalize first letter
            student_name[i][0] = toupper(student_name[i][0]);
            for (int k = 1; student_name[i][k]; k++)
                student_name[i][k] = tolower(student_name[i][k]);
            printf("%s\n", student_name[i]);
        }
    }
}

int main()
{
    //Array that stores 5 names, each up to 10 characters each
    char student_name[5][10]; 
    //Array that stores results for 5 students, 13 test results each
    int test_results[5][13];
    //Array that stores the average results of each student
    float averages[5];

    //Asks the user to enter the names and 13 scores for each student.
    for (int i = 0; i < 5; i++)
    {
        // Reads the names of the students
        scanf("%10s", student_name[i]);
        
        //Loop that goes through each character of the students names
       for (int k = 0; student_name[i][k] != '\0'; k++) 
        {
            //condition that checks for invalid characters in the student name
            if (!isalpha(student_name[i][k])) 
            {
                printf("Invalid name: %s\n", student_name[i]);
                return 1;
            }
        }

        // Convert first letter to uppercase 
        student_name[i][0] = toupper(student_name[i][0]);

        // Read 13 test results for this student
        for (int j = 0; j < 13; j++)
        {
            scanf("%d", &test_results[i][j]);
            //condition that checks if the test results are within the valid range (0-10)
            if (test_results[i][j] < 0 || test_results[i][j] > 10) 
            {
                printf("Invalid test result: %d\n", test_results[i][j]);
                return 1;
            }
        }

        // Calculate and store average for this student
        averages[i] = average_points(test_results[i], 13);
    }

    // Find the student with the highest average
    int max_index = 0;
    for (int i = 1; i < 5; i++) 
    {
        if (averages[i] > averages[max_index]) 
        {
            max_index = i;
        }
    }

    // Print the name of the student with the highest average
    printf("%s\n", student_name[max_index]);

    // Calculate group average
    float group_sum = 0.0f;
    for (int i = 0; i < 5; i++) 
    {
        group_sum += averages[i];
    }
    float group_avg = group_sum / 5.0f;

    // Print students below group average
    print_below_group_average(student_name, averages, group_avg);

    return 0;
}

