#include "dataStructuresExercise1.h"

int main()
{
    int nums[] = { -4, -1, 0, 3, 10 };
    int numsLength = sizeof(nums) / sizeof(int);
    int dataSize = sizeof(int);
    int* result;

    printf("Exercise 1:\n\n");
    printf("Input: nums\n");
    showData( nums, dataSize, numsLength, showInt );

    if(         !validateInt( numsLength, LOWER_LENGTH_LIMIT, UPPER_LENGTH_LIMIT )           )
    {
        printf("ERROR: Array length is not valid\n");
        return LENGTH_ERROR;
    }

    result = malloc( numsLength * dataSize );

    if(         !result         )
    {
        printf("ERROR: Could not allocate memory\n");
        return MALLOC_ERROR;
    }

    if(         !validateArrayContentAndCalculateSolution( nums, result, numsLength, MIN_VALUE, MAX_VALUE )            )
    {
        printf("ERROR: Array content is not valid\n");
        free(result);
        return ARRAY_CONTENT_ERROR;
    }

    printf("Output: result\n");
    showData( result, dataSize, numsLength, showInt );
    free( result );

    return 0;
}

//Cases to test the code:
    ///empty array case -> return 0
//    {};
    ///one element case -> return 0
//    { -2 };
    ///104 elements with valid ranges case -> return 0
//    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
//    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
//    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
//    60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
//    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
//    100, 101, 102, 103};

    ///105 elements with valid range case   -> return LENGTH_ERROR
//    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
//    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
//    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
//    60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
//    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
//    100, 101, 102, 103, 104};
    ///content error cases -> return ARRAY_CONTENT_ERROR
//    { 1, 105 };
//    { -105, 1 };
    ///valid content case -> return 0
//    { -104, 104 };
    ///Random cases:
//    { -4, -3, 0, 1, 2 };
//    { -4, -3, 100, 101, 102 };
//    { -104, -103, -102, -101, 2, 3, 5 };
//    { -4, -1, 0, 3, 10 };
//    { -4, -3, 1, 2 };
