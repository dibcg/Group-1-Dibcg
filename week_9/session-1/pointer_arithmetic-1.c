#include <stdio.h>

int main()
{
    float vector[5] = {11,13,17, 23 , 31};

    float* address = vector;

    printf ( "\nAddress[0] = %f\n", *address);

    printf ( "\nAddress[1] = %f\n", * (address+1) );

    printf ("\n Address[2] = %f\n", *(address+2));

    

}