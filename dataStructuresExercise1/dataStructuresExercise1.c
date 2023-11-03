#include "dataStructuresExercise1.h"

int validateInt( int number, int lowerLimit, int upperLimit )
{
    return ( number >= lowerLimit && number <= upperLimit );
}

int* validateArrayContentAndCalculateSolution( const int* nums, int* result, int numsLength, int minValue, int maxValue )
{
    const int* startOfNums = nums;                  //startOfNums points to first element of the nums array
    const int* endOfNums = nums + numsLength - 1;   //endOfNums points to last element of the nums array
    int initialPointerResult;
    int finalPointerResult;
    int remainToBeOrdered = numsLength;
    int insertPosition = numsLength - 1;            //insertPosition is the index of the results array where the data insertion begins

    while(          remainToBeOrdered           )
    {
        if(         !validateInt( *startOfNums, minValue, maxValue) || !validateInt( *endOfNums, minValue, maxValue )          )    //validation of the contents of the nums array
        {
            return NULL;
        }

        initialPointerResult = pow( *startOfNums, 2 );                  //solution calculation
        finalPointerResult = pow( *endOfNums, 2);

        if(         initialPointerResult > finalPointerResult         ) //insert sorted into results array
        {
            *( result + insertPosition ) = initialPointerResult;
            startOfNums++;                                              //increments startOfNums pointer if insert elements from left
        }
        else
        {
            *( result + insertPosition ) = finalPointerResult;
            endOfNums--;                                                //increments endOfNums pointer if insert elements from right
        }
        insertPosition--;
        remainToBeOrdered--;
    }

    return result;
}

void showInt( const void* data )
{
    printf("%d\t", *(int*)data );
}

void showData( const void* data, int dataSize, int dataLength, void (*show)( const void* data ) )
{
    int i;

    for( i = 0; i < dataLength; i++ )
    {
        show( data );
        data += dataSize;
    }
    printf("\n\n");
}
