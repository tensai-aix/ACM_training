#include <stdio.h>
#include <stdlib.h>
typedef struct DATA{
    char core;
    int istrue;
}Data;
void check(Data data[100][100],int i,int j,char biaozhun[],int n){
    if(j<=n-7){
        int count=0;
        while(1){
            if(data[i][j+count].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i][j+k].istrue=1;
                }
                break;
            }
        }
    }
    if(j>=6){
        int count=0;
        while(1){
            if(data[i][j-count].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i][j-k].istrue=1;
                }
                break;
            }
        }
    }
    if(i<=n-7){
        int count=0;
        while(1){
            if(data[i+count][j].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i+k][j].istrue=1;
                }
                break;
            }
        }
    }
    if(i>=6){
        int count=0;
        while(1){
            if(data[i-count][j].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i-k][j].istrue=1;
                }
                break;
            }
        }
    }
    if(j>=6 && i>=6){
        int count=0;
        while(1){
            if(data[i-count][j-count].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i-k][j-k].istrue=1;
                }
                break;
            }
        }
    }
    if(j>=6 && i<=n-7){
        int count=0;
        while(1){
            if(data[i-count][j+count].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i-k][j+k].istrue=1;
                }
                break;
            }
        }
    }
    if(j<=n-7 && i>=6){
        int count=0;
        while(1){
            if(data[i+count][j-count].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i+k][j-k].istrue=1;
                }
                break;
            }
        }
    }
    if(j<=n-7 && i<=n-7){
        int count=0;
        while(1){
            if(data[i+count][j+count].core==biaozhun[count]){
                count++;
            }
            else{
                break;
            }
            if(count==7){
                for(int k=0;k<=6;k++){
                    data[i+k][j+k].istrue=1;
                }
                break;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char c[100][100];
    for(int i=0;i<=n-1;i++){
        scanf("%s",c[i]);
    }
    char biaozhun[7]={"yizhong"};
    Data data[100][100];
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            data[i][j].core=c[i][j];
            data[i][j].istrue=0;

        }
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
           if(data[i][j].core=='y'){
                check(data,i,j,biaozhun,n);
           }
        }
    }

    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            if(data[i][j].istrue==0){
                data[i][j].core='*';
            }
            printf("%c",data[i][j].core);
        }
        printf("\n");
    }
}
