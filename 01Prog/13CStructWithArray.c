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
        printf("Set the length of the array: ");
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
        printf("-------------------- ------------------------- -------------------- \n");
        for (int i = 0; i < CustomArray->ArrayLength ; i++)
        {
            printf("[%d]: %p \t %d \n" , i , &CustomArray->ArrayAddress[i] , CustomArray->ArrayAddress[i] ) ; 
        }
    }

//InsertItemSerially()
void InsertItemSerially(struct CreateArray* CustomArray)
    {
        printf("\nEnter the number of elements to enter inside Array\n");
        if(CustomArray->ArrayLength <= CustomArray->ArraySize)
            { for (int i = 0; i < (CustomArray->ArrayLength) ; i++)
               scanf("%d" , &CustomArray->ArrayAddress[i]);
            }
        else
            printf("Requested Length is greater than the size of the Array\n");
        }


void AppendItem(struct CreateArray* CustomArray , int item)
    {
        if(CustomArray->ArrayLength < CustomArray->ArraySize)
            {
                CustomArray->ArrayAddress[CustomArray->ArrayLength++] = item ; 
                printf("\nAppended Element inside the Array\n");
            }
        else
            printf("No Space Left \n");
    }


void InsertItem(struct CreateArray* CustomArray , int index , int item)
    {
        if(index >= 0 && index <= CustomArray->ArrayLength)
            {
                for (int i = CustomArray->ArrayLength ; i > index ; i-- )
                        CustomArray->ArrayAddress[CustomArray->ArrayLength] = CustomArray->ArrayAddress[CustomArray->ArrayLength - 1] ;
                CustomArray->ArrayAddress[index] = item;
                CustomArray->ArrayLength++;
            }
        else
            printf("Out Of Bound \n");
    }

// Delete an item at the index
int DeleteItem(struct CreateArray* CustomArray , int index)
    {

        if(index >= 0 && index <= CustomArray->ArrayLength)
            {
            // move the items after deletion.
            int item = CustomArray->ArrayAddress[index] ;
            for (size_t i = index ; i < CustomArray->ArrayLength -  1; i++)
                CustomArray->ArrayAddress[i] = CustomArray->ArrayAddress[i+1];
            CustomArray->ArrayLength--;
            return item;
            }
        return 0;
    }

// Gradually increases the performance
void SwapTrasnpose(struct CreateArray* CustomArray , int oldIndex , int newIndex)
    {
        if (newIndex >= 0)
        {
            int temp = CustomArray->ArrayAddress[oldIndex];
            CustomArray->ArrayAddress[oldIndex] = CustomArray->ArrayAddress[newIndex];
            CustomArray->ArrayAddress[newIndex] = temp;
        }

    }

//Directly Swaps with 0 index
void SwapToZero(int* oldIndexValue , int* zeroIndexValue)
    {
            int temp = *oldIndexValue;
            *oldIndexValue = *zeroIndexValue;
            *zeroIndexValue = temp;
    }

// Search the array with improvement in time for next search by Transposition
int SearchItemLinear(struct CreateArray* CustomArray , int item)
    {
        for(int i = 0 ; i < CustomArray->ArrayLength ; i++)
            if (CustomArray->ArrayAddress[i] == item)
            {   
                SwapTrasnpose(CustomArray , i , i - 1 );
                SwapToZero(&CustomArray->ArrayAddress[i - 1] , &CustomArray->ArrayAddress[0]);
                return i;
            }
        return -1;
    }


int main(void)
    {
        struct CreateArray myArray;
        DefineArray(&myArray);
        InsertItemSerially(&myArray);
        AppendItem(&myArray , 99);
        InsertItem(&myArray , 9 , 35);
        DeleteItem(&myArray , 9);
        SearchItemLinear(&myArray , 7);
        PrintContentsOfArray(&myArray);
        free(myArray.ArrayAddress);
        printf("Freeing memory after printing elements\n");
        return 0;
    }