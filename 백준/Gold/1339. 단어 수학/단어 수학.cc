#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> check_num(26,0);
    for(int i=0;i<N;i++){ //입력
        string s;
        cin >> s;

        for(int j=0;j<s.length();j++){
            check_num[s[j]-'A'] += 1 * pow(10,s.length()-j-1); 
        }
    }
    sort(check_num.rbegin(),check_num.rend());
    int answer = 0;
    int max_num = 9;
    for(int i=0;i<26;i++){
        if(check_num[i]==0) break;
        answer += max_num * check_num[i];
        --max_num;
    }
    cout << answer;
    return 0;
}