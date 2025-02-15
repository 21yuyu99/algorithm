#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int N;
vector<int> team_1;
vector<int> team_2;
vector<bool> have_team;
vector<vector<int>> power;
int ans = INT_MAX;
void div_team_2(){
    for(int i=0;i<N;i++){
        if(have_team[i]) continue;
        team_2.push_back(i);
    }
}
void count_power(){
    int power_1 = 0;
    int power_2 = 0;
    for(int i=0;i<team_1.size();i++){
        for(int j=0;j<team_1.size();j++){
             power_1 += power[team_1[i]][team_1[j]];
             power_2 += power[team_2[i]][team_2[j]];
        }
    }
    ans = min(ans,abs(power_1-power_2));
}
void div_team_1(int num){
    if(team_1.size()==N/2){
        div_team_2();
        count_power();
        team_2.clear();
        return;
    }
    for(int i=num;i<N;i++){
        team_1.push_back(i);
        have_team[i] = true;
        div_team_1(i+1);
        have_team[i] = false;
        team_1.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    power.resize(N,vector<int>(N,0));
    have_team.resize(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> power[i][j];
        }
    }
    div_team_1(0);
    cout << ans;
    return 0;
}