#include <stdio.h>

#define arraySize 5

// static int arraySize = 5 ;
/*
    https://stackoverflow.com/questions/13645936/variably-modified-array-at-file-scope-in-c
    Size of an array should not be a constant or a different variable.
    06CPointersAndArrays.c:4:5: error: variably modified ‘myrray’ at file scope
    int myrray[ arraySize ] ;
    
*/

int main(void) 
{
    int myArray[arraySize] ; 
    myArray[0] = 21 ;
    myArray[1] = 31 ;
    myArray[2] = 41 ;
    myArray[3] = 51 ;
    myArray[4] = 61 ;

int* pointArray = myArray;

    for( short i = 0 ; i < arraySize ; i++)
    {
        printf("Direct Referencing Address: %p , Address: %p \n",&myArray[i] , myArray + i) ;
        printf("In-Direct Referencing Value: %d , Value: %d \n",pointArray[i], *(pointArray + i ) ) ;
    }
    return 0 ;
}