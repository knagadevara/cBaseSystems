#include <stdio.h>

int main(void) 
{
    /* Let us make a pointer pointing to pointer[ only works on the same type ]. To store the address of the pointer make a pointer of same datatype.
            Whaaaaaat the Freddie Mercury you are talking about? 
                    And, Thats when I said "Patience Bitch" */
    int a = 10 ;
    int normalVar ;
    printf("Value at 'a': %d\n",a) ;
    printf("Address of '&a': %p\n",&a) ;
    int* b = &a ;
    printf("value at 'b' is address of 'a': %p\n",b);
    printf("Dereferencing '*b' points to value at 'a': %d\n",*b);
    printf("Address of '&b': %p\n",&b);
    int** c = &b ;
    printf("value at c is address of 'b': %p\n",c);
    printf("Dereferencing '*c' points to value at 'c' which is the address of 'a' : %p\n",*c);
    printf("Dereferencing '**c' points to Value at 'a': %d\n",**c);
    printf("Address of '&c': %p\n",&c);
    int*** d = &c ;
    printf("value at d is address of 'c': %p\n",d) ;
    printf("Dereferencing '**d' points to value at 'b' which is the address of 'a': %p\n", **d);
    printf("Dereferencing '*d' points to value at 'c' which is the address of 'b': %p\n", *d);
    printf("Dereferencing '***d' points to value at 'a': %d\n", ***d);
    printf("Address of '&d': %p\n",&d);
    // printf("value at normalVar: %p\n",normalVar);
    /* This would error out as there is no possiblity of saving the address*
    04CPointer2Pointer.c: In function main:
    04CPointer2Pointer.c:16:17: warning: initialization of int **** from incompatible pointer type int ** [-Wincompatible-pointer-types] 
    int**** e = &b ; */
    ***d = 10 ;
    printf("Value at a after changing ***d = 10 : %d\n",a) ;
    return 0;
}