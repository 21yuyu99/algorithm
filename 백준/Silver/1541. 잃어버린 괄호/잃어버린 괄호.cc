#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
int ans = 0;
int make_max(int idx){
    int int_num = 0;
    string num = "";
    for(int i=idx;i<s.length();i++){
        if(s[i]=='-'){
            idx = i;
            break;
        }
        if(s[i]=='+') {
            int_num += stoi(num);
            num = "";
        }
        else{
            num += s[i];
        }
        if(i==s.length()-1){
            idx = i;
        }
    }
    int_num += stoi(num);
    ans -= int_num;
    return idx;
}
int make_min(int idx){
    int int_num = 0;
    string num = "";
    for(int i=idx;i<s.length();i++){
        if(s[i]=='-'){
            idx = i;
            break;
        }
        if(s[i]=='+') {
            int_num += stoi(num);
            num = "";
        }
        else{
            num += s[i];
        }
        if(i==s.length()-1){
            idx = i;
        }
    }
    int_num += stoi(num);
    ans += int_num;
    return idx;    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    string first_num = "";
    int second_idx = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-' || s[i]=='+'){
            second_idx = i;
            break;
        }
        first_num += s[i];
    }
    ans += stoi(first_num);
    for(int i=second_idx;i<s.length();i++){
        if(s[i]=='-'){
            i = make_max(i+1);
            if(i==s.length()-1){
                break;
            }
            else{
                --i;
            }
        }
        else if(s[i]=='+'){ //부호가 나오면
            i = make_min(i+1);
            if(i==s.length()-1){
                break;
            }
            else{
                --i;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
