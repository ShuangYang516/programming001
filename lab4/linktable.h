#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#include <pthread.h>

#define success 0
#define failure (-1)

typedef struct LinkTableNode
{
    struct LinkTableNode *pNext;
}tLinkTableNode;
typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int SumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;
tLinkTable * CreateLinkTable();
//Delete linktable
int DeleteLinkTable(tLinkTable * pLinkTable);
//Add a linktable node
void AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);
//Delete a linktable node
int DeleteLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);
//Get linktable head
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable);
//Get next linktable node
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);
#endif

