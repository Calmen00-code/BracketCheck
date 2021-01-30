#ifndef LINKEDLIST
#define LINKEDLIST


typedef struct LinkedListNode
{
    struct LinkedListNode *next;
    void *data;
} LinkedListNode;

typedef struct
{
    LinkedListNode *head;
    LinkedListNode *tail;
    int count;
} LinkedList;

LinkedList* createLinkedList();
void insertStart(LinkedList*, void*);
void* removeStart(LinkedList*);
void insertLast(LinkedList*, void*);
void* removeLast(LinkedList*);
void* peekLast(LinkedList*);
void* peekFirst(LinkedList*);

void printLinkedList(LinkedList *);
void freeLinkedList(LinkedList *);

#endif
