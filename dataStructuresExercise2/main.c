#include "dataStructuresExercise2.h"

int main()
{
    tInterval intervals[] =
    {
        { 1, 3 },
        { 2, 6 },
        { 3, 7 },
        { 8, 10 },
        { 15, 18 },
        {18, 20},
        {21,22}
    };
    int dataSize = sizeof(tInterval);
    int intervalsLength = sizeof(intervals) / dataSize;
    tInterval result[intervalsLength];
    int resultLength = 0;

    printf("Input: intervals\n");
    showData( intervals, dataSize, intervalsLength, showInterval );

    if(         !validateInt( intervalsLength, LOWER_LENGTH_LIMIT, UPPER_LENGTH_LIMIT )            )
    {
        printf("ERROR: Array length is not valid\n");
        return LENGTH_ERROR;
    }

    if(         ARRAY_CONTENT_ERROR == validateArrayContentAndLoadResultsArray( intervals, result, dataSize, intervalsLength, &resultLength, MIN_VALUE, MAX_VALUE )           )
    {
        printf("ERROR: Array content is not valid\n");
        return ARRAY_CONTENT_ERROR;
    }

    printf("Output: result\n");
    showData( result, dataSize, resultLength, showInterval );

    return 0;
}

    /// (1,3), (2,6), (8,10), (15,18)   ->  (1,6), (8,10), (15,18)
    /// (1,3), (2,6), (3,7), (8,10), (15,18) -> (1,7), (8,10), (15,18)
    /// (1,2),(1,3), (2,6), (3,7), (8,10), (15,18) -> (1,7),(8,10), (15,18)
//    {
//       {1,2},
//       {1,3},
//       {2,6},
//       {3,7},
//       {8,10},
//       {15,18},
//    };

