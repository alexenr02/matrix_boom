
#include "main.h"
#include "file_handler.h"
#include "math_operation.h"
#include "user_input_handler.h"

#define numThreads_omp 6

int main(void) 
{  
	clock_t start_t, end_t, total_t;
    matrix_t matrix_data[4] = {0,0,0,0, NULL};

    if (loadTxts(matrix_data) != Success)
    {
        return Error;
    }


	start_t = clock();
    matrix_mult_serial(matrix_data);
	end_t = clock();
	total_t = end_t - start_t;
	printf("\nTiempo: %f segundos\n", ((float)total_t) / CLOCKS_PER_SEC);
    
	writeElements(matrix_data);

    ending_program
}
