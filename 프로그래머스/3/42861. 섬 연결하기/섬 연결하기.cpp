#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <iostream>
using namespace std;
bool compare(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}
vector<int> parents;
int Find(int a){
    if(parents[a]==a) return a;
    return parents[a] = Find(parents[a]);
}
void Union(int pA, int pB){
    if(pA<pB){
        parents[pB] = pA;
    }
    else{
        parents[pA] = pB;
    }
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),compare);
    
    parents.resize(n);
    for(int i=0;i<n;i++){
        parents[i] = i;
    }
    for(int i=0;i<costs.size();i++){
        int a = costs[i][0];
        int b = costs[i][1];
        int c = costs[i][2];
        int pA = Find(a);
        int pB = Find(b);
        if(pA == pB) continue;
        //cout << a << " " << pA << " " << b << " " << pB << "\n";
        Union(pA,pB);
        answer+= c;
    }
    
    return answer; //건설하는 최소 비용
}
//n은 100 이하
//costs의 길이는 ((n-1)*n)/2 이하 (5000 이하)
//다익스트라?
//100*log5000