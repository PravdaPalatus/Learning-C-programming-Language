//entering information to the structure, capture data from the user and append it to the file (binary mode, "world.dat"), 
//Ask for the user the index of an entry, load it from the file and print out to the terminal

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen

#define NCHAR 64
#define WPOP 7800000000

typedef struct Data_{
    char country[NCHAR];
    long int population;
    float world_share; //percentage of world's population
} Data;

long int fsize(char *filename);
void printOption(int option, long int numOfEntries);
void scan_data(Data * pd);
void printData (Data country);

int main(){
    long int entryTotal;
    int option;
    
    puts("********************************************************************");

    //finding the total number of countries in the file
    entryTotal = fsize("world.dat")/sizeof(Data);
    printf("We will work with a list containing data from %ld different countries.\n", entryTotal);

    //user's input
    do{
    puts("PLEASE CHOOSE AN OPTION FROM THE MENU BELOW.");
    puts("1 - Include a country and its data in the country list");
    puts("2 - Read the data from a listed country and display it on the screen");
    puts("0 - Exit");
    scanf("%d%*c", &option);
    printOption(option, entryTotal);
    } while(option > 0);


    return EXIT_SUCCESS;
}

long int fsize(char *filename){
    long int listSize;
    FILE *list = fopen("world.dat", "r");
    if(list !=NULL){
        fseek(list, 0, SEEK_END);
        listSize = ftell(list);
        fclose(list);
    }
    return listSize;
}

void scan_data(Data * pd){
    puts("\nCountry:");
    fgets(pd -> country, NCHAR -1, stdin);
    pd->country[strlen(pd->country) - 1] = '\0';
    puts("Population:");
    scanf("%ld%*c", &(pd->population));
    pd->world_share = (((float) pd->population)/WPOP);
}

void printOption(int option, long int numOfEntries){
    switch (option)
    {
    case 0:
        puts("You chose to exit the analysis.");
        break;

    case 1:
        FILE *list;
        list = fopen("world.dat", "ab");
        if(list != NULL){
            Data *userCountry;
            userCountry = (Data *) calloc(1, sizeof(Data));
            scan_data(userCountry);
            fwrite(userCountry, numOfEntries, sizeof(Data), list);
            fclose(list);
            free(userCountry);
        }
        break;

    case 2:
        int entry;
        puts("What is the number of the entry you want to read?");
        scanf("%d%*c", &entry);
        Data country;
        FILE *listopt = fopen("world.dat", "rb");
        if(listopt != NULL){
            fseek(listopt, entry*sizeof(Data), SEEK_SET);
            fread(&country, 1, sizeof(Data), listopt);
            fclose(listopt);
        }
        printData(country);
        break;
    
    default:
        puts("This option does not exist.");
        break;
    }
}

void printData (Data country){
    printf("%s %ld %.2f%%\n", country.country, country.population, (country.world_share)*100);
}
