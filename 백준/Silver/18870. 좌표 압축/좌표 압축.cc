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
    vector<int> sort_arr(N); //여기는 중복 들어가면 안됨
    for(int i=0;i<N;i++){
        cin >> arr[i];
        sort_arr[i] = arr[i];
    }
    sort(sort_arr.begin(),sort_arr.end());
    sort_arr.erase(unique(sort_arr.begin(),sort_arr.end()),sort_arr.end());
    for(int i=0;i<N;i++){
        int idx = lower_bound(sort_arr.begin(),sort_arr.end(),arr[i]) - sort_arr.begin();
        if(sort_arr[idx]==arr[i]){
            cout << idx;
        }
        else
            cout << idx+1;
        cout << " ";
    }
    return 0;
}