#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,M;
    cin >> N >> M;
    unordered_set<string> not_hear; 
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        not_hear.insert(s);
    }
    vector<string> ans;
    for(int i=0;i<M;i++){
        string s;
        cin >> s;
        if(not_hear.find(s)==not_hear.end()) continue;
        ans.push_back(s);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }
    return 0;
}