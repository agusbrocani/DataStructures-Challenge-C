#ifndef DATASTRUCTURESEXERCISE2_H_INCLUDED
#define DATASTRUCTURESEXERCISE2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "dataStructures/queue.h"

#define LOWER_LENGTH_LIMIT 1
#define UPPER_LENGTH_LIMIT 104

#define MIN_VALUE 0
#define MAX_VALUE 104

//ERRORS:
#define LENGTH_ERROR -1
#define ARRAY_CONTENT_ERROR 2

#define OK 1

typedef struct
{
    int starti;
    int endi;
}tInterval;

void showInterval( const void* data );
void showData( const void* data, int dataSize, int dataLength, void (*show)( const void* data ) );

int validateInt( int number, int lowerLimit, int upperLimit );
int validateInterval( tInterval* interval, int minValue, int maxValue );

int thereIsOverlap( tInterval* firstInterval, tInterval* secondInterval );
int validateArrayContentAndLoadResultsArray( tInterval* intervals, tInterval* result, int dataSize, int intervalsLength, int* resultLength, int minValue, int maxValue );

#endif // DATASTRUCTURESEXERCISE2_H_INCLUDED
