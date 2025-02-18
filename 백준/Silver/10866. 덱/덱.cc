#include <iostream>
#include <deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    deque<int> dq;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        if(s=="push_front"){
            int n;
            cin >> n;
            dq.push_front(n);
        }
        else if(s=="push_back"){
            int n;
            cin >> n;
            dq.push_back(n);
        }
        else if(s=="pop_front"){
            if(dq.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        else if(s=="pop_back"){
            if(dq.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        else if(s=="size"){
            cout << dq.size() << "\n";
        }
        else if(s=="empty"){
            cout << dq.empty() << "\n";
        }
        else if(s=="front"){
            if(dq.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << dq.front() << "\n";
        }
        else if(s=="back"){
            if(dq.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << dq.back() << "\n";
        }
    }
    return 0;
}