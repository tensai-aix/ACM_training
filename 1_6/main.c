#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    int num;
    int n_n[n+1];
    for(int i=0;i<=n;i++){
        n_n[i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&num);
        n_n[num]++;
    }
    int ans=n_n[1];
    for(int j=2;j<=n;j++){
        if(n_n[j]<ans){
            ans=n_n[j];
        }
    }
    printf("%d",ans);
    return 0;
}
