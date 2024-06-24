#include <stdio.h>
#include <stdlib.h>

int main()
{
    int budget[12],i,left,a_m,m_b,sign,m_g;
    for (i=0;i<=11;i++){
        scanf("%d",&budget[i]);
    }
    m_b=0;
    sign=1;
    m_g=0;
    for(i=0;i<=11;i++){
        a_m=m_b+300-budget[i];
        if(a_m<0){
            sign=0;
            printf("-%d",i+1);
            break;
        }
        m_g=m_g+a_m/100;
        m_b=a_m-(a_m/100)*100;
    }
    if(sign){
        printf("%d",m_g*120+m_b);
    }
}
