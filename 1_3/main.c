#include <stdio.h>
#include <stdlib.h>

int main()
{
    int apple[10],height,sum;
    sum=0;
    for(int i=0;i<=9;i++){
        scanf("%d",&apple[i]);
    }
    scanf("%d",&height);
    for(int i=0;i<=9;i++){
        if(apple[i]<=height+30){
            sum++;
        }
    }
    printf("%d",sum);
}
