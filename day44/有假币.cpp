/*
链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
来源：牛客网

居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。
nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。
只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。
*/

/*
平均分三份是最快的方法，两份进行称重（对比出三个的重量 ），后对最重的那份再次进行称重，直到称重
的个数不足2个时则结束，获得假币 如果无法平均分3分则余数要么是1要么是2，因为是要最多称几次，n=n/3+1
满足每次取最大 分称3份，取两份一样多的过秤，然后把三份中最多的那份继续分，直到硬币剩余0或1时截至
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	long long n;
	int cnt;
	while ((scanf("%lld",&n)) != EOF) {
		if (n == 0)
			break;
		cnt=0;
		while (n >= 2) {
			if (n % 3) {
				//不可以整除则取最差情况：最重的一份是 n/3 + 1个金币
				n=n/3+1;
			} else {
				//可以整除在直接整除，能够获取到最重的一份
				n/=3;
			} 
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
