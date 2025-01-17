#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int cnt = 0;
    int tmp = N/5;
    if(tmp!=0){ //5원
        if(N%2==0){
            if(tmp%2!=0){
                --tmp;
            }
        }
        else{ //홀수면
            if(tmp%2==0){
                --tmp;
            }
        }        
        N-= tmp * 5;
        cnt += tmp;
    }
    tmp = N/2;
    if(tmp!=0){
        cnt += tmp;
        N -= tmp * 2;
    }
    if(N==0)
        cout << cnt;
    else
        cout << -1;
    return 0;
}