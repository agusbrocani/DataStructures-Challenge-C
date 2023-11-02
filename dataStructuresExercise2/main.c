#include "dataStructuresExercise2.h"

int main()
{
    tInterval intervals[] =
    {
        { 1, 3 },
        { 2, 6 },
        { 8, 10 },
        { 15, 18 },
    };
    int dataSize = sizeof(tInterval);
    int intervalsLength = sizeof(intervals) / dataSize;
    tInterval result[intervalsLength];  ///ELEGI ESTO POR EL PADDING PARA EVITAR PROBLEMAS CON EL BYTE ALIGNMENT

    printf("Input: intervals\n");
    showData( intervals, dataSize, intervalsLength, showInterval );

    if(         !validateInt( intervalsLength, LOWER_LENGTH_LIMIT, UPPER_LENGTH_LIMIT )            )
    {
        printf("ERROR: Array length is not valid\n");
        return LENGTH_ERROR;
    }



    printf("Output: result\n");
    showData( result, dataSize, intervalsLength, showInterval );

    return 0;
}
