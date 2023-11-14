#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declaring this value so I can use it in different places
#define buffer_size 100

/**
 * @brief Struct to hold each daily reading, contains the date as a string
 *        and the bloodIron as a floating point number.
 *
 */
typedef struct
{
    char date[20];
    float bloodIron;
} reading;

/**
 * @brief Adapted version of the tokeniseRecord function which you should now be familiar with - this one is adapted for this data file
 *        as it has fewer outputs and gives you the bloodIron as a float
 *
 * @param input the line of the file to be split
 * @param delimiter what character it should split on
 * @param date the place where the date will be stored
 * @param bloodIron the place where the bloodIron will be stored.
 */
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, float *bloodIron)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        // turns the blood iron into a float - similar to atoi().
        // we have to tell C that bloodIron is a pointer so it stores it.
        *bloodIron = atof(token);
    }

    // Free the duplicated string
    free(inputCopy);
}

/**
 * @brief Finds and prints the maximum value
 *
 * @param data the array of readings
 * @param num_records the number of readings in the array
 */
void find_max(reading *data, int num_records)
{
    float current_max = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (data[i].bloodIron > current_max)
        {
            current_max = data[i].bloodIron;
        }
    }
    printf("Your highest blood iron reading was %.1f\n", current_max);
}

void find_min(reading *data, int num_records)
{
    float current_min = 99999999;
    for (int i = 0; i < num_records; i++)
    {
        if (data[i].bloodIron < current_min)
        {
            current_min = data[i].bloodIron;
        }
    }
    printf("Your lowest blood iron reading was %.1f\n", current_min);
}

void print_month(reading* data, int count){
    // ask for month as 3 capital code
    // and print out any record where I find it?

    printf("Which month's data would you like to see.\nEnter this as a 3-letter value e.g. JAN, FEB, MAR\n");
    char line[buffer_size];
    fgets(line,buffer_size,stdin);
    char month[3];
    sscanf(line, "%s", month);

    for(int i=0;i<count;i++){
        if(strstr(data[i].date,month)){
            printf("%s - blood iron: %.1f\n",data[i].date,data[i].bloodIron );
        }
    }
}