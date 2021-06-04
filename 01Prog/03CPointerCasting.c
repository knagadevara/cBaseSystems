#include <stdio.h>

int main(void)
{
    int oneBit = 1024;
    int* pointertoOneBit = &oneBit;
    char initialName = 'N';
    char* pointertoInitialName = &initialName;
    char* charPointer; 
    
    printf("Indirect Referencing of oneBit through pointertoOneBit.\n\tAddress of oneBit = %x\n\tValue of oneBit = %d\n", pointertoOneBit , *pointertoOneBit );
    printf("Pointer Arthmatic on pointertoOneBit, Adding Size of IntegerType, which is %d bytes\n\tAddress of pointertoOneBit after increasing it by 1x4 = %x\n\tValue of pointertoOneBit = %d\n", sizeof(int) , pointertoOneBit + 1 , *(pointertoOneBit + 1) );
    printf("Indirect Referencing of initialName through pointertoInitialName.\n\tAddress of initialName = %x\n\tValue of initialName = %c\n", pointertoInitialName , *pointertoInitialName );
    printf("Pointer Arthmatic on pointertoInitialName, Adding Size of CharacterType, which is %d bytes\n\tAddress of pointertoInitialName after increasing it by 1x4 = %x\n\tValue of pointertoInitialName = %c\n", sizeof(char) , pointertoInitialName + 1 , *(pointertoInitialName +1) );
    // Saving the address of int type into a char type   
    // pointertoOneBit is an integer pointer which has the address of oneBit. Saving that to character type
    charPointer = (char*)pointertoOneBit;
    printf("Address at charPointer: %x and Value charPointer %d\n", charPointer, *charPointer);
    return 0;
}
