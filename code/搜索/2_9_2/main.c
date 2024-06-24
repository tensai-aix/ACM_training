#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int dx[5]= {1,0,-1,0};
const int dy[5]= {0,1,0,-1};
const int p[10]= {5,1,2,3,6,9,8,7,4};      //p[i]表示数字i在目标状态中的位置
int s,flag,r[10],a[5][5],map[5][5],dis[10][10];    //r[i]表示数字i在当前状态中的位置
bool check()  {
	for(int i=1; i<=9; i++) if(r[i]!=p[i])return 0;     //没有到达目标状态
	return 1;
}
int get()  {
	int t=0;
	for(int i=1; i<=9; i++) t+=dis[r[i]][p[i]];      //当前状态到目标状态共需要移动的次数
	return t;
}
int jue(int a,int b) {                      //求绝对值
	int t=a-b;
	return t<0?-t:t;
}
int calx(int i) {
	return (i-1)/3+1;
}
int caly(int i) {
	return i%3==0?3:i%3;
}
void dfs(int depth,int x,int y) {   //深搜
	if(depth+get()>s)  return;
	if(check())  {
		flag=1;
		return;
	}
	for(int i=0; i<4; i++) {
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>3||yy>3)  continue;
		swap(a[x][y],a[xx][yy]);      //交换两个数
		swap(r[a[x][y]],r[a[xx][yy]]);     //坐标也交换
		dfs(depth+1,xx,yy);
		swap(a[x][y],a[xx][yy]);
		swap(r[a[x][y]],r[a[xx][yy]]);
	}
}
void pre() {
	for(int i=1; i<=9; i++)
		for(int j=i+1; j<=9; j++)        //dis[i][j]表示从第i个点到第j个点至少移动的步数
			dis[i][j]=dis[j][i]=calx(j)-calx(i)+jue(caly(i),caly(j));
}
int main() {
	pre();
	int sx,sy;
	for(int i=1; i<=9; i++) {         //完成map的初始化构建和记录0的位置
		char ch=getchar();
		int x=calx(i),y=caly(i);    //坐标
		map[x][y]=ch-'0';
		r[ch-'0']=i;        //数字在初始的位置 i
		if(ch=='0')  sx=x,sy=y;     //空格的位置
	}
	for(s=0;; s++) {
		memcpy(a,map,sizeof(map));
		dfs(0,sx,sy);
		if(flag)  {
			printf("%d\n",s);
			break;
		}
	}
	return 0;
}
