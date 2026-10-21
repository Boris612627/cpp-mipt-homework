#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[50];
    int pages;
    float price;
} Book;

int main() {
    int* p1 = (int*)malloc(sizeof(int));
    *p1 = 123;
    printf("%i\n", *p1);
    free(p1);


    char* p2 = (char*)malloc(sizeof(char)*9);
    strcpy(p2, "Elephant");
    printf("%s\n", p2);
    free(p2);


    char** p3 = (char**)malloc(sizeof(char*));
    *p3 = (char*)malloc(sizeof(char)*14);
    strcpy(*p3, "Cats and Dogs");
    printf("%s\n", *p3);
    free(*p3);
    free(p3);


    Book* p4 = (Book*)malloc(sizeof(Book));
    strcpy(p4->title, "Don Quixote");
    p4->pages = 1000;
    p4->price = 750.0;
    printf("Book: %s, Pages: %i, Price: %f\n", p4->title, p4->pages, p4->price);
    free(p4);


    Book a;
    strcpy(a.title, "Don Quixote");
    a.pages = 1000;
    a.price = 750.0;
    Book* p5 = &a;
    printf("Book: %s, Pages: %i, Price: %f\n", p5->title, p5->pages, p5->price);


    Book** p6 = (Book**)malloc(sizeof(Book*));
    *p6 = (Book*)malloc(sizeof(Book));
    strcpy((*p6)->title, "Don Quixote");
    (*p6)->pages = 1000;
    (*p6)->price = 750.0;
    printf("Book: %s, Pages: %i, Price: %f\n", (*p6)->title, (*p6)->pages, (*p6)->price);
    free(*p6);
    free(p6);
    Book* p7 = (Book*)malloc(sizeof(Book)*3);
    strcpy(p7[0].title, "Don Quixote");
    p7[0].pages = 1000;
    p7[0].price = 750.0;
    strcpy(p7[1].title, "Oblomov");
    p7[1].pages = 400;
    p7[1].price = 250.0;
    strcpy(p7[2].title, "The Odyssey");
    p7[2].pages = 500;
    p7[2].price = 500.0;
    printf("Book: %s, Pages: %i, Price: %f\n", p7[0].title, p7[0].pages, p7[0].price);
    printf("Book: %s, Pages: %i, Price: %f\n", p7[1].title, p7[1].pages, p7[1].price);
    printf("Book: %s, Pages: %i, Price: %f\n", p7[2].title, p7[2].pages, p7[2].price);
    free(p7);
}

