
#include "main.h"
#include "file_handler.h"


int main(void) 
{  
    matrix_t matrix_data[NUM_FILES] = {0,0,0,0, NULL};

    processStatus_t result = loadTxts(matrix_data);
    if (result != Success)
    {
        return Error;
    }
    else
    {
        
    }
    _aligned_free(array1);
    return 0;
}