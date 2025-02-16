#include <iostream>
#include <stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    int tops[500001] = {0,};
    stack<pair<int,int>> st;
    for(int i=1;i<=N;i++){
        cin >> tops[i];
    }
    cout << 0 << " ";
    for(int i=2;i<=N;i++){
        if(tops[i-1]>=tops[i]){
            cout << i-1 << " ";
            st.push({i-1,tops[i-1]});
        }
        else{
            if(st.empty()){
                cout << 0 << " ";
            }
            else{
                int cur_ans = 0;
                while(!st.empty()){
                    if(st.top().second>=tops[i]){
                        cur_ans = st.top().first;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                cout << cur_ans << " ";
            }
        }
    }
    return 0;
}