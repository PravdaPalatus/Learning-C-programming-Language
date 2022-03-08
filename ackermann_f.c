// Ackermann function

#include <stdio.h>

//prototypes

int ackermann(int m, int n);

int main(){
    int m, n;
    printf("m - > 0,1,2,3 ; n -> 0,1,2,3,4 : \n");
    scanf("%d %d", &m, &n);
    printf("The result is: %d\n",ackermann(m, n));

    return 0;
}

//declaration

int ackermann(int m, int n){                        // m and n are no negative values
    if(m == 0 && n > 0) return n + 1;
    else if(n == 0 && m > 0) return ackermann(m - 1, 1);
    else if(m > 0 && n > 0) return ackermann(m - 1, ackermann(m, n-1));
    return 0;
}

