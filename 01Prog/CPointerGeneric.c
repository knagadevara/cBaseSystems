#include <stdio.h>

int main() {

    int width_val;
    int *p_width_val ;
    width_val = 20 ;
    p_width_val = &width_val;

    /* width_val is an integer type variable. p_width_val is a pointer variable of type integer */ 
    
    printf("&p_width_val p  %x\n", &p_width_val); // Address of p_width_val
    printf("p_width_val p %x\n", p_width_val); // Address of width_val
    printf("p_width_val d %d\n", *p_width_val); // the contents of the address which is present i.e the value of width_val 
    printf("&width_val p %x\n", &width_val); // Address of width_val same as contents of  p_width_val 
    printf("width_val  d %d\n", width_val); // Value at width_val
    
    return 0;
}