#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int dx[5]= {1,0,-1,0};
const int dy[5]= {0,1,0,-1};
const int p[10]= {5,1,2,3,6,9,8,7,4};      //p[i]��ʾ����i��Ŀ��״̬�е�λ��
int s,flag,r[10],a[5][5],map[5][5],dis[10][10];    //r[i]��ʾ����i�ڵ�ǰ״̬�е�λ��
bool check()  {
	for(int i=1; i<=9; i++) if(r[i]!=p[i])return 0;     //û�е���Ŀ��״̬
	return 1;
}
int get()  {
	int t=0;
	for(int i=1; i<=9; i++) t+=dis[r[i]][p[i]];      //��ǰ״̬��Ŀ��״̬����Ҫ�ƶ��Ĵ���
	return t;
}
int jue(int a,int b) {                      //�����ֵ
	int t=a-b;
	return t<0?-t:t;
}
int calx(int i) {
	return (i-1)/3+1;
}
int caly(int i) {
	return i%3==0?3:i%3;
}
void dfs(int depth,int x,int y) {   //����
	if(depth+get()>s)  return;
	if(check())  {
		flag=1;
		return;
	}
	for(int i=0; i<4; i++) {
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>3||yy>3)  continue;
		swap(a[x][y],a[xx][yy]);      //����������
		swap(r[a[x][y]],r[a[xx][yy]]);     //����Ҳ����
		dfs(depth+1,xx,yy);
		swap(a[x][y],a[xx][yy]);
		swap(r[a[x][y]],r[a[xx][yy]]);
	}
}
void pre() {
	for(int i=1; i<=9; i++)
		for(int j=i+1; j<=9; j++)        //dis[i][j]��ʾ�ӵ�i���㵽��j���������ƶ��Ĳ���
			dis[i][j]=dis[j][i]=calx(j)-calx(i)+jue(caly(i),caly(j));
}
int main() {
	pre();
	int sx,sy;
	for(int i=1; i<=9; i++) {         //���map�ĳ�ʼ�������ͼ�¼0��λ��
		char ch=getchar();
		int x=calx(i),y=caly(i);    //����
		map[x][y]=ch-'0';
		r[ch-'0']=i;        //�����ڳ�ʼ��λ�� i
		if(ch=='0')  sx=x,sy=y;     //�ո��λ��
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
