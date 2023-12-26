#include "inverted_search.h"

char *fname;

// Function to create a database from the given file linked list
void create_database(Flist *f_head, Wlist *head[])
{
    while(f_head)
    {
        // Read data from the file and update the database
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
}

// Function to read data from a file and update the word linked list
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    fname = filename;

    FILE *fptr = fopen(filename, "r");

    // Handle file opening failure
    if (fptr == NULL) {
        return NULL;
    }

    char word[WORD_SIZE];

    // Loop through each word in the file
    while(fscanf(fptr, "%s", word) != EOF)
    {
        // Calculate the index based on the first character of the word
        int index = tolower(word[0]) % 97;

        // Handle characters other than alphabets
        if (!(index >= 0 && index <= 25))
            index = 26;

        int flag = 1;

        // Check whether words are repeated or not in the word linked list
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];

            // Compare the new word with each word in the list
            while(temp)
            {
                if (!strcmp(temp->word, word))
                {
                    // Update the word count if the word is repeated
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }

        // If the word is not repeated, insert it into the word linked list
        if (flag == 1)
        {
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);
}

// Function to update the word count in the link table
int update_word_count(Wlist **head, char *file_name)
{
    Ltable *temp = (*head)->Tlink;

    // Traverse the link table
    while(temp->table_link != NULL)
    {
        // Check if the file names are the same
        if (!strcmp(temp->file_name, file_name))
        {
            // Increment the word count if the file names match
            temp->word_count += 1;
            return SUCCESS;
        }
        else
        {
            // Increment the file count if the file names are different
            (*head)->file_count += 1;
        }
        temp = temp->table_link;
    }

    // Create a new node in the link table if the file name is not found
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
        return FAILURE;

    new->word_count = 1;
    strcpy(new->file_name, file_name);
    new->table_link = NULL;

    // Link the new node to the existing list
    temp->table_link = new;
    return SUCCESS;
}

