#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s = 1;
    long long e = LLONG_MAX;
    int cnt = 0;
    while(s<=e){
        long long mid = s + (e-s)/2;
        long long tmp_cnt = 0;
        for(auto t:times){
            tmp_cnt += mid/t;
            if(tmp_cnt>=n) break;
        }
        if(tmp_cnt<n){
            s = mid+1;
        }
        else{
            e = mid-1;
            answer = mid;
        }
    }
    
    return answer;
}


// 입국심사 기다리는 수 10^9
// 입국심사 시간 10^9
//심사관 10^6 => 이거 잘 써먹어야 함

//심사관(입국시간 순으로 정렬 x)
//이분탐색
//최저시간 구하기
//n시간동안 각각 몇명을 심사할 수 있는가?