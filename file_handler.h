
#ifndef __file_handler_h
#define __file_handler_h

#define READING_MODE                        "r"

#if 1
#define MATRIXA_FILENAME                    "matrixA2500.txt"
#define MATRIXB_FILENAME                    "matrixB2500.txt"
#else
#define MATRIXA_FILENAME                    "matrixA1048576.txt"
#define MATRIXB_FILENAME                    "matrixB1048576.txt"
#endif


#define NUM_FILES                           2
#define MAX_FILES                           2

/*
* Function that executes the reading process of the two txt files that contains the arrays of array
* and saves them in dynamic memory arrays of arrays.
*
* params ->		    matrix_data[] Struct that contains data of both arrays, like the size of rows and columns, num of elements in the actual array and in the txt, and pointer to allocated memory
*
* return ->         void
*
*
*/
processStatus_t loadTxts(matrix_t matrix_data[]);


/*
* Function that open the txt file, read it and counts the num of elements that the array can have. This quantity is saved on numElements[]
*
* params ->         filePointer:      pointer to the txt file
*                   i:                counter to identify which of the two txt files we are handling
* return ->         void
*
*
*/
void numElementsTxt(FILE* filePointer, uint8_t i, matrix_t matrix_data[]);

/*
* Function
*
* params ->
*
* return ->         void
*
*
*/

processStatus_t verifySize(matrix_t matrix_data[], uint8_t i, const char* stringArray[NUM_FILES]);

/*
* Function
*
* params ->
*
* return ->         void
*
*
*/

processStatus_t convertToDynamic(FILE* filePointer, uint8_t i, matrix_t matrix_data[]);


/*
* Function 
*
* params ->         
*                   
* return ->         void
*
*
*/

void readElements(FILE* filePointer, uint8_t i, matrix_t matrix_data[]);



/*
* Function
*
* params ->
*
* return ->         void
*
*
*/

processStatus_t printArray(uint8_t i, matrix_t matrix_data[]);









#endif // __file_handler_h