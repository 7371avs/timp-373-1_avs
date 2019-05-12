#include <stdlib.h>
#include <stdio.h>

struct node
{
int value;
struct node *next;
struct node *prev;
};

struct list
{
    struct node *head;
    struct node *tail;
};

void init(struct list* l)
{
    l->head = NULL;
    l->tail = NULL;
}

int isEmpty(struct list *l)
{
    if (l->head == NULL)
        return 1;
    else
        return 0;
}

int push_front(struct list *l, int value)
{
    struct node *temp =(struct node*) malloc(sizeof(struct node));
    temp->value = value;
    if (l->head == NULL)
    {
        l->head = temp;
        l->tail = temp;
        temp->next = NULL;
        temp->prev = NULL;
        return 0;
    }
    temp->next = l->head;
    l->head->prev = temp;
    temp->prev = NULL;
    l->head = temp;
    return 0;
}

int push_back(struct list *l, int value)
{

    if (l->head == NULL)
    {
        push_front(l, value);
        return 0;
    }
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->value = value;
    temp->prev = l->tail;
    temp->next = NULL;
    l->tail->next = temp;
    l->tail = temp;
    return 0;
}

void DeleteAllNodes(struct node * l)
{
    if (l == NULL)
        return;
    if (l->next != NULL)
        DeleteAllNodes(l->next);
    free(l);
}

void Clear(struct list* l)
{
    DeleteAllNodes(l->head);
}

struct node* Find(struct list* l, int value)
{
    for(struct node *i = l->head; i != NULL; i = i->next)
    {
        if (i->value == value)
            return i;
    }
    return NULL;
}

void Print(struct list* l)
{
    for(struct node *i = l->head; i != NULL; i = i->next)
        printf("%d ", i->value);
    printf("\n");
}

void Print_Invers(struct list* l)
{
    for(struct node *i = l->tail; i != NULL; i = i->prev)
            printf("%d ", i->value);
        printf("\n");
}

struct node* GetByIndex(struct list* l, int index)
{
    struct node* cur = l->head;
    for (int i = 1; i < index && cur != NULL; i++, cur=cur->next);
    return cur;
};

int insertAfter(struct node* n, int value)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->value = value;
    temp->prev = n;
    temp->next = n->next;
    if (n->next != NULL)
    {
        n->next->prev = temp;
    }
    n->next = temp;
    return 0;
}

int insertBefore(struct node* n, int value)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->value = value;
    temp->next = n;
    temp->prev = n->prev;
    if (n->prev != NULL)
    {
        n->prev->next = temp;
    }
    n->prev = temp;
    return 0;
}

int removeFirst(struct list* l, int value)
{
    if (l->head->value == value)
    {
        struct node *temp = l->head->next;
        free(l->head);
        temp->prev = NULL;
        l->head = temp;
        return 0;
    }
    struct node *cur = l->head;
    while (cur->value != value && cur != NULL)
    {
        cur = cur->next;
    }

    if (cur == NULL)
        return -1;

    if (l->tail == cur)
    {
        l->tail = l->tail->prev;
        l->tail->next = NULL;
        free(cur);
        return 0;
    }

    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    free(cur);
    return 0;
}

int removeLast(struct list* l, int value)
{
    if (l->tail->value == value)
    {
        struct node *temp = l->tail->prev;
        free(l->tail);
        temp->next = NULL;
        l->tail = temp;
        return 0;
    }
    struct node *cur = l->tail;
    while (cur->value != value && cur != NULL)
    {
        cur = cur->prev;
    }

    if (cur == NULL)
        return -1;

    if (l->head == cur)
    {
        l->head = l->head->next;
        l->head->prev = NULL;
        free(cur);
        return 0;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
    return 0;
}

int main()
{
    struct list *l =(struct list*) malloc(sizeof(struct list));
    init(l);
    int n,k;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k);
        push_back(l, k);
    }

    Print (l);

    for (int i=0; i<3; i++)
    {
        scanf("%d", &k);
        if (Find(l,k) != NULL)
        {
            printf("1");
        }
        else
            printf("0");
    }
    printf("\n");


    int m;
    scanf("%d",&m);
    push_back(l,m);

    Print_Invers(l);

    int t;
    scanf ("%d",&t);
    push_front(l,t);

    Print(l);

    int x,j;
    struct node* q;
    scanf ("%d%d",&j,&x);
    q=GetByIndex(l,j);
    if (q!=NULL)
        insertAfter(q,x);

    Print_Invers(l);

    int u,y;
    scanf ("%d %d", &u,&y);
    q=GetByIndex(l,u);
    if (q!=NULL)
        insertBefore(q,y);

    Print (l);

    int z;
    scanf("%d", &z);
    removeFirst(l,z);

    Print_Invers(l);

    int r;
    scanf("%d", &r);
    removeLast(l,r);

    Print(l);

    Clear(l);
}
