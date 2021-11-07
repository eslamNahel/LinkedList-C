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
    describe the function here.
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


