#include "MultiLinked_List.h"

void _insertTitle(DataNode* datanode, HeadNode* headnode)
{
    DataNode* tmpNode;
    DataNode* preNode;
    int result;
    preNode = NULL;
    tmpNode = headnode->titlefront;
    int flag = 0;
    if (headnode->count == 0)
    {
        headnode->titlefront = datanode;
        headnode->titlerear = datanode;
    }
    else
    {
        while (1)
        {
            if (tmpNode == NULL)
                break;
            result = _compareTitle(datanode, tmpNode);
            if (result < 0)
            {
                flag = 1;
                break;
            }
            preNode = tmpNode;
            tmpNode = tmpNode->titlenode;
        }
        if (flag == 1)
        {
            datanode->titlenode = tmpNode;
            if (preNode == NULL)
                headnode->titlefront = datanode;
            else
                preNode->titlenode = datanode;
        }
        else if (flag == 0)
        {
            preNode->titlenode = datanode;
            headnode->titlerear = datanode;
        }

    }
    printf("==> Insert title complete\n");

}
int _deleteTitle(DataNode* datanode, HeadNode* headnode)
{

    DataNode* resultnode;
    resultnode = _searchTitle(datanode->movie->title, headnode);

    if (resultnode == NULL)
    {
        return -1;
    }
    else
    {
        if (headnode->prenode == NULL) //검색 결과가 첫번째 노드일경우
        {
            headnode->titlefront = resultnode->titlenode;
        }
        else
        {
            headnode->prenode->titlenode = resultnode->titlenode;
        }
        if (headnode->titlerear == resultnode) //검색 결과가 마지막 노드일 경우
        {
            headnode->titlerear = _getTitlePreLast(headnode); // rear 노드 재설정
        }
        _deleteYear(resultnode, headnode);
        _deleteDirector(resultnode, headnode);

        return 1;
    }

}
DataNode* _searchTitle(char* title, HeadNode* headnode)
{
    DataNode* tmpnode;
    headnode->prenode = NULL;
    tmpnode = headnode->titlefront;
    while (1)
    {
        if (tmpnode == NULL)
        {
            return NULL;
        }
        else if (strcmp(title, tmpnode->movie->title) == 0)
        {
            return tmpnode;
        }

        headnode->prenode = tmpnode;
        tmpnode = tmpnode->titlenode;
    }

    return NULL;
}
DataNode* _getTitlePreLast(HeadNode* headnode)
{
    DataNode* tmpnode = NULL;
    DataNode* prenode = NULL;
    DataNode* pprenode = NULL;
    tmpnode = headnode->titlefront;
    while (1)
    {
        if (tmpnode == NULL)
        {
            return pprenode;
        }
        pprenode = prenode;
        prenode = tmpnode;
        tmpnode = tmpnode->titlenode;
    }
}
void _traverseTitle(HeadNode* headnode)
{
    DataNode* tmpnode;
    tmpnode = headnode->titlefront;
    printf("\n==> Sorted by title\n");
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
        tmpnode = tmpnode->titlenode;
    }
}
int _compareTitle(DataNode* datanode1, DataNode* datanode2)
{
    int result;
    char* title1;
    char* title2;
    char tmp[190];
    title1 = datanode1->movie->title;
    title2 = datanode2->movie->title;
    if (strcmp(title1, title2))
        result = -1;
    else if (strcmp(title1, title2))
        result = +1;
    else
        result = 0;
    return result;
}
