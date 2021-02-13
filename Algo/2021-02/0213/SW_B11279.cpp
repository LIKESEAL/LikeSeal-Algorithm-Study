###
baekjoon 11279 : 수들의 합
solved by SW
DATE : 2021.02.13
힙을 사용해서 풀라고 제시되어 있으나 priority_queue 사용
arr : 입력을 받는 priority_queue (최대 힙)
###

#include <iostream>
#include <queue>

#define endl '\n'
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> arr;
	int N;
	cin >> N;

	while (N-- > 0) {
		int i;
		cin >> i;

		if (i != 0) {
			arr.push(i);
		}
		else if (arr.empty()){
			cout << 0 << endl;
		}
		else {
			cout << arr.top() << endl;
			arr.pop();
		}
	}
	return 0;
}
