/*
*  Program: file.c
*  Purpose: Reading the input file of c code for analyse
*  Date: 02 December 2020 
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "ucp_string.h"

char** read( char *fileName, int *size )
{
    FILE *readPtr = NULL;
    char **content = NULL, str[LEN] = "";
    int fileSize, i;

    readPtr = fopen(fileName, "r");

    if( readPtr == NULL )
        perror("Error while reading file");
    else
    {
        /* Get the number of lines of the input file */
        fileSize = getFileSize( readPtr );
        *size = fileSize;
        rewind(readPtr);
        content = (char **)malloc(sizeof(char*) * fileSize);

        i = 0;
        while( i < fileSize )
        {
            content[i] = (char *)malloc(sizeof(char) * LEN);
            fgets(str, LEN, readPtr);
            ucp_strcpy(content[i], str);
            i++;
        }
        fclose(readPtr);
        readPtr = NULL;
    }
    return content;
}

int getFileSize( FILE *readPtr )
{
    int line = 0;
    char str[LEN] = "";
    
    while( fgets(str, LEN, readPtr) != NULL )
        line++;

    return line;
}
