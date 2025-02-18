#include <iostream>
#include <vector>
using namespace std;
int board[50][50];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<vector<bool>> visited;
int N,L,R;
int country_cnt = 0;
int people_cnt = 0;
vector<pair<int,int>> check_move;
bool isRunning = true;
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int tmpx = x + dx[i];
        int tmpy = y + dy[i];
        if(tmpx<0 || tmpy < 0 || tmpx>=N || tmpy>=N) continue;
        if(visited[tmpx][tmpy]) continue;
        int total = abs(board[tmpx][tmpy] - board[x][y]);
        // cout << total << " " << "\n";
        if(total>=L && total<=R){
            visited[tmpx][tmpy] = true;
            dfs(tmpx,tmpy);
            ++country_cnt;
            people_cnt += board[tmpx][tmpy];
            check_move.push_back({tmpx,tmpy});
        }
    }
}
void change_cnt_and_close(){
    int cnt = people_cnt/country_cnt;
    for(int i=0;i<check_move.size();i++){
        board[check_move[i].first][check_move[i].second] = cnt;
    }
    check_move.clear();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    visited.resize(N,vector<bool>(N,false));
    int ans = 0;
    while(isRunning){
        isRunning = false;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j]) continue;
                visited[i][j] = true;
                country_cnt = 1;
                people_cnt = board[i][j];
                check_move.push_back({i,j});

                dfs(i,j);
                if(country_cnt>1){
                    isRunning = true;
                }
                change_cnt_and_close();
            }
        }
        visited.assign(N,vector<bool>(N,false));
        if(isRunning){
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
//인구 차이 L명 이상, R명 이하