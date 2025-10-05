#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<array<int,2>>> roads(n+1);
    vector<int> spaceNum(n+1,0);
    //각 지점별 로드 저장
    for(int i=0;i<paths.size();i++){
        roads[paths[i][0]].push_back({paths[i][1],paths[i][2]});
        roads[paths[i][1]].push_back({paths[i][0],paths[i][2]});
    }
    
    for(int i=0;i<gates.size();i++){
        spaceNum[gates[i]] = 1;
    }
    for(int i=0;i<summits.size();i++){
        spaceNum[summits[i]] = 2;
    }
    
    vector<int> answer;
    int answer_idx = n+1;
    long long intensity = LLONG_MAX;
    priority_queue<array<long long,2>,vector<array<long long,2>>,greater<array<long long,2>>> pq; //현재 intensity, 현재 지점
    //각 출입구별로 시작해보기
    for(int i=0;i<gates.size();i++){
            vector<long long> distance(n+1,LLONG_MAX);
            pq.push({0,gates[i]}); 
            //각 지점에서의 intensity
            while(!pq.empty()){
                int cur_spot = pq.top()[1];
                int cur_intensity = pq.top()[0];
                pq.pop();
                if(cur_intensity>intensity) continue;
                
                for(int r=0;r<roads[cur_spot].size();r++){
                    int next_spot = roads[cur_spot][r][0];
                    int next_intensity = max(roads[cur_spot][r][1],cur_intensity);
                    if(next_intensity>intensity) continue;
                    if(spaceNum[next_spot]==1) continue;
                    if(next_intensity>=distance[next_spot]) continue;
                    distance[next_spot] = next_intensity;
                    if(spaceNum[next_spot]==2) {
                        if(intensity > next_intensity){
                           answer_idx = next_spot;
                           intensity = next_intensity;
                       }
                        else if(answer_idx > next_spot && intensity == next_intensity){
                           answer_idx = next_spot;
                           intensity = next_intensity;
                       }
                    }
                    else{
                        pq.push({next_intensity,next_spot});                        
                    }
                }
            }
    }
    //cout << intensity << " " << answer_idx;
    answer.push_back(answer_idx);
    answer.push_back(intensity);
    return answer; //산봉우리 번호(오름차순), intensity
}
//1~n
//출입구, 쉼터, 산봉우리
//다익스트라?
//휴식 없는 가장 긴 시간 = intensity
//intensity가 최소가 되어야 함.


//산봉우리는 한 번만 가능
//도착지 == 출발지이어야 함.
//다른 출입구를 중간에 방문하면 안됨


//n은 5 * 10^4
//path는 2*10^5
//w는 10^7
//gates와 summits에 등장하지 않는 지점은 모두 쉼터

//근데 여기는 쉼터,산봉우리, 출입구 중 하나임
//다익스트라 아님
//그냥 dfs, bfs?라고 하기에는 경우의 수가 너무 많다.
//이미 그 경로로 방문했는지 확인해야 함. 

//dp?
//각 지점에서의 intensity 