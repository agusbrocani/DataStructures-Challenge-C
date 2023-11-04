#include "dataStructuresExercise2.h"

int validateInt( int number, int lowerBound, int upperBound )
{
    return ( number >= lowerBound && number <= upperBound );
}

void showInterval( const void* data )
{
    printf("%d\t%d\n", ((tInterval*)data)->starti, ((tInterval*)data)->endi );
}

void showData( const void* data, int dataSize, int dataLength, void (*show)( const void* data ) )
{
    int i;

    for( i = 0; i < dataLength; i++ )
    {
        show( data );
        data += dataSize;
    }
    printf("\n");
}

int validateInterval( tInterval* interval, int minValue, int maxValue )
{
    return ( validateInt( interval->starti, minValue, maxValue ) && validateInt( interval->endi, minValue, maxValue ) && ( interval->starti <= interval->endi ) );
}

int thereIsOverlap( tInterval* firstInterval, tInterval* secondInterval )
{
    if(         firstInterval->endi < secondInterval->starti         )
    {
        return false;
    }

    firstInterval->endi = secondInterval->endi; //first Interval->starti is already the smaller of the two start values.

    return true;
}

tInterval* validateArrayContentAndLoadResultsArray( tInterval* intervals, tInterval* result, int dataSize, int intervalsLength, int* resultLength, int minValue, int maxValue )
{
    tQueue resultsQueue;    ///I used a queue to demonstrate my knowledge of data structures, but I could have directly loaded the result into the result array.
    tInterval firstInterval;
    int toBeTraversed = intervalsLength;
    int i = 0;

    createQueue( &resultsQueue );

    while(          toBeTraversed           )
    {
        firstInterval = intervals[i];   //firstInterval is a variable used to store the interval that will be saved in the results queue.

        if(         !validateInterval( &firstInterval, minValue, maxValue )         )    //validateInterval ensures that intervals satisfy all preconditions.
        {
            return NULL;
        }

        //If there is no overlap, thereIsOverlap returns false. However, if there is an overlap, thereIsOverlap combines both intervals and loads the result into firstInterval.
        while(          toBeTraversed && thereIsOverlap( &firstInterval, &intervals[i + 1] )            )
        {
            if(         !validateInterval( &intervals[i + 1], minValue, maxValue ))
            {
                return NULL;
            }
            i++;
            toBeTraversed--;
        }
        qPush( &resultsQueue, &firstInterval, dataSize );   //firstInterval contains a valid interval to be loaded into the result.

        i++;
        toBeTraversed--;
    }

    while(          !qEmpty( &resultsQueue )            )       //clear queue and load result array.
    {
        qPop( &resultsQueue, &firstInterval, dataSize );
        result[(*resultLength)] = firstInterval;                //The length variable is used as an index and then the length is incremented.
        (*resultLength) ++;
    }
    clearQueue( &resultsQueue );            //to ensure no memory leaks.

    return result;
}
