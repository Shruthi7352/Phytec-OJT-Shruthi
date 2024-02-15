#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GroceryItem {
    char name[50];
    float price;
};

void addItem(struct GroceryItem **list, int *itemCount) {
    *list = realloc(*list, (*itemCount + 1) * sizeof(struct GroceryItem));
    if (*list == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    printf("Enter the name of the item: ");
    scanf("%s", (*list)[*itemCount].name);
    printf("Enter the price of the item: ");
    scanf("%f", &(*list)[*itemCount].price);

    (*itemCount)++;
}
void displayList(struct GroceryItem *list, int itemCount) {
    printf("Grocery List:\n");
    printf("%-5s %-20s %s\n", "Index", "Item", "Price");

    for (int i = 0; i < itemCount; i++) {
        printf("%-5d %-20s $%.2f\n", i, list[i].name, list[i].price);
    }
}

void editItem(struct GroceryItem *list, int itemCount) {
    displayList(list, itemCount);
    int index;
    
    printf("Enter the index of the item to edit: ");
    scanf("%d", &index);

    if (index >= 0 && index < itemCount) {
        printf("Enter the new name of the item: ");
        scanf("%s", list[index].name);
        printf("Enter the new price of the item: ");
        scanf("%f", &list[index].price);
    } else {
        printf("Invalid index.\n");
    }
}

void removeItem(struct GroceryItem **list, int *itemCount, int index) {
    if (index >= 0 && index < *itemCount) {
        for (int i = index; i < *itemCount - 1; i++) {
            (*list)[i] = (*list)[i + 1];
        }
        *list = realloc(*list, (*itemCount - 1) * sizeof(struct GroceryItem));
        (*itemCount)--;
        printf("Item removed.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void saveListToFile(struct GroceryItem *list, int itemCount) {
    FILE *file = fopen("grocery_list.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s %.2f\n", list[i].name, list[i].price);
    }

    fclose(file);
    printf("List saved to file.\n");
}

void loadListFromFile(struct GroceryItem **list, int *itemCount) {
    FILE *file = fopen("grocery_list.txt", "r");
    if (file == NULL) {
        printf("No saved list found.\n");
        return;
    }

    *list = NULL;
    *itemCount = 0;

    while (!feof(file)) {
        *list = realloc(*list, (*itemCount + 1) * sizeof(struct GroceryItem));
        if (*list == NULL) {
            printf("Memory allocation error.\n");
            exit(1);
        }

        fscanf(file, "%s %f\n", (*list)[*itemCount].name, &(*list)[*itemCount].price);
        (*itemCount)++;
    }

    fclose(file);
    printf("List loaded from file.\n");
}

float calculateTotal(struct GroceryItem *list, int itemCount) {
    float total = 0.0;

    for (int i = 0; i < itemCount; i++) {
        total += list[i].price;
    }

    return total;
}

void removeList(struct GroceryItem **list, int *itemCount) {
    if (*list != NULL) {
        free(*list);
        *list = NULL;
        *itemCount = 0;
        printf("Grocery list removed.\n");
    } else {
        printf("No grocery list to remove.\n");
    }
}

int main() {
    struct GroceryItem *groceryList = NULL;
    int itemCount = 0;
    int choice;

    loadListFromFile(&groceryList, &itemCount);

    do {
         printf("\n=====================================\n");
        printf("         Grocery List Menu\n");
        printf("=====================================\n");
        printf("1. Add Item\n");
        printf("2. Display List\n");
        printf("3. Edit Item\n");
        printf("4. Remove Item\n");
        printf("5. Remove Entire List\n");
        printf("6. Save List to File\n");
        printf("7. Calculate Total Value\n");
        printf("8. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addItem(&groceryList, &itemCount);
                break;
            case 2:
                displayList(groceryList, itemCount);
                break;
            case 3:
                editItem(groceryList, itemCount);
                break;
            case 4:
                {
                    int index;
                    printf("Enter the index of the item to remove: ");
                    scanf("%d", &index);
                    removeItem(&groceryList, &itemCount, index);
                }
                break;
            case 5:
                removeList(&groceryList, &itemCount);
                break;
            case 6:
                saveListToFile(groceryList, itemCount);
                break;
            case 7:
                 printf("Total Value: $%.2f\n", calculateTotal(groceryList, itemCount));
                 break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    while (choice != 8);

    return 0;
}

