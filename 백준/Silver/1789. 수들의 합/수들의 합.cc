#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long S;
    cin >> S;
    long long cnt = 0;
    long long j = 3;
    long long i = 2;
    while(i<S){
        ++cnt;
        //cout << i << " " << cnt << " \n";        
        i+=j;
        ++j;
    }
    ++cnt;
    cout << cnt;
    return 0;
}