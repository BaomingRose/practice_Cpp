/*�˿������ٶ��ٴγ��⣬һ�ο���һ�š�һ�ԡ�5���š�3����
A 2 3 4 5 6 7 8 9 10��10���ƣ�����һ������Ϊ10�����飬�ֱ��ʾÿ���Ƶ�����*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

//���õ������ֵ 
const int inf = 0x3f3f3f3f;
//�������ٵĽ�� 
int minn;
//���յ����� 
int arr[15];

//��ֹ����֮һ ����ȫ������ 
bool isok(int a[]) {
	for(int i = 0; i < 10; i++) {
		if(a[i] != 0) return false;
	}
	return true;
}

//�ӵ�ǰ����step
void dfs(int a[], int step){
	if(step > minn) return;
	
	//��������˲��ұ�ԭ����СֵС����� 
	if(isok(a) && minn > step) {
		minn = step;
	}
	
	//��iΪ��׼   i��0��9���� 
	for(int i = 0; i < 10; i++) {
		//��iΪͷ����5�� 
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
		//��iΪͷ����3�� 
		if(i + 2 < 10 && a[i] > 1 && a[i + 1] > 1 && a[i + 2] > 1) {
			a[i] -= 2;
			a[i + 1] -=2;
			a[i + 2] -=2;
			dfs(a, step + 1);
			a[i] += 2;
			a[i + 1] +=2;
			a[i + 2] +=2;

		}
		//������i 
		if(minn == inf && a[i] > 1) {
			a[i] -= 2;
			dfs(a, step + 1);
			a[i] += 2;
		}
		//��һ��i 
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
