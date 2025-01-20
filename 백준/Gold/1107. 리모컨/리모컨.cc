#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string N;
    cin >> N;
    int M;
    cin >> M;
    bool isDead[10] = {0,};
    for(int i=0;i<M;i++){   
        int input;
        cin >> input;
        isDead[input] = true;
    }
    int ans = abs(stoi(N)-100);
    for(int i=0;i<1000000;i++){
        string s = to_string(i);
        bool isSucceed = true;
        for(int j=0;j<s.length();j++){
            if(isDead[(s[j]-'0')]) {
                isSucceed = false;
                break;
            }
        }
        if(isSucceed){
            if(abs(stoi(s)-stoi(N))+(int)s.length()<ans){
                ans = abs(stoi(s)-stoi(N)) + s.length();
            }
        }
    }
    cout << ans;
    return 0;
}