#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int dis=abs(m-n);
    int ans=0;
    for(int i=1;i<=dis/2;i++){
        ans=ans+2*i;
    }
    if(dis!=dis/2*2){
        ans=ans+(dis+1)/2;
    }
    printf("%d",ans);
}
