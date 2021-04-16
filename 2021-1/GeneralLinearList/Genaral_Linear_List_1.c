// Simple Implementation

#include "Genaral_Linear_List_1.h"
#include <stdio.h>

LinearList* createList()
{
	LinearList* pNewList = (LinearList*)malloc(sizeof(LinearList));
	if (pNewList == NULL)
		return NULL;

	pNewList->count = 0;
	pNewList->head = NULL;

	return pNewList;
}
int traverseList(LinearList* pList, int fromWhere, Element* pDataOut)
{
	if (fromWhere == 0 || pList->pos == NULL)
		pList->pos = pList->head;
	else
		pList->pos = pList->pos->next;

	if (pList->pos != NULL) {
		*pDataOut = pList->pos->data;
		return 1;
	}
	else {
		*pDataOut = 0;
		return 0;
	}
}
Element retrieveNode(LinearList* pList, Element key)
{
	// get key and find data
}
int countListItem(LinearList* pList)
{
	return pList->count;
}
int PrintListItems(LinearList* pList)
{
	if (isEmpty(pList)) {
		printf("No item in list!!");
		return 0;
	}

	int fromWhere = 0;
	Element* curData;
	printf("Items: ");
	while (traverseList(pList, fromWhere, curData)) {
		printf("%d ", curData);
	}
}
int isEmpty(LinearList* pList)
{
	if (pList->count == 0) return 1;
	else return 0;
}
int insertNode(LinearList* pList, Element data)
{
	Node* pPre = NULL, * pLoc = NULL;
	int found = searchNode(pList, &pPre, &pLoc, data);

	if (!found) { // 동일한 노드가 없다. 
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->data = data;

		if (pPre == NULL) { // insert before head node
			pNewNode->next = pList->head;
			pList->head = pNewNode;
		}
		else {
			pNewNode->next = pPre->next;
			pPre->next = pNewNode;
		}
		pList->count++;

		return 1;
	}

	return 0;
}
int searchNode(LinearList* pList, Node** ppPre, Node** ppLoc, Element data)
{
	for (*ppPre = NULL, *ppLoc = pList->head; *ppLoc != NULL;
		 *ppPre = *ppLoc, *ppLoc = (*ppLoc)->next) {
		if ((*ppLoc)->data == data)     // data was found
			return 1;
		else if ((*ppLoc)->data > data) // No more searching is needed
			break;
	}

	return 0;
}
int removeNode(LinearList* pList, Element data)
{
	Node* pPre = NULL, * pLoc = NULL;
	int found = searchNode(pList, &pPre, &pLoc, data);

	if (found) {
		if (pPre == NULL) { // delete head node
			pList->head = pLoc->next;
		}
		else {
			pPre->next = pLoc->next;
		}

		free(pLoc);
		pList->count--;

		return 1;
	}

	return 0;
}
void destroyList(LinearList* pList)
{
	Node* pDelNode = NULL, * pNextNode = NULL;

	for (pDelNode = pList->head; pDelNode != NULL; pDelNode = pNextNode) {
		pNextNode = pDelNode->next;
		free(pDelNode);
	}

	free(pList);
}