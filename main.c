
#include <omp.h>
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
    int i, j, k;
    omp_set_num_threads(omp_get_num_procs());
	start_t = clock();
    matrix_mult_serial(matrix_data);
    #pragma omp parallel for private(i,j,k) shared(array1,array2,array3)
    for (i = 0; i < matrix_data[RESULT_MATRIX].rows; ++i)
    {
        for (j = 0; j < matrix_data[RESULT_MATRIX].columns; ++j)
        {
            for (k = 0; k < matrix_data[FIRST_MATRIX].columns; ++k)
            {
                MAT_AND_COORD(RESULT_MATRIX, i, j) += (MAT_AND_COORD(FIRST_MATRIX, i, k) * MAT_AND_COORD(SECOND_MATRIX, k, j));
            }
        }
    }

	end_t = clock();
	total_t = end_t - start_t;
	printf("\nTiempo: %f segundos\n", ((float)total_t) / CLOCKS_PER_SEC);
	writeElements(matrix_data);
    print_matrix(RESULT_MATRIX);

    ending_program


}

