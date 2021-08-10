#include <stdio.h>

/*
Creating a 3D array
// 000 , 001 , 010 , 011
// 100 , 101 , 110 , 111
// 200 , 201 , 210 , 211
*/ // threeDArray[x][y][z] :-> makes x arrays which contains y rows and z collumns.

    int threeDArray[3][2][2] = {
        { {20 , 30} , {40 , 50} },
        { {21 , 31} , {41 , 51} },
        { {22 , 32} , {42 , 52} }
    };

int countMeUpFor(int (*array3D)[2][2])

    {
        int lenOfArray  = sizeof(array3D)/sizeof(int); // Why is the length of the array a different value here?
        for ( int i = 0 ; i < 3 ; i++ ) // iterates over the arrays in this case there are 3
            {
                for ( int j = 0 ; j < 2 ; j++ ) // iterates over the rows in this case there are 2 rows per array
                    {
                        for ( int k = 0 ; k < 2 ; k++ ) // iterates over the columns in this case there are 2 colums per rows
                        {
                        printf("\n array3D[%d][%d][%d] \n Address: %p\t Value: %d\n",i,j,k, &array3D[i][j][k] , array3D[i][j][k]);
                        }
                    }
            }

        return lenOfArray ;
    }

// void countMeUpWhile(int (*startAdd)[2][2] , int (*endAdd)[2][2])
void countMeUpWhile(int *startAdd , int *endAdd)
    {
        while (startAdd <= endAdd)
        {
            printf("\nAddress: %p\tValue: %d\n", startAdd , *startAdd) ;
            startAdd++ ; 
        }
    }

int main(void)
    {

    int lenOfArray = sizeof(threeDArray)/sizeof(int);
    int lenOfArray2 = countMeUpFor(threeDArray); // Why length of array is 2?
    printf("length of Array: %d\n" , lenOfArray ) ;
    printf("length of Array: %d\n" , lenOfArray2 ) ;
    // printf("Address of Array object at: %d\n" , *threeDArray[lenOfArray - 1]) ;
    countMeUpWhile(&threeDArray[0][0][0] , &threeDArray[2][1][1]);
    return 0;
    
    }