#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getinput() 
{
    char *myinput = (char *)malloc(20);
    printf("Plese enter the data \n");
    fgets(myinput, 20, stdin);
    return myinput;
}

char *reverse(char *reversme) //reverse given string and return it
{
    char *reversed = (char *)malloc(20); //create 20 charecter long string
    int begin, end, count = 0;
    while (reversme[count] != '\0') //find the end of the string by searching null terminator and determine lenght
    {
        count++;
    }
    end = count - 1; // decrease by one to move it left to the null terminator
    for (begin = 0; begin < count; begin++) //loop till the end of the string
    {
        reversed[begin] = reversme[end]; //Put the last charecter of reversme to first string of reversed and continue doing it
        end--; //after copying last charecter of reversme decrease end variable by one to move it to the left
    }
    reversed[begin] = '\0'; //add null terminator to the end of the reversed. Variable begin is at the end of the string right now
    return reversed;
}

void writeToFile(char *writeme)
{
    FILE *filePointer;
    filePointer = fopen("myfile.txt", "a");
    fprintf(filePointer, "%s", writeme);
    fclose(filePointer);
}

int main()
{
    printf("Please enter the text you want to invert and save in a file \n");
    char *myinput = (char *)malloc(20); // create 20 charecter long string
    while( strcmp("end\n", myinput=getinput()) )  //Loop untill the user enters "end\n". Gotta check for \n too because fgets include new line charecter too
    {
        writeToFile(reverse(myinput)); //write reversed input to the file
    }
    return 0;
}
