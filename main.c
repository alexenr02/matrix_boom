
#include "main.h"
#include "file_handler.h"
#include "math_operation.h"
#include "user_input_handler.h"


int main(void) 
{  
    matrix_t matrix_data[4] = {0,0,0,0, NULL};

    if (loadTxts(matrix_data) != Success)
    {
        return Error;
    }

    print_matrix(SECOND_MATRIX);
    matrix_transpose(matrix_data, SECOND_MATRIX);
    print_matrix(SECOND_MATRIX);
    //matrix_mult_serial(matrix_data);
    //matrix_transpose(matrix_data, RESULT_MATRIX);
    //print_matrix(RESULT_MATRIX);
    //writeElements(matrix_data);

    ending_program
}