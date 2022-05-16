//members sorted by weight ascending and descending order
#include <stdio.h>
#include <string.h>
#define N 100

typedef struct person_{
    char name[N];
    float weight;
} person;

person initialize();
void printPerson(person p);
void scanPerson(person *p);
int minWeight(person *p, int size, int start);
int maxWeight(person *p, int size, int start);
void swap(person *a, person *b);
void sortedAscending(person *p, int size);
void sortedDescending(person *p, int size);

int main(){
    float num;
    int i;
    puts("Enter with the number of elements: ");
    scanf("%f%*c", &num);

    person group[N];
    for(i = 0; i < num; i++){
        group[i] = initialize();
        scanPerson(group + i);
    }
    
    printf("\n");
    puts("List of individuals:");
    for(i = 0; i < num; i++){
        printPerson(group[i]);
        printf("\n");
    }

    printf("\n");

    sortedAscending(group, num);
    printf("People sorted by weigth: ascending order: \n");
    for(i = 0; i < num; i++){
        printPerson(group[i]);
        printf("\n");
    }

    printf("\n");

    sortedDescending(group, num);
    printf("People sorted by weigth: descending order: \n");
    for(i = 0; i < num; i++){
        printPerson(group[i]);
        printf("\n");
    }

    return 0;
}

person initialize(){
    person p = {"", 0};
    return p;
}

void printPerson(person p){
    printf("%s, %.1fkg", p.name, p.weight);
}

void scanPerson(person *p){
    puts("Enter name: ");
    fgets(p->name, N-1, stdin); p->name[strlen(p->name) - 1] = '\0';
    puts("Enter weight: ");
    scanf("%f%*c", &(p->weight));
}

int minWeight(person *p, int size, int start){
    int min = start;
    for(int j = start + 1; j < size; j++){
        if(p[j].weight < p[min].weight) min = j;
    }
    return min;
}
int maxWeight(person *p, int size, int start){
    int max = start;
    for(int j = start + 1; j < size; j++){
        if(p[j].weight > p[max].weight) max = j;
    }
    return max;
}

void swap(person *a, person *b){
    person aux = *a;
    *a = *b;
    *b = aux;
}

void sortedAscending(person *p, int size){
    int aux;
    for(int j = 0; j < size; j++){
        aux = minWeight(p, size, j);
        if(aux != j) swap(p+j, p+aux);
    } 
}

void sortedDescending(person *p, int size){
    int aux;
    for(int j = 0; j < size; j++){
        aux = maxWeight(p, size, j);
        if(aux != j) swap(p+j, p+aux);
    } 
}
