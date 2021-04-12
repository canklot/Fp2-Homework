#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getinput()
{
    char *myinput = (char *)malloc(20);
    printf("\nPlese enter the data \n");
    fgets(myinput, 20, stdin);
    return myinput;
}
void writeToFile(char *writeme)
{
    FILE *filePointer;
    filePointer = fopen("myfile.txt", "a");
    fprintf(filePointer, "%s", writeme);
    fclose(filePointer);
}
char *readFromFile(char *readme)
{
    FILE *filePointer;
    char *buff = (char *)malloc(500);
    filePointer = fopen(readme, "r");
    fread(buff, 1, 500, filePointer);
    fclose(filePointer);
    return buff;
}
int checkPalindrome(char *controlme)
{
    int end = strlen(controlme) - 2;                         // -2 because arrays start from zero and strings end with '\n'
    for (int i = 0; controlme[i] == controlme[end - i]; i++) //Check if fist and last charecters are equal and continue by moving them
    {
        if (i == end)
        {
            return 1; //word is palindromes
        }
    }
    return 0; //not palindromes
}

int main()
{
    printf("\nWelcome to palindrome saver. Please enter the text you want to check. Type exit if you want to quit and read palindromes from the file.");
    char *myinput = (char *)malloc(20);            // create 20 charecter long string
    while (strcmp("exit\n", myinput = getinput())) //Loop untill the user enters "exit\n". Gotta check for \n too because fgets include new line charecter too
    {
        if (checkPalindrome(myinput))
        {
            printf("This word is an palindrome and will be written to a file \n");
            writeToFile(myinput);
        }
        else
        {
            printf("this is NOT a palindrome \n");
        }
    }
    printf("\nExiting the program.\nReading the file: \n");
    printf(readFromFile("myfile.txt"));
    return 0;
}