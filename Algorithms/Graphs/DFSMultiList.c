#include <stdio.h>
#include <stdlib.h>
int n;
struct rownode
{
    int row;
    struct rownode *rlink;
    struct columnnode *clink;
};
typedef struct rownode ROWNODE;
struct columnnode
{
    int value;
    struct columnnode *link;
};
typedef struct columnnode COLNODE;
struct row
{
    ROWNODE *head;
};
typedef struct row ROW;
struct column
{
    COLNODE *head;
};
typedef struct column COL;
void init(ROW*, int);
void display(ROW*);
void insert(ROW*, int, int);
int main()
{
    int source,i,j;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    ROW *l = (ROW*)malloc(sizeof(ROW));
    init(l, n);
    while (1)
    {
        printf("Enter source and destination vertex : ");
        scanf("%d %d", &i,&j);
        if(i==0 && j==0)
            break;
        else
            insert(l,i,j);
    }
    display(l);
    printf("Enter starting position : ");
    scanf("%d", &source);

}
void init(ROW *l, int m)
{
    ROWNODE *node = (ROWNODE*)malloc(sizeof(ROWNODE));
    node->row = 1;
    node->rlink = NULL;
    node->clink = NULL;
    l->head = node;
    ROWNODE *pres = l->head;
    int ctr = 2;
    while(ctr<=m)
    {
        ROWNODE *temp = (ROWNODE*)malloc(sizeof(ROWNODE));
        temp->clink = NULL;
        temp->row = ctr;
        pres->rlink = temp;
        pres = temp;
        ctr+=1;
    }
    pres->rlink = NULL;
}
void insert(ROW *l, int m, int n)
{
    ROWNODE *node = l->head;
    int ctr = 1;
    while(ctr<m)
    {
        node = node->rlink;
        ctr+=1;
    }
    COLNODE *temp = (COLNODE*)malloc(sizeof(COLNODE));
    temp->value = n;
    //temp->column = n;
    temp->link=NULL;
    if (node->clink == NULL)
    {
        COL *cl = (COL*)malloc(sizeof(COL));
        cl->head = temp;
        node->clink = temp;
    }
    else
    {
        COLNODE *pres = node->clink;
        COLNODE *prev = NULL;
        while(pres!=NULL)
        {
            prev = pres;
            pres = pres->link;
        }
        prev->link = temp;
        temp->link = NULL;
    } 
}
void display(ROW *l)
{
    ROWNODE *node = l->head;
    while(node!=NULL)
    {
        COLNODE *temp = node->clink;
        printf("%d->",node->row);
        while(temp!=NULL)
        {
            printf("%d,", temp->value);
            temp = temp->link;
        }
        printf("\n");
        node = node->rlink;
    }
}