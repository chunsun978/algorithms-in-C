#include <stdio.h>
#include <stdlib.h>


// Node Structure
typedef struct node {
    int val;
    struct node *next;
}Node;

// display the list
void printList(Node *head)
{
    Node *temp = NULL;

    temp = head;
    while (temp != NULL) {
        printf ("%d->", temp->val);
        temp = temp->next;
    }
    printf ("NULL\n");
}

// insert a node at the begining
int addToHead(Node **head, int val)
{
    Node *node = NULL;
    Node *temp = NULL;

    node = malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    else {
        node->val = val;
        node->next = NULL;
    }

    if (*head == NULL) {
        *head = node;
        node->next = NULL;
    }
    else {
        temp = *head;
        node->next = temp;
        *head = node;
    }

    return 1; 
} 

// append a node at the end
int addToEnd (Node *head, int val) 
{
    Node *node = NULL;
    Node *temp = NULL;

    node = malloc(sizeof(Node));
    if(node == NULL) {
        return 0;
    }
    else {
        node->val = val;
        node->next = NULL;
    }

    temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;

    return 1;
}

// release memory
void clearList (Node **head)
{
    Node *temp = NULL;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next; 
        free (temp);
    }
}


// a single program, so it is easier to step throgh it in VS Code
int main()
{
    Node *head = NULL;

    addToHead(&head, 10);
    addToHead(&head, 20);
    addToEnd(head, 30);
    addToEnd(head, 40);
    printList(head);
    
    clearList (&head);
    return 0;
}
