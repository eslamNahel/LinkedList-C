#include <stdio.h>
#include <stdlib.h>


// Components structs.
typedef struct Node
{
    int element;
    struct Node *next;
}Node, *PNode;
typedef PNode NodePointer;

typedef struct LinkedList
{
    PNode head;
    PNode tail;
}LinkedList, *PlinkedList;


// methods callers
PlinkedList createEmptyList(void);
void insertEndOfList(PlinkedList list, int element);
void printList(PlinkedList list);
void mergeLists(PlinkedList firstList, PlinkedList secondList, PlinkedList toMerge);


// main function
int main()
{
    PlinkedList listOne, listTwo;
    PlinkedList mergedList;

    int element;
    int size;

    listOne = createEmptyList();
    listTwo = createEmptyList();

    mergedList = createEmptyList();

    printf("Please enter the size of your first list: ");
    scanf("%d", &size);
    printf("Your first list is of size %d. Now please enter your list elements: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element);
        insertEndOfList(listOne, element);
    }
    printf("Your first list is: ");
    printList(listOne);

    printf("\nPlease enter the seize of your second list: ");
    scanf("%d", &size);
    printf("Your second list is of size %d. Now please enter your list elements: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element);
        insertEndOfList(listTwo, element);
    }
    printf("Your second list is: ");
    printList(listTwo);
    mergeLists(listOne, listTwo, mergedList);
    printf("\nYour merged list is: ");
    printList(mergedList);

    return 0;
}


// Helper Methods
PlinkedList createEmptyList(void)
{
    // create a new list and allocate memory for it.
    PlinkedList list;
    list = (PlinkedList)malloc(sizeof(NodePointer));

    // if the list is null, i.e empty, make the tail = null.
    if (list != NULL)
    {
        list->tail = NULL;
    } 
    else 
    {
        printf("Couldn't create new list!\n");
    }
    return list;
}


void swapElements(NodePointer a, NodePointer b)
{
    // create a new temp element and assign it to the first element value
    int temp = a->element;
    // swap the elements values
    a->element = b->element;
    b->element = temp;
}


void BubbleSort(PlinkedList list)
{
    int swapped;
    NodePointer currentNode;
    NodePointer lastNode = NULL;

    if (list->head == NULL)
    {
        printf("cannot sort list, empty list!.\n");
        return;
    }

    do {
        swapped     = 0;
        currentNode = list->head;

        while (currentNode->next != lastNode)
        {
            if (currentNode->element > currentNode->next->element)
            {
                swapElements(currentNode, currentNode->next);
                swapped = 1;
            }
            currentNode = currentNode->next;
        }
        lastNode = currentNode;
    } while(swapped);
}


NodePointer merge(NodePointer firstNode, NodePointer secondNode)
{
    NodePointer mergedNode = NULL;

    if (firstNode == NULL)
    {
        return secondNode;
    }
    else if (secondNode == NULL)
    {
        return firstNode;
    }

    if (firstNode->element <= secondNode->element)
    {
        mergedNode          = firstNode;
        mergedNode->next    = merge(firstNode->next, secondNode);
    }
    else 
    {
        mergedNode          = secondNode;
        mergedNode->next    = merge(firstNode, secondNode->next);
    }

    return mergedNode;
}


void mergeLists(PlinkedList firstList, PlinkedList secondList, PlinkedList toMerge)
{
    NodePointer firstHead     = firstList->head;
    NodePointer secondHead    = secondList->head;

    NodePointer mergedList;

    if (firstHead == NULL)
    {
        mergedList = secondHead;
    }
    else if (secondHead == NULL)
    {
        mergedList = firstHead;
    }

    if (firstHead->element <= secondHead->element)
    {
        mergedList = firstHead;
        mergedList->next = merge(firstHead->next, secondHead);
    }
    else
    {
        mergedList = secondHead;
        mergedList->next = merge(firstHead, secondHead->next);
    }
    toMerge->head = mergedList;
}
    

void insertEndOfList(PlinkedList list, int element)
{
    NodePointer newNode;
    
    newNode = (NodePointer)malloc(sizeof(struct Node));

    newNode->element = element;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else 
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    BubbleSort(list);
}


void printList(PlinkedList list)
{
    NodePointer currentNode = list->head;
    
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->element);
        currentNode = currentNode->next;
    }
    printf("\n");
}