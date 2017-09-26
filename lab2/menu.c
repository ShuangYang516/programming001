#include<stdio.h>
#include<stdlib.h>

int project();
int quit();
int edit();
int help();
int find();
int view();
int clear();
int file();
int analysis();

int main()
{
    char cmd[128];
    while(1)
    {
        printf("Input your cmd:\n");
        scanf("%s",cmd);
        if (!strcmp(cmd,"quit"))
        {
	    quit();
        }
        if (!strcmp(cmd,"edit"))
        {
	    edit();
        } 
        if(!strcmp(cmd,"project"))
        {

            project();
        }  
        if(!strcmp(cmd,"help"))
        { 
	    help();
        }
 
        if(!strcmp(cmd,"view"))
        { 
       	    view();
        }
        if(!strcmp(cmd,"find"))
        {
	    find();
        }
        if(!strcmp(cmd,"clear"))
        {
	    clear();
        }
        if(!strcmp(cmd,"analysis"))
        {
	    analysis();
        }
	else file();
    }
}

int project()
{
    printf("This is project\n");
}

int quit()
{
    file();
}

int edit()
{
    printf("This is edit\n");
}

int view()
{
   printf("This is view\n");
}

int help()
{
   printf("This is help\n");
}

int analysis()
{
    printf("This is analysis\n");
}

int find()
{
    printf("This is find\n");
}

int file()
{
    exit(0);
    return 0;
}

int clear()
{
    printf("This is clear\n");
}
    
