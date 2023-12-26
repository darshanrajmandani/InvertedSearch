#include "inverted_search.h"

// Function to display the database containing word counts and associated file information
void display_database(Wlist *head[])
{
    // Print header for the database display
    printf("\n[index]               [word]          file_count    file/s    File_name           word_count\n");

    // Loop through each index in the array
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            // Call the function to print word count information for the current index
            print_word_count(head[i]);
        }
    }
}

// Function to print word counts and associated file information for a given word
int print_word_count(Wlist *head)
{
    // Traverse through the word list
    while (head != NULL)
    {
        // Print word count information
    printf("[%2d]                   %-10s	 %2d         file/s:  ", tolower(head->word[0]) % 97, head->word, head->file_count);

        // Traverse through the link table
        Ltable *Thead = head->Tlink;
        while (Thead)
        {
            // Print file information
            printf(" %-10s             %2d", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        printf("\n");

        // Move to the next word in the word list
        head = head->link;
    }
}

