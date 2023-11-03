#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMUM( X, Y ) ( ( X < Y ) ? (X) : (Y) )

typedef struct sNode
{
    void* data;
    size_t dataSize;
    struct sNode* next;
}tNode;

typedef struct
{
    tNode* first;
    tNode* last;
}tQueue;

void createQueue( tQueue* q );
int qPush( tQueue* q, const void* data, size_t dataSize );
int qPop( tQueue* q, void* data, size_t dataSize );
int qEmpty( const tQueue* q );
int fullQueue( const tQueue* q, size_t dataSize );
void clearQueue( tQueue* q );
int qFront( const tQueue* q, void* data , size_t dataSize );

#endif // QUEUE_H_INCLUDED
