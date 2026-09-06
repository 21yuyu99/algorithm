#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N,M;
vector<vector<int>> Board;
struct Box{
    int h,w;
    int r,c;
};
map<int,Box> Boxes;
unordered_map<int,int> visited;
void DropBox(int &r,int c,int h,int w){
    //cout <<"====start====\n";
    int j = c;
    for(int i=r;i<N;i++){//box 시작점
            if(i+h>N) return; 
            for(int cur_h = i;cur_h<i+h;cur_h++){
                for(int cur_w=j;cur_w<j+w;cur_w++){
                    //cout << cur_h << " " << cur_w << "\n";
                    if(Board[cur_h][cur_w]) return; 
                }
            }
            r = i;
            //cout << "\n";
    }
}
void moveBox(int k,int next_r){
    Box b = Boxes[k];
    for(int i=b.r;i<b.r+b.h;i++){
        for(int j=b.c;j<b.c+b.w;j++){
            Board[i][j] = 0;
        }
    }

    for(int i=next_r;i<next_r+b.h;i++){
        for(int j=b.c;j<b.c+b.w;j++){
            Board[i][j] = k;
        }
    }
    Boxes[k].r = next_r;
}
void DropBox(int k){
    Box b = Boxes[k];
    int r = b.r;
    int c = b.c;
    int h = b.h;
    int w = b.w;
    int isOk = true;
    for(int i=r+1;i<N;i++){ //box 시작점
        if(!isOk) break;
        if(i+h>N) break;
        for(int cur_h = i;cur_h<i+h;cur_h++){
            if(!isOk) break;
            for(int cur_w=c;cur_w<c+w;cur_w++){
                if(Board[cur_h][cur_w]!= k && Board[cur_h][cur_w]!=0) {
                    isOk = false;
                    break;
                }
            }
        }
        if(isOk){
            r = i;
        }
    }
    if(r!=Boxes[k].r){
        moveBox(k,r);
    }
}
void printBoard(){
    cout << "\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << Board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void MarkNum(int r,int c, int h,int w,int k){
    for(int i=r;i<r+h;i++){
        for(int j=c;j<c+w;j++){
            //cout << i << " " << j << " " << k << "\n";
            Board[i][j] = k;
        }
    }
    Boxes[k] = Box({h,w,r,c});
}
void Input(){
    cin >> N; //NxN board
    cin >> M; //택배 수
    Board.resize(N,vector<int>(N,0));
    for(int i=0;i<M;i++){ //택배의 위치 정보
        //택배 번호 k, 세로 크기 h, 가로 크기 w, 좌측 좌표 c
        int k,h,w,c;
        int r = 0;
        cin >> k >> h >> w >> c;
        c-=1;
        DropBox(r,c,h,w);
        MarkNum(r,c,h,w,k);
        //cout << k << " " << r << " " << c << " " << h << " " << w << " " << "\n"; //(4,2)
    }
}
int FindLeftBox(){
    int k = -1;
    for(auto b:Boxes){
        int r = b.second.r;
        int c = b.second.c;
        int h = b.second.h;
        int w = b.second.w;
        k = b.first;
        int isOk = true;
        for(int i=r;i<r+h;i++){
            for(int j=c-1;j>=0;j--){
                if(Board[i][j]!=0){
                    isOk = false;
                    break;
                }
            }
            if(!isOk) break;
        }
        if(isOk){
                cout <<k<<"\n";
                //cout << "k : " << k << "\n";
                return k;
        }
    }
    return -1;
}
int FindRightBox(){
    int k = -1;
    for(auto b:Boxes){
        int r = b.second.r;
        int c = b.second.c;
        int h = b.second.h;
        int w = b.second.w;
        k = b.first;
        int last_w = c + w -1;
        int isOk = true;
        for(int i=r;i<r+h;i++){
            for(int j=last_w+1;j<N;j++){
                if(Board[i][j]!=0){
                    isOk = false;
                    break;
                }
            }
            if(!isOk) break;
        }
        if(isOk){
                cout <<k<<"\n";
                //cout << "k : " << k << "\n";
                return k;
        }
    }
    return -1;
}
void OutBox(int k){
    Box b = Boxes[k];
    for(int i=b.r;i<b.r+b.h;i++){
        for(int j=b.c;j<b.c+b.w;j++){
            Board[i][j] = 0;
        }
    }
    Boxes.erase(k);
}
int main() {
    Input();
    //cout <<"===start===\n";
    //printBoard();
    // for(auto x:Boxes){
    //     cout << x.first << " ";
    // }
    //cout << "\n";
    while(!Boxes.empty()){
        //cout <<"===left===\n";
        int k = FindLeftBox();
        if(k>-1){
            OutBox(k);
            visited.clear();
            for(int i=N-1;i>=0;i--){
                for(int j=0;j<N;j++){
                    //cout <<"print: ";
                    //cout << Board[i][j] << " " << visited[Board[i][j]] << "\n";
                    if(Board[i][j]!=0 && !visited[Board[i][j]]){
                        visited[Board[i][j]] = true;
                        DropBox(Board[i][j]);
                    }
                }
            }
        }
        //printBoard();
        if(Boxes.empty()) break;
        //cout <<"===right===\n";
        k = FindRightBox();
        if(k>-1){
            OutBox(k);
            visited.clear();
            for(int i=N-1;i>=0;i--){
                for(int j=0;j<N;j++){
                    if(Board[i][j]!=0 && !visited[Board[i][j]]){
                        //cout <<"drop: ";
                        //cout << Board[i][j] << "\n"; 
                        visited[Board[i][j]] = true;
                        DropBox(Board[i][j]);
                    }
                }
            }
        }
        //printBoard();
    }
    return 0;
}