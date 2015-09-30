#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <stdlib.h>

typedef int (*CompareFuncT)( void *, void * );
typedef void (*DestructFuncT)( void * );

/*typedef struct Node_
{
	void* dataPtr;
	void* next;
	int refCount;
}Node;*/

struct SortedList 
{
	CompareFuncT cf;
	int numItems;
	Node* head;
};
typedef struct SortedList* SortedListPtr;

struct SortedListIterator
{
       	void* dataPtr;
	void* next;
	int refCount;
};
typedef struct SortedListIterator* SortedListIteratorPtr;

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df);

void SLDestroy(SortedListPtr list);

int SLInsert(SortedListPtr list, void *newObj);

int SLRemove(SortedListPtr list, void *newObj);

SortedListIteratorPtr SLCreateIterator(SortedListPtr list);

void SLDestroyIterator(SortedListIteratorPtr iter);

void * SLNextItem(SortedListIteratorPtr iter);

void * SLGetItem( SortedListIteratorPtr iter );



#endif


