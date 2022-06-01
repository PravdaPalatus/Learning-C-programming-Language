//code to sort books by title, author, pages or price in ascending or descending order

#include <stdio.h>
#include <string.h>
#define MAXN 100

typedef struct book_{
    char title[MAXN];
    char author[MAXN];
    int pages;
    float price;
} book;

//support functions
book bookInitialize();
void bookScan(book *livro);
void printBook(book livro);
void upperCase(char *name);
void lowerCase(char *name);

//sort functions
int minInt(int a, int b);
float minFloat(float a, float b);
void swapBooks(book *livroA, book *livroB);
int minStr(char *strA, char *strB);
void byTitle(book *livros, int size, int st, int order);
void byAuthor(book *livros, int size, int st, int order);
void byPages(book *livros, int size, int st, int order);
void byPrice(book *livros, int size, int st, int order);

int main(){
    int num;
    puts("HOW MANY BOOKS DO YOU WANT TO ORGANIZE?");
    scanf("%d%*c", &num);

    book bookList[MAXN];
    puts("\nPLEASE ENTER THE DATA OF THE BOOKS.");
    for(int i = 0; i < num; i++){
        bookList[i] = bookInitialize();
        bookScan(&bookList[i]);
    }

    puts("\nWE HAVE THE FOLLOWING LIST OF BOOKS: ");
    for(int i = 0; i < num; i++){
        printBook(bookList[i]);
    }

    char field[MAXN];
    puts("Which field (title, author, pages or price) do you want to use to organize the books?");
    fgets(field, MAXN, stdin); field[strlen(field) - 1] = '\0';
    int order;
    puts("Ascending (1) or Descending (2)?");
    scanf("%d", &order);

    if(strcmp(field, "title") == 0) byTitle(bookList, num, 0, order);
    else if(strcmp(field, "author") == 0) byAuthor(bookList, num, 0, order);
    else if(strcmp(field, "pages") == 0) byPages(bookList, num, 0, order);
    else if(strcmp(field, "price") == 0) byPrice(bookList, num, 0, order);

    printf("\n");
    printf("List of books organized by %s\n", field);
    for(int i = 0; i < 4; i++){
        printBook(bookList[i]);
    }

    return 0;
}

//declarations
book bookInitialize(){
    book livro = {"", "", 0, 0.0};
    return livro;
}

void bookScan(book *livro){
    puts("Enter the name of the book: ");
    fgets(livro->title, MAXN, stdin); livro->title[strlen(livro->title) -1] = '\0';
    puts("Enter the name of the author: ");
    fgets(livro->author, MAXN, stdin); livro->author[strlen(livro->author) -1] = '\0';
    puts("Enter the number of pages: ");
    scanf("%d%*c", &(livro->pages));
    puts("Enter the price of the book: ");
    scanf("%f%*c", &(livro->price));
}

void printBook(book livro){
    printf("Title: %s\n", livro.title);
    printf("Author: %s\n", livro.author);
    printf("Pages: %d\n", livro.pages);
    printf("Price: %.2f\n", livro.price);
    printf("\n");
}

void upperCase(char *name){
    for(int i = 0; i < MAXN; i++){
        if(name[i] >= 97 && name[i] <= 122){
            name[i] = name[i] - 32;
        }
    }
}

void lowerCase(char *name){
    for(int i = 0; i < MAXN; i++){
        if(i == 0 || name[i - 1] == ' '){
            continue;
        }
        if(name[i] >= 65 && name[i] <= 99){
            name[i] = name[i] + 32;
        }
    }
}

int minInt(int a, int b){
    if(a < b) return 1;
    else if(a > b) return 0;
    return 2; //same pages
}

float minFloat(float a, float b){
    if(a < b) return 1;
    else if(a > b) return 0;
    return 2; //same price
}

void swapBooks(book *livroA, book *livroB){
    book aux = *livroA;
    *livroA = *livroB;
    *livroB = aux;
}

int minStr(char *strA, char *strB){
    upperCase(strA);
    upperCase(strB);
    for(int i = 0; i < MAXN; i++){
        if(strA[i] < strB[i]){
            lowerCase(strA);
            lowerCase(strB);
            return 1; //the first string is the min
        }
        else if(strA[i] > strB[i]){
            lowerCase(strA);
            lowerCase(strB);
            return 0; //the second string is the min
        }
    }
    lowerCase(strA);
    lowerCase(strB);
    return -1; //same string
}

void byTitle(book *livros, int size, int st, int order){
    if(order == 1){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minStr(livros[st].title, livros[i].title) == 0){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byTitle(livros, size, st + 1, 1);
        
    }
    if(order == 2){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minStr(livros[st].title, livros[i].title) == 1){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byTitle(livros, size, st + 1, 2);
        
    }

}

void byAuthor(book *livros, int size, int st, int order){
    if(order == 1){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minStr(livros[st].author, livros[i].author) == 0){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byAuthor(livros, size, st + 1, 1);
        
    }
    if(order == 2){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minStr(livros[st].author, livros[i].author) == 1){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byAuthor(livros, size, st + 1, 2);
        
    }

}

void byPages(book *livros, int size, int st, int order){
    if(order == 1){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minInt(livros[st].pages, livros[i].pages) == 0){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byPages(livros, size, st + 1, 1);
        
    }
    if(order == 2){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minInt(livros[st].pages, livros[i].pages) == 1){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byPages(livros, size, st + 1, 2);
        
    }

}

void byPrice(book *livros, int size, int st, int order){
    if(order == 1){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minFloat(livros[st].price, livros[i].price) == 0){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byPrice(livros, size, st + 1, 1);
        
    }
    if(order == 2){
        for(int i = st + 1; i <= size - 1; i++){      
            if(minFloat(livros[st].price, livros[i].price) == 1){
                swapBooks(livros + st, livros + i);
            }
        }
        if(st != size - 1) byPrice(livros, size, st + 1, 2);
        
    }

}
