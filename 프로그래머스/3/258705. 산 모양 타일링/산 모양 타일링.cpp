#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> tops) {
    int dp_size = 2*n+1;
    vector<int> DP(dp_size+1,0);
    DP[1] = 1;
    DP[0] = 1;
    int top_idx = 0;
    
    for(int i=2;i<=dp_size;i++){
        DP[i] = DP[i-1] + DP[i-2];
        
        if(i%2==0){
            if(tops[top_idx]!=0){
                DP[i] += DP[i-1];   
            }
            ++top_idx;
        }
        // cout << i << " " << DP[i] << "\n";
        DP[i]%=10007;
    }
    
    int answer = DP[dp_size];
    return answer; //경우의 수
}


//두 개짜리 - 마름모 or 삼각형
//한 개짜리 - 무조건 삼각형