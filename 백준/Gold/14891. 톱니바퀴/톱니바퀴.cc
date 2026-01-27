#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> wheel(4,vector<int>(8,0));
vector<int> w_position(8,0);
void move_position(int num,int dir){
    w_position[num]+=dir;
    if(w_position[num]>7){
        w_position[num] = 0;
    }
    else if(w_position[num]<0){
        w_position[num] = 7;
    }
}
int find_position(int num){
    if(num<0){
        num = 8 + num;
    }
    else if(num>7){
        num = num - 8;
    }
    return num;
}
void check_left(int num,int dir){
    //왼쪽 바퀴 확인
    int nextdir = dir==1?-1:1;
    for(;num>0;num--){
        //둘이 극하면
        int a_idx = find_position(w_position[num] - 2);
        int b_idx = find_position(w_position[num-1] + 2);
        if(wheel[num][a_idx]!=wheel[num-1][b_idx]){
            move_position(num,nextdir);
            nextdir = nextdir==1?-1:1;
            if(num-1==0){
                move_position(num-1,nextdir);
            }
        }
        else{
            move_position(num,nextdir);
            break;
        }
    }
}
void check_right(int num,int dir){
    //오른쪽 바퀴 확인
    int nextdir = dir==1?-1:1;
    for(;num<3;num++){
        int a_idx = find_position(w_position[num] + 2);
        int b_idx = find_position(w_position[num+1] - 2);
        //둘이 극하면
        if(wheel[num][a_idx]!=wheel[num+1][b_idx]){
            move_position(num,nextdir);
            nextdir = nextdir==1?-1:1;
            if(num+1==3){
                move_position(num+1,nextdir);
            }
        }
        else{
            move_position(num,nextdir);
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //바퀴 입력
    vector<string> input_whell(4);
    for(int i=0;i<4;i++){
        cin >> input_whell[i];
    }
    for(int i=0;i<4;i++){ 
        for(int j=0;j<8;j++){
            wheel[i][j] = input_whell[i][j] - '0';
        }
    }
    //회전방법 입력
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int num,dir;
        cin >> num >> dir;
        //num을 인덱스로 바꿔주기 (num-1)
        num -=1;
        //w_position 기억하기
        int num_position = w_position[num];
        check_left(num,dir);
        w_position[num] = num_position;
        check_right(num,dir);
        w_position[num] = num_position;
        move_position(num,dir==1?-1:1);
    }
    //answer//
    int answer = 0;
    int score[4] = {1,2,4,8};
    for(int i=0;i<4;i++){
        answer += wheel[i][w_position[i]] * score[i];
    }
    cout << answer;
    return 0;
}