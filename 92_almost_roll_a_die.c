//roll a die
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollADie(void);
void countFrequencies(int);

int main(void){

    srand(time(NULL)); //seed

    int numberOfRolls;

    printf("How many dice do we roll?");
    scanf("%d", &numberOfRolls);

    countFrequencies(numberOfRolls);

    return 0;
}

void countFrequencies(int numberOfRolls){   
    int face;
    int freq1, freq2, freq3, freq4, freq5, freq6;
    freq1 = freq2 = freq3 = freq4 = freq5 = freq6 = 0;

    for(int i = 0; i < numberOfRolls; ++i){
        face = rollADie();
        printf("Roll: %d\n", face);
        switch (face){
            case 1:
            //count #face 1
                freq1++;
            break;
            case 2:
                freq2++;
            break;
            case 3:
                freq3++;
            break;
            case 4:
                freq4++;
            break;
            case 5:
                freq5++;
            break;
            case 6:
                freq6++;
            break;
        }
    }

    printf("Face1 came up %d #times\n", freq1);
    printf("Face2 came up %d #times\n", freq2);
    printf("Face3 came up %d #times\n", freq3);
    printf("Face4 came up %d #times\n", freq4);
    printf("Face5 came up %d #times\n", freq5);
    printf("Face6 came up %d #times\n", freq6);

}

int rollADie(void){
    //random number in range [1 - 6]

    int face = rand() % 6 + 1;

    return face;
}
