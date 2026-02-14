#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,H; //세로선 개수,가로선 개수, 점선 수
vector<array<int,2>> num; //각 번호별 위치
vector<vector<int>> board;
int dx[3] = {-1,1,0}; //왼,오,아래
int dy[3] = {0,0,1};
int answer = -1;
bool move_test(){
    for(int i=1;i<=N;i++){
        int x = 1;
        int y = i;
        while(x<=H){
            if(board[x][y]==1){ //오른쪽으로 이동
                y+=1;
            }
            else if(y-1 > 0 && board[x][y-1]==1){ //왼쪽으로 이동
                y-=1;
            }
            x+=1;
        }
        if(x >= H && y == i) {
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
void make_new_line(int newLine,int x,int y){
    if(newLine > 3) return;
    if(answer != -1 && answer<newLine) return;
    if(x==H && y == N){
        // 사다리 진행
        if(move_test()){
            answer = answer==-1?newLine:min(answer,newLine);
        }
        return;
    }
    if(y!= N && (y+1<=N && board[x][y]!=1) && (y==1 || (y-1>0 && board[x][y-1]!=1))){ // 선 추가가 가능한가?
        board[x][y] = 1;
        make_new_line(newLine+1,x,y+1);
        board[x][y] = 0;    
    }
    if(y+1<=N){
        make_new_line(newLine,x,y+1);
    }
    else{
        make_new_line(newLine,x+1,1);
    }
} 
int main(){
    cin >> N >> M >> H; //세로,가로,점선
    board.resize(H+1,vector<int>(N+1));
    for(int i=1;i<=M;i++){
        int a,b; //점선 가로, 세로선
        cin >> a >> b;
        board[a][b] = 1;
    }
    make_new_line(0,1,1);
    cout << answer;
    return 0;
}