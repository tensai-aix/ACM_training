#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,sign,max,min,size;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if(c>a){
            max=c;
            min=b;
        }
        else if(c<b){
            max=a;
            min=c;
        }
        else{
            max=a;
            min=b;
        }
    }
    if(a<b){
        if(c>b){
            max=c;
            min=a;
        }
        else if(c<a){
            max=b;
            min=c;
        }
        else{
            max=b;
            min=a;
        }
    }
    sign=1;
    size=2;
    while(sign){
        for(int i=size;i<=min/2;i++){
            if(min==min/i*i&&max==max/i*i){
                min=min/i;
                max=max/i;
                break;
            }
            else{
                size++;
                break;
            }
        }
        if(size==min/2+1){
            sign=0;
        }
    }
    printf("%d/%d",min,max);

}
