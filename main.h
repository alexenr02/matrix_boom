
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
// total amount of elements of the array
#define TOTAL_ELEM_ARRAY                    (matrix_data[i].rows*matrix_data[i].columns)
#define TOTAL_ELEM_ARRAY_PTR                (matrix_data->rows*matrix_data->columns)
#define FIRST_ARRAY                         0
#define SECOND_ARRAY                        1
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

typedef struct matrix
{
    long long rows;
    long long columns;
    long long numElements;
    long long numElementsInTxt;
    double*   ptrArray;
    
}matrix_t;

#endif // __main_h