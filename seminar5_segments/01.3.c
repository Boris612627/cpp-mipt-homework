#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book{
        char* title;
        int pages;
        float price;
};
typedef struct book Book;


struct library{
        Book* books;
        int number_of_books;
};
typedef struct library Library;


void print_book(Book* b){
        printf("Book:%s Pages:%i Price:%f\n", b->title, b->pages, b->price);
}


void library_create(Library* l, int n){
        l->books = (Book*)malloc(sizeof(Book)*n);
        l->number_of_books = n;
}


void library_set(Library* l, int i, char* title, int pages, float price){
        l->books[i].title = (char*)malloc(sizeof(char)*(strlen(title) + 1));
        strcpy(l->books[i].title, title);
        l->books[i].pages = pages;
        l->books[i].price = price;
}


Book* library_get(Library* l, int i){
        return &l->books[i];
}


void library_print(Library* l){
        for(int i = 0; i < l->number_of_books; i++){
                print_book(&l->books[i]);
}
}

void library_destroy(Library* l){
        for(int i = 0; i < l->number_of_books; i++){
                free(l->books[i].title);
        }
        free(l->books);
        l->books = NULL;
        l->number_of_books = 0;
}


int main(){
        Library a;
        library_create(&a, 3);
        library_set(&a, 0, "Don Quixote", 1000, 750.0);
        library_set(&a, 1, "Oblomov", 400, 250.0);
        library_set(&a, 2, "The Odyssey", 500, 500.0);
        library_print(&a);
        print_book(library_get(&a, 1));
        library_destroy(&a);
}

