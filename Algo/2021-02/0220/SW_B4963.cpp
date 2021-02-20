#include <iostream>
#define endl '\n'
using namespace std;

int w, h, map[51][51] = { 0, };
int cnt = 0;
int move_i[8] = { -1,-1,-1,0,0,1,1,1 };
int move_j[8] = { 1,0,-1,1,-1,1,0,-1 };

void check(int i, int j) {
	map[i][j] = 0;
	for (int d = 0; d < 8; d++) {
		int new_i = i + move_i[d], new_j = j + move_j[d];
		if (new_i < 0 || new_j < 0 || new_i >= h || new_j >= w)
			continue;
		if (map[new_i][new_j] == 1) {
			check(new_i, new_j);
		}
	}
	return;
}
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		// 너비 w와 높이 h 입력
		cin >> w >> h;
		// 0이 두 개 주어지면 입력 종료
		if (w == 0 && h == 0) {
			break;
		}

		// 지도 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != 0) {
					++cnt;
					check(i, j);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
