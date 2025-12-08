#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100001] = {0,};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,K;
    cin >> N >> K;
    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin >> input[i];
    }

    int s = 0, e = 0;
    int answer = 0;
    while(s<=e && e<N){
        int eNum = input[e];
        ++arr[eNum];
        if(arr[eNum]>K){
            while(s<=e){
                int sNum = input[s];
                --arr[sNum];
                ++s;         
                if(eNum == sNum){
                    break;
                }
            }
        }
        answer = max(answer,e-s+1);  //이 지점이 애매함
        ++e;
    }
    cout << answer;
    return 0;
}