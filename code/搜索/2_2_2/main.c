#include <stdio.h>
#include <stdlib.h>

int num[10] = {6,2,5,5,4,5,6,3,7,6},sum;
int huochai(int n){
    int k = 0;
    for(int i = n;i != 0;i /= 10){
        k += num[i % 10];
    }
    if(n==0){
        k += num[0];
    }
    return k;
}
int main(){
    int cnt = 0;
    int n;
    scanf("%d",&n);
    for(int i = 0;i <= 1111;i++){
        for(int j = 0;j <= 1111;j++){
            if(huochai(i) + huochai(j) + huochai(i + j) + 4 == n){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
