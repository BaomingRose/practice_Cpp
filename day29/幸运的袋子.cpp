/*一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。
现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。*/

#if 0
解题思路：
每次从全集中选择若干元素（小球）组成子集（袋子）。对于任意两个正整数a,b如果满足 a+b>ab，则必有一个数为1.
可用数论证明：设a=1+x,b=1+y，则1+x+1+y>(1+x)(1+y)，---> 1>xy，则x，y必有一个为0，即a,b有一个为1.
推广到任意k个正整数，假设a1,a2,...ak，如果不满足给定条件，即和sum小于等于积pi。
如果此时再选择一个数b,能使其满足sum+b > pib，则，b必然为1，且为必要非充分条件。
反之，如果选择的b>1，则sum+b <= pi*b，即a1,a2,...,ak,b不满足给定条件。
因此，将球按标号升序排序。每次从小到大选择，当选择到a1,a2,...,ak-1时满足给定条件，而再增加选择ak
时不满足条件（ak必然大于等于max(a1,a2,...,ak-1)），继续向后选择更大的数，必然无法满足！此时不必再继续向后搜索。
如果有多个1，即当k=1时，sum(1)>pi(1)不满足，但下一个元素仍为1，则可以满足1+1>1*1， 
所以要判断当前ak是否等于1，如果等于1，虽然不能满足，组合的个数不能增加，但是继续向后搜索，
仍然有满足条件的可能.对于重复数字，组合只能算一个，要去重。 
#endif


#include<iostream>
#include<algorithm>
using namespace std;
/*
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x[]: 袋子中的所有球
n: 球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
	int count = 0;
		//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i<n; i++) {
		sum += x[i];
		multi *= x[i];
		if (sum > multi) {
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		} else if (x[i] == 1) {
			//如何不符合要求，且当前元素值为1，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		} else {
			//如何sum大于multi,则后面就没有符合要求的组合了
			break;
		} 
		//要搜索下一个位置之前，首先恢复sum和multi
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1]) {
			i++;
		}
	} 
	return count;
} 

int main() {
	int n;
	while (cin >> n) {
		int x[n];
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		} 
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	} 
	return 0;
}

