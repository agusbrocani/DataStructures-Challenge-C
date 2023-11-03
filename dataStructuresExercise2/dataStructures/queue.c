#include "queue.h"

void createQueue( tQueue* q )
{
    q -> first = NULL;
    q -> last = NULL;
}

int qPush( tQueue* q,const void* data, size_t dataSize )
{
    tNode* newNode = (tNode*)malloc( sizeof(tNode) );

    if(         !newNode            )
    {
        return 0;
    }

    newNode -> data = malloc( dataSize );

    if(         !( newNode-> data )          )
    {
        free( newNode );
        return 0;
    }

    newNode ->dataSize = dataSize;
    newNode -> next = NULL;
    memcpy( newNode -> data, data, dataSize );

    if(         NULL == q -> first           )
    {
        q -> first = newNode;
    }
    else
    {
        q-> last -> next = newNode;
    }

    q-> last = newNode;

    return 1;
}

int qPop( tQueue* q, void* data, size_t dataSize )
{
    tNode* aux = q -> first;

    if(         !aux            )
    {
        return 0;
    }

    memcpy( data, aux -> data, MINIMUM( dataSize, aux -> dataSize ) );

    q -> first = aux -> next;
    free( aux -> data );
    free(aux);

    if(         !( q -> first )           )
    {
        q -> last = NULL;
    }

    return 1;
}
int qEmpty( const tQueue* q )
{
    return NULL == q -> first;
}
int fullQueue( const tQueue* q, size_t dataSize )
{
    tNode* newNode = (tNode*)malloc( sizeof(tNode) );
    void* data = malloc( dataSize );
    free( data );
    free( newNode );
    return !( newNode || data );
}
void clearQueue( tQueue* q )
{
    tNode* aux;

    while(          q -> first          )
    {
        aux = q -> first;
        q -> first = aux -> next;
        free( aux -> data );
        free( aux );
    }
}
int qFront( const tQueue* q, void* data, size_t dataSize )
{
    if(         !( q -> first )           )
    {
        return 0;
    }
    memcpy( data, q -> first -> data, MINIMUM( dataSize, q -> first -> dataSize ) );
    return 1;
}
