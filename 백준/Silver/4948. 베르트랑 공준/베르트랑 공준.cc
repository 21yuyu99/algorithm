#include <iostream>
using namespace std;   
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool isPrime[246913];
    for(int i=0;i<246913;i++){
        isPrime[i] = true;
    }

    for(int i=2;i<=123456;i++){
        int j = i*2;
        while(j<=246912){
            isPrime[j] = false;
            j+=i;
        }
    }
    while(true){
        int N;
        cin >> N;
        if(N==0) break;
        int cnt = 0;
        for(int i=N+1;i<=2*N;i++){
            if(isPrime[i]){
                ++cnt;
              //  cout << i << " ";
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
//11 13 17 19