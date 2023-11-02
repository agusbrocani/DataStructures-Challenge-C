#ifndef DATASTRUCTURESEXERCISE2_H_INCLUDED
#define DATASTRUCTURESEXERCISE2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LOWER_LENGTH_LIMIT 1
#define UPPER_LENGTH_LIMIT 104

#define MIN_VALUE -104
#define MAX_VALUE 104

//ERRORS:
#define LENGTH_ERROR -1
#define MALLOC_ERROR 1
#define ARRAY_CONTENT_ERROR 2


typedef struct
{
    int starti;
    int endi;
}tInterval;

void showInterval( const void* data );
void showData( const void* data, int dataSize, int dataLength, void (*show)( const void* data ) );

int validateInt( int number, int lowerLimit, int upperLimit );

#endif // DATASTRUCTURESEXERCISE2_H_INCLUDED
