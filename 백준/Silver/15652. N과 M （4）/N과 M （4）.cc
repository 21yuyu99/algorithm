#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int N,M;
vector<int> ans;
void req(int num){
    if(ans.size()==M){
        for(auto x:ans){
            cout << x << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i=num;i<=N;i++){
        ans.push_back(i);
        req(i);
        ans.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    req(1);
    return 0;
}