#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T,N;
    cin >> T;
    for(int testcase = 0;testcase<T;testcase++){
        int N;
        cin >> N;
        vector<array<int,2>> arr(N);
        for(int i=0;i<N;i++){
            int a,b;
            cin >> a >> b;
            arr[i][0] = a;
            arr[i][1] = b;
        }
        sort(arr.begin(),arr.end());
        // cout <<"정렬 완료\n";
        // for(int i=0;i<N;i++){
        //     cout << arr[i][0] << " " << arr[i][1];
        //     cout <<"\n";
        // }
        int cnt = 1;
        int min_score = arr[0][1];
        for(int i=1;i<N;i++){
            if(min_score>arr[i][1]){
                min_score = arr[i][1];
                ++cnt;
            }
        }
        //cout <<"answer : ";
        cout << cnt << "\n";

    }
    return 0;
}