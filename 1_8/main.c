#include <stdio.h>
#include <stdlib.h>
int findmax(int h[],int n){
    int r=0;
    for(int i=0;i<=n-1;i++){
        if(r<h[i]){
            r=h[i];
        }
    }
    for(int i=0;i<=n-1;i++){
        if(h[i]==r){
            h[i]=0;
            break;
        }
    }
    return r;
}
int main()
{
    int n,h[20000];
    long b;
    scanf("%d %ld",&n,&b);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&h[i]);
    }
    int ans=0;
    while(b>0){
        b=b-findmax(h,n);
        ans++;
    }
    printf("%d",ans);
}
