#include "MultiLinked_List.h"

void _insertYear(DataNode* datanode, HeadNode* headnode)
{
    DataNode* tmpNode;
    DataNode* preNode;
    int result;
    preNode = NULL;
    tmpNode = headnode->yearfront;
    int flag = 0;
    if (headnode->count == 0)
    {
        headnode->yearfront = datanode;
        headnode->yearrear = datanode;
    }
    else
    {
        while (1)
        {
            if (tmpNode == NULL)
                break;
            result = _compareYear(datanode, tmpNode);
            if (result < 0)
            {
                flag = 1;
                break;
            }
            preNode = tmpNode;
            tmpNode = tmpNode->yearnode;
        }
        if (flag == 1)
        {
            datanode->yearnode = tmpNode;
            if (preNode == NULL)
                headnode->yearfront = datanode;
            else
                preNode->yearnode = datanode;
        }
        else if (flag == 0)
        {
            preNode->yearnode = datanode;
            headnode->yearrear = datanode;
        }


    }
    printf("==> Insert year complete\n");

}
int _deleteYear(DataNode* datanode, HeadNode* headnode)
{
    DataNode* resultnode;
    resultnode = _searchYear(datanode->movie->year, headnode);
    if (resultnode == NULL)
    {
        return -1;
    }
    else
    {
        if (headnode->prenode == NULL) //검색 결과가 첫번째 노드일 경우
        {
            headnode->yearfront = resultnode->yearnode;
        }
        else
        {
            headnode->prenode->yearnode = resultnode->yearnode;
        }
        if (headnode->yearrear == resultnode) //검색 결과가 마지막 노드일 경우
        {
            headnode->yearrear = _getYearPreLast(headnode); // rear 노드 재설정
        }
        _deleteTitle(resultnode, headnode);
        _deleteDirector(resultnode, headnode);

        return 1;
    }

}
DataNode* _searchYear(int year, HeadNode* headnode)
{
    DataNode* tmpnode;
    headnode->prenode = NULL;
    tmpnode = headnode->yearfront;
    while (1)
    {

        if (tmpnode == NULL)
        {
            return NULL;
        }
        else if (year == tmpnode->movie->year)
        {

            return tmpnode;
        }

        headnode->prenode = tmpnode;
        tmpnode = tmpnode->yearnode;

    }

    return NULL;
}
DataNode* _getYearPreLast(HeadNode* headnode)
{
    DataNode* tmpnode = NULL;
    DataNode* prenode = NULL;
    DataNode* pprenode = NULL;
    tmpnode = headnode->yearfront;
    while (1)
    {
        if (tmpnode == NULL)
        {
            return pprenode;
        }
        pprenode = prenode;
        prenode = tmpnode;
        tmpnode = tmpnode->yearnode;
    }

}
void _traverseYear(HeadNode* headnode)
{
    DataNode* tmpnode;
    tmpnode = headnode->yearfront;
    printf("\n==> Sorted by year\n");
    while (1)
    {
        if (tmpnode != NULL)
        {
            printNode(tmpnode);
        }
        else if (tmpnode == NULL)
        {
            printf("==> traversal finished\n");
            break;
        }
        tmpnode = tmpnode->yearnode;
    }
}
int _compareYear(DataNode* datanode1, DataNode* datanode2)
{
    int result;
    int year1;
    int year2;
    year1 = datanode1->movie->year;
    year2 = datanode2->movie->year;

    if (year1 < year2)
        result = -1;
    else if (year1 > year2)
        result = 1;
    else
        result = 0;
    return result;
}