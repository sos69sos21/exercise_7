/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(ItemData item, ListNode *pnode);

// /* interface functions */
// /* set the list to empty */
void InitializeList(List *plist)
{
    // Updates required here, need to set both the head and tail pointers to NULL to initialize correctly.
    plist->pListHead = plist->pListTail = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
    // Updates required here, we now check if the head pointer is NULL for verifiying the list is empty.
    if (plist->pListHead == NULL)
        return true;
    else
        return false;
}


/* returns true if list is full */
bool ListIsFull(const List *plist)
{
    ListNode *pt;
    bool full;

    pt = (ListNode *)malloc(sizeof(ListNode));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}



/* returns number of nodes */
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    // Updates here to set start of list to the head
    ListNode *pnode = plist->pListHead;

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->pNext; /* set to next node */
    }

    return count;
}

// Minor logic updates here, since we are now tracking the tail, we no longer need 
// the scan logic, hence, we always know the last node location in order to add an item
// to the list...

// /* creates node to hold item and adds it to the end of */
// /* the list pointed to by plist (slow implementation) */
bool AddItem(ItemData item, List *plist)
{
    ListNode *pnew;
    //updates here, no longer need scan logic, removed variable...

    pnew = (ListNode *)malloc(sizeof(ListNode));
    if (pnew == NULL)
        return false; /* quit the function on failure */

    CopyToNode(item, pnew);
    pnew->pNext = NULL;

    // Updates here for testing if list is empty
    if (plist->pListHead == NULL)
        plist->pListHead = pnew;
    else
    {
        // Updates here for adding the new node
        plist->pListTail->pNext = pnew;
    }

    // Updates here for updating the tail pointer
    plist->pListTail = pnew;

    return true;
}

/* visit each node and execute a function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(ItemData item))
{
    // Updates here to grab the start/head of the list
    // we simply start travering at that point/begining now...
    ListNode *pnode = plist->pListHead;

    while (pnode != NULL)
    {
        (*pfun)(pnode->itemData); /* apply the function to the item */
        pnode = pnode->pNext; /* advance to the next item */
    }
}

// Minor Updates on logic here... See inline comments... 

/* free memory allocated by malloc() */
/* set the list pointer to NULL */
void EmptyTheList(List *plist)
{
    ListNode *psave;

    // the while condition is updated to check if head node is null, see comments below...
    while (plist->pListHead != NULL)
    {
        // Updates here for grabbing the next node after the head
        psave = plist->pListHead->pNext;
        // Updates here to free/remove the current head node
        free(plist->pListHead);
        // Assign the node after the head node we captured above to the head node.
        // Hene, with this while loop we are ultimately removing/freeing 
        // the head node, and setting the head node to the node after the head node...
        // Logic repeats until list is empty, hence the while condition, where if we see
        // the head node == NULL, we know we have removed all nodes...
        plist->pListHead = psave;
    }

    // Update here to set the tail pointer to NULL
    plist->pListTail = NULL;
}

/* local function definition */
/* copies an item into a node */
static void CopyToNode(ItemData item, ListNode *pnode)
{
    pnode->itemData = item;  /* Structure copy */
}