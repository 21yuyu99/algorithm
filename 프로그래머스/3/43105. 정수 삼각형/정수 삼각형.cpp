#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> triangle) {
    int ySize = triangle.size();
    int xSize = triangle[ySize-1].size();
    for(int y=1;y<ySize;y++){
        int curXSize = triangle[y].size();
        for(int x=0;x<curXSize;x++){
            if(x==0){
                triangle[y][x] = triangle[y-1][x] + triangle[y][x];
            }
            else if (x==curXSize-1){
                triangle[y][x] = triangle[y-1][x-1] + triangle[y][x];
            }
            else{
                triangle[y][x] = max(triangle[y-1][x],triangle[y-1][x-1]) + triangle[y][x];         
            }
        }
    }
    int answer = 0;
    for(int x=0;x<xSize;x++){
        answer = max(answer,triangle[ySize-1][x]);
    }
    return answer;
}
//dfs로 하면
// 2^500 절대 불가



