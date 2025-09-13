#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
using namespace std;
int M,N,H;
int dh[6] = {-1,1,0,0,0,0};
int dx[6]= {0,0,0,0,-1,1};
int dy[6] = {0,0,-1,1,0,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H; //x y z
    vector<vector<vector<int>>> box(H,vector<vector<int>>(N,vector<int>(M,0)));
    int babyTomato = 0;
    queue<array<int,3>> q;
    for(int h=0;h<H;h++){ //z
        for(int i=0;i<N;i++){ //y
            for(int j=0;j<M;j++){ //x
                cin >> box[h][i][j];
                if(box[h][i][j] == 0){
                    ++babyTomato;
                }
                else if(box[h][i][j]==1){
                    q.push({h,i,j});
                }
            }   
        }
    }
    bool isTrue = true;
    int days = 0;
    if(babyTomato == 0){
        cout << "0";
        return 0;
    }

    while(!q.empty()){
        int qH = q.front()[0];
        int qI = q.front()[1];
        int qJ = q.front()[2];
        int qDay = box[qH][qI][qJ];
        q.pop();
        for(int d=0;d<6;d++){
            int tmpH = qH + dh[d];
            int tmpY = qI + dy[d];
            int tmpX = qJ + dx[d];
            if(tmpH<0 || tmpH>=H || tmpY<0 || tmpY>=N || tmpX<0 || tmpX>=M) continue;
            if(box[tmpH][tmpY][tmpX]==-1 || box[tmpH][tmpY][tmpX]>0) continue;
            box[tmpH][tmpY][tmpX] = qDay+1;
            days = max(days,qDay);
            --babyTomato;
            q.push({tmpH,tmpY,tmpX});
        }
    }
    if(babyTomato == 0){
        cout << days;
    }
    else{
        cout << -1;
    }

    return 0;
}