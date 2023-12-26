#include "inverted_search.h"

// Function to save the database to a file
void save_database(Wlist *head[])
{
    // Prompt user for the file name
    char file_name[FNAME_SIZE];
    printf("Enter the file name\n");
    scanf("%s", file_name);

    // Open the file in write mode
    FILE *fptr = fopen(file_name, "w");

    // Loop through each index in the array
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            // Write the database information to the file
            write_databasefile(head[i], fptr);
        }
    }

    // Print a message indicating successful save
    printf("Database saved in file %s\n", file_name);
	fclose(fptr);
}

// Function to write database information to a file
void write_databasefile(Wlist *head, FILE *databasefile)
{
    // Traverse through the word list
    while (head)
    {
        // Print word count information to the file
        fprintf(databasefile, "#[%d]\n word is [%s]: file count is [%d] : \n", head->word[0] % 97, head->word, head->file_count);

        // Traverse through the link table
        Ltable *Thead = head->Tlink;
        while (Thead)
        {
            // Print file information to the file
            fprintf(databasefile, " file/s: file is %s : word count is %d\n", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        // Move to the next word in the word list
        head = head->link;
    }
}

