#include <iostream>
#include <vector>
#include <string>
using namespace std;
int memo[200001][26] = {0,};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int i=0;i<s.length();i++){
        for(int j=0;j<26;j++){
            memo[i+1][j] = memo[i][j];
        }
        ++memo[i+1][s[i]-'a'];
    }
    for(int i=0;i<q;i++){
        char c;
        int l,r;
        cin >> c >> l >> r;
        cout << memo[r+1][c-'a'] - memo[l][c-'a'] << "\n";
    }
    return 0;
}