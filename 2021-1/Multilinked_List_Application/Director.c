#include "MultiLinked_List.h"

void _insertDirector(DataNode* datanode, HeadNode* headnode)
{
    DataNode* tmpNode;
    DataNode* preNode;
    int result;
    preNode = NULL;
    tmpNode = headnode->directorfront;
    int flag = 0;
    if (headnode->count == 0)
    {
        headnode->directorfront = datanode;
        headnode->directorrear = datanode;
    }
    else
    {
        while (1)
        {
            if (tmpNode == NULL)
                break;
            result = _compareDirector(datanode, tmpNode);
            if (result < 0)
            {
                flag = 1;
                break;
            }
            preNode = tmpNode;
            tmpNode = tmpNode->directornode;
        }
        if (flag == 1)
        {
            datanode->directornode = tmpNode;
            if (preNode == NULL)
                headnode->directorfront = datanode;
            else
                preNode->directornode = datanode;
        }
        else if (flag == 0)
        {
            preNode->directornode = datanode;
            headnode->directorrear = datanode;
        }

    }
    printf("==> Insert director complete\n");

}
int _deleteDirector(DataNode* datanode, HeadNode* headnode)
{

    DataNode* resultnode;
    resultnode = _searchDirector(datanode->movie->director, headnode);

    if (resultnode == NULL)
    {
        return -1;
    }
    else
    {
        if (headnode->prenode == NULL) // 검색 결과가 첫번째 노드일경우
        {
            headnode->directorfront = resultnode->directornode;
        }
        else
        {
            headnode->prenode->directornode = resultnode->directornode;
        }
        if (headnode->directorrear == resultnode) //검색 결과가 마지막 노드일 경우
        {
            headnode->directorrear = _getDirectorPreLast(headnode); // rear 노드 재설정
        }
        _deleteYear(resultnode, headnode);
        _deleteTitle(resultnode, headnode);

        return 1;
    }

}
DataNode* _searchDirector(char* director, HeadNode* headnode)
{
    DataNode* tmpnode;
    headnode->prenode = NULL;
    tmpnode = headnode->directorfront;
    while (1)
    {
        if (tmpnode == NULL)
        {
            return NULL;
        }
        else if (strcmp(director, tmpnode->movie->director) == 0)
        {
            return tmpnode;
        }

        headnode->prenode = tmpnode;
        tmpnode = tmpnode->directornode;
    }

    return NULL;
}
DataNode* _getDirectorPreLast(HeadNode* headnode)
{
    DataNode* tmpnode = NULL;
    DataNode* prenode = NULL;
    DataNode* pprenode = NULL;
    tmpnode = headnode->directorfront;
    while (1)
    {
        if (tmpnode == NULL)
        {
            return pprenode;
        }
        pprenode = prenode;
        prenode = tmpnode;
        tmpnode = tmpnode->directornode;
    }
}
void _traverseDirector(HeadNode* headnode)
{
    DataNode* tmpnode;
    tmpnode = headnode->directorfront;
    printf("\n==> Sorted by director\n");
    while (1)
    {
        if (tmpnode != NULL)
        {
            printNode(tmpnode);
        }
        else if (tmpnode == NULL)
        {
            printf("==> Traversal finished\n");
            break;
        }
        tmpnode = tmpnode->directornode;
    }
}
int _compareDirector(DataNode* datanode1, DataNode* datanode2)
{
    int result;
    char* director1;
    char* director2;
    char tmp[190];
    director1 = datanode1->movie->director;
    director2 = datanode2->movie->director;
    if (strcmp(director1, director2) == -1)
        result = -1;
    else if (strcmp(director1, director2) == 1)
        result = +1;
    else
        result = 0;
    return result;
}
