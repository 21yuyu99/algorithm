#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N >> M;
    vector<int> arr(N);
    int s,e,mid;
    s = 1;
    e = 0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        e+=arr[i];
    }
    int answer = e;

    while(s<=e){
        mid = (s+e)/2;
        int tmp = 0;
        int cnt = 1;

        for(int i=0;i<N;i++){
            if(cnt>M) break;
            tmp+=arr[i];
            if(tmp>mid){ 
                if(arr[i]<=mid){
                    tmp = arr[i];
                    ++cnt;
                }
                else{
                    //mid가 너무 작아서 불가함
                    cnt = M+1;
                    break;
                }
            }
        }
        //cout << mid << " " << tmp << " " << cnt << "\n";
        if(cnt<=M){
            answer = min(mid,answer);
            e = mid-1;
        }
        else{ //mid가 너무 작은 것
            s = mid+1;
        }
    }
    cout << answer;
    return 0;
}

//숫자 카드 N개 5 * 10^5
//정수 M개
