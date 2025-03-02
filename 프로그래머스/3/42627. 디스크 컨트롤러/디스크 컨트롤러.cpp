#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    //입력 [요청시점, 소요시간]
    int answer = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> waiting_pq;
    sort(jobs.begin(),jobs.end());
    //다 넣어두면 안되고. 일단 그 time 이후 요청인 값을 넣어야 되는데...
    int time = 0;
    int next_idx = 0;
    while(next_idx<jobs.size()){
        for(next_idx;next_idx<jobs.size();next_idx++){
            if(time>= jobs[next_idx][0]){
                waiting_pq.push({jobs[next_idx][1],{jobs[next_idx][0],next_idx}});         
            }
            else{
                break;
            }
        }
        //대기큐에 들어오기 전에 시간만 흐른다면.. 하나 일단 추가
        if(waiting_pq.empty()&&next_idx<jobs.size()){
            waiting_pq.push({jobs[next_idx][1],{jobs[next_idx][0],next_idx}});   
            time = jobs[next_idx][0];
            //cout << "time : " << time << "\n";
            ++next_idx;
        }
        if(!waiting_pq.empty()){
                pair<int,pair<int,int>> xy = waiting_pq.top();
                time += xy.first;
                answer += time - xy.second.first;
                //cout << time << " " << xy.second.first << "\n";
                waiting_pq.pop();
        }          
    }
    while(!waiting_pq.empty()){
                pair<int,pair<int,int>> xy = waiting_pq.top();
                time += xy.first;
                answer += time - xy.second.first;
                //cout << time << " " << xy.second.first << "\n";
                waiting_pq.pop();
    }
    answer/= jobs.size();
    return answer;
}
//우선순위
//소요시간 짧 -> 요청시간 빠른 것 -> 작업 번호 작은 것
//반환시간 = 종료시간 - 작업 요청 시간
//반환 시간의 평균 정수 부분을 구해라