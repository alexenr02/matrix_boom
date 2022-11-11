#include "main.h"
#include "file_handler.h"
#include "math_operation.h"



processStatus_t validation_of_matMult(matrix_t matrix_data[])
{
	if (matrix_data[FIRST_MATRIX].columns != matrix_data[SECOND_MATRIX].rows)
	{
		printf("\n\nERROR: These arrays cannot be multiplied.\n");
		printf("Number of Columns of first matrix: %lld\n", matrix_data[FIRST_MATRIX].columns);
		printf("Number of rows of second matrix: %lld\n", matrix_data[SECOND_MATRIX].columns);
		printf("Different sizes of rows and columns\n\n");

		return Error;
	}
	return Success;
}

processStatus_t validation_of_matMult(matrix_t matrix_data[])
{

}