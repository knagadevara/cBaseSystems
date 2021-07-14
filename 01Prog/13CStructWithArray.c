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
        *SizeOfArray = (*SizeOfArray) * sizeof(int) ;
        if (*SizeOfArray<1)
            *SizeOfArray = 4;
        int* NewHeapArray = (int*) calloc(*SizeOfArray, sizeof(int));
        return NewHeapArray;
    }

//SetLength
//SetSize
//CreateArray
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
        printf("Freeing memory after printing elements\n");
    }

//InsertItemSerially()
int InsertItemSerially(struct CreateArray* CustomArray)
    {
        printf("\nEnter the number of elements to enter inside Array\n");
        for (int i = 0; i < (CustomArray->ArrayLength) ; i++)
            scanf("%d" , &CustomArray->ArrayAddress[i]);
        return 0;
    }


int main(void)
    {
        struct CreateArray myArray;
        DefineArray(&myArray);
        InsertItemSerially(&myArray);
        PrintContentsOfArray(&myArray);
        free(myArray.ArrayAddress);
        return 0;
    }