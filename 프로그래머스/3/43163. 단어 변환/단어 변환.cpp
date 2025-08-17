#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    vector<bool> isVisited(words.size(),0);
    queue<pair<string,int>> que;
    que.push({begin,0});
    int answer = 0;
    while(!que.empty()){
        string queFrt = que.front().first;
        int queCnt = que.front().second;
        que.pop();
        bool isTarget = false;
        for(int i=0;i<words.size();i++){
            if(isVisited[i]) continue;
            int dffrntWord = 0;
            for(int w=0;w<words[i].size();w++){
                if(words[i][w] != queFrt[w]){
                    ++dffrntWord;
                }
            }
            if(dffrntWord==1){
                isVisited[i] = true;
                if(words[i]==target){
                    isTarget = true;
                    break;
                }
                que.push({words[i],queCnt+1});
            }
        }
        if(isTarget){
            answer = queCnt+1;
            break;
        }
    }
    return answer;
}
// 모든 경우의 수를 짬뽕하기
//이미 바꾼 것으로 또 바꾸지 않게 isVisted