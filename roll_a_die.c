//roll a die
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollADie(void);
void countFrequencies(int);

//static int c1, c2, c3, c4, c5, c6;


int main(void){
    //int i, x;
    //printf("intervalo da rand: [0, %d]\n", RAND_MAX);
    //srand( (unsigned)time(NULL) );
    //for(i = 1; i <= 10; i++){
    //    printf("Número %d: %d\n", i, rand());
    //}
//
    //x = 1 + (rand() % 6);
    //printf("%d\n", x);
//
    //return 0;

    srand(time(NULL)); //apresenta cada segundo passado since 1970 Jan 01

    //se rodarmos o programa no mesmo segundo os números serão os mesmos

    int numberOfRolls;

    printf("Quantos roladas?");
    scanf("%d", &numberOfRolls);

    countFrequencies(numberOfRolls);

    
    //for(i = 1; i <= 10; i++){
    //    face = rollADie();
    //    printf("#%d ROLL: %d\n", i, face);
    //    if(face == 1) c1++;
    //    if(face == 2) c2++;
    //    if(face == 3) c3++;
    //    if(face == 4) c4++;
    //    if(face == 5) c5++;
    //    if(face == 6) c6++;
       
    //}
    //printf("Counts: 1s - %d *** 2s - %d *** 3s - %d *** 4s - %d *** 5s - %d *** 6s - %d\n", c1, c2, c3, c4, c5, c6);
    return 0;
}

void countFrequencies(int numberOfRolls){
    //int i;
    //for(i = 1; i <= numberOfRolls; i++){
    //    int face = rollADie(); 
    //    printf("ROLL#i: %d\n", face);
    //    if(face == 1) c1++;
    //    if(face == 2) c2++;
     //   if(face == 3) c3++;
    //    if(face == 4) c4++;
    //    if(face == 5) c5++;
    //    if(face == 6) c6++;
    
    int face;
    int freq1, freq2, freq3, freq4, freq5, freq6;
    freq1 = freq2 = freq3 = freq4 = freq5 = freq6 = 0;

    for(int i = 0; i < numberOfRolls; ++i){
        face = rollADie();
        printf("Rolada: %d\n", face);
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
    //rand() -> [0, RAND_MAX].....RAND_MAX é o integer máximo que varia para cada computador

    int face = rand() % 6 + 1;

    return face;
}