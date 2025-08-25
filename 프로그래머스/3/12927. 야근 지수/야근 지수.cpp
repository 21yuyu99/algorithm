#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    for(auto w:works){
        pq.push(w);
    }
    for(int i=0;i<n;i++){
        if(pq.empty()) continue;
        int tmp = pq.top()-1;
        pq.pop();
        if(tmp<0) continue;
        pq.push(tmp);
    }
    long long answer = 0;
    while(!pq.empty()){
        int tmp = pq.top();
        answer += tmp*tmp;
        pq.pop();
    }
    return answer;
}

// n : 남은 시간
//야근 피로도를 최소화하기
//야근 피로도 += 남은 일의 작업량 ^2

//가장 많은 작업량을 줄이기
//매번 정렬?
//logn