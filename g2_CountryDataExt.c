//entering information to the structure, capture data from the user and append it to the file, 
//Ask for the user the index of an entry, load it from the file and print out to the terminal
//EXT: Show the entire database sorted by population in ascending or descending order
//Search the file for a specific country by its name, 
//Print out the total population in database in absolute values and as a percentage of the world's population

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen
#include <string.h>

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
void buildArray (Data *array, long int numOfEntries);
void popAscOrder(Data *array, long int numOfEntries);
void popDesOrder(Data *array, long int numOfEntries);
void printArray(Data *array, long int numOfEntries);

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
    puts("3 - Show the entire database sorted by population, in ascending order");
    puts("4 - Show the entire database sorted by population, in descending order");
    puts("5 - Search the file for a specific country by its name (or first letters)");
    puts("6 - Print out the total population in database in absolute values and as a percentage of the world's population");
    puts("0 - Exit");
    scanf("%d%*c", &option);
    printOption(option, entryTotal);
    if(option == 1) entryTotal = entryTotal + 1;
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
            fwrite(userCountry, 1, sizeof(Data), list);
            free(userCountry);
        }
        fclose(list);
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
    
    case 3:
        Data *arrayAsc;
        arrayAsc = (Data*) calloc(numOfEntries, sizeof(Data));
        buildArray(arrayAsc, numOfEntries);
        popAscOrder(arrayAsc, numOfEntries);
        printArray(arrayAsc, numOfEntries);
        free(arrayAsc);
        break;

    case 4:
        Data *arrayDes;
        arrayDes = (Data*) calloc(numOfEntries, sizeof(Data));
        buildArray(arrayDes, numOfEntries);
        popDesOrder(arrayDes, numOfEntries);
        printArray(arrayDes, numOfEntries);
        free(arrayDes);
        break;

    case 5:
        char str1[NCHAR] = {}; str1[strlen(str1) - 1] = '\0';
        char str2[NCHAR] = {}; str2[strlen(str2) - 1] = '\0';
        int length;

        puts("Which country would you like to search?");
        fgets(str1, NCHAR, stdin);

        length = strlen(str1)/sizeof(char);

        FILE *file;
        file = fopen("world.dat", "rb");

        if(file != NULL){
            for(int i = 0; i < numOfEntries; i++){
                fseek(file, i*sizeof(Data), SEEK_SET);
                
                fgets(str2, NCHAR, file);
                int count = 0;
                for(int j = 0; j < length; j++){
                    if(str1[j] == str2[j]) count += 1;
                }
                if(count == length - 1){
                    fseek(file, i*sizeof(Data), SEEK_SET);
                    Data curData;
                    fread(&curData, 1, sizeof(Data), file);
                    printData(curData);
                    break;
                }
                if(i == numOfEntries - 1) puts("Sorry! The country you entered could not be found.\n");
            }
        }
    
        fclose(file);
        break;

    case 6:
        printf("%ld\n", numOfEntries);
        long int sum = 0;
        long int pop;
        double percentage;
        Data countryCur;
        FILE *filePop;
        filePop = fopen("world.dat", "rb");
        if(filePop != NULL){
            for(int i = 0; i < numOfEntries; i++){
                fseek(filePop, i*sizeof(Data), SEEK_SET);
                fread(&countryCur, 1, sizeof(Data), filePop);
                pop = countryCur.population;
                sum += pop;
            }
        fclose(filePop);
        }
        percentage = (double) sum / WPOP;
        printf("The population in database in absolute value is: %ld.\n", sum);
        printf("Total population as a percentage of the world's population: %.2f%%\n", percentage*100);
        break;
    
    default:
        puts("This option does not exist.");
        break;
    }
}

void printData (Data country){
    printf("%s %ld %.2f%%\n", country.country, country.population, (country.world_share)*100);
}

void buildArray (Data *array, long int numOfEntries){
    FILE *file;
    file = fopen("world.dat", "rb");
    if(file != NULL){
        for(int i = 0; i < numOfEntries; i++){
            fread(&array[i], 1, sizeof(Data), file);
        }
    }
    fclose(file);
}

void popAscOrder(Data *array, long int numOfEntries){
    Data *aux;
    aux = (Data*) calloc(1, sizeof(Data));
    for(int j = 0; j < numOfEntries; j++){
        for(int i = 0; i < numOfEntries; i++){
            if(array[j].population < array[i].population){
                *aux = array[j];
                array[j] = array[i];
                array[i] = *aux;
            }
        }
    }
    free(aux);
}

void popDesOrder(Data *array, long int numOfEntries){
        Data *aux;
    aux = (Data*) calloc(1, sizeof(Data));
    for(int j = 0; j < numOfEntries; j++){
        for(int i = 0; i < numOfEntries; i++){
            if(array[j].population > array[i].population){
                *aux = array[j];
                array[j] = array[i];
                array[i] = *aux;
            }
        }
    }
    free(aux);
}

void printArray(Data *array, long int numOfEntries){
    for(int i = 0; i < numOfEntries; i++) printData(array[i]);
}
