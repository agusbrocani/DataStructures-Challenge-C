#ifndef DATASTRUCTURES_H_INCLUDED
#define DATASTRUCTURES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LOWER_LENGTH_LIMIT 1
#define UPPER_LENGTH_LIMIT 104

#define MIN_VALUE -104
#define MAX_VALUE 104

//ERRORS:
#define LENGTH_ERROR -1
#define MALLOC_ERROR 1
#define ARRAY_CONTENT_ERROR 2

int validateInt( int number, int lowerLimit, int upperLimit );

int* validateArrayContentAndCalculateSolution( const int* nums, int* result, int numsLength, int minValue, int maxValue );

void showInt( const void* data );
void showData( const void* data, int dataSize, int dataLength, void (*show)( const void* data ) );


#endif // DATASTRUCTURES_H_INCLUDED
