#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<N;i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    return 0;
}