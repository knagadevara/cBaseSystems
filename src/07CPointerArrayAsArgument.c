#include <stdio.h>

int i = 0;

int SumOfElements(int* myArray , int arrayLen) // "int* myArray" is equalent to "int myArray[]"
{
    int sum = 0 ;
    printf("Inside SoE: %p\n",myArray); // is interpretted as the starting Address of myArray
    printf("Inside SoE: %p\n",myArray[0]); // is interpretted as value of myArray at index 0
    for (i ; i < arrayLen ; i++)
    {
        printf("\t%d\n",myArray[i]); // // is *myArray[0]
        sum += myArray[i]; // is *(myArray+1)
    }
    return sum;
}

void DoubleAllElements(int* myArray , int arrayLen)
{
    for ( i = 0; i < arrayLen ; i++ )
    {
        myArray[i] = (myArray[i]) * 2 ; // you are directly referencing the value inside the array at index point 'i'
    }
}

int main(void)
{
    int myArray[] = {21, 31, 41, 51, 61} ;
    printf("%p\n",myArray);
    int arrayLen = sizeof(myArray)/sizeof(myArray[0]) ;
    int sumOfElements = SumOfElements(myArray , arrayLen) ; // The Address "&myArray[0]" directly being sent 
    printf("Sum of Elements\n") ;
    printf("----------\nTotal: %d\n",sumOfElements);
    printf("\n") ;
    printf("Double the Elements\n") ;
    DoubleAllElements(myArray , arrayLen);
    for(i = 0 ; i < arrayLen ; i++)
    {
        printf("%d\n", myArray[i]);
    }

    return 0;
}