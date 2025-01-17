#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int dp[46] = {0,};
    dp[1] = 1;
    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N];
    return 0;
}