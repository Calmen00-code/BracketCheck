#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "ucp_string.h"
#include "main.h"
#include "newSleep.h"
#include "bracket.h"
#include "stack.h"

void display( char **content, int line )
{
    char space[LEN] = "", cursor = '^';
    char after[100] = "", before[100] = "", color[10] = "";
    char *bracket = NULL, *popBracket = NULL, openBracket = ' ', closeBracket = ' ';
    int writeLen = 0, spaceLen = 0;
    int i, j, ii;
    int stop = FALSE;

    LinkedList *stack = NULL;
    stack = createStack();

    /* First loop determines the cursor going down */
    /* The cursor will move until the end of current line before next line */
    for( i = 0; i < line; i++ )
    {
        /* Printing the moving cursor for each line */
        j = 0;
        while( content[i][j] != '\0' && stop == FALSE )
        {
            /* Process to highlight OR stop if bracket is inbalanced */
            if( isBracket( content[i][j] ) == TRUE )
            {
                /* Splitting the string to two parts */
                /* content[i][j] AKA the bracket acts as the separator */
                copyBefore( before, content[i], j );
                copyAfter( after, content[i], j+1 );

                /* Get the specific color for each type of bracket */
                getColor( content[i][j], color ); 

                if( isPush( content[i][j] ) == TRUE )
                {
                    bracket = (char*)malloc(sizeof(char));
                    *bracket = content[i][j];
                    push( stack, bracket );
                }
                else
                {
                    /* Opening bracket appears before closing bracket */
                    if( stack->head != NULL )
                    {
                        popBracket = top( stack );
                        if( isMatch( content[i][j], *popBracket ) == FALSE )
                        {
                            printBefore( content, i );

                            openBracket = *popBracket;
                            closeBracket = getMatch( openBracket );

                            /* Printing space and the cursor */
                            printf("%s%c\n", space, cursor);
                            printErrorMsg( closeBracket, space );
                            strcat(space, " ");

                            /* Stop the loop */
                            stop = TRUE;
                        }
                        else
                        {
                            popBracket = pop( stack );
                            free(popBracket); popBracket = NULL;
                        }
                    }
                    else    /* Closing bracket appears before opening bracket */
                    {
                        printBefore( content, i );
                        openBracket = getMatchOpen( content[i][j] );

                        /* Printing space and the cursor */
                        printf("%s%c\n", space, cursor);
                        printErrorMsg( openBracket, space );
                        strcat(space, " ");

                        stop = TRUE;    /* Unbalancing occurs */
                    }   
                }

                /* Adding highlight background to the particular bracket */
                writeLen = writeColorText( content[i], before, after, 
                                           content[i][j], color );

                /* length of content[i] will be longer since 
                   color code has been included */
                j += writeLen;
            }
            memset(before, '\0', sizeof(before));
            memset(after, '\0', sizeof(after));

            /*  If stop = TRUE, we dont need to print line before as 
                it was already done above */
            if( stop == TRUE )
            {
                printAfter( content, i, line );
                printf("\n");
                #ifdef STACK
                printLinkedList( stack );
                #endif
            }
            else
            {
                printBefore( content, i );

                /* Printing space and the cursor */
                printf("%s%c\n", space, cursor);
                strcat(space, " ");
                printAfter( content, i, line );
                #ifdef STACK
                printLinkedList( stack );
                #endif
            }

            /* i is not last line AND stop = TRUE for others bad example cases */
            if( stop != TRUE )
            {
                newSleep(0.4);
                system("clear");
                j++;
            }
        }

        /* Only check when i = last line and using ROUND because it is YELLOW */
        if( (i == line-1) && stop != TRUE )
        {
            spaceLen = strlen(space);

            for( ii = 0; ii < line; ii++ )
                printf("%s", content[ii]);

            /* Remove that last extra added space ' ' */
            /* Which was added before the terminate condition of the WHILE loop */
            space[spaceLen-1] = '\0';   

            printf("%s%c\n", space, cursor);

            if( stack->head == NULL )   /* Good case */
                printf("%s%sAll Good!%s\n", space, ROUND, RESET); 
            else    /* Incomplete (no closing bracket at the end) */
            {
                popBracket = top( stack );
                closeBracket = getMatch( *popBracket );
                printf("%s%s'%c'expected before End of Code%s\n", 
                        space, ANGLE, closeBracket, RESET);
            }
            #ifdef STACK
                printLinkedList( stack );
            #endif
        }

        /* Always reset space to empty for every new line */
        memset(space, '\0', sizeof(space)); 
    }
    freeStack( stack );
}

int writeColorText( char *str, char *before, char *after, char ch, char *color )
{
    int len = 0;
    char data[LEN] = "";

    sprintf( data, "%s%s%c%s%s", before, color, ch, RESET, after );

    /* str is the same as content[i] */
    /* Always set the content[i] to empty first rather than overwriting */
    memset( str, '\0', sizeof(char) );
    ucp_strcpy( str, data );

    /* this len will be return to caller to update the index */
    len = strlen(color) + strlen(RESET);    

    return len;
}

void printErrorMsg( char bracket, char *space )
{
    /* Using ANGLE as it is RED */
    printf("%s%s'%c'expected%s\n", space, ANGLE, bracket, RESET);
}

void printBefore( char **content, int i )
{
    int k;
    for( k = 0; k <= i; k++ )
        printf("%s", content[k]);
}

void printAfter( char **content, int i, int line )
{
    int k;

    /* Print contents after the line of the current cursor */
    for( k = i+1; k < line; k++ )
        printf("%s", content[k]);
}
