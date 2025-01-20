#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    if(N==1){
        cout<<1;
        return 0;
    }
    queue<int> q;
    q.push(arr[0]);
    q.push(arr[1]);
    bool isPlus = false;
    int ans = 2;
    if(arr[0]<arr[1])
        isPlus = true;
    for(int i=2;i<N;i++){
        if((isPlus && arr[i]>=q.back()) || (!isPlus && arr[i]<=q.back())){
            q.push(arr[i]);
        }
        else if(arr[i]>q.back() || arr[i]<q.back()){
            isPlus = !isPlus;
            while(!q.empty()){
                if(q.back()!=q.front()){
                    q.pop();
                }
                else
                    break;
            }
            q.push(arr[i]);
        }
        ans = max(ans,(int)q.size());
    }
    cout << ans;
    return 0;
}