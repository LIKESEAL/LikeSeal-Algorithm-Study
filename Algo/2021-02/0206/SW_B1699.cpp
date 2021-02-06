###
baekjoon 1699 : 제곱수의 합
solved by SW
DATE : 2021.02.06
다이나믹 프로그래밍
dp : 인덱스에 해당하는 숫자의 제곱수의 합의 최소 개수를 담은 배열
###

#include <iostream>
#define endl '\n'
#define MIN(a,b) a<b?a:b
using namespace std;

int dp[100001] = { 0, };
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
    // 1^2 * i가 제곱수 합의 최대 개수이므로 max로 초기화
		dp[i] = i;
		for (int j = 1; j <= i; j++) {
			if (j*j > i)
				break;
			dp[i] = MIN(dp[i], dp[i - j * j] + 1);

		}
	}

	cout << dp[N] << endl;
	return 0;
}
