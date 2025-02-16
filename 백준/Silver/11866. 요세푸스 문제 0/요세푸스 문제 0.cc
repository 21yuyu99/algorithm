#include <iostream>
#include <list>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,K;
    cin >> N >> K;
    list<int> arr;
    for(int i=1;i<=N;i++){
        arr.push_back(i);
    }
    list<int>::iterator it = arr.begin();
    cout << '<';
    while(!arr.empty()){
        for(int i=1;i<K;i++){
            ++it;
            if(it==arr.end()){
                it = arr.begin();
            }
        }
        cout << *it;
        it = arr.erase(it);
        if(arr.empty()){
            cout << '>';
            break;
        }
        if(it==arr.end()){
            it = arr.begin();
        }
        cout << ", ";
    }
    return 0;
}