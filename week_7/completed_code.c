
#include "my_utilities.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }

    while (fgets(line, buffer_size, input))
    {
        // split up the line and store it in the right place
        tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
        counter++;
    }

    fclose(input);

    int num_records = counter;

    for(int i=0;i<num_records;i++){
        if(daily_readings[i].date[0]=='\0' || daily_readings[i].bloodIron == 0){
            printf("Error: Bad data\n");
            return 1;
        }
    }

    while (1)
    {
        printf("A: View all your blood iron levels\n");                        // BRONZE
        printf("B: View your average blood iron level\n");                     // BRONZE
        printf("C: View your lowest blood iron level\n");                      // SILVER
        printf("D: View your highest blood iron level\n");                     // SILVER
        printf("E: View the blood iron levels for a specific month\n");        // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n");  // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                   // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        choice = getchar();
        while (getchar() != '\n');

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            for (int i = 0; i < num_records; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            break;

        case 'B':
        case 'b':
            mean = 0;
            for (int i = 0; i < num_records; i++)
            {
                mean += daily_readings[i].bloodIron;
            }
            mean /= num_records;
            printf("Your average blood iron was %.2f\n", mean);
            break;

        case 'C':
        case 'c': // lowest
            find_min(daily_readings, num_records);
            break;

        case 'D':
        case 'd': // highest
            find_max(daily_readings, num_records);
            break;

        case 'E':
        case 'e': // specific month
            print_month(daily_readings, num_records);
            break;

        case 'F':
        case 'f': // extra stats
            return 0;
            break;

        case 'G':
        case 'g': // graph
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}