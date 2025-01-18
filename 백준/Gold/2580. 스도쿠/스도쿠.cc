#include <iostream>
#include <vector>
using namespace std;
int board[9][9] = {0,};
vector<pair<int,int>> blank;
bool Row[9][10] = {false,};
bool Col[9][10] = {false,};
bool Box[9][10] = {false,};
bool isAnswer = false;
int check_box_num(int x,int y){
    if(x<=2 && y<=2)
        return 0;
    if(x<=2 && y<=5)
        return 1;
    if(x<=2 && y<=8)
        return 2;
    if(x<=5){
        if(y<=2)
            return 3;
        if(y<=5)
            return 4;
        return 5;
    }
    if(x<=8){
        if(y<=2)
            return 6;
        if(y<=5)
            return 7;
        return 8;
    }
    return 0;
}
bool check(int n,int x,int y){
    if(Row[x][n])
        return false;
    if(Col[y][n])
        return false;
    if(Box[(check_box_num(x,y))][n])
        return false;
    return true;
}
void find(int idx){
    if(idx>=blank.size()) {
        isAnswer = true;
    }
    for(int i=1;i<=9;i++){
        int x = blank[idx].first;
        int y = blank[idx].second;
        bool isOk = check(i,blank[idx].first,blank[idx].second);
        if(!isOk) continue;
        board[blank[idx].first][blank[idx].second] = i;
        Row[blank[idx].first][i] = true;
        Col[blank[idx].second][i] = true;
        Box[(check_box_num(x,y))][i] = true;
        find(idx+1);
        if(isAnswer)
            return;
        board[blank[idx].first][blank[idx].second] = 0;
        Row[blank[idx].first][i] = false;
        Col[blank[idx].second][i] = false;
        Box[(check_box_num(x,y))][i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
            if(board[i][j]==0){
                blank.push_back({i,j});
            }
            else{
                Row[i][board[i][j]] = true;
                Col[j][board[i][j]] = true;
                Box[check_box_num(i,j)][board[i][j]] = true;
            }
        }
    }
    find(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}