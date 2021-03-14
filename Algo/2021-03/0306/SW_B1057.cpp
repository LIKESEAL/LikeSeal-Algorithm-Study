# BJ Silver3 - 토너먼트
# solved by SW
# DATE : 2021.03.07

#include <iostream>
#define endl '\n'
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a, b;
	cin >> N >> a >> b;

	int round = 1;
	while (true) {
		a = (a + 1) / 2; // 이겼을 경우 다음 참가 번호
		b = (b + 1) / 2;

		if (a == b)
			break;
		++round;
	}
	cout << round << endl;
	return 0;
}
