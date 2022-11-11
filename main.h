
#ifndef __main_h
#define __main_h

#include <stdarg.h>
#include <stdio.h>
#include <conio.h>  /* for clrscr */
#include <dos.h>  /* for delay */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

#define ALIGNMENT_8                         8
#define FIRST_MATRIX                        0
#define SECOND_MATRIX                       1

// total amount of elements of the array
#define TOTAL_ELEM_ARRAY                    (matrix_data[i].rows*matrix_data[i].columns)
#define MATRIX(i)                           matrix_data[i].ptrArray
#define POSITION(x,y)                       (x * matrix_data[i].columns) + y
#define MAX_ROWS                            matrix_data[i].rows
#define MAX_COLUMNS                         matrix_data[i].columns


#define print_matrix(which_matrix)          printArray(which_matrix, matrix_data);


#define ending_program                      _aligned_free(array1); \
                                            return 3;


#define MALLOC_ARRAY(number, type) \
    ((type *)malloc((number) * sizeof(type)))

#define ALIGNED_MALLOC(SIZE, ALIGNMENT, TYPE) \
    (TYPE*)_aligned_malloc(SIZE*sizeof(TYPE*),ALIGNMENT)

//          __mm__malloc   preferencia intrinsicas

//          _aligned_malloc windows

#define CALLOC_ARRAY(elements, type) \
    ((type *)calloc(elements, (elements) * sizeof(type)))


#if 0
#define ENABLE_DEBUG_MESSAGES
#endif


#ifdef  ENABLE_DEBUG_MESSAGES
#define PRINT_PARAMS(value,...)             printf( #value "\n",## __VA_ARGS__);
#define PRINT(value)                        printf( #value "\n");
#define DEBUG(value)                        value
#else
#define PRINT_PARAMS(value,...) 
#define PRINT(value)
#define DEBUG(value)
#endif


typedef enum processStatus
{
    Success,
    Error
}processStatus_t;


//static long long numElements[NUM_FILES];
static double* array1;
static double* array2;


//Struct that contains the all the important information about a matrix defined. 
//The data the struct contains is the quantity of rows and columns the matrix has, how many elements it has and how many is the 
//number of elements in its txt file
//The ptrArray points to the beggining of the allocated memory, so It can access the array from this struct.
typedef struct matrix
{
    long long rows;
    long long columns;
    long long numElements;
    long long numElementsInTxt;
    double*   ptrArray;
    
}matrix_t;

#endif // __main_h