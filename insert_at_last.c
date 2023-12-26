#include "inverted_search.h"

// External declaration of the global variable fname
extern char *fname;

// Function to insert a new node at the end of the word linked list
int insert_at_last(Wlist **head, data_t *data)
{
    // Allocate memory for a new node
    Wlist *newnode = malloc(sizeof(Wlist));
    if (newnode == NULL)
        return FAILURE;

    // Initialize the new node
    newnode->file_count = 1;
    strcpy(newnode->word, data);
    newnode->Tlink = NULL;
    newnode->link = NULL;

    // Update the link table for the new node
    update_link_table(&newnode);

    // Check if the word linked list is empty
    if (*head == NULL)
    {
        *head = newnode;
        return SUCCESS;
    }

    // Non-empty list
    Wlist *temp = *head;

    // Traverse to the end of the list
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    // Insert the new node at the end
    temp->link = newnode;
    return SUCCESS;
}

// Function to update the link table for a given word node
int update_link_table(Wlist **head)
{
    // Allocate memory for a new link table node
    Ltable *newnode = malloc(sizeof(Ltable));
    if (newnode == NULL)
        return FAILURE;

    // Initialize the new link table node
    newnode->word_count = 1;
    strcpy(newnode->file_name, fname);
    newnode->table_link = NULL;

    // Link the new link table node to the given word node
    (*head)->Tlink = newnode;
    return SUCCESS;
}

