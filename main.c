#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");

    // Validate Command Line Arguments (CLA)
    if (argc <= 1)
    {
        printf("Enter a valid number of CLA\n");
        printf("./Slist.exe file1.txt file2.txt ...\n");
        return 0;
    }

    // Create file linked list, declaring head pointer
    Flist *f_head = NULL;
    Wlist *head[27] = {NULL};

    // Validate the files and create the file linked list
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("Error: No files are available in the file list.\nEnter a file with contents.\n");
        return 1;
    }

    // Prompt the user for choice
    char option2;
    do
    {
        int option;
        printf("Select your choice among the following options:\n");
        printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save Database\n6. EXIT\n Enter your choice\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // Create the database
            create_database(f_head, head);
            break;
        case 2:
            // Display the database
            display_database(head);
            break;
        case 3:
            // Update the database
            update_database(head, &f_head);
            break;
        case 4:
            // Search for a word in the database
            char word[WORD_SIZE];
            printf("Enter the word: ");
            scanf("%s", word);
            search(head[tolower(word[0]) % 97], word);
            break;
        case 5:
            // Save the database
            save_database(head);
            break;
        case 6:
            // Exit the program
            exit(0);
            break;
        default:
            printf("Enter the correct option!!!\n");
            break;
        }

        // Clear input buffer
        while (getchar() != '\n');

        printf("Do you want to continue?\n");
        printf("Enter y/Y to continue or n/N to exit\n");
        scanf(" %c", &option2);

    } while (option2 != 'n' && option2 != 'N');
}

