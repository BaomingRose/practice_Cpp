/*扑克牌最少多少次出光，一次可以一张、一对、5连张、3连对
A 2 3 4 5 6 7 8 9 10共10张牌，给定一个容量为10的数组，分别表示每张牌的张数*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

//设置的无穷大值 
const int inf = 0x3f3f3f3f;
//保存最少的结果 
int minn;
//接收的数组 
int arr[15];

//终止条件之一 、牌全出完了 
bool isok(int a[]) {
	for(int i = 0; i < 10; i++) {
		if(a[i] != 0) return false;
	}
	return true;
}

//从当前步数step
void dfs(int a[], int step){
	if(step > minn) return;
	
	//如果出光了并且比原来最小值小则更新 
	if(isok(a) && minn > step) {
		minn = step;
	}
	
	//以i为基准   i从0到9深搜 
	for(int i = 0; i < 10; i++) {
		//以i为头连出5张 
		if(i + 4 < 10 && a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0 && a[i + 3] > 0 && a[i + 4] > 0) {
			a[i] -= 1;
			a[i + 1] -= 1;
			a[i + 2] -= 1;
			a[i + 3] -= 1;
			a[i + 4] -= 1;
			dfs(a, step + 1);
			a[i] += 1;
			a[i + 1] += 1;
			a[i + 2] += 1;
			a[i + 3] += 1;
			a[i + 4] += 1;
		}
		//以i为头连出3对 
		if(i + 2 < 10 && a[i] > 1 && a[i + 1] > 1 && a[i + 2] > 1) {
			a[i] -= 2;
			a[i + 1] -=2;
			a[i + 2] -=2;
			dfs(a, step + 1);
			a[i] += 2;
			a[i + 1] +=2;
			a[i + 2] +=2;

		}
		//出两张i 
		if(minn == inf && a[i] > 1) {
			a[i] -= 2;
			dfs(a, step + 1);
			a[i] += 2;
		}
		//出一张i 
		if(minn == inf && a[i] > 0) {
			a[i] -= 1;
			dfs(a, step + 1);
			a[i] += 1;
		}
	}
}
int main()
{
	minn = inf;
	for(int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(arr, 0);
	printf("%d\n", minn);
	return 0;
}
