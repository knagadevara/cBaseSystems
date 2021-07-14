#include <stdio.h>
#include <stdlib.h>

struct CreateArray
    {
    int* ArrayAddress;
    int ArraySize;
    int ArrayLength; 
    };

int* CreateHeapIntArray(int* SizeOfArray)
    {   
        *SizeOfArray = (*SizeOfArray) * sizeof(int) ;
        if (*SizeOfArray<1)
            *SizeOfArray = 4;
        int* NewHeapArray = (int*) calloc(*SizeOfArray, sizeof(int));
        return NewHeapArray;
    }


void PrintContentsOfArray(struct CreateArray* CustomArray)
    {
        for (int i = 0; i < CustomArray->ArrayLength ; i++)
        {
            printf("ArrayAddress[%d]: %p \t %d \n" , i , &CustomArray->ArrayAddress[i] , CustomArray->ArrayAddress[i] ) ; 
        }
        printf("Freeing memory after printing elements\n");
    }

int DefineArray(struct CreateArray* CustomArray)
    {
        printf("Set the length of the array\n");
        scanf("%d" , &CustomArray->ArrayLength);
        printf("\nEnter the number of elements to enter inside Array\n");
        for (int i = 0; i < (CustomArray->ArrayLength) ; i++)
            scanf("%d" , &CustomArray->ArrayAddress[i]);
        PrintContentsOfArray(CustomArray);
        return 0;
    
    }


int main(void)
    {
        struct CreateArray myArray;
        printf("Enter the size of the array: ");
        scanf("%d" , &myArray.ArraySize);
        myArray.ArrayAddress = CreateHeapIntArray(&myArray.ArraySize);
        printf("Array Created\n");
        DefineArray(&myArray);
        free(myArray.ArrayAddress);
        return 0;
    }