#include "MultiLinked_List.h"

void printNode(DataNode* datanode)
{
    printf("==> year: %d\t", datanode->movie->year);
    printf("title: %s\t", datanode->movie->title);
    printf("director: %s\n", datanode->movie->director);
}
DataNode* scanNode()
{
    int year;
    char title[41];
    char director[41];
    DataNode* newnode = (DataNode*)malloc(sizeof(DataNode));
    Movie* movie = (Movie*)malloc(sizeof(Movie));
    newnode->movie = movie;
    newnode->titlenode = NULL;
    newnode->yearnode = NULL;
    newnode->directornode = NULL;
    printf("==> Input year: ");
    scanf(" %d", &year);
    printf("==> Input title: ");
    scanf(" %s", title);
    printf("==> Input director: ");
    scanf(" %s", director);
    newnode->movie->year = year;
    strcpy(newnode->movie->title, title);
    strcpy(newnode->movie->director, director);

    return newnode;
}
HeadNode* createHead()
{
    HeadNode* headnode = (HeadNode*)malloc(sizeof(HeadNode));
    if (headnode == NULL)
        return NULL;
    headnode->compare = NULL;
    headnode->count = 0;
    headnode->prenode = NULL;
    headnode->titlefront = NULL;
    headnode->titlerear = NULL;
    headnode->yearfront = NULL;
    headnode->yearrear = NULL;
    headnode->directorfront = NULL;
    headnode->directorrear = NULL;

    return headnode;
}
DataNode* createNode()
{
    DataNode* datanode = (DataNode*)malloc(sizeof(DataNode));
    if (datanode == NULL)
        return NULL;

    Movie* movie = (Movie*)malloc(sizeof(Movie));
    if (movie == NULL)
        return NULL;

    datanode->movie = movie;
    datanode->yearnode = NULL;
    datanode->titlenode = NULL;
    datanode->directornode = NULL;

    return datanode;
}
void insert(DataNode* datanode, HeadNode* headnode)
{
    _insertYear(datanode, headnode);
    _insertTitle(datanode, headnode);
    _insertDirector(datanode, headnode);
    headnode->count++;
    printf("==> Insert complete\n");
    printf("==> Total Data: %d\n", headnode->count);
}
void delete(DataNode* datanode, HeadNode* headnode, char key)
{
    int result;

    if (key == 'y')
        result = _deleteYear(datanode, headnode);
    else if (key == 't')
        result = _deleteTitle(datanode, headnode);
    else if (key == 'd')
        result = _deleteDirector(datanode, headnode);

    if (result == 1) {
        printf("Delete complete\n");
        headnode->count--;
    }
    else if (result == -1)
        printf("Movie not found\n");
    else
        printf("Delete error\n");

    printf("==> Total Data: %d\n", headnode->count);
}
void search(DataNode* datanode, HeadNode* headnode, char key)
{
    DataNode* tmpnode;

    if (key == 'y')
        tmpnode = _searchYear(datanode->movie->year, headnode);
    else if (key == 't')
        tmpnode = _searchTitle(datanode->movie->title, headnode);
    else if (key == 'd')
        tmpnode = _searchDirector(datanode->movie->director, headnode);

    if (tmpnode == NULL)
        printf("Movie not found\n");
    else
        printNode(tmpnode);

    return;
}
void printAll(HeadNode* headnode)
{
    _traverseYear(headnode);
    _traverseTitle(headnode);
    _traverseDirector(headnode);
}
void _deleteAll(HeadNode* headnode)
{
    HeadNode* newhead;
    newhead = createHead();
    free(headnode);
    headnode = newhead;
    printf("==> All deleted\n");
}