#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    multiset<int> st;
    for(auto w:works){
        st.insert(w);
    }
    for(int i=0;i<n;i++){
        if(st.empty()) continue;
        auto it = --st.end();
        int tmp = *it-1;
        st.erase(it);
        if(tmp<0) continue;
        st.insert(tmp);
    }
    long long answer = 0;
    for(auto s:st){
        answer += s*s;
    }
    return answer;
}

// n : 남은 시간
//야근 피로도를 최소화하기
//야근 피로도 += 남은 일의 작업량 ^2

//가장 많은 작업량을 줄이기
//매번 정렬?
//logn