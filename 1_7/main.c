#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    scanf("%c",&c);
    int num[2]={0};
    int i=1;
    int n=0;
    while(c!='@'){
        if(c=='('){
            num[0]++;
            n++;
        }
        else if(c==')'){
            num[1]++;
        }
        else if(c!='+' && c!='-' && c!='*' && c!='/' && (c-'a'<0 || c-'z'>0) && (c-'0'<0 || c-'9'>0)){
            printf("NO");
            exit(0);
        }
        if(num[1]>num[0]){
            printf("NO");
            exit(0);
        }
        scanf("%c",&c);
        i++;
    }
    if(num[0]==num[1] && n<20 && i<255){
        printf("YES");
    }
    else{
        printf("NO");
    }
}
