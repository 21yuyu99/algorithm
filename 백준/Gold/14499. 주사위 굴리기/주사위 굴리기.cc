#include <iostream>
#include <vector>
using namespace std;
int dice[6]={0,};
int x,y;
vector<vector<int>> map;
int move(int command,int n,int m){
    int answer;
    switch(command){
        //동쪽
        case 1:{
            if(x+1==m)
                return -1;
            x++;
            int tmp[6] = {0,};
            tmp[1] = dice[0]; tmp[0] = dice[4]; tmp[4] = dice[5]; tmp[5]=dice[1];
            tmp[2]=dice[2];tmp[3]=dice[3];
            copy(tmp,tmp+6,dice);
            // int tmp_x[3];
            // for(int i=0;i<3;i++){
            //     tmp_x[(i+1)%3] = dice_x[i];
            // }
            // copy(tmp_x,tmp_x+3,dice_x);
            // dice_y[1] = dice_x[1];
        } 
            break;
        //서쪽
        case 2:{
            if(x-1==-1)
                return -1;
            x--;
            int tmp[6] = {0,};
            tmp[1] = dice[5]; tmp[0] = dice[1]; tmp[4] = dice[0]; tmp[5]=dice[4];
            tmp[2]=dice[2];tmp[3]=dice[3];
            copy(tmp,tmp+6,dice);
            // int tmp_x[3];
            // for(int i=0;i<3;i++){
            //     tmp_x[i] = dice_x[(i+1)%3];
            // }
            // copy(tmp_x,tmp_x+3,dice_x);
            // dice_y[1] = dice_x[1];
        }
            break;
        //북쪽
        case 3:{
            if(y-1==-1)
                return -1;
            y--;
            int tmp[6] = {0,};
            tmp[0] = dice[2]; tmp[2] = dice[5]; tmp[3] = dice[0]; tmp[5]=dice[3];
            tmp[1]=dice[1];tmp[4]=dice[4];
            copy(tmp,tmp+6,dice);
            // int tmp_y[4];
            // for(int i=0;i<4;i++){
            //     tmp_y[i] = dice_y[(i+1)%4];
            // }
            // copy(tmp_y,tmp_y+4,dice_y);
            // dice_x[1] = dice_y[1];
        }
            break;
        //남쪽
        case 4:{
            if(y+1==n)
                return -1;
            y++;
            int tmp[6] = {0,};
            tmp[0] = dice[3]; tmp[2] = dice[0]; tmp[3] = dice[5]; tmp[5]=dice[2];
            tmp[1]=dice[1];tmp[4]=dice[4];
            copy(tmp,tmp+6,dice);
            // int tmp_y[4];
            // for(int i=0;i<4;i++){
            //     tmp_y[(i+1)%4] = dice_y[i];
            // }
            // copy(tmp_y,tmp_y+4,dice_y);
            // dice_x[1] = dice_y[1];
        }
            break;
    }
    answer = dice[0];
    if(map[y][x]==0){
        map[y][x] = dice[5];
    }
    else{
        dice[5] = map[y][x];
        map[y][x] = 0;
    }
    return answer;
}
int main(){
    int n,m,a,b,k;
    vector<vector<int>> map_cin;
    vector<int> command;
    cin >> n >> m >> a >> b >> k;
    map_cin.resize(n,vector<int>(m));
    map.resize(n,vector<int>(m));
    command.resize(k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map_cin[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin >> command[i];
    }
    x = b; y = a;
    copy(map_cin.begin(),map_cin.end(),map.begin());
    for(int i=0;i<k;i++){
        int tmp = move(command[i],n,m);
        if(tmp == -1) continue;
        cout << tmp << endl; 
    }
    return 0;
}