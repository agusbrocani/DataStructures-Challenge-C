#include "dataStructuresExercise2.h"

int validateInt( int number, int lowerLimit, int upperLimit )
{
    return !( number >= lowerLimit && number <= upperLimit ) ? false : true;
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
