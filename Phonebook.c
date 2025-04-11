#include <stdio.h>
#include <windows.h>
#include <string.h>

struct phnbk
{
    char name[50];
    char phone_number[15];
    char address[100];
    char group[20];
};

void add_info(struct phnbk info[], int *numcontact)
{
    if (*numcontact < 100)
    {
        struct phnbk new;
        printf("Name: ");
        scanf(" %[^\n]", new.name);

        printf("Phone Number: ");
        scanf(" %14s", new.phone_number);

        printf("Address: ");
        scanf(" %[^\n]", new.address);

        printf("Group: ");
        scanf(" %[^\n]", new.group);

        info[*numcontact] = new;
        (*numcontact)++;

        printf("Contact added successfully!\n");
    }

    else
    {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void disp_info(struct phnbk info[], int numcontact)
{
    if (numcontact > 0)
    {
        printf("Contact List:\n");
        for (int i = 0; i < numcontact; i++)
        {
            printf("Contact %d:\n", i + 1);
            printf("Name: %s\n", info[i].name);
            printf("Phone Number: %s\n", info[i].phone_number);
            printf("Address: %s\n", info[i].address);
            printf("Group: %s\n", info[i].group);
            printf("-----------------------\n");
        }
    }
    else
    {
        printf("Phonebook is empty.\n");
    }
}

void disp_infog(struct phnbk info[], int numcontact)
{
    char group[20];
    if (numcontact > 0)
    {
        printf("Contact List:\n");
        printf("Enter group name: ");
        scanf(" %[^\n]", group);
        for (int i = 0; i < numcontact; i++)
        {
            if (strcmp(info[i].group, group) == 0)
            {
                printf("Contact %d:\n", i + 1);
                printf("Name: %s\n", info[i].name);
                printf("Phone Number: %s\n", info[i].phone_number);
                printf("Address: %s\n", info[i].address);
                printf("-----------------------\n");
            }
        }
    }

    else
    {
        printf("Phonebook is empty.\n");
    }
}

int main()
{
    struct phnbk info[100];
    int numcontact = 0;

    system("color 73");
    printf("                                                           ");
    printf("\n");
    printf("                         PhoneBook                         ");
    printf("\n");
    printf("                        -----------                        ");
    printf("\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Show by Group\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_info(info, &numcontact);
            break;

        case 2:
            disp_info(info, numcontact);
            break;

        case 3:
            disp_infog(info, numcontact);
            break;

        case 4:
            printf("Exiting the Phonebook Application.\n");
            return 0;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}
