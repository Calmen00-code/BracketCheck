/*
*  Program: main.c
*  Purpose: Driver file for the entire program
*  Date: 02 December 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "display.h"

int main(int argc, char *argv[])
{
    char **content = NULL;
    int *size = NULL;

    if( argc != 2 )
        printf("Usage: ./prog <input.c>\n");
    else
    {
        size = (int *)malloc(sizeof(int));
        /* Using integer pointer to get the size */
        content = read( argv[1], size );

        if( content != NULL )
        {
            system("clear");
            display( content, *size );

            freeContent( content, *size );
        }
        free(size); size = NULL;
    }
    return 0;
}

void freeContent( char **content, int size )
{
    int i;
    for( i = 0; i < size; i++ )
    {
        free(content[i]); 
        content[i] = NULL;
    }
    free(content); content = NULL;
}
