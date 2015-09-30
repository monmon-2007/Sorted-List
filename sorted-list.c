#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sorted-list.h"


SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{
    
    
   
    SortedListPtr sort = malloc(sizeof(struct SortedList));
    memset(sort,0,sizeof(struct SortedList));
    
    if(sort == NULL )
    {
        printf("ERROR: OUT OF MEMORY\n");
        return NULL;
    }
        
    sort->cfStruct = cf;
    sort->dfStruct = df;
    sort->head = NULL;
    
    return sort;
}


void SLDestroy(SortedListPtr list)
{
     
     free(list);
}

int SLInsert(SortedListPtr list, void *newObj)
{
    list->head->dataPtr = newObj;
    list->head->dataPtr++;
    return 0;
}
    
    
