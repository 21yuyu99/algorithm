#include <iostream>
#include <climits>
using namespace std;
struct Team {
    int cur_cnt;
    int total_score;
    int last_score;
    int total_cnt; //총인원
};
int main(){
    int T;
    cin >> T;
    ///////testcase start///////
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
    ///////team, running 초기화///////
        Team team[201];
        for(int i=1;i<201;i++){
            team[i] = {0,0,0,0};
        }
        team[0] = {0,INT_MAX,0,0};
        int running[N];
    ///////달리기///////
        for(int n=0;n<N;n++){
            //팀번호
            int team_num;
            cin >> team_num;
            //각 팀당 총인원 구하기
            team[team_num].total_cnt++;  
            running[n] = team_num;
        }
    ////점수 매기기////  
        int min_team_num = 0;
        int cur_score = 0;
        for(int n=0;n<N;n++){
            int team_num = running[n];
            if(team[team_num].total_cnt!=6) continue;            
            ++cur_score;
            team[team_num].cur_cnt++;
            if(team[team_num].cur_cnt==5){
                team[team_num].last_score = cur_score;
            }
            else if(team[team_num].cur_cnt==6){
                continue;
            }
            else{
                team[team_num].total_score += cur_score;
            }
        }
        for(int i=1;i<201;i++){
            //cout << team[i].last_score << " ";
            if(team[i].total_cnt!=6) continue;
            if(team[i].total_score<team[min_team_num].total_score){
                min_team_num = i;
            }
            else if(team[i].total_score==team[min_team_num].total_score && team[i].last_score<team[min_team_num].last_score){
                min_team_num = i;
            }
        }
        cout << min_team_num << "\n";
    }
}
//팀의 인원이 6명이 되는지.
//상위 4명 점수 +
//마지막 5주자의 점수는 기억해두기