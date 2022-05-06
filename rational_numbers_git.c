//code to work with rational numbers (gcd, simplification, addition, subtraction, multiplication and division)
#include <stdio.h>
#include <stdlib.h>

typedef struct rational_{
    int numerator;
    int denominator;
} rational;

void scanRational(rational *ran);
int greatestCommonDivisor(int a, int b);
rational simplification(rational ran);
void printRational(rational ran);
rational addRationals(rational a, rational b);
rational subtractRationals(rational a, rational b);
rational multiplyRationals(rational a, rational b);
rational divRationals(rational a, rational b);

int main(){
    printf("\n");
    rational num1;
    rational num2;
    puts("Enter the first rational number (numerator and non-zero denominator):");
    scanRational(&num1);
    puts("Enter the second rational number (numerator and non-zero denominator):");
    scanRational(&num2);
    printf("The first rational number after the simplification is:");
    printRational(num1);
    printf("The second rational number after the simplification is:");
    printRational(num2);

    rational addRan = addRationals(num1, num2);
    printf("Addition result: ");
    printRational(addRan);

    rational subtractRan = subtractRationals(num1, num2);
    printf("Subtraction result: ");
    printRational(subtractRan);

    rational multRan = multiplyRationals(num1, num2);
    printf("Multiplication result: ");
    printRational(multRan);

    rational divRan = divRationals(num1, num2);
    printf("Division result: ");
    printRational(divRan);

    printf("\n");

    return 0;
}

void scanRational(rational *ran){
    scanf("%d %d", &(ran->numerator), &(ran->denominator));
}

int greatestCommonDivisor(int a, int b){
    int cdiv = 1;
    int aux = 2;
    while(aux <= abs(a) || aux <= abs(b)){
        if(a % aux == 0 && b % aux == 0) cdiv = aux;
        aux += 1;
    }
    return cdiv;
}

rational simplification(rational ran){ 
    rational res;
    if(ran.numerator == 0){
        res.numerator = 0;
        res.denominator = 1;
        return res;
    }
    int gcd = greatestCommonDivisor(ran.numerator, ran.denominator);
    res.numerator = ran.numerator/gcd;
    res.denominator = ran.denominator/gcd;
    if(ran.denominator < 0){
        res.numerator = -res.numerator;
        res.denominator = abs(res.denominator);
    }
    if(ran.numerator < 0){
        res.numerator = res.numerator;
        res.denominator = abs(res.denominator);
    }
    return res;
}

void printRational(rational ran){
    rational res = simplification(ran);
    printf("%d\\%d ", res.numerator, res.denominator);
    printf("\n");
}

rational addRationals(rational a, rational b){
    rational res;
    res.numerator = (a.numerator*b.denominator)+(b.numerator*a.denominator);
    res.denominator = a.denominator*b.denominator;
    return simplification(res);
}

rational subtractRationals(rational a, rational b){
    rational res;
    res.numerator = (a.numerator*b.denominator)-(b.numerator*a.denominator);
    res.denominator = a.denominator*b.denominator;
    return simplification(res);
}

rational multiplyRationals(rational a, rational b){
    rational res;
    res.numerator = a.numerator*b.numerator;
    res.denominator = a.denominator*b.denominator;
    return simplification(res);
}

rational divRationals(rational a, rational b){
    rational res;
    res.numerator = a.numerator*b.denominator;
    res.denominator = a.denominator*b.numerator;
    return simplification(res);
}