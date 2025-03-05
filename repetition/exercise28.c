#include<stdio.h>

int main(){
    int i, sum ,num;
    sum = 0;

    for(i=0; i<5; i++ ){
        printf("Enter a no. : ");
        scanf("%d", &num);
        sum += num;
    }

    printf("The total no. is %d ",sum);
    return 0;
}