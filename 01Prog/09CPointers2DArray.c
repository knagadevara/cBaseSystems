#include <stdio.h>

int main(void)
    {

        int twoDArray[2][3] ; 
        /* 
        creats a two one dimentional arrays say Array1[3] and Array2[2] 
        of type integer with three elements each.
        In our case twoDArray[0] is Array1 and twoDArray[1] is Array2,
        which would be sizeof(int) * 3 each. 
        */

        twoDArray[0][0] =  2 ;
        twoDArray[0][1] =  4 ; 
        twoDArray[0][2] =  6 ;
        twoDArray[1][0] =  3 ;
        twoDArray[1][1] =  6 ;
        twoDArray[1][2] =  9 ;

        int (*twoDArrayPointer)[3] = twoDArray;
        /* Creatig a pointer type of which points to [3] units of integer memory addresses */ 

        int arraySize1 = sizeof(twoDArray[0]) ;
        int arraySize2 = sizeof(twoDArray[1]) ;
        int arraySize = sizeof(twoDArray) ;
        
        printf("Starting address of twoDArray %p\n" , twoDArray) ; // will print the address of the first index in the array equal to *twoDArray
        printf("Starting address of *twoDArray %p\n" , *twoDArray) ;
        printf("Dereferencing Direct array object Prints the Value at **twoDArray %d\n" , **twoDArray) ; // Will print the value at 'twoDArray[0][0]' but will not work for other indexes
        printf("Dereferencing Direct array object Prints the Value at *(*twoDArray+5) %d\n" , *(*twoDArray+5)) ; 
        /* This basically is *twoDArray + 1 which is address of twoDArray[0] + sizeof(int) * 5 , 
        which is getting dereferenced again so it prints the value at the address &(twoDArray[0] + sizeof(int) * 5)
        so it tells to add 20 bytes to the existing address and print its value  
        That expression can also be viewed as twoDArray[0][5] */
        printf("Size of the 2DArray: %d\n" , arraySize) ;

        printf("First Array adress twoDArray[0] %p\n" , twoDArray[0]) ; // returns a pointer to integer similar to *twoDArray[returns the first index memory address] or &twoDArray[0] or twoDArray[0][0]
        printf("Size of the Array1: %d\n" , arraySize1) ;
        printf("The address of the first one dimentionally indirecreference %p\n" , twoDArrayPointer); // returns a pointer to iniiger similar to *(twoDArrayPointer)
        printf("Indirect reference value of *twoDArrayPointer[0] %d\n" , *twoDArrayPointer[0]) ; // returns the value present at the index 0, errors out if index is not provided.

        printf("Second Array adress twoDArray[1] %p\n" , twoDArray[1]) ; // returns a pointer to integer similar to *(twoDArray+1) or  (twoDArray+1) or twoDArray+1 or &twoDArray[1] or twoDArray[1][0]
        printf("Size of the Array2: %d\n" , arraySize2) ;
        printf("The address of the Second one dimentionally indirecreference %p\n" , twoDArrayPointer+1); // returns a pointer to iniiger  similar to *(twoDArrayPointer+1)
        printf("Indirect reference value of *twoDArrayPointer[1] %d\n" , *twoDArrayPointer[1]) ; // returns the value present at the index 1, errors out if index is not provided.        
        
        printf("Array address at twoDArray[1][2] %p\n" , &twoDArray[1][2]) ; // to get the address of the internel elements of the array '&' is required
        printf("Array value at twoDArray[1][2] %d\n" , twoDArray[1][2]) ;
        printf("Indirect reference to Array address at twoDArrayPointer[1][2] %p\n" , &twoDArrayPointer[1][2]) ; // addressing would require '&'
        printf("Indirect reference to Array value at twoDArrayPointer[1][2] %d\n" , twoDArrayPointer[1][2]) ; // addressing would require '&'

        return 0;
    }