#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N,M,F;
vector<vector<int>> Board; //1: 장애물, 3 : wall, 이상현상 : 5, 목적지 : 4
vector<vector<int>> Wall[5];
vector<vector<int>> Strange;
vector<vector<int>> Strange_Board;


int Me[3] = {0,}; //Me[2]이면 -1이면 미지의 공간 아니면 z값
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};//동,서,남,북
int Wall_Pos[2] = {-1,-1}; //미지의 공간에서 wall 첫 위치
int result = -1;
int next_z[5][4] = {
    {3,2,-1,4}, //동
    {2,3,-1,4}, //서
    {0,1,-1,4}, //남
    {1,0,-1,4}, //북
    {0,1,2,3} //윗
};
struct Me_pos{
    int r;
    int c;
    int z;
    int turn;
};
vector<vector<bool>> visited_Board;
vector<vector<bool>> visited_Wall[5];
void get_next_rc(int &r,int& c,int z,int d){
    int tr = r;
    int tc = c;
    if(z<4 && (d == 0 || d == 1)){ //옆면 -> 옆면 //(r,c) 순서동일
        tc = M-1 - c;
    }
    else if(z == 0 && d == 3){ //동쪽 옆면 -> 윗면 //(r,c) -> (c,r)
        tr = M-1 - c;
        tc = M-1 - r;
    }
    else if(z == 1 && d == 3){ //서쪽 옆면 -> 윗면 //(r,c) -> (c,r)
        tr = c;
        tc = r;
    }
    else if(z == 2 && d == 3){ //남쪽 옆면 -> 윗면 //(r,c)
        tr = M-1 - r;
        tc = c;
    }
    else if(z == 3 && d == 3){ //북쪽 옆면 -> 윗면 //(r,c)
        tr = r;
        tc = M-1 - c;
        //(0,0) -> (0,M-1)
    }
    else if(z == 0 && d == 2){ //동쪽면 -> 아래로 //(r,c) -> (c,r)
        tr = (M-1 + Wall_Pos[0]) - c;
        tc = Wall_Pos[1] + M-1 + 1;
    }
    else if(z == 1 && d == 2){ //서쪽면 -> 아래로 //(r,c) -> (c,r)
        tr = Wall_Pos[0] + c;
        tc = Wall_Pos[1] -1; 
    }
    else if(z == 2 && d == 2){ //남쪽면 -> 아래로 //(r,c) 
        tr = Wall_Pos[0] + M;
        tc = Wall_Pos[1] + c;
    }
    else if(z == 3 && d == 2){ //북쪽면 -> 아래로 //(r,c) 
        tr = Wall_Pos[0] - 1;
        tc = (M-1 + Wall_Pos[1]) - c;
    }
    else if(z==4 && d == 0){ //윗면 -> 동쪽으로 //(r,c) -> (c,r)
        tr = M-1 - c;
        tc = M-1 - r;
    }
    else if(z==4 && d == 1){ //윗면 -> 서쪽으로 //(r,c) -> (c,r)
        tr = c;
        tc = r; 
    }
    else if(z== 4 && d == 2){ //윗면 -> 남쪽으로 //(r,c) 
        tr = M-1 - r;
        tc = c;
    }
    else if (z == 4 && d == 3){ //윗면 -> 북쪽으로 //(r,c) 
        tr = r;
        tc = M-1 - c;
    }   
    r = tr;
    c = tc;
}
//빈공간 : 0
//장애물 : 1
//시간의벽 : 3
//탈출구 : 4
//시간이상 : 5
bool check_Board_bound(int y,int x){
    if(x<0 || y<0 || x>=N || y>=N)  
        return false;
    return true;
}
void spread_bad(){
    for(int turn = 1;turn<400;turn++){
        for(int f=0;f<F;f++){
            if(Strange[f][4] == 1 && turn%Strange[f][3] == 0){
                    int r = Strange[f][0];
                    int c = Strange[f][1];
                    int d = Strange[f][2];
                    int tr = r+dr[d];
                    int tc = c+dc[d];

                    if(!check_Board_bound(tr,tc)) {
                        Strange[f][4] = 0;
                        continue;
                    }
                    if(Board[tr][tc] == 1 || Board[tr][tc] == 4 || Board[tr][tc] == 3) {
                        Strange[f][4] = 0;
                        continue;
                    }
                    ////////현재 내가 있는 곳일 수도 있음///////
                    Strange[f][0] = tr;
                    Strange[f][1] = tc;
                    if(Strange_Board[tr][tc]>-1) continue;
                    Strange_Board[tr][tc] = turn;
            }
        }
    }
}
void printf_Strange(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << Strange_Board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool move_me(int &r,int& c,int& z,int d){ //z : 현재 벽면
    int tr = r + dr[d];
    int tc = c + dc[d];
    if(-1==z && !check_Board_bound(tr,tc)) return false; //미지의 공간 && bound 넘을 때
    if(z>=0){ //시간의 벽일 때
        if(tr<0 || tc<0 || tr>=M || tc>=M){//다른 면 또는 미지의 공간으로 이동
            tr = r;
            tc = c;
            get_next_rc(tr,tc,z,d);
            int tz = next_z[z][d];
            if(tz == -1){ //미지의 공간으로 잘 이동했는지 확인
                if(!check_Board_bound(tr,tc) || Board[tr][tc] == 1 || Board[tr][tc] == 3 || Board[tr][tc] == 5) return false;
            }
            else if(Wall[tz][tr][tc] == 1) return false;//시간의 벽
            r = tr;
            c = tc;
            z = tz;
            return true;
        }
        else if(Wall[z][tr][tc] == 1) return false;
        else{
            r = tr;
            c = tc;
            return true;
        }
    }
    else{ //미지의 공간에서 이동
        if(Board[tr][tc] == 1 || Board[tr][tc] == 3 || Board[tr][tc] == 5) return false;
        r = tr;
        c = tc;
        return true;
    }
}
void Bfs(){
    queue<Me_pos> q;
    Me_pos me_pos = {Me[0],Me[1],Me[2],0};
    visited_Wall[me_pos.z][me_pos.r][me_pos.c] = 1;
    q.push(me_pos); //y,x,어느벽면
    while(!q.empty()){
        auto& head = q.front();
        int r = head.r;
        int c = head.c;
        int z = head.z;
        int turn = head.turn;
        q.pop();
        if(z == -1 && Board[r][c] == 4) {
            result = turn;
            break;
        }        

        for(int d=0;d<4;d++){
            int tr = r;
            int tc = c;
            int tz = z;
            if(!move_me(tr,tc,tz,d)) continue;
            if(tz == -1 && Strange_Board[tr][tc]>=0 && Strange_Board[tr][tc]<=turn+1) continue;
            if(tz== -1 && visited_Board[tr][tc]) continue;
            if(tz!= -1 && visited_Wall[tz][tr][tc]) continue;
            if(tz== -1)
                visited_Board[tr][tc] = true;
            else
                visited_Wall[tz][tr][tc] = true;
            q.push({tr,tc,tz,turn+1});
            /*
            * test
            * cout << "d : " << d << "\n";
            * cout << tr << " " << tc << " " << tz << "\n";
            */
        }
        //***************
        //2. 타임머신 이동 end...// 
        //***************     
    }
}
void Input(){
    cin >> N >> M >> F;
    Strange_Board.resize(N,vector<int>(N,-1));
    Board.resize(N,vector<int>(N,0));
    visited_Board.resize(N,vector<bool>(N,false));
    for(int i=0;i<5;i++)
        visited_Wall[i].resize(M,vector<bool>(M,false)); 
    for(int d=0;d<5;d++){
            Wall[d].resize(M,vector<int>(M,0));        
    }
    Strange.resize(F,vector<int>(5,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> Board[i][j];
            if(Wall_Pos[0]==-1 && 3==Board[i][j]){ //시간의 벽 시작점
                Wall_Pos[0] = i;
                Wall_Pos[1] = j;    
            }
        }
    }
    for(int d=0;d<5;d++){ //동,서,남,북,윗
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                cin >> Wall[d][i][j];
                if(Wall[d][i][j]==2){ //현재 내 위치
                    Me[0] = i;
                    Me[1] = j;
                    Me[2] = 4; //윗면
                    Wall[d][i][j] = 0;
                }
            }
        }
    }
    for(int i=0;i<F;i++){
        cin >> Strange[i][0] >> Strange[i][1] >> Strange[i][2] >> Strange[i][3];
        int r = Strange[i][0];
        int c = Strange[i][1];
        Strange[i][4] = 1;
        if(Board[r][c]!= 1 && Board[r][c]!=4){ 
            Strange_Board[r][c] = 0; //이상현상 
        }
    }       
}
int main() {
    Input();
    spread_bad();
    //printf_Strange();
    Bfs();
    cout << result;
    return 0;
}