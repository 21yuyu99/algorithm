#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,D;
    cin >> N >> D;
    vector<vector<tuple<int,int>>> fast_road(D);
    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b >> c;
        fast_road[a].push_back({c,b}); //길이,도착지
    }
    vector<int> distance(D+1,INT_MAX);

    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> pq;
    pq.push({0,0}); //거리, 위치
    while(!pq.empty()){
        int d = get<0>(pq.top());
        int x = get<1>(pq.top());
        pq.pop();
        if(x>=D) break;
        if(distance[x]<d) continue;
        for(int i=0;i<fast_road[x].size();i++){
            int td = get<0>(fast_road[x][i]);
            int dx = get<1>(fast_road[x][i]);

            int t_total = td+d;
            if(t_total<distance[dx]){
                distance[dx] = t_total;
                pq.push({t_total,dx});
            }
        }
        if(distance[x+1]>d+1){
            distance[x+1] = d+1;
            pq.push({d+1,x+1});
        }
    }
    cout << distance[D];
    return 0;
}