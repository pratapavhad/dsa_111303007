typedef struct node {
        char *str;
        struct node *next, *prev;
}node;
typedef struct list{
        node *head, *tail;
        int length;
}list;
void init(list *l);
void insert(list *l, int pos, char *str);
void append(list *l, char *str);                                           
