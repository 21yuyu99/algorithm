#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<char>> board;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int answer = 1;
void check_len(int x, int y){
    int r_len = 0;
    int c_len = 0;
    int tmp_len = 0; //현재 길이
    char cur_char = ' ';
    for(int i=0;i<N;i++){
        if(i==0 || cur_char == board[y][i]){ //행 확인
            ++tmp_len;
            r_len = max(r_len,tmp_len);
            cur_char = board[y][i];
        }
        else{
            tmp_len = 1;
            cur_char = board[y][i];
            r_len = max(r_len,tmp_len);
        }
    }
    tmp_len = 0;
    answer = max(answer,r_len);
    for(int i=0;i<N;i++){
        if(i==0 || cur_char == board[i][x]){ //열 확인
            ++tmp_len;
            c_len = max(c_len,tmp_len);
            cur_char = board[i][x];
        }
        else{
            tmp_len = 1;
            cur_char = board[i][x];
            c_len = max(c_len,tmp_len);
        }
    }
    answer = max(answer,c_len);
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.assign(N,vector<char>(N,0));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<N;i++){ // y
        for(int j=0;j<N;j++){ //x
            check_len(j,i);
            for(int d=0;d<4;d++){
                int tmpi = i + dy[d];
                int tmpj = j + dx[d];
                if(tmpi < 0 || tmpj < 0 || tmpi >= N || tmpj >= N) continue;
                if(board[tmpi][tmpj] == board[i][j]) continue;
                char tmpc = board[i][j];
                board[i][j] = board[tmpi][tmpj];
                board[tmpi][tmpj] = tmpc;
                check_len(j,i);
                board[tmpi][tmpj] = board[i][j];
                board[i][j] = tmpc;
            }
        }
    }
    cout << answer;
    return 0;
}