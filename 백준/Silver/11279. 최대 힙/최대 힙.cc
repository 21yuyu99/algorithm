#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    priority_queue<int> pq;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a==0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(a);
        }
    }
    return 0;
}