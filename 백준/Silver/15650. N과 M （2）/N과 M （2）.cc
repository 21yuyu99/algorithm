#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> ans;
void req(int num,int cnt){
    if(cnt==M) {
        for(auto x:ans){
            cout << x << " ";
        }
        cout << "\n";
    }
    for(int i=num;i<=N;i++){
        ans.push_back(i);
        req(i+1,cnt+1);
        ans.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    req(1,0);
    return 0;
}