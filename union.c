#include <stdio.h>
#define MAX_SIZE 1000

struct fiction_t {
    char title[250];
    char author[250];
    float price;
};
typedef struct fiction_t fiction;

struct nonfiction_t {
    char title[250];
    char subject[50];
    float price;
};
typedef struct nonfiction_t nonfiction;

union booktype_t {
    fiction fction;
    nonfiction nonfiction;
};
typedef union booktype_t booktype;

struct book_t {
    int type; // 1 for fiction, 2 for nonfiction
    booktype booktype;
};
typedef struct book_t book;

int bookcount;
book books[MAX_SIZE];

void readbooks() {
    printf("Enter the number of books: ");
    scanf("%d", &bookcount);
    
    for (int i = 0; i < bookcount; i++) {
        printf("Enter book type (1-fiction, 2-nonfiction): ");
        scanf("%d", &books[i].type);
        switch (books[i].type) {
            case 1: {
                printf("Enter fiction book details (title, author, price): ");
                scanf(" %249[^\n] %249[^\n] %f", books[i].booktype.fction.title, books[i].booktype.fction.author, &books[i].booktype.fction.price);
                break;
            }
            case 2: {
                printf("Enter non-fiction book details (title, subject, price): ");
                scanf(" %249[^\n] %49[^\n] %f", books[i].booktype.nonfiction.title, books[i].booktype.nonfiction.subject, &books[i].booktype.nonfiction.price);
                break;
            }
            default:
                printf("Invalid book type. Please enter 1 or 2.\n");
                i--; // Decrement i to repeat this iteration
                break;
        }
    }
}

void displaybooks() {
    for (int i = 0; i < bookcount; i++) {
        switch (books[i].type) {
            case 1: {
                printf("Fiction Book: Title: %s, Author: %s, Price: %.2f\n", books[i].booktype.fction.title, books[i].booktype.fction.author, books[i].booktype.fction.price);
                break;
            }
            case 2: {
                printf("Non-Fiction Book: Title: %s, Subject: %s, Price: %.2f\n", books[i].booktype.nonfiction.title, books[i].booktype.nonfiction.subject, books[i].booktype.nonfiction.price);
                break;
            }
            default:
                printf("Invalid book type.\n");
                break;
        }
    }
}

int main() {
    readbooks();
    displaybooks();
    return 0;
}
