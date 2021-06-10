#include <stdio.h>
#include <string.h>

char firstName[4] = {'S' , 'a' , 'i' ,'\0'}; // one cannot declare and initialize the charater type seperately it is a compiler error '\0' is a terminator and tells that there are no charactyers after this point
char lastName[] = "Nagadevara" ; // This is known as a string literal and it dosent not reqire a '\0' to tell it is the end.

int printFirstName(char* firstName)
    {
        while (*firstName != '\0')
        {
            printf("firstName: %c. SizeOf: %ld\n", *firstName, sizeof(*firstName));
            firstName = firstName + 1 ; // or firstName++ will add one unit size of character type to first name and saved it again. remember that thae evaluation happens from right to left
        }
        return 0;
    }

int main(void)
    {
        printFirstName(firstName); // passes the address of the first byte character type array index
        printf("lastName: %s. SizeOf: %ld and Length: %ld\n", lastName, sizeof(lastName) , strlen(lastName));
        return 0;
    }