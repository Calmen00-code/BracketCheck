#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANGLE "\033[41m"
#define RESET "\033[0m"

void copyBefore( char *dest, char *src, int idx )
{
    int i;
    for( i = 0; i < idx; i++ )
        dest[i] = src[i];
}

int main()
{
    char str[100] = "#include <stdio.h>";
    char newStr[100] = "";
    printf("Before: %s\n", newStr);
    copyBefore( newStr, str, 9 );
    printf("After: %s\n", newStr);
/*
    char *ptr = NULL;
    char before[100] = "";
    char Str[100] = "";
    int i = 9;

    ptr = strchr(str, str[i+1]);
    strncpy(before, str, i-1);
    printf("str: %s\n", str);
    printf("before: %s\n", before);
    printf("ptr: %s\n", ptr);
    sprintf(Str,"%s%s%c%s%s", before, ANGLE, str[i], RESET, ptr);
    printf("%s\n", Str);
*/  
    return 0;
}
