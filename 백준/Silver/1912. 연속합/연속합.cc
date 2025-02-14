#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int arr[100001];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int e = 1;
    int ans = arr[0];
    int next = max(0,ans);
    while(e<N){
        next+=arr[e++];

        ans = max(ans,next);

        if(next<0){
            next = 0;
        }
    }
    cout << ans;
    return 0;
}