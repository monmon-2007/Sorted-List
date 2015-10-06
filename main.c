//Roberto Merino
//Mina G.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sorted-list.h"

int compareStrings(void *p1, void *p2)
 {
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

int compareInts(void *a, void *b)
{
	int i = *(int*)a;
	int j = *(int*)b;

	return i - j;
}

int compareDoubles(void *a, void *b)
{
	float i = *(float*)a;
	float j = *(float*)b;

	return i - j;
}
void destroy(void *p)
{
	free(p);
}


int main(void)
{
//TEST CASE 1 WITH CHARACTERS
  SortedListPtr si =SLCreate(compareStrings, destroy);
  
  SLInsert(si, "z");
  SLInsert(si, "a");
  SLInsert(si, "a");
  SLInsert(si, "b");
  SLInsert(si, "x");
  printf("\n=-=-=-=-=-=-=- Testing Characters =-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Completed inserting characters into list\n");
// SLRemove(si, "x");
    
  Node *ptr;
  SortedListIteratorPtr it =  SLCreateIterator(si);
  
  //iterator has been created, begin to iterate through the list and print out the values
  //we use the SLGetItem to return the current item 
  ptr =SLGetItem(it);	  
  while(ptr != NULL)
  {
	  printf("\n%s", ptr->data);
	  ptr = SLNextItem(it);  //uses the SLNextItem to move the pointer to the next item to continue iterating
  }
  printf("\nCompleted interating through the list\n");
  
  //The iterator gets destroyed 
  SLDestroyIterator(it); 
  printf("Iterator has been destroyed\n");
  
  //the list has not been affected since the iterator got destroyed
  printf("Destroyed iterator does not affect list by printing out values from list\n");
  printf("First item in the list: %s\n", si->head->data); //prints out the item in the list where head points to
  printf("Second item in the list: %s\n", si->head->next->data); //prints out the item after head
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");	
//+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+	


//TEST CASE 2 WITH INTEGERS 
 
 	int arr[]= {2,3,10,8,4,11,21,8,1,7,16};
	 
	int length = sizeof(arr)/sizeof(arr[0]);
	
	int i;
	
	SortedListPtr si2 =SLCreate(compareInts, destroy);
	int *intPtr;
	
	int x = 100;              //
	int *insrt;               //   to insert a number 100
	insrt = &x;              //    after iterated through list
 printf("\n=-=-=-=-=-=-=-=-=-Testing Integers=-=-=-=-=-=-=-=-=-=-=-=\n");
 
  //inserts numbers from arrray into linked list 
	for(i = 0; i < length;i++)
	{
		intPtr = &arr[i];
		SLInsert(si2,intPtr);
	}
  printf("Finished inserting numbers into linked list\n");
  	
  Node* ptr2;
  SortedListIteratorPtr it2 =  SLCreateIterator(si2);
  ptr2 = SLGetItem(it2);
 
  //iterator traverses through the list
  while(ptr2 != NULL)
  {   
      printf("%d\n", (*(int*)(ptr2->data)) );
  	  ptr2 = SLNextItem(it2);
  } 
  printf("Finished traversing through linked list\n");  
  
  SLInsert(si2, insrt);
  printf("Number 100 has been inserted into the list\n");
  
  //destroys iterator
  SLDestroyIterator(it2);
  printf("Iterator has been destroyed\n");
  
  //list has not been affectedby iterator by printing values in list
  printf("First value in list: %d\n",  (*(int*)(si2->head->data))   );
  printf("Second value in list: %d\n",  (*(int*)(si2->head->next->data))   );
  
  
  //remove item from list
 SLRemove(si2, insrt);
 printf("item containing 100 has been deleted from list\n");
 printf("First item after deletion:%d\n",  (*(int*)(si2->head->data)) );  
 printf("Second item after deletion:%d\n",  (*(int*)(si2->head->next->data)) );  
 printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
 
 //TESTING FLOATS--------------------------
float arrDbl[]= {2.2,3.6,10.9,8.3,4.7,11.3,21.7,8.1,1.8,7.2,16.5};
	 
	int size = sizeof(arrDbl)/sizeof(arrDbl[0]);
	
	int count;
	
	SortedListPtr si3 =SLCreate(compareDoubles, destroy);
	float *dblPtr;
	
	float var = 170.5;              
	float *insert;             
	insert = &var;           
 printf("\n=-=-=-=-=-=-=-=-=-Testing Floats=-=-=-=-=-=-=-=-=-=-=-=\n");
 
  //inserts numbers from arrray into linked list 
	for(count = 0; count < size;count++)
	{
		dblPtr = &arrDbl[count];
		SLInsert(si3,dblPtr);
	}
  printf("Finished inserting numbers into linked list\n");
  	
  Node* ptr3;
  SortedListIteratorPtr it3 =  SLCreateIterator(si3);
  ptr3 = SLGetItem(it3);
 
  //iterator traverses through the list
  while(ptr3 != NULL)
  {   
      printf("%f\n", (*(float*)(ptr3->data)) );
  	  ptr3 = SLNextItem(it3);
  } 
  printf("Finished traversing through linked list\n");  
  
  SLInsert(si3, insert);
  printf("Number 170.5 has been inserted into the list\n");
  
  //destroys iterator
  SLDestroyIterator(it3);
  printf("Iterator has been destroyed\n");
  
  //list has not been affectedby iterator by printing values in list
  printf("First value in list: %f\n",  (*(float*)(si3->head->data))   );
  printf("Second value in list: %f\n",  (*(float*)(si3->head->next->data))   );
  
  
  //remove item from list
 SLRemove(si3, insert);
 printf("item containing 100 has been deleted from list\n");
 printf("First item after deletion:%f\n",  (*(float*)(si3->head->data)) );  
 printf("Second item after deletion:%f\n",  (*(float*)(si3->head->next->data)) );  
 printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
 
	return 0;
}
