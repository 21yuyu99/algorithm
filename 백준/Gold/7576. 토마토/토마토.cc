#include <iostream>
#include <queue>
using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M,N;
    cin >> M >> N;
    int board[1000][1000];
    queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    int not_ripe = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
            if(board[i][j]==1){
                q.push({i,j});
            }
            else if(board[i][j]==0){
                ++not_ripe;
            }
        }
    }
    bool visited[1000][1000] ={0,};
    int day = 0;
    if(q.empty()){
        cout << -1;
        return 0;
    }
    while(not_ripe>0){
        int prev_not_ripe = not_ripe;
        while(!q.empty()){
            pair<int,int> xy = q.front();
            visited[xy.first][xy.second] = true;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xy.first + dx[i];
                int y = xy.second + dy[i];
                if(x<0 || y<0 || x>=N || y>=M) continue;
                if(visited[x][y] || board[x][y]!=0) continue;
                board[x][y] = 1;
                --not_ripe;
                q2.push({x,y}); 
            }
        }
        if(prev_not_ripe!=not_ripe){
            ++day;
        }
        prev_not_ripe = not_ripe;
        while(!q2.empty()){
            pair<int,int> xy = q2.front();
            visited[xy.first][xy.second] = true;
            q2.pop();
            for(int i=0;i<4;i++){
                int x = xy.first + dx[i];
                int y = xy.second + dy[i];
                if(x<0 || y<0 || x>=N || y>=M) continue;
                if(visited[x][y] || board[x][y]!=0) continue;
                board[x][y] = 1;
                --not_ripe;
                q.push({x,y});
            }
        }
        if(prev_not_ripe!=not_ripe){
            ++day;
        }
        prev_not_ripe = not_ripe;
       if(q.empty() && q2.empty() && not_ripe>0){
            day = -1;
            break;
       }
    }
    cout << day;
    return 0;
}