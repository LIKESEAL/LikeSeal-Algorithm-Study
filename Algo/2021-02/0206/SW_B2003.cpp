###
이번주 세연이가 푼 문제인데
문제 그대로풀면 시간 초과가 난다 하였으나
문제 그대로 풀었는데 ( 그리디?? 완전탐색?? 모라하지 ) 정답 처리가 되어서 답안 올립니다
물론 다른 답안에 비해서 시간은 오래 걸린 듯 합니다!!

baekjoon 2003 : 수들의 합
solved by SW
DATE : 2021.02.06
투포인터지만 완전탐색으로
sum : i~j까지의 합계
answer : i~j까지 합해서 M이 되는 경우의 수
###

#include <iostream>
#define endl '\n'
using namespace std;
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int A[10001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int sum = 0, answer = 0;
  // i(수열의 시작지점)를 0부터 N-1까지
	for (int i = 0; i < N; i++) {
    // sum 변수 초기화
		sum = 0;
    // i ~ j까지 sum에 더함
		for (int j = i; j < N; j++) {
			sum += A[j];
      // M과 같으면 answer + 1
			if (sum == M) {
				++answer;
				break;
			}
      // M보다 크면 break
			else if (sum > M) {
				break;
			}
		}
	}

	cout << answer << endl;
	return 0;
}
