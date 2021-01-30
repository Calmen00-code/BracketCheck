#ifndef BRACKET
#define BRACKET

#define ANGLE "\033[41m"    /* RED */
#define SQUARE "\033[42m"   /* GREEN */
#define ROUND "\033[43m"    /* YELLOW */
#define CURLY "\033[44m"    /* BLUE */

#define RESET "\033[0m"     /* Reset To Default */

int isBracket( char );
int isPush( char );
int isMatch( char, char );
char getMatch( char );
void getColor( char, char* );
char getMatchOpen( char );

#endif
