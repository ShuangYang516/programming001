#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"

void cmdHelp();
void cmdLs();
void cmdPs();
void cmdPwd();
void cmdDate();
void cmdAdd();
void cmdSub();
void cmdVersion();
void cmdQuit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char * cmd;
    char * desc;
    void (*handler)();
}tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode, void * args)
{
    char* cmd =(char*)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;
    }
    return FAILURE;
}
/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,cmd);
}
/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}


int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Show  help list";
    pNode->handler =cmdHelp;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "ls";
    pNode->desc = "List files";
    pNode->handler = cmdLs;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "ps";
    pNode->desc = "List all processes status";
    pNode->handler = cmdPs;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "pwd";
    pNode->desc = "Print working directory";
    pNode->handler = cmdPwd;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "date";
    pNode->desc = "Show current time";
    pNode->handler = cmdDate;
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "add";
    pNode->desc = "add two nums";
    pNode->handler = cmdAdd;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);   
    pNode->cmd = "sub";
    pNode->desc = "Sub two nums ";
    pNode->handler = cmdSub;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode->cmd = "version";
    pNode->desc = "Show the program's version";
    pNode->handler = cmdVersion;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit the program";
    pNode->handler =cmdQuit;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    return 0;
}
tLinkTable * head = NULL;
int main() 
{
    char cmd[CMD_MAX_LEN];
    InitMenuData(&head);
    while(1)
    {
        printf("Please input the cmd:");
        scanf("%s",cmd);
        tDataNode *p = findCmd(head,cmd);
        if (p == NULL)
        {
            printf("Error:unkown command!Please check your command again!\n");
            continue;
        }
        if( p->handler != NULL )
        {
            p->handler();
        }
    }
    return 0;
}

void cmdHelp()
{
    showAllCmds(head);
}
void cmdLs()
{
    system("ls");
}
void cmdPs()
{
    system("ps");
}
void cmdPwd()
{
    system("pwd");
}
void cmdDate()
{
    system("date");
}

void cmdAdd()
{
    int a,b;
    printf("Please input two nums:");
    scanf("%d %d",&a,&b);
    printf("%d+%d=%d\n",a,b,a+b);
}

void cmdSub()
{
    int a,b;
    printf("Please input two nums:");
    scanf("%d %d",&a,&b);
    printf("%d-%d=%d\n",a,b,a-b);
}

void cmdVersion()
{
    printf("This program is v3.0\n");
}

void Quit()
{
    exit(0);
}
