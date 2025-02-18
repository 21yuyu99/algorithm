#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        if(n==0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top().second << "\n";
                pq.pop();

            }
        }
        else{
            pq.push({abs(n),n});
        }
    }

    return 0;
}