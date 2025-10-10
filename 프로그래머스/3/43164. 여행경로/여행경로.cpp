#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

bool compare(vector<string> &a, vector<string> &b){
    return a[1] < b[1];
}

vector<bool> visited;
vector<string> answer;
void dfs(string nm, vector<vector<string>> &tickets,vector<string> ans){
    for(int i=0;i<tickets.size();i++){ //10^4
        if(visited[i]==1) continue;
        string a = tickets[i][0];
        string b = tickets[i][1];
        if(a!=nm) continue;
        vector<string> tmp = ans;
        tmp.push_back(b);
        visited[i] = 1;
        dfs(b,tickets,tmp);
        visited[i] = 0;
    }
    if(answer.size()<ans.size()){
        answer = ans;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end(),compare);
    visited.resize(tickets.size(),0);
    dfs("ICN",tickets,vector<string>{"ICN"});
    return answer; //방문하는 공항 경로(중복 발생시 알파벳 순서 먼저)
}
//모든 항공권을 이용해야 함
//공항 수 10^4
//"ICN" 출발

//가중치 x dfs?
//중복 발생시 알파벳 순서

//각 경로별 정렬하면 됨

//단방향.
//시간복잡도 dfs log10^4면 4 * 