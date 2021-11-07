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

// main function

int main()
{
    
    return 0;
}


// Helper Methods

/*
    add this to methods and describe them here.
*/


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


void deleteList(PlinkedList List)
{
    /*
    create two new nodes, one to hold the value of the current node
    that we will free, and the other is a temp node to hold the value
    of the next node we want to free
    */
    NodePointer currentNode, tempNode;
    // assign the current node the head of the list
    currentNode = List->head;
    // delete the list by simply assigning the head to null.
    List->head = NULL;

    /*
    we assigned the head to null, but the list is still in memory,
    so we go through all the nodes and free them, starting from the head
    we do this by using our current node and temp node.
    */
    while (currentNode != NULL)
    {
        // assign temp node to the next node in the list.
        tempNode = currentNode->next;
        // free the current node from memory.
        free(currentNode);
        // assign the current node to the next node.
        currentNode = tempNode;
    }
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

    if (list == NULL)
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

PlinkedList mergeLists(PlinkedList firstList, PlinkedList secondList)
{
    NodePointer firstHead     = firstList->head;
    NodePointer secondHead    = secondList->head;

    PlinkedList mergedList;

    if (firstHead == NULL)
    {
        mergedList->head = secondHead;
        return mergedList;
    }
    else if (secondHead == NULL)
    {
        mergedList->head = firstHead;
        return mergedList;
    }

    if (firstHead->element <= secondHead->element)
    {
        mergedList->head = firstHead;
        mergedList->head->next = merge(firstHead->next, secondHead);
    }
    else
    {
        mergedList->head = secondHead;
        mergedList->head->next = merge(firstHead, secondHead->next);
    }
    return mergedList;
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