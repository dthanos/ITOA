#ifndef ITOA_H_
#define ITOA_H_

char *itoa(int number);

// CONVERTS INTEGER TO CHARACTER BY MAKING A DIGIT ARRAY OF THE NUMBER AND CONVERTING THE NUMBERS INTO CHARACTERS
char *itoa(int number)
{
    int n = log10(number) + 1; /*FINDING THE NUMBER OF DIGITS*/
    int i;
    int *number_array = (int *)malloc(n * sizeof(int));
    if (number == 0)
    {
        char *char_array = (char *)malloc(2 * sizeof(char));
        char_array[0] = '0';
        char_array[1] = '\0';
        return char_array;
    }
    /*MAKING AN ARRAY OF DIGITS*/
    for (i = 0; i < n; i++)
    {
        number_array[i] = number % 10;
        number /= 10;
    }
    char *char_array = (char *)calloc((n + 1), sizeof(char));
    //memset(char_array, '\0', sizeof(char_array));
    /*CONVERTING THE NUMBER ARRAY INTO A CHARACTER ARRAY*/
    for (i = 0; i < n; i++)
    {
        char_array[i] = '0' + number_array[n - (i + 1)];
    }
    return char_array;
}

#endif