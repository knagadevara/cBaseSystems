#include <stdio.h>

int SumOfElements(int* myArray , int arrayLen)
{
    int i , sum = 0 ;
    printf("Inside SoE: %p\n",myArray);
    printf("Inside SoE: %p\n",&myArray[0]);
    for (i = 0 ; i < arrayLen ; i++)
    {
        printf("\t%d\n",myArray[i]);
        sum += myArray[i];
    }
    return sum;
}

int main(void)
{
    int myArray[] = {21, 31, 41, 51, 61} ;
    printf("%p\n",myArray);
    int arrayLen = sizeof(myArray)/sizeof(myArray[0]) ;
    int sumOfElements = SumOfElements(myArray , arrayLen) ;
    printf("----------\nTotal: %d\n",sumOfElements);
    return 0;
}