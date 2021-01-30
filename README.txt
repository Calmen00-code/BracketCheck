This is a program that will read and detect any unbalanced bracket in a code file.
Whenever an opening bracket is encountered, it must be another matching close 
bracket for the pairs.

When a bracket is encountered, the program will automatically highlight it. 

----------------------------------------------------------------------------------
The files provided has included several example for testing purpose.

Examples of the files are:

example_good.c
example_good2.c
example_bad1.c
example_bad2.c
example_bad3.c
example_bad4.c
----------------------------------------------------------------------------------

2 ways to run the program: 

First: ./prog <file name>
Second: ./progStack <file name>

For example, ./prog example_good.c OR ./progStack example_good.c

When progStack is run, all bracket(s) stored in the stack will be displayed on the
bottom of the program as it progresses.
