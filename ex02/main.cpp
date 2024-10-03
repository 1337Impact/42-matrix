#include <math.h>
#include <stdio.h>

typedef 

int lerp(int a, int b, int t){
    printf("int\n");
    return a + (b - a) * t;
}

int *lerp(int *a, int *b, int t){
    printf("int *\n");
    return a + (*b - *a) * t;
}

int **lerp(int **a, int **b, int t){
    printf("int **\n");
    return a + (**b - **a) * t;
}


int main(){
    int a = 1;
    int b = 2;
    printf("%d\n", lerp(&a, &b, 0.5));
    return 0;
}