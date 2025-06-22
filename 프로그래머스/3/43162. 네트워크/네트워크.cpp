#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N;
vector<bool> visited;
vector<vector<int>> Computers;
int answer = 0;
void dfs(int idx){
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        if (idx == i) continue;
        if(Computers[idx][i] == 1){
            visited[i] = 1;
            visited[idx] = 1;
            dfs(i);
            --answer;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    answer = n;
    N = n;
    visited.resize(n,false);
    Computers = computers;
    for(int i=0;i<n;i++){
        dfs(i);        
    }
    return answer;
}
// 그룹의 개수 구하기
// 연결이 끊길 때까지 연결해보고. 연결 끊기면 +1