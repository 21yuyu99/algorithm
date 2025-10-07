#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int tmp;
        cin >> tmp;
        auto iter = lower_bound(arr.begin(),arr.end(),tmp);
        if(iter != arr.end() && *iter == tmp){
            cout << 1 << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
    return 0;
}

//숫자 카드 N개 5 * 10^5
//정수 M개
