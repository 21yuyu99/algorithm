#include <iostream>
#include <vector>
using namespace std;
int R,C,T;
vector<vector<int>> Board;
vector<vector<int>> next_board;
vector<int> machine(2,-1);
bool isWall(int x,int y,vector<vector<int>> &B){
    if(x<0 || y<0|| x>=R || y>=C) return false;
    if(B[x][y]==-1) return false;
    return true;
}
void init_board(){
    next_board.assign(R,vector<int>(C,0));
    next_board[machine[0]][0] = -1;
    next_board[machine[1]][0] = -1;
}
void make_for_air_board(){
    next_board.assign(R,vector<int>(C,0));
    next_board[machine[0]][0] = -1;
    next_board[machine[1]][0] = -1;
    for(int i=1;i<machine[0];i++){
        for(int j=1;j<=C-2;j++){
            next_board[i][j] = Board[i][j];
        }
    }
    for(int i=machine[1]+1;i<=R-2;i++){
        for(int j=1;j<=C-2;j++){
            next_board[i][j] = Board[i][j];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    Board.assign(R,vector<int>(C,0));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> Board[i][j];
            if(Board[i][j]==-1){
                if(machine[0]==-1){
                    machine[0] = i;
                }
                else{
                    machine[1] = i;
                }
            }
        }
    }   //초기화 end
    //case 시작
    for(int t=0;t<T;t++){
        //확산
        init_board();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                int value = Board[i][j];
                if(value>0){
                    int v_spread = value/5;
                    int spread_cnt = 0;
                    for(int d=0;d<4;d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(!isWall(nx,ny,Board)) continue;
                        ++spread_cnt;
                        next_board[nx][ny] += v_spread;
                    }
                    next_board[i][j] += (value - spread_cnt * v_spread);
                }
            }
        } //확산 end
        Board = next_board;
        make_for_air_board();
        //공기청정기 start
        //위쪽 공기 순환
        for(int i=2;i<C;i++){
            next_board[machine[0]][i] = Board[machine[0]][i-1];
        }
        for(int i=machine[0]-1;i>=0;i--){
            next_board[i][C-1] = Board[i+1][C-1];
        }
        for(int i=C-2;i>=0;i--){
            next_board[0][i] = Board[0][i+1];
        }
        for(int i=1;i<machine[0];i++){
            next_board[i][0] = Board[i-1][0];
        }
        //아래쪽 공기 순환
        for(int i=2;i<C;i++){
            next_board[machine[1]][i] = Board[machine[1]][i-1];
        }
        for(int i=machine[1]+1;i<R;i++){
            next_board[i][C-1] = Board[i-1][C-1];
        }
        for(int i=C-2;i>=0;i--){
            next_board[R-1][i] = Board[R-1][i+1];
        }
        for(int i=R-2;i>machine[1];i--){
            next_board[i][0] = Board[i+1][0];
        }
        Board = next_board;
    }
    //answer
    int answer = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(Board[i][j]==-1) continue;
            answer += Board[i][j];
        }
    }
    cout << answer;
    return 0;
}