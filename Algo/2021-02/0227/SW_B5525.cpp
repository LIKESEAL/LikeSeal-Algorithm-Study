#include <iostream>
#define endl '\n'
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S, M;
	cin >> N >> M;

	int cnt = 0;
	int len = 0;
	char before = 'O';

	while (M-- > 0) {
		char c;
		cin >> c;

		if (before == c) {
			if (c == 'I') {
				len = 1;
			}
			else {
				len = 0;
			}
		}
		else {
			++len;
			if (len % 2 && len >= (2 * N + 1)) {
				++cnt;
			}
		}
		before = c;
	}

	cout << cnt << endl;
	return 0;
}
