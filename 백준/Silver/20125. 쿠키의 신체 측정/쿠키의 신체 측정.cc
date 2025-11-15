//심장 기준
//심장의 위치를 먼저 알아야 함
//머리는 한칸
//머리 바로 밑이 심장
//심장 왼오가 팔
//심장 밑이 허리
//허리 대각선이 다리

#include <iostream>
#include <vector>
using namespace std;
int count_left_arm(vector<vector<char>> &board,int hx,int hy){
    int x = hx;
    int y = hy-1;
    int rt = 0;
    while(y>0 && board[x][y]=='*'){
        ++rt;
        --y;
    }
    return rt;
}
int count_right_arm(vector<vector<char>> &board,int hx,int hy,int N){
    int x = hx;
    int y = hy+1;
    int rt = 0;
    while(y<=N && board[x][y]=='*'){
        ++rt;
        ++y;
    }
    return rt;
}
int count_waist(vector<vector<char>> &board,int hx,int hy,int N){
    int x = hx+1;
    int y = hy;
    int rt = 0;
    while(x<=N && board[x][y]=='*'){
        ++rt;
        ++x;
    }
    return rt;
}
int count_left_leg(vector<vector<char>> &board,int hx,int hy,int N,int waistLen){
    int x = hx+waistLen+1;
    int y = hy-1;
    int rt = 0;
    while(x<=N && board[x][y]=='*'){
        ++rt;
        ++x;
    }
    return rt;    
}
int count_right_leg(vector<vector<char>> &board,int hx,int hy,int N,int waistLen){
    int x = hx+waistLen+1;
    int y = hy+1;
    int rt = 0;
    while(x<=N && board[x][y]=='*'){
        ++rt;
        ++x;
    }
    return rt;    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int head[2] = {-1,-1};
    int heart[2] = {-1,-1};
    vector<vector<char>> board(N+1,vector<char>(N+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[i][j];
            if(head[0]==-1 && board[i][j] == '*'){
                head[0] = i;
                head[1] = j;
                heart[0] = i+1;
                heart[1] = j;
            }
        }
    }
    cout << heart[0] << " " << heart[1] << "\n";
    cout << count_left_arm(board,heart[0],heart[1]) << " ";
    cout << count_right_arm(board,heart[0],heart[1],N) << " ";
    int countWaist = count_waist(board,heart[0],heart[1],N); 
    cout << countWaist << " "; 
    cout << count_left_leg(board,heart[0],heart[1],N,countWaist) << " ";
    cout << count_right_leg(board,heart[0],heart[1],N,countWaist);
    return 0;
}