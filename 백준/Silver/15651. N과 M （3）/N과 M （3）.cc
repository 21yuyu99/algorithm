#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> arr;
void req(){
    if(arr.size()==M){
        for(auto x:arr){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=N;i++){
        arr.push_back(i);
        req();
        arr.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    req();
    return 0;
}