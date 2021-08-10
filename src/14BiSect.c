#include <stdio.h>
#include <stdlib.h>


int values[] = { 88, 56, 100, 2, 25 };

// void ASSERT(int a)
//     { if (a){
//             printf("Failure!!\n");
//         }
//     }

int comparator(const void* lhs, const void* rhs)
    {
        return ( *(int*)lhs - *(int*)rhs );
    }

void print_data(const int* const data, size_t len)
    {
        for(int i = 0; i < len; ++i)
                printf("%d ", data[i]);
        printf("\n");
    }

int bisect(int guess, int* data, size_t len)
    {
        qsort(data, len, sizeof(int), comparator);
        print_data(data, len);
        printf("Data Sorted!\n");
        int mid = 0, low = 0, high = 0;
        high = len - 1; //4
        mid = len/2 ; //2

        while (low <= high)
            {

                mid = (low + high)/2;

                 if(guess == data[mid])
                    {
                        printf("guess == data[mid]\n");
                        printf("low: %d\n" , low);
                        printf("mid: %d\n" , mid);
                        printf("guess: %d\n" , guess);
                        printf("data[mid]: %d\n" , data[mid]);
                        return mid;
                        break;
                    }
                else if(guess > data[mid])
                    {
                        low = mid + 1;
                        printf("guess > data[mid]\n");
                        printf("low: %d\n" , low);
                        printf("mid: %d\n" , mid);
                        printf("guess: %d\n" , guess);
                        printf("data[mid]: %d\n" , data[mid]);
                    }
                else
                    {
                        high = mid - 1;
                        printf("guess < data[mid]\n");
                        printf("low: %d\n" , low);
                        printf("mid: %d\n" , mid);
                        printf("guess: %d\n" , guess);
                        printf("data[mid]: %d\n" , data[mid]);
                    }
            }
            return -1;
    }

int main(void)
    {
        int* item1 = (int*) calloc(1 , sizeof(int)); 
        int* item2 = (int*) calloc(1 , sizeof(int)); 
        *item1 = 100;
        *item2 = 110;
        int some_val = comparator(item1 , item2);
        printf("%d\n",some_val);
        print_data(values,5);
        int my_val = bisect( 100, values, 5);
        printf("%d\n",my_val);
        // int val_2 = 5;
        // printf("%d\n",val_2/2);
        return 0;
    }