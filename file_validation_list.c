#include "inverted_search.h"

// Function to validate files and create the file linked list
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty;
    // Loop through each command line argument
    while (argv[i] != NULL)
    {
        // Check if the file is available and not empty
        empty = isFileEmpty(argv[i]);
        if (empty == FILE_NOTAVAILABLE)
        {
            printf("Error: %s file is not available\n", argv[i]);
            i++;
            continue;
        }
        else if (empty == FILE_EMPTY)
        {
            printf("File: %s is not having any contents, cannot be added to the linked list\n", argv[i]);
            i++;
            continue;
        }
        else
        {
            // Attempt to add the file to the file linked list
            int ret_val = to_create_list_of_files(f_head, argv[i]);

            if (ret_val == SUCCESS)
            {
                printf("File %s added to the list successfully\n", argv[i]);
            }
            else if (ret_val == REPEATATION)
            {
                printf("File: %s is already available, cannot be added\n", argv[i]);
            }
            else
            {
                printf("Failure in adding the file %s to the list\n", argv[i]);
            }
            i++;
            continue;
        }
    }
}

// Function to check if a file is empty or not available
int isFileEmpty(char *filename)
{
    // Open file in read mode
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        if (errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
    fclose(fptr);
}

// Function to create a list of files in the file linked list
int to_create_list_of_files(Flist **f_head, char *name)
{
    Flist *newfile = malloc(sizeof(Flist));

    if (newfile == NULL)
    {
        printf("Error: Memory allocation for newfile is not successful\n");
        return FAILURE;
    }

    // Initialize the new file node
    strcpy(newfile->file_name, name);
    newfile->link = NULL;

    // Check if the file linked list is empty
    if (*f_head == NULL)
    {
        *f_head = newfile;
        return SUCCESS;
    }

    // Non-empty list
    Flist *temp = *f_head;

    // Traverse to the end of the list
    while (temp->link != NULL)
    {
        // Check for repetition of file names
        if (strcmp(temp->file_name, name) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }

    // Insert the new file node at the end
    temp->link = newfile;
    return SUCCESS;
}

