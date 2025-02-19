#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,E;
    cin >> N >> E;
    vector<vector<pair<int,int>>> graph(N+1);
    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b}); //거리, 정점
        graph[b].push_back({c,a});
    }
    int V1,V2;
    cin >> V1 >> V2;
    int distance[801][4]; //0, 1 : v1, 2:,v2, 3:모두 패스
    for(int i=0;i<801;i++){
        distance[i][0] = INT_MAX;
        distance[i][1] = INT_MAX;
        distance[i][2] = INT_MAX;
        distance[i][3] = INT_MAX;
    }
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq; //하나는 거리, 정점, 여부
    if(V1==1){
        distance[1][1] = 0;
        pq.push({{0,1},1});
    }
    else{
        distance[1][0] = 0;
        pq.push({{0,1},0});
    }

    while(!pq.empty()){
        int dis = pq.top().first.first;
        int node = pq.top().first.second;
        int isPass = pq.top().second;
       // cout << "dis: " << dis << "node : " << node << "isPass : " << isPass << "\n";
        pq.pop();
        if(distance[node][isPass]<dis) continue;
        for(int i=0;i<graph[node].size();i++){
            int tmp_dis = dis + graph[node][i].first;
            int tmp_node = graph[node][i].second;
            if(isPass==3){
                if(tmp_dis<distance[tmp_node][3]){
                    distance[tmp_node][3] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},3});
                }
            }
            else if(isPass==1 && tmp_node!=V2){
                if(tmp_dis<distance[tmp_node][1]){
                    distance[tmp_node][1] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},1});
                }
            }
            else if(isPass==2 && tmp_node!=V1){
                if(tmp_dis<distance[tmp_node][2]){
                    distance[tmp_node][2] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},2});
                }
            }
            else if(tmp_node==V1){
                if(isPass==2 && tmp_dis<distance[tmp_node][3]){
                    distance[tmp_node][3] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},3});
                }
                else if(tmp_dis<distance[tmp_node][1]){
                    distance[tmp_node][1] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},1});
                }
            }
            else if(tmp_node==V2){
                if(isPass==1 && tmp_dis<distance[tmp_node][3]){
                    distance[tmp_node][3] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},3});
                }
                else if(tmp_dis<distance[tmp_node][2]){
                    distance[tmp_node][2] = tmp_dis;
                    pq.push({{tmp_dis,tmp_node},2});
                }
            }
            else if(tmp_dis<distance[tmp_node][0]){
                distance[tmp_node][0] = tmp_dis;
                pq.push({{tmp_dis,tmp_node},0});
            }
        }
    }
    if(distance[N][3]==INT_MAX)
        cout << -1;
    else
        cout << distance[N][3];
    return 0;
}