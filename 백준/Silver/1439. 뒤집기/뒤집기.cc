#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    char last_char = s[0];
    int answer = 0;
    for(int i=1;i<s.length();i++){
        if(last_char == s[i]) continue; //변경 ver : 연속된 수면 continue
        if(s[i]!=s[i-1]){ //기존 ver : 연속된 수가 아니면 +1;
            ++answer;
        }
        last_char = s[i]=='0'?'1':'0'; //변경 ver
    }
    cout << answer;
    return 0;
}