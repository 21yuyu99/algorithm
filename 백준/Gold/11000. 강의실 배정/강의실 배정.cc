#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> study(N);
    for(int i=0;i<N;i++){
        cin >> study[i].first >> study[i].second;
    }

    sort(study.begin(),study.end());

    priority_queue<int,vector<int>,greater<int>> pq;
    int answer = 0;
    for(int i=0;i<N;i++){
        if(!pq.empty()){
            int end_time = pq.top();
            if(end_time<=study[i].first){
                pq.pop();
                pq.push(study[i].second);
                continue;
            }
        }
        ++answer;
        pq.push(study[i].second);
    }
    cout << answer;
    return 0;
}