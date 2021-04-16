// Simple Implementation

#ifndef __GENERAL_LINEAR_LIST_1__
#define __GENERAL_LINEAR_LIST_1__

#include <stdio.h>
#include <stdlib.h>

// Data node
typedef int Element;

typedef struct _node {
	Element key;
	Element data;
	struct _node* next;
}Node;

// Head node
typedef struct _linearList {
	int count;
	Node* pos;
	Node* head;
}LinearList;


// Function declare
LinearList* createList();
int traverseList(LinearList** pList, int fromWhere, Element* pDataOut);
Element retrieveNode(LinearList* pList, Element key);
int countListItem(LinearList* pList);
int PrintListItems(LinearList* pList);
int isEmpty(LinearList* pList);
int insertNode(LinearList* pList, Element data);
int searchNode(LinearList* pList, Node **ppPre, Node **ppLoc, Element data);
int removeNode(LinearList* pList, Element data);
void destroyList(LinearList* pList);


#endif
