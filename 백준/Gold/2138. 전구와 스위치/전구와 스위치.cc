#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string a,b;
    cin >> a >> b;
    vector<int> arr(N+1);
    vector<int> goal(N+1);
    for(int i=0;i<N;i++){
        arr[i] = a[i]-'0';
        goal[i] = b[i]-'0';
    }
    int answer = -1;
    //첫번째 스위치 누른 버전
    vector<int> tmp = arr;
    tmp[0] = !tmp[0];
    tmp[1] = !tmp[1];
    int cnt = 1;
    for(int i=1;i<N;i++){
        if(tmp[i-1]!=goal[i-1]){
            tmp[i-1] = !tmp[i-1];
            tmp[i] = !tmp[i];
            tmp[i+1] = !tmp[i+1];
            ++cnt;
        }
    }
    bool isOk = true;
    for(int i=0;i<N;i++){
        if(tmp[i]!=goal[i]){
            isOk = false;
            break;
        }
    }
    if(isOk) answer = cnt;
    cnt = 0;
    tmp = arr;
    //첫번째 스위치 안누른 버전
    for(int i=0;i<N;i++){
        if(tmp[i-1]!=goal[i-1]){
            tmp[i-1] = !tmp[i-1];
            tmp[i] = !tmp[i];
            tmp[i+1] = !tmp[i+1];
            ++cnt;
        }
    }
    isOk = true;
    for(int i=0;i<N;i++){
        if(tmp[i]!=goal[i]){
            isOk = false;
            break;
        }
    }
    if(isOk && (answer == -1 || cnt < answer )) answer = cnt;
    cout << answer;
    return 0;
}