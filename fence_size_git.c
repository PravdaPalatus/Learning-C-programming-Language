#include <stdio.h>
#include <math.h>

//aqui podemos utilizar o typedef para economizar a ecrita do struct point no resto do programa
struct point{
    double x;
    double y;
};

void insertPoint(struct point* currentPoint);
void printPoint(struct point coordPoint);
double euclideanDistance(struct point prevPoint, struct point currentPoint);
int checkEqual(struct point prevPoint, struct point currentPoint);
double totalFence();

int main(){
    
    double totalSum = totalFence();
    printf("You will need %lf meters of material to complete your fence.", totalSum);
    return 0;
}

void insertPoint(struct point* currentPoint){
    puts("Enter the coordinates x and y of the next point: ");
    scanf("%lf %lf", &(currentPoint->x), &(currentPoint->y));
}

void printPoint(struct point coordPoint){
    printf("(%lf, %lf)", coordPoint.x, coordPoint.y);
    printf("\n");
}

double euclideanDistance(struct point prevPoint, struct point currentPoint){
    double distance;
    double aux;
    double z, k; //I am using these variables (z and k) to clarify the code
    z = prevPoint.x - currentPoint.x;
    k = prevPoint.y - currentPoint.y;
    aux = pow(z, 2) + pow(k, 2);
    distance = sqrt(aux);
    return distance;
}

int checkEqual(struct point prevPoint, struct point currentPoint){
    if(prevPoint.x == currentPoint.x && prevPoint.y == currentPoint.y) return 1;
    return 0;
}

double totalFence(double sum){
    struct point startPoint;
    struct point currentPoint;
    struct point prevPoint;    
    puts("Enter coordenates of the first point: ");
    scanf("%lf %lf", &(startPoint.x), &(startPoint.y));
    currentPoint = startPoint;
    do{
        prevPoint = currentPoint;
        insertPoint(&currentPoint);
        sum += euclideanDistance(prevPoint, currentPoint);
    } while(checkEqual(startPoint, currentPoint) != 1);
    return sum;
}
