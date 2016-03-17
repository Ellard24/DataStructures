#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	/* FIXME: you must write this */	 
	assert(q != 0);
	q->size = 0;
	q->Sentinel = malloc(sizeof(struct DLink));
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));
	newLink->value = val;


	/*temporary return value..you may need to change it*/
	return newLink;

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */	 
	assert(q != 0);
	assert(lnk != 0);
	//assert() check for lnk in deque
	

	struct DLink *newLink = _createLink(v);

	//struct DLink *newLink = (struct DLink *)malloc(sizeof(struct DLink));

	newLink->value = v;
	newLink->next = lnk->next;
	newLink->prev = lnk;

	lnk->next->prev = newLink;  // link after lnk points to newlink
	lnk->next = newLink;

	q->size++;


	

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */
	assert(q != 0);
	
	/*** test purposes
	struct DLink *newLink = (struct DLink*)malloc(sizeof(struct DLink));

	newLink->value = val;
	newLink->next = q->Sentinel;           //newLink points sentinel
	newLink->prev = q->Sentinel->prev;

	q->Sentinel->prev->next = newLink;    //previous element behind sentinel now points to newLink

	q->Sentinel->prev = newLink;        //Sentinel prev points to newLink;

	q->size++;
	***/

	_addLinkAfter(q, q->Sentinel->prev, val);
	

}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	 
	assert(q != 0);


	/***   test purposes
	struct DLink *newLink = (struct DLink*)malloc(sizeof(struct DLink));

	newLink->value = val;

	newLink->next = q->Sentinel->next;

	newLink->prev = q->Sentinel;


	q->Sentinel->next->prev = newLink;

	q->Sentinel->next = newLink;


	q->size++;
	***/

	_addLinkAfter(q, q->Sentinel, val);

}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */	 

	assert(q != 0);
	assert(q->size != 0);


	/*temporary return value..you may need to change it*/
	return q->Sentinel->next->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert(q != 0);
	assert(q->size != 0);
	/*temporary return value..you may need to change it*/
	return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */	 
	assert(q != 0);
	assert(q->size != 0);

	//link behind link now points to link after lnk
	lnk->prev->next = lnk->next; 

	//link after link now points to link before lnk
	lnk->next->prev = lnk->prev;




	free(lnk);

	q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	assert(q != 0);
	assert(q->size != 0);
	_removeLink(q, q->Sentinel->next);


}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */	 
	assert(q != 0);
	assert(q->size != 0);

	_removeLink(q, q->Sentinel->prev);

}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink *temp = q->Sentinel;
	/* FIXME: you must write this */	 
	while (!isEmptyCirListDeque(q))
	{
		temp = temp->next;
		_removeLink(q, temp);
		
	}
	free(q->Sentinel);
	q->size = 0;
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
	assert(q != 0);

	if (q->size != 0)
		return 0;
	else
		return 1;

}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	assert(q != 0);
	assert(q->size != 0);
	struct DLink *temp = q->Sentinel->next;

	while (temp != q->Sentinel)
	{
		printf("%g\n", temp->value);
		temp = temp->next;
	}

}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	assert(q != 0);
	assert(q->size != 0);

	//Create new deque 
	struct cirListDeque *temp = createCirListDeque();
	assert(temp != 0);

	while (!isEmptyCirListDeque(q))
	{
		addBackCirListDeque(temp, backCirListDeque(q));
		//printf("%f \n", backCirListDeque(q));
		removeBackCirListDeque(q);
	}

	while (!isEmptyCirListDeque(temp))
	{
		addFrontCirListDeque(q, backCirListDeque(temp));
		//printf("%f \n", backCirListDeque(q));
		removeBackCirListDeque(temp);
	}

	free(temp);
}