#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> TownRequest(N,0);
    int total = 0;
    int maxMoney = 0;
    for(int i=0;i<N;i++){
        //각 지방의 예산 요청
        cin >> TownRequest[i];
        total += TownRequest[i];
        maxMoney = maxMoney>TownRequest[i]?maxMoney:TownRequest[i];
    }
    int TotalMoney;
    cin >> TotalMoney;
    if(total<= TotalMoney){
        cout << maxMoney;
        return 0;
    }
    int s = 1;
    int e = 100000;
    int mid = (s+e)/2; // s + (e-s) / 2;
    int answer = 0;
    while(s<=e){
        int tmpTotal = 0;
        for(auto tr : TownRequest){
            if(tr<=mid){
                tmpTotal += tr;
            }
            else{
                tmpTotal += mid;
            }
        }
        if(tmpTotal<=TotalMoney){ //예산 안의 금액일 때
            // cout << s << " " <<  " " << e << " " << mid << "\n";
            answer = mid;
            s = mid+1;
        }
        else{
            e = mid - 1;
        } 
        mid = (s+e)/2;
    } 
    cout << answer;
    return 0;
}
//배정될 수 있으면 모두 배정
//상한액을 정해서 배정
//그 합이 최대가 되도록 하기