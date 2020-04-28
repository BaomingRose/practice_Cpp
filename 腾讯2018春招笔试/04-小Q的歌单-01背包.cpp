/*================================================
 * description：
小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，
现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，
在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

每个输入包含一个测试用例。
每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。
=================================================*/
//01背包求解
#include <iostream>
#include <cstring>
using namespace std;

int K, A, X, B, Y;
int dp[201][1001];
int p[201];
int mod = 1000000007;

int main() {
	while (cin >> K) {
		cin >> A >> X >> B >> Y;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= X; i++)
			p[i] = A;
		for (int j = X + 1; j <= X + Y; j++)
			p[j] = B;
		for (int i = 1; i <= X + Y; i++) {
			for (int j = 0; j <= K; j++) {
				if (j >= p[i])
					dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - p[i]] % mod) % mod;
				else
					dp[i][j] = dp[i - 1][j] % mod;
			}
		}
		cout << dp[X + Y][K] % mod << endl;
	}

	return 0;
}