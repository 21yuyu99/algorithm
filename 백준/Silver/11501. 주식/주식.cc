#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int t = 0;t<T;t++){
        int N;
        cin >> N;
        vector<long long> arr(N+1,0);
        for(int i=1;i<=N;i++){
            cin >> arr[i];
        }
        long long pay_num = 0;
        long long pay_cnt = 0;
        long long profit = 0;
        for(int i=N;i>=1;i--){
            //cout << arr[i] << " " << arr[i-1] << "\n";
            if(arr[i]>arr[i-1]){ //현재가 제일 큰 값. 판다.
                long long nextI = 1;
                for(int j = i-1;j>=1;j--){
                    if(arr[j]>arr[i]) {
                        nextI = j+1;
                        break;
                    }
                    ++pay_cnt;
                    pay_num += arr[j];
                }
                if(pay_cnt>0){
                    profit += pay_cnt * arr[i] - pay_num;
                    //cout << profit << " " << pay_cnt << " " << arr[i] << " " << pay_num << " \n";
                    pay_num = 0;
                    pay_cnt = 0;
                }
                i = nextI;
            }
        }
        cout << profit << "\n";
    }
    return 0;
}