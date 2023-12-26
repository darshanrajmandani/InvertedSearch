#include "inverted_search.h"

// Function to search for a word in the database
void search(Wlist *head, char *word)
{
    // Check if the word list is empty
    if (head == NULL)
    {
        printf("List is Empty, search is not possible\n");
        return;
    }

    // Traverse through the word list
    while (head)
    {
        // Compare search word with each node's word
        if (!(strcmp(head->word, word)))
        {
            // Print information about the found word
            printf("Word %s is present in %d file/s\n", word, head->file_count);
            
            // Traverse through the link table
            Ltable *Thead = head->Tlink;
            while (Thead)
            {
                // Print file information for the found word
                printf("In file : %s    %d times\n", Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            
            printf("\n");
            return;
        }
        head = head->link;
    }

    // Print a message indicating the word was not found
    printf("Search Word %s is not found\n", word);
    return;
}

