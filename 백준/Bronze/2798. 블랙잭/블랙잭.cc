#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int ans = 0;
int N,M;
vector<int> arr;
int tmp = 0;
void req(int idx,int cnt){
    if(cnt==3){
        ans = max(ans,tmp);
        return;
    }
    for(int i=idx;i<N;i++){
        tmp+=arr[i];
        if(tmp<=M){
            req(i+1,cnt+1);
        }
        tmp-=arr[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    req(0,0);
    cout << ans;
    return 0;
}