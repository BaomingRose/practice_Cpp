/* 
小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。
现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
*/

/*通过输入碗半径计算得到周长，与输入的猫的身长相比较*/

#include <iostream>
using namespace std;

int main() {
	double n,r;
	while(cin >> n >> r) {
		//周长：2*r*3.1415
		//身长：n
		if(n > (2 * r * 3.1415))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	} 
	return 0;
} 
