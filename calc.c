#include <stdio.h>  
int main()  
{  
    
    char opt;  
    int n1, n2;   
    float res;  
    printf (" Choose an operator(+, -, *, /) to perform the operation in C Calculator \n ");  
    scanf ("%c", &opt); 
    if (opt == '/' )  
    {  
        printf ("Division selected");  
    }  
    else if (opt == '*')  
    {  
        printf ("Multiplication selected");  
     }  
       
    else if (opt == '-')  
    {  
        printf ("Subtraction selected");  
     }  
        else if (opt == '+')  
    {  
        printf ("Addition selected ");  
     }     
    printf (" \n Enter the first number: ");  
    scanf(" %d", &n1); // take fist number  
    printf (" Enter the second number: ");  
    scanf (" %d", &n2); // take second number  
     switch(opt)  
    {  
        case '+':  
            res = n1 + n2; // add two numbers  
            printf (" Addition of %d and %d is: %.2f", n1, n2, res);  
            break;
        case '-':  
            res = n1 - n2; // subtract two numbers  
            printf (" Subtraction of %d and %d is: %.2f", n1, n2, res);  
            break;    