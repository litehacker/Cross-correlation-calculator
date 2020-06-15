// By Giorgi Gvimradze //as a homework
// Cross-Correlation Machine
// Source: https://www.dspguide.com/ch7/3.htm

// Note: when a[n] and b[n], are convolved to produce c[n], 
// the equation is written: a[n] * b[n] = c[n]. In comparison, 
// the cross-correlation of a[n] and b[n] can be written: 
// a[n] * b[-n] = c[n].


#include <stdio.h>
#include <math.h>

#define INPUT 10
#define TESTED 4
#define OUTPUT 13


int input[INPUT]={2,4,1,5,3,6,6,4,2,0};
int tested[TESTED]={6,4,2,0};
int output[OUTPUT]={0};

void print_array(int *y,int n){
    int i,j;
    for(i=0;i<n;i++){
        printf("%d: ", i);
        for(j=0;j<y[i];j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void flip_impulse_array(int *x)
{
    int tmp[TESTED]={0},i,j;

    for(i=TESTED-1,j=0;i>=0;i--,j++)
        tmp[j]=x[i];

    for(j=0;j<TESTED;j++)
        x[j]=tmp[j];
}

void correlation(int *x, int *h, int *y)
{    
    int i,j;

    flip_impulse_array(tested);
    
    for(i=0;i<=OUTPUT;i++){
        y[i]=0;
    }
    
    for(i=0;i<=INPUT;i++){
        for(j=0;j<=TESTED;j++){
            y[i+j] = y[i+j] + x[i]*h[j];
        }
    }    
}

int main()
{
    printf("generated signal:\n");
    print_array(tested,TESTED);
    printf("input signal:\n");
    print_array(input,INPUT);
    correlation(input,tested,output);
    printf("cross-correlated signal:\n");
    print_array(output,OUTPUT);

    return 0;
}