
#include "main.h"
#include "file_handler.h"
#include "math_operation.h"


int main(void) 
{  
    matrix_t matrix_data[NUM_FILES] = {0,0,0,0, NULL};

    if (loadTxts(matrix_data) != Success)
    {
        return Error;
    }
    
    DEBUG(print_matrix(FIRST_MATRIX);
    print_matrix(SECOND_MATRIX);)

    if (validation_of_matMult(matrix_data) == Success)
    {
        printf("\n[");
        for (int x = 0; x < 10; x++)
        {
            printf("=");
            Sleep(50);
        }
        printf(">] 100% \n");
    }
    
    matrix_multiplication(matrix_data);
    
    
    ending_program
}