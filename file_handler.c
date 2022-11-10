
#include "main.h"
#include "file_handler.h"

static void numElementsTxt(FILE* filePointer, uint8_t i, matrix_t matrix_data[])
{
    double fp;
    //PRINT(Contenido del archivo : );   //debug message
    while (feof(filePointer) == 0)
    {
        if (fscanf_s(filePointer, "%lf", &fp) == Error)
        {
            //PRINT_PARAMS(%lf,fp);         //debug message
            matrix_data[i].numElementsInTxt++;                //counting num of elements that the matrix will can have to allocate that amount of  memory
        }

    }
}


static void readElements(FILE* filePointer, uint8_t i, matrix_t matrix_data[])
{
    double fp;
    long long max_elem_allowed = TOTAL_ELEM_ARRAY;

    int r = 0, c = 0;

    rewind(filePointer);
    while ((feof(filePointer) == 0) && max_elem_allowed != 0)
    {
        if (fscanf_s(filePointer, "%lf", &fp) == Error)
        {

            if (r < matrix_data[i].rows)
            {
                if (c < matrix_data[i].columns)
                {
                    (array1[(r * matrix_data[i].columns) + c]) = fp;
                    c++;
                    if (c == matrix_data[i].columns)
                    {
                        c = 0;
                        r++;
                    }

                }
            }
        }
        max_elem_allowed--;
    }
}

processStatus_t verifySize(matrix_t matrix_data[], uint8_t i, const char* stringArray[NUM_FILES])
{
    if (TOTAL_ELEM_ARRAY > matrix_data[i].numElementsInTxt)
    {
        printf("\n\n ------------------- Error --------------------------------");
        printf("\n\nElements of the text file %s available ----> %lld \n\n", stringArray[i], matrix_data[i].numElementsInTxt);

        printf("Elements asked ----> %lld\n\n", TOTAL_ELEM_ARRAY);
        printf("Error: Elements in the text file are not enough");
        return Error;
    }
    return Success;
}


processStatus_t printArray(uint8_t i, matrix_t matrix_data[])
{
    for (long long x = 0; x < matrix_data[i].rows; x++)
    {
        for (long long y = 0; y < matrix_data[i].columns; y++)
        {
            printf("%.10lf\t", matrix_data[i].ptrArray[(x * matrix_data[i].columns) + y]);
        }
        printf("\t\n");
    }
}

processStatus_t convertToDynamic(FILE* filePointer, uint8_t i, matrix_t matrix_data[])
{
    /************************ DEBUG MESSAGES ***************************/
                                                                       //
    DEBUG(long long x = 0;)                                            //
    PRINT_PARAMS(array1 tam : % lld, TOTAL_ELEM_ARRAY);                //
    DEBUG(x = (long long)sizeof(double) * TOTAL_ELEM_ARRAY;)           //
    PRINT_PARAMS(tamaño en bytes : % lld, x);                          //
                                                                       //
/*******************************************************************/


    switch (i)
    {
        //Fill the first matrix
    case FIRST_ARRAY:
        array1 = ALIGNED_MALLOC(TOTAL_ELEM_ARRAY, ALIGNMENT_8, double); //      returns a pointer to a block of (TOTAL_ELEM_ARRAY * sizeof(*double)) memory alligned to 8 bytes
        matrix_data[i].ptrArray = array1;

        if (array1 != NULL)
        {
            readElements(filePointer, i, matrix_data);
            printArray(i, matrix_data);
            //DEBUG(printf("Memoria almacenada correctamente: %lld bytes\n", (long long)_aligned_msize(array1, ALIGNMENT_8, 0));)
        }
        else
        {
            printf("Memory not allocated, error ");
            perror("Malloc");

            return Error;
        }
        break;
        //Fill the second matrix
    case SECOND_ARRAY:
        array2 = ALIGNED_MALLOC(TOTAL_ELEM_ARRAY, ALIGNMENT_8, double); //      returns an 8 BYTE aligned block of memory of total elements * 8 bytes
        matrix_data[i].ptrArray = array1;
        if (array2 != NULL)
        {
            readElements(filePointer, i, matrix_data);
            printArray(i, matrix_data);

            //DEBUG(printf("Memoria almacenada correctamente: %lld bytes\n", (long long)_aligned_msize(array1, ALIGNMENT_8, 0));)
        }
        else
        {
            printf("Memory not allocated, error ");
            perror("Malloc");

            return Error;
        }
        break;

    default:
        printf("cannot be more than 2 matrix");
        return Error;
        break;
    }

    return Success;
}



/*
* Function that executes the reading process of the two txt files that contains the arrays of array
* and saves them in dynamic memory arrays of arrays.
*/
processStatus_t loadTxts(matrix_t matrix_data[])
{

    _Post_ _Notnull_ FILE* filePointer; /* declare the file pointer */
    FILE* filePointer_aux = NULL;
    uint8_t readStatus = 0;


    const char* stringArray[NUM_FILES] =        //Setting an array with the names of the two txt files
    {
        MATRIXA_FILENAME,
        MATRIXB_FILENAME
    };


    //loop to read two files that contains many double (8 byte) variables
    for (uint8_t i = 0; i < NUM_FILES; i++)
    {
        printf("---Matrix %d---\n", i + 1);
        printf("Give me the rows: ");
        matrix_data[i].rows = userinput(matrix_data[i].rows);
        printf("Give me the columns: ");
        matrix_data[i].columns = userinput(matrix_data[i].columns);
        matrix_data[i].numElements = TOTAL_ELEM_ARRAY;

        processStatus_t reading = (fopen_s(&filePointer, stringArray[i], READING_MODE)); //Opening file in read mode
        filePointer_aux = filePointer; // save the file pointer read

        //Validation of the file reading process
        if (((reading != Success) || (filePointer == NULL || filePointer == 0)) && NUM_FILES > MAX_FILES)
        {
            printf("Error! Failed to open file!");
            return Error;
        }
        else
        {
            //counts the elements in the two files and saves it in matrix_data.numElementsInTxt for each file. matrix_data.numElementsInTxt contains the num of elements available in the first file
            numElementsTxt(filePointer, i, matrix_data);

            //Verify if the file contains the required num of elements to create the matrix of the size that the user requires
            if (verifySize(matrix_data, i, stringArray) != Success)
            {
                return Error;
            }

            //Proceed to create the dynamic arrays
            convertToDynamic(filePointer, i, matrix_data);

            PRINT_PARAMS(File % s opened and %lld data loaded into dynamic matrix, stringArray[i], TOTAL_ELEM_ARRAY);

            if (fclose(filePointer) != Success || filePointer == NULL || filePointer != filePointer_aux)  /* close the file prior to exiting the routine */
            {
                printf("problemas al cerrar el archivo");
                return Error;
            }

        }


    }
    return Success;
}

