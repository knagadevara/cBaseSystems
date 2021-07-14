#include <stdio.h>
#include <stdlib.h>

struct CreateArray
    {
    int* ArrayAddress;
    int ArraySize;
    int ArrayLength; 
    };

//Creates an Array in the Heap.
int* CreateHeapIntArray(int* SizeOfArray)
    {   
        if (*SizeOfArray<=1)
            *SizeOfArray = 4;
        int* NewHeapArray = (int*) calloc(*SizeOfArray, sizeof(int));
        return NewHeapArray;
    }

//SetLength
//SetSize
//CreatesArray
void DefineArray(struct CreateArray* CustomArray)
    {
        printf("Enter the size of the array: ");
        scanf("%d" , &CustomArray->ArraySize);
        printf("Set the length of the array\n");
        scanf("%d" , &CustomArray->ArrayLength);
        if (CustomArray->ArraySize > 0)
        {
        CustomArray->ArrayAddress = CreateHeapIntArray(&CustomArray->ArraySize);
        printf("Array Created\n");
        }
    }

//DisplayArrayContents()
void PrintContentsOfArray(struct CreateArray* CustomArray)
    {
        for (int i = 0; i < CustomArray->ArrayLength ; i++)
        {
            printf("ArrayAddress[%d]: %p \t %d \n" , i , &CustomArray->ArrayAddress[i] , CustomArray->ArrayAddress[i] ) ; 
        }
    }

//InsertItemSerially()
void InsertItemSerially(struct CreateArray* CustomArray)
    {
        int oneUnit = sizeof(int);
        size_t arrayLength = oneUnit * CustomArray->ArrayLength;
        size_t arraySize = oneUnit * CustomArray->ArraySize ;
        printf("\nEnter the number of elements to enter inside Array, Unit: %d \t Size: %ld \t Length: %ld \n" , oneUnit , arraySize , arrayLength);
        if(arrayLength <= arraySize)
            for (int i = 0; i < (CustomArray->ArrayLength) ; i++)
               scanf("%d" , &CustomArray->ArrayAddress[i]);
        }


void AppendItem(struct CreateArray* CustomArray , int item)
    {
        int oneUnit = sizeof(int);
        size_t arrayLength = oneUnit * CustomArray->ArrayLength;
        size_t arraySize = oneUnit * CustomArray->ArraySize ;
        if(arrayLength < arraySize)
            {
                CustomArray->ArrayAddress[CustomArray->ArrayLength++] = item ; 
                printf("\nAppended Element inside the Array\n");
                CustomArray->ArrayLength++;
            }
        else
            printf("No Space Left \n");
    }


void InsertItem(struct CreateArray* CustomArray , int index , int item)
    {
        int oneUnit = sizeof(int);
        // size_t arrayLength = oneUnit * CustomArray->ArrayLength;
        // size_t arraySize = oneUnit * CustomArray->ArraySize ;
        if(index >= 0 && index <= CustomArray->ArrayLength )
            {
                for (int i = CustomArray->ArrayLength ; i > index ; i-- )
                        CustomArray->ArrayAddress[CustomArray->ArrayLength] = CustomArray->ArrayAddress[CustomArray->ArrayLength - 1] ;
                CustomArray->ArrayAddress[index] = item;
                CustomArray->ArrayLength++;
            }
        else
            printf("Out Of Bound \n");
    }


int main(void)
    {
        struct CreateArray myArray;
        DefineArray(&myArray);
        InsertItemSerially(&myArray);
        AppendItem(&myArray , 99);
        PrintContentsOfArray(&myArray);
        free(myArray.ArrayAddress);
        printf("Freeing memory after printing elements\n");
        return 0;
    }