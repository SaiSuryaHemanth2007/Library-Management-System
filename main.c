#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    struct Book* next;
} Book;

Book* head = NULL;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter The Book ID: "); scanf("%d", &newBook->id);
    getchar();
    printf("Enter The Title of The Book: "); fgets(newBook->title, 100, stdin);
    printf("Enter The Author Name: "); fgets(newBook->author, 100, stdin);
    printf("Enter The Quantity of The Book: "); scanf("%d", &newBook->quantity);
    newBook->next = head;
    head = newBook;
    printf("Book added successfully!\n");
}

void displayBooks() {
    Book* temp = head;
    if (!temp) {
        printf("No books available.\n");
        return;
    }
    printf("\nID\tTitle\tAuthor\tQuantity\n");
    while (temp != NULL) {
        printf("%d\t%s\t%s\t%d\n", temp->id, temp->title, temp->author, temp->quantity);
        temp = temp->next;
    }
}

void searchBook() {
    int id;
    printf("Enter The Book ID to be Searched: "); scanf("%d", &id);
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Found: %s by %s (Qty: %d)\n", temp->title, temp->author, temp->quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}

void deleteBook() {
    int id;
    printf("EnterThe Book ID to Delete: "); scanf("%d", &id);
    Book *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Book deleted successfully.\n");
}

void issueBook() {
    int id;
    printf("Enter The Book ID to Issue: "); scanf("%d", &id);
    Book* temp = head;
    while (temp) {
        if (temp->id == id && temp->quantity > 0) {
            temp->quantity--;
            printf("Book issued.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Cannot issue - Book not available or not found.\n");
}

void returnBook() {
    int id;
    printf("Enter The Book ID to Return: "); scanf("%d", &id);
    Book* temp = head;
    while (temp) {
        if (temp->id == id) {
            temp->quantity++;
            printf("Book returned.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Library System Management Menu ---\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Issue Book\n6. Return Book\n7. Exit\n");
        printf("Enter choice: "); scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}