#include <stdio.h>
#include <stdlib.h>

int* AddXY(int* var1 , int* var2) 
// function will return a pointer to integer which is saved in 'heap' memory whose existance will be there until it is manually freed.
// this helps in a case where, TOP(called) functions which are to return pointers/addresses to the BOTTOM(calling) funtions.
// As stack memory will be erased after the execution of function.  
{
    int* result = (int*)calloc(1 , sizeof(int));
    *result = (*var1) + (*var2) ;
    printf("address of result: %p\n" , result);
    return result;
}

int main()
{
    int n;
    printf("Enter a value which is under 25: ");
    scanf("%d" , &n) ;

    void* a = malloc(n*sizeof(int)) ;
    int* b = (int*) a;
    // dynamically allocates memory to the variable and stores it in Heap, it will stay untill freed or execution of function/program completes.
    // malloc, calloc, realloc would generally returns a generic void pointer which later has to be typecasted to the specific data-type.

    int* p = (int*) malloc(n*sizeof(int)) ; 
    // A type casted approach, malloc accepts one argument size.
    // allocated memory is not initalized with anything, it would generally have garbage value.
    // initilization can be done in the similar way as Array.

    int* q = (int*) calloc(n , sizeof(int)) ;
    // functions similar to malloc takes 2 arguments, (units to allocate and size of each unit)
    // allocated memory will be initialized with '0'.

    int* c = (int*)realloc(NULL , n * sizeof(int)) ;
    // similar to malloc, 'n' blocks of memory will be allocated, it generally returns a pointer to void but in this case it is typecasted.
    
    int* d = (int*)realloc(c , 2 * n * sizeof(int)) ;
    // Checks if the memory can be extended to the existing block in a consequtive way then the existing block is extended, 
    // else creates a new block,  copies the content of the existing block into new blocl and deallocates memory of the old block.

    int* d_erase = (int*) realloc(d , 0);
    // Similar to calling free(d), this will de-allocate the memory at block d and gives out void pointer.
    // the allocated memory will be made available again.
    // free(a);
    // free(b);
    // free(c);
    // free(d);
    // free(d_erase);
    // free(p);
    // free(q);
    
    // if free() is called on a null pointer or called on the same address aga in it would throug
    // "free(): double free detected in tcache 2"

    int x = 20 ;
    int y = 10 ;
    // these variables will be created in the main functions stack-frame, as this is the calling function they will exist untill finish.

    int* z = AddXY(&x , &y) ; 
    // creating a pointer to integer z.
    // passing the address of x,y to the AddXY function which returns a pointer to Integer.

    printf("address of z: %p\n" , z);
    printf("result: %d\n" , *z);

    return 0;
}