#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node *next;
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

void DeleteAllNodes(struct node * l)
{
    if (l == NULL)
        return;
    if (l->next != NULL)
        DeleteAllNodes(l->next);
    free(l);
}

void clear(struct list* l)
{
    DeleteAllNodes(l->head);
}

int IsEmpty(struct list *l)
{
    if (l->head == NULL)
        return 1;
    else return 0;
}

struct node* find(struct list* l, int value)
{
    for(struct node *i = l->head; i != NULL; i = i->next)
    {
        if (i->value == value)
            return i;
    }
    return NULL;
}

int push_front(struct list* l, int value)
{
    struct node * a = (struct node*) malloc(sizeof(struct node));
    a->value = value;
    a->next = l->head;
    l->head = a;
    if (l->tail == NULL)
        l->tail = l->head;
    return 0;
}

int push_back(struct list* l, int value)
{

    if (l->head == NULL)
    {
        push_front(l, value);
    }
    else
    {
        struct node * a = (struct node*) malloc(sizeof(struct node));
        a->value = value;
        a->next = NULL;
        l->tail->next = a;
        l->tail = a;
    }

    return 0;
}

struct node* GetByIndex(struct list* l, int index)
{
	struct node* cur = l->head;
	for(int i=1; i<index && cur!=NULL;i++, cur=cur->next);
	return cur;
};

int insertAfter(struct node* n, int value)
{
    struct node * a = (struct node*) malloc(sizeof(struct node));
    a->value = value;
    a->next = n->next;
    n->next=a;
    return 0;
}

int Remove(struct list* l, int value)
{
    if (value==l->head->value)
    {
        struct node * a = l->head->next;
        free(l->head);
        l->head = a;
        return 0;
    }
    else
    {
        struct node *cur = l->head->next, *prev = l->head;
        while (cur->value != value && cur != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
            return -1;

        prev->next = cur->next;
        if (l->tail == cur)
            l->tail = prev;
        free(cur);

        return 0;
    }
}

void print(struct list* l)
{
    for(struct node *i = l->head; i != NULL; i = i->next)
        printf("%d ", i->value);
    printf("\n");
}

int main()
{
    struct list *l = (struct list*) malloc(sizeof(struct list));
    init(l);
    int n,k;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k);
        push_back(l, k);
    }

    print (l);

    for (int i=0; i<3; i++)
    {
        scanf("%d", &k);
        if (find(l,k) != NULL)
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

    print(l);

    int t;
    scanf ("%d",&t);
    push_front(l,t);

    print(l);

    int j,x;
    struct node* q;
    scanf ("%d%d",&j,&x);
    q=GetByIndex(l,j);
    if (q!=NULL)
        insertAfter(q,x);

    print (l);

    int z;
    scanf("%d", &z);
    Remove(l,z);

    print(l);

    clear(l);
}
