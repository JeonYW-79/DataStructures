#ifndef __MULTILINKED_LIST__
#define __MULTILINKED_LIST__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _movie
{
    int year;
    char title[41];
    char director[41];
}Movie;

typedef struct _dataNode DataNode;
struct _dataNode
{
    Movie* movie;
    DataNode* yearnode;     // 다음 year node 
    DataNode* titlenode;    // 다음 title node
    DataNode* directornode; // 다음 director node
};
typedef struct _headNode
{
    int count;
    DataNode* yearfront;     // head in year list
    DataNode* yearrear;      // tail in year list
    DataNode* titlefront;    // head in title list
    DataNode* titlerear;     // tail in title list
    DataNode* directorfront; // head in director list
    DataNode* directorrear;  // tail in director list
    DataNode* prenode;       // 탐색 시 현재 노드
    DataNode* compare;       // 정렬 시 비교 노드
} HeadNode;

/*Public*/
HeadNode* createHead();                                        // Create Head node
DataNode* createNode();                                        // Create Data node
void printNode(DataNode* datanode);                            // Print single node
void printAll(HeadNode* headnode);                             // Print all nodes
DataNode* scanNode();                                          // scan single node
void insert(DataNode* datanode, HeadNode* headnode);           // insert node
void delete(DataNode* datanode, HeadNode* headnode, char key); // delete node
void search(DataNode* datanode, HeadNode* headnode, char key); // search node

/*Private*/
void _insertYear(DataNode* datanode, HeadNode* headnode);      // insert in year list
void _insertTitle(DataNode* datanode, HeadNode* headnode);     // insert in title list
void _insertDirector(DataNode* datanode, HeadNode* headnode);  // insert in director list

int _deleteYear(DataNode* datanode, HeadNode* headnode);       // delete in year list
int _deleteTitle(DataNode* datanode, HeadNode* headnode);      // delete in title list
int _deleteDirector(DataNode* datanode, HeadNode* headnode);   // delete in director list

DataNode* _searchYear(int year, HeadNode* headnode);           // search in year list
DataNode* _searchTitle(char* title, HeadNode* headnode);       // search in title list
DataNode* _searchDirector(char* director, HeadNode* headnode); // search in director list

DataNode* _getYearPreLast(HeadNode* headnode);                 // get prenode of last node in year list
DataNode* _getTitlePreLast(HeadNode* headnode);                // get prenode of last node in title list
DataNode* _getDirectorPreLast(HeadNode* headnode);             // get prenode of last node in director list

void _deleteAll(HeadNode* headnode);                           // delete all nodes

void _traverseYear(HeadNode* headnode);                        // traverse in year list
void _traverseTitle(HeadNode* headnode);                       // traverse in title list
void _traverseDirector(HeadNode* headnode);                    // traverse in director list

int _compareYear(DataNode* datanode1, DataNode* datanode2);    // compare year
int _compareTitle(DataNode* datanode1, DataNode* datanode2);   // compare title
int _compareDirector(DataNode* datanode1, DataNode* datanode2);// compare director

#endif
