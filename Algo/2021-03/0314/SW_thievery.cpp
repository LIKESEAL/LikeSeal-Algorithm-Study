#include <string>
#include <vector>
#define MAX(a,b) a>b?a:b
using namespace std;

int dp[3][1000001] = {0,};
int solution(vector<int> money) {
    int answer = 0;
    int money_cnt = money.size();
    
    dp[0][0]=money[0]; // 1번집부터 털자
    dp[0][1]=money[0]; // 이 부분 초기화 안해서 계속 틀림 ㅠㅠ
    for (int i = 2; i < money_cnt-1; i++) {
        dp[0][i] = MAX(dp[0][i-2]+money[i], dp[0][i-1]);
    }
    
    dp[1][1]=money[1]; // 2번집부터 떨자
    for (int i = 2; i < money_cnt; i++) {
        dp[1][i] = MAX(dp[1][i-2]+money[i], dp[1][i-1]);
    }
    
    dp[2][2]=money[2]; // 0번집도 1번집도 털지 않고 3번째 집부터 털 경우를 대비해서 만들었는데 dp[0] dp[1]만 있어도 되는듯..
    for (int i = 3; i < money_cnt; i++) {
        dp[2][i] = MAX(dp[2][i-2]+money[i], dp[2][i-1]);
    }
    
    answer = MAX(dp[0][money_cnt-2], dp[1][money_cnt-1]);
    return MAX(answer, dp[2][money_cnt-1]);
}
