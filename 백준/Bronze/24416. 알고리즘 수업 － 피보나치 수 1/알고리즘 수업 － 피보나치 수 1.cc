#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans1 = 0;
void req(int n){
    if(n==1 || n==2){
        ++ans1;
    }
    else{
        req(n-1);
        req(n-2);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    req(N);
    cout << ans1;
    cout << " " << max(0,N-2);
    return 0;
}
