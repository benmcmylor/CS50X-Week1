#include <stdio.h>
#include<cs50.h>

int main(void)
{
    string name = 
        get_string("What's your name?\n");//rompt the user to submit their name, then intialize variable 'name' as a string and put the user name in there
    printf("hello, %s\n", name);//print "hello, [user name]"
}

