#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int cnt = 0;//최대 거리 저장
    
    vector<vector<int>> roads(n+1);
    for(int e=0;e<edge.size();e++){
        int nodeA = edge[e][0];
        int nodeB = edge[e][1];
        roads[nodeA].push_back(nodeB);
        roads[nodeB].push_back(nodeA);
    }
    vector<int> distance(n+1,INT_MAX);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;//거리,현재 노드
    pq.push({0,1});
    while(!pq.empty()){
        int crntDstnc = pq.top()[0];
        int crntNode = pq.top()[1];
        pq.pop();
        if(crntDstnc>distance[crntNode]) continue;
        for(int e=0;e<roads[crntNode].size();e++){
            int nextNode = roads[crntNode][e];
            int nextDstnc = crntDstnc + 1;
            if(nextNode == 1) continue;
            if(distance[nextNode]<=nextDstnc) continue;
            distance[nextNode] = nextDstnc;
            cnt = max(cnt,nextDstnc);
            pq.push({nextDstnc,nextNode});
        }
    }
    int answer = 0;
    //cout << "cnt :  " << cnt << "\n";
    for(int d=1;d<=n;d++){
        if(distance[d]==cnt){
            //cout << d << " ";
            ++answer;
        }
    }
    return answer; //1번 노드에서 최단경로 기준 가장 멀리 떨어진 노드 개수
}
// n 2*10^4
//edge 5 * 10^4

//다익스트라로 각 노드의 최단경로 구하기(log10^4*5)