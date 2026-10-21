#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book{
        char* title;
        int pages;
        float price;
};
typedef struct book Book;

void print_book(Book* b){
        printf("Book:%s Pages:%i Price:%f\n", b->title, b->pages, b->price);
}

int main(){
        Book* p = (Book*)malloc(sizeof(Book));
        p->title = (char*)malloc(sizeof(char*)*13);
        strcpy(p->title, "Don Quixote");
        p->pages = 1000;
        p->price = 750.0;
        print_book(p);
        free(p->title);
        free(p);
}
