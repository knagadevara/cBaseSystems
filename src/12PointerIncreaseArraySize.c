#include <stdio.h>
#include <stdlib.h>

int GetArraySize(int* ArrayAddress)
    {
        int SizeOfArray = (int)sizeof(ArrayAddress);
        return SizeOfArray;
    }

int GetArrayLength(int* ArrayAddress)
    {
        int LenOfArray = (int)sizeof(ArrayAddress)/(int)sizeof(ArrayAddress[0]);
        return LenOfArray;
    }

int* CreateHeapIntArray(int SizeOfArray)
    {
        if (SizeOfArray<1)
            SizeOfArray = 1;
        int* NewHeapArray = (int*) calloc(SizeOfArray, sizeof(int));
        return NewHeapArray;
    }

int* IncreaseArraySize(int* OldArray, int OldSize , int NewSize)
    {
        if( NewSize < OldSize )
            NewSize = OldSize + 1;
        int* NewArray = CreateHeapIntArray(NewSize);

        for (int i = 0; i < OldSize; i++)
        {
            NewArray[i] = OldArray[i];
        }
        free(OldArray) ;
        OldArray = NewArray;
        NewArray = NULL;
        return OldArray;
    }

int* FillNumbers(int* ArrayAddress , int ArraySize)
    {
        for (int i = 0; i < ArraySize; i++)
        {
            ArrayAddress[i] = i;
        }
        
        return ArrayAddress;
    }

void PrintContentsOfArray(int* ArrayAddress , int ArraySize)
    {
        for (int i = 0; i < ArraySize; i++)
        {
            printf("ArrayAddress[%d]:\t%d\n" , i , ArrayAddress[i]) ; 
        }
    }

int main(void)
    {
        int* myArray = CreateHeapIntArray(20);
        myArray = FillNumbers(myArray,20);
        PrintContentsOfArray(myArray,20);
        printf("Size of array in Function: %d\n", GetArraySize(myArray) );
        int mySize = sizeof(myArray);
        printf("Size of array in Main: %d\n", mySize );
        printf("Length: %d\n", GetArrayLength(myArray) );

        return 0;
    }
