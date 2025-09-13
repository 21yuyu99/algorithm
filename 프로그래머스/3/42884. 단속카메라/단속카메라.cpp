#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end(),compare);
    vector<bool> isVisited(routes.size(),0);
    int answer = 0;
    for(int i=0;i<routes.size();i++){
        if(isVisited[i]) continue;
        isVisited[i] = 1;
        ++answer;
        for(int j=i+1;j<routes.size();j++){
            if(routes[j][0]<= routes[i][1] || routes[j][1]<=routes[i][1]){
                isVisited[j]=1;
            }
            else{
                break;
            }
        }
    }
    return answer;
}
//단속용 카메라를 무조건 만나야 됨
//최소 몇 대 설치?
//10^4
//얘네가 고속도로에 있는 중에 카메라를 만나야되는 것