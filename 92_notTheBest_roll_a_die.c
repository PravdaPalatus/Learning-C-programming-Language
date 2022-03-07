//roll a die
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollADie(void);
void countResults(int);

int main(void){

    srand(time(NULL)); //seed

    int numberOfRolls;

    printf("How many dice do we roll?");
    scanf("%d", &numberOfRolls);

    countResults(numberOfRolls);

    return 0;
}

void countResults(int numberOfRolls){   
    int face;
    int res1, res2, res3, res4, res5, res6;
    res1 = res2 = res3 = res4 = res5 = res6 = 0;

    for(int i = 0; i < numberOfRolls; ++i){
        face = rollADie();
        printf("Roll: %d\n", face);
        switch (face){
            case 1:
            //count #face 1
                res1++;
            break;
            case 2:
                res2++;
            break;
            case 3:
                res3++;
            break;
            case 4:
                res4++;
            break;
            case 5:
                res5++;
            break;
            case 6:
                res6++;
            break;
        }
    }

    printf("Face1 came up %d #times\n", res1);
    printf("Face2 came up %d #times\n", res2);
    printf("Face3 came up %d #times\n", res3);
    printf("Face4 came up %d #times\n", res4);
    printf("Face5 came up %d #times\n", res5);
    printf("Face6 came up %d #times\n", res6);

}

int rollADie(void){
    //random number in range [1 - 6]

    int face = rand() % 6 + 1;

    return face;
}
