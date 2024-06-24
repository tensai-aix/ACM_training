#include <stdio.h>
#include <stdlib.h>

typedef long long LL;
const int MAX = 21*21*21;


int get_index(int a,int b,int c){   //用一个数储存三维数组
    return a*21*21 + b*21 + c;
}
int w(int a,int b,int c,int mems[],int flags[]){
	if(a <= 0||b <= 0||c <= 0)	return 1;
	int index = get_index(a,b,c);
	if(flags[index])	return mems[index];
	if(a < b&&b < c)
		mems[index] = w(a,b,c-1,mems,flags) + w(a,b-1,c-1,mems,flags) - w(a,b-1,c,mems,flags);
	else
		mems[index] = w(a-1,b,c,mems,flags)+w(a-1,b-1,c,mems,flags)+w(a-1,b,c-1,mems,flags)-w(a-1,b-1,c-1,mems,flags);
	flags[index] = 1;
	return mems[index];
}

int main()
{
	LL a,b,c;
	int ans;
	int mems[MAX];
    int flags[MAX];
	while(1){
        scanf("%lld %lld %lld",&a,&b,&c);
		if(a == -1&&b == -1&&c == -1)	break;
		else if(a <= 0||b <= 0||c <= 0)	ans = 1;
		else{
			if(a > 20||b > 20||c > 20)
				ans = w(20,20,20,mems,flags);
			else
				ans = w(a,b,c,mems,flags);
		}
		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans);
	}
	return 0;
}
