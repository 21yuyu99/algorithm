#include <iostream>
using namespace std; 
int arr[20] = {0,};
int N,S;
int total = 0;
int ans = 0;
void req(int num){
    for(int i=num;i<N;i++){
        total += arr[i];
        if(total==S){
            ++ans;
        }
        req(i+1);
        total -= arr[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    req(0);
    cout << ans;
    return 0;
}