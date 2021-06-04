#include <stdio.h>

int globalA = 1;

int incrementVarGen(int var) // Called Function accepts integer type value
    {
        var = var + 1 ;
        printf("Passed the value directly\n");
        printf("What is incremented var: %d\n" , var );
        return 0;
    }

int incrementVarPtr(int* var) // Called Function accepts integer type address
    {
        *var = *var + 1 ;
        printf("Passed the address directly\n");
        printf("What is incremented var: %d\n" , *var );
        return 0;
    }

int main() // Calling Function
    {
        int a,b;
        a = 10 ;
        printf("What is 'a': %d\n" , a );
        incrementVarGen(a) ; /* 'a' is Actual argument which is passed and the function is called by value */
        printf("What is 'a' after function call: %d\n" , a );

        b = 10;
        printf("What is 'b': %d\n" , b);
        incrementVarPtr(&b) ; /* 'b' is Actual argument which is passed and the function is called by address reference */
        printf("What is 'b' after function call: %d\n" , b );
        return 0;
    }