#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int len_memo[2] = {0,};
    char last_char = s[0];
    int answer = 0;
    for(int i=1;i<s.length();i++){
        if(last_char == s[i]) continue;
        if(s[i]=='0'){
            ++len_memo[0];
        }
        else{
            ++len_memo[1];
        }
        if(s[i]!=s[i-1]){
            ++answer;
        }
        last_char = s[i]=='0'?'1':'0';
    }
    cout << answer;
    return 0;
}