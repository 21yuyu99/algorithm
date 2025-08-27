#include <iostream>
#include <queue>
#include <functional>
#include <climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K,X;
    cin >> N; //도시의 개수
    cin >> M; //도로의 개수
    cin >> K; //거리 정보
    cin >> X; //도시의 번호
    //각 도시마다 해당 도시 바로 연결되는지 체크하거나
    //각 도시마다 연결되는 도시 push
    vector<vector<int>> city(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        city[a].push_back(b);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,X}); //거리, 도시
    vector<int> distance(N+1,INT_MAX);
    distance[X] = 0;
    while(!pq.empty()){
        int curDis = pq.top().first;
        int curCity = pq.top().second;
        pq.pop();
        if(curDis>distance[curCity]) continue;
        for(auto c:city[curCity]){
            if(curDis + 1 < distance[c]){
                distance[c] = curDis + 1;
                pq.push({curDis+1,c});
            }
        }
    }
    bool isExist = false;
    for(int i=1;i<=N;i++){
        if(distance[i]==K){
            cout << i << "\n";
            isExist = true;
        }
    }
    if(!isExist){
        cout << -1;
    }
    return 0;
}