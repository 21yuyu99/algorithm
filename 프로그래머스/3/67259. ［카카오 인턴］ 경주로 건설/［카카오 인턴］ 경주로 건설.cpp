#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <array>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int answer = INT_MAX;

int solution(vector<vector<int>> board) {
    queue<array<int,4>> q; //현재 위치, 현재 비용, 현재 방향, 
    q.push({0,0,0,-1});
    vector<vector<vector<int>>> memo(board.size(),vector<vector<int>>(board.size(),vector<int>(2,INT_MAX))); //가로[0], 세로[1] 방향 순
    while(!q.empty()){
        auto [cur_x,cur_y,cur_cost, cur_d] = q.front();
        q.pop();
        if(cur_x == board.size()-1 && cur_y == board.size()-1){
        answer = min(answer,cur_cost);
        continue;
    }
    for(int d=0;d<4;d++){
            int tmp_x = cur_x + dx[d];
            int tmp_y = cur_y + dy[d];
            if(tmp_x<0 || tmp_y<0 || tmp_x>= board.size() || tmp_y>= board.size()) continue;
            if(board[tmp_x][tmp_y] == 1) continue;
            int tmp_cost = (cur_d<2 && d<2) || (cur_d>=2 && d>=2) ||(cur_d==-1) ? cur_cost+100:cur_cost+600;
            if(tmp_cost>memo[tmp_x][tmp_y][d<2?0:1]) continue;
            memo[tmp_x][tmp_y][d<2?0:1] = tmp_cost;
            q.push({tmp_x,tmp_y,tmp_cost,d});
        }
    }
    return answer; //최소 비용
}

//(0,0)~(N-1,N-1)
//상,하,좌,우
//1은 벽 있는 칸
//출발점부터 도착점까지 끊기지 않고 건설
//직선 도로 - 100원, 코너 - 500원

//bfs