#include "inverted_search.h"

// Function to update the database with a new file
void update_database(Wlist *head[], Flist **f_head)
{
    // Reading filename
    char file_name[FNAME_SIZE];
    printf("Enter the file name to update\n");
    scanf("%s", file_name);

    int empty;

    // Check if the file is available and not empty
    empty = isFileEmpty(file_name);
    if (empty == FILE_NOTAVAILABLE)
    {
        printf("Error: %s file is not available\n", file_name);
        return;
    }
    else if (empty == FILE_EMPTY)
    {
        printf("File: %s is not having any contents, cannot be added to linked list\n", file_name);
        return;
    }
    else
    {
        // Attempt to add the file to the file linked list
        int ret_val = to_create_list_of_files(f_head, file_name);

        if (ret_val == SUCCESS)
        {
            printf("File %s added to the list successfully\n", file_name);
        }
        else if (ret_val == REPEATATION)
        {
            printf("File: %s is already available, cannot be added\n", file_name);
            return;
        }
        else
        {
            printf("Failure in adding the file %s to the list\n", file_name);
            return;
        }
    }

    // Create the database with the updated file
    create_database(*f_head, head);
}

