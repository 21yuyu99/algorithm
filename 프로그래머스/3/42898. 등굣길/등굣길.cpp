#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    //m이 x, n이 y
    long divNum = 1000000007L;
    vector<vector<long>> dp(n+1,vector<long>(m+1,0));
    
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i=1;i<=n;i++){ //y
        for(int j=1;j<=m;j++){ //x
            if(dp[i][j] == -1) continue;
            if(i == 1 && j == 1) continue;
            dp[i][j] = (max(dp[i-1][j],0L)%divNum + max(dp[i][j-1],0L)%divNum) %divNum;
        }
    }
    int answer = dp[n][m];
    return answer;
}