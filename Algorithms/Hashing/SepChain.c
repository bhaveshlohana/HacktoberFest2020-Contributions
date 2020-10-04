#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int key;
    char name[20];
    struct node* link;
};
typedef struct node NODE;
struct hash
{
    NODE *head;
};
typedef struct hash HASH;
HASH *h;
int size;
void insert(int,char*);
void display();
void search(int);
void delete(int);
int main()
{
    printf("Enter table size : ");
    scanf("%d",&size);
    h = (HASH*)malloc(sizeof(HASH)*size);
    for(int i=0;i<size;i++)
        h[i].head = NULL;
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
void insert(int key,char *name)
{
    int index = key%size;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->key = key;
    node->link = NULL;
    strcpy(node->name,name);
    if (h[index].head==NULL)
    {
        h[index].head = node;
    }
    else
    {
        node->link = h[index].head;
        h[index].head = node;
    }
}
void display()
{
    for(int i=0;i<size;i++)
    {
        if(h[i].head!=NULL)
        {
            NODE* pres = h[i].head;
            while(pres!=NULL)
            {
                printf("%d %s\n",pres->key,pres->name);
                pres = pres->link;
            }
        }
    }
}
void search(int key)
{
    int index = key%size;
    if(h[index].head==NULL)
    {
        printf("Not found!\n");
        return;
    }
    NODE *pres = h[index].head;
    while(pres!=NULL)
    {
        if(pres->key==key)
        {
            printf("%d %s\n",pres->key,pres->name);
            return;
        }
        pres = pres->link;
    }
    printf("Not found!\n");
}
void delete(int key)
{
    int index = key%size;
    if(h[index].head==NULL)
    {
        printf("Not found!\n");
        return;
    }
    NODE *pres = h[index].head;
    NODE *prev = NULL;
    while(pres!=NULL)
    {
        if(pres->key==key)
        {
            printf("%d %s deleted!\n",pres->key,pres->name);
            if (prev==NULL)
                h[index].head = h[index].head->link;
            else
            {
                prev->link = pres->link;
                free(pres);
            }
            return; 
        }
        prev = pres;
        pres = pres->link;
    }
    printf("Not found!\n");
}