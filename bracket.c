#include <stdio.h>
#include "main.h"
#include "bracket.h"
#include "ucp_string.h"

/*
FUNCTION: isBracket
IMPORT: ch (Character)
EXPORT: bracket (Integer)
ASSERTION: Return TRUE if ch is a bracket 
*/
int isBracket( char ch )
{   
    int bracket = FALSE;

    if( ch == '<' || ch == '>' || ch == '(' || ch == ')' ||
        ch == '{' || ch == '}' || ch == '[' || ch == ']' )
        bracket = TRUE;

    return bracket;
}

/*
FUNCTION: isPush
IMPORT: bracket (Character)
EXPORT: status (Integer)
ASSERTION: Return TRUE if bracket is open bracket
*/
int isPush( char bracket )
{
    int status = FALSE;

    if( bracket == '<' || bracket == '(' || bracket == '{' || bracket == '[' )
       status = TRUE;

    return status;
}

/*
FUNCTION: isMatch
IMPORT: bracket (Character), popBracket (Character)
EXPORT: status (Integer)
ASSERTION: Return TRUE if open and close bracket matches
*/
int isMatch( char bracket, char popBracket )
{
    int status = FALSE;
    char match = ' ';

    match = getMatch( popBracket );

    if( match == bracket )
        status = TRUE;

    return status;
}

/*
FUNCTION: getMatch
IMPORT: popBracket (Character)
EXPORT: Get the open bracket, return the close bracket
ASSERTION: Return closing match bracket of popBracket
*/
char getMatch( char popBracket )
{   
    char match = ' ';

    switch( popBracket )
    {
        case '<': 
            match = '>';
        break;

        case '(':
            match = ')';
        break;

        case '{':
            match = '}';
        break;

        case '[':
            match = ']';
        break;
    }
    return match;
}

/*
FUNCTION: getColor
IMPORT: bracket (Character), color (Character Pointer)
EXPORT: none
ASSERTION: Store the color code into *color based on the bracket type
*/
void getColor( char bracket, char *color )
{
    switch( bracket )
    {
        case '<' : case '>': 
            ucp_strcpy( color, ANGLE );
        break;

        case '[' : case ']': 
            ucp_strcpy( color, SQUARE );
        break;

        case '(' : case ')': 
            ucp_strcpy( color, ROUND );
        break;

        case '{' : case '}': 
            ucp_strcpy( color, CURLY );
        break;
    }
}

/*
FUNCTION: getMatchOpen
IMPORT: closeBracket (Character)
EXPORT: openBracket (Character)
ASSERTION: Given the closeBracket, return the matching openBracket
*/
char getMatchOpen( char closeBracket )
{
    char openBracket = ' ';

    switch( closeBracket )
    {
        case '>': 
            openBracket = '<';
        break;

        case ')':
            openBracket = '(';
        break;

        case '}':
            openBracket = '{';
        break;

        case ']':
            openBracket = '[';
        break;
    }
    return openBracket;
}
