#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long S;
    cin >> S;
    long long cnt = 0;
    long long total = 0;
    long long i = 0;
    while(total<S){
        ++i;
        total += i;
        if(total<=S)
            ++cnt;
    }
    cout << cnt;
    return 0;
}