#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hash
{
    int key;
    char name[20];
    int mark;
}HASH;
HASH *h;
int size, len = 0;
int hashfunc(int);
void search(int);
void delete(int);
void display();
void insert(int key, char *name);
int main()
{
    printf("Enter size of table : ");
    scanf("%d",&size);
    h = (HASH*)malloc(sizeof(HASH)*size);
    for (int i = 0;i<size;i++)
        h[i].mark = 0;
    int key; char name[20];
    while(1)
    {
        printf("Enter key and name : ");
        scanf("%d %s",&key,name);
        if(key==0)
            break;
        insert(key,name);
    }
    display();
    printf("Enter key to search : ");
    scanf("%d",&key);
    search(key);
    printf("Enter key to delete : ");
    scanf("%d",&key);
    delete(key);
    display();
}
int hashfunc(int key)
{
    return key%size;
}
void insert(int key, char* name)
{
    if(len==size)
    {
        printf("Table Full!\n");
        return;
    }
    int index = key%size;
    int i = 1;
    while(h[index].mark==1)
    {
        if(h[index].key==key)
        {
            printf("Duplicate Entry.\n");
            return;
        }
        index = (index+i*hashfunc(key))%size;
        i++;
    }
    h[index].key = key;
    h[index].mark = 1;
    strcpy(h[index].name,name);
    len++;
}
void display()
{
    for(int i=0;i<size;i++)
    {
        if(h[i].mark==1)
            printf("%d %s\n", h[i].key, h[i].name);
    }
}
void search(int key)
{
    int index = key%size;
    int ctr = 0, i = 1;
    while(ctr<=len)
    {
        if(h[index].key==key)
        {
            printf("%d %s\n", h[index].key, h[index].name);
            return;
        }
        if(h[index].mark==1) ctr++;
        index = (index+i*hashfunc(key))%size;
        i++;
    }
    printf("Not found.\n");
}
void delete(int key)
{
    if(len==0)
    {
        printf("Table Empty!\n");
        return;
    }
    int index = key%size;
    int ctr = 0, i = 1;
    while(ctr<=len)
    {
        if(h[index].key==key)
        {
            printf("%d %s Deleted\n", h[index].key, h[index].name);
            h[index].mark = 0;
            return;
        }
        if(h[index].mark==1) ctr++;
        index = (index+i*hashfunc(key))%size;
        i++;
    }
    printf("Not found.\n");
}