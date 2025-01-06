#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 50
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

// Book structure
typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int available;
} Book;

// User structure
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

// Global arrays to store books and users
Book books[MAX_BOOKS];
User users[MAX_USERS];
int book_count = 0;
int user_count = 0;

// Function prototypes
void addBook();
void deleteBook();
void searchBook();
void displayBooks();
void addUser();
void deleteUser();
void displayUsers();
void issueBook();
void returnBook();
int findBookById(int id);
int findUserById(int id);

int main() {
    int choice;
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Add User\n");
        printf("6. Delete User\n");
        printf("7. Display Users\n");
        printf("8. Issue Book\n");
        printf("9. Return Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: deleteBook(); break;
            case 3: searchBook(); break;
            case 4: displayBooks(); break;
            case 5: addUser(); break;
            case 6: deleteUser(); break;
            case 7: displayUsers(); break;
            case 8: issueBook(); break;
            case 9: returnBook(); break;
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Book storage full!\n");
        return;
    }
    Book newBook;
    newBook.id = book_count + 1;
    printf("Enter title: ");
    getchar(); // consume newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // remove newline
    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n"); // remove newline
    newBook.available = 1;
    books[book_count++] = newBook;
    printf("Book added successfully!\n");
}

void deleteBook() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    int index = findBookById(id);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }
    for (int i = index; i < book_count - 1; i++) {
        books[i] = books[i + 1];
    }
    book_count--;
    printf("Book deleted successfully!\n");
}

void searchBook() {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    int index = findBookById(id);
    if (index == -1) {
        printf("Book not found!\n");
    } else {
        printf("Book ID: %d\nTitle: %s\nAuthor: %s\nAvailable: %s\n", books[index].id, books[index].title, books[index].author, books[index].available ? "Yes" : "No");
    }
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books available!\n");
        return;
    }
    for (int i = 0; i < book_count; i++) {
        printf("Book ID: %d\nTitle: %s\nAuthor: %s\nAvailable: %s\n\n", books[i].id, books[i].title, books[i].author, books[i].available ? "Yes" : "No");
    }
}

void addUser() {
    if (user_count >= MAX_USERS) {
        printf("User storage full!\n");
        return;
    }
    User newUser;
    newUser.id = user_count + 1;
    printf("Enter name: ");
    getchar(); // consume newline
    fgets(newUser.name, NAME_LENGTH, stdin);
    strtok(newUser.name, "\n"); // remove newline
    printf("Enter password: ");
    fgets(newUser.password, PASSWORD_LENGTH, stdin);
    strtok(newUser.password, "\n"); // remove newline
    users[user_count++] = newUser;
    printf("User added successfully!\n");
}

void deleteUser() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    int index = findUserById(id);
    if (index == -1) {
        printf("User not found!\n");
        return;
    }
    for (int i = index; i < user_count - 1; i++) {
        users[i] = users[i + 1];
    }
    user_count--;
    printf("User deleted successfully!\n");
}

void displayUsers() {
    if (user_count == 0) {
        printf("No users available!\n");
        return;
    }
    for (int i = 0; i < user_count; i++) {
        printf("User ID: %d\nName: %s\n\n", users[i].id, users[i].name);
    }
}

void issueBook() {
    int book_id, user_id;
    printf("Enter book ID to issue: ");
    scanf("%d", &book_id);
    printf("Enter user ID: ");
    scanf("%d", &user_id);
    int book_index = findBookById(book_id);
    int user_index = findUserById(user_id);
    if (book_index == -1 || user_index == -1) {
        printf("Book or User not found!\n");
        return;
    }
    if (books[book_index].available) {
        books[book_index].available = 0;
        printf("Book issued successfully to user %d!\n", user_id);
    } else {
        printf("Book is currently unavailable!\n");
    }
}

void returnBook() {
    int book_id;
    printf("Enter book ID to return: ");
    scanf("%d", &book_id);
    int index = findBookById(book_id);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }
    if (!books[index].available) {
        books[index].available = 1;
        printf("Book returned successfully!\n");
    } else {
        printf("Book was not issued!\n");
    }
}

int findBookById(int id) {
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findUserById(int id) {
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            return i;
        }
    }
    return -1;
}
