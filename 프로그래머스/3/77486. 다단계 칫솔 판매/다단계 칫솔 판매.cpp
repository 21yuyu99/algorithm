#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int parents[10001] = {0,};

// int Union(int a){
//     if(parents[a] == a)
//         return parents[a];
//     else{
//         parents[a] = Union(a);
//     }
// }
// void Find(int a,int b){
//     int parentsA = Union(a);
//     int parentsB = Union(b);
//     if(parentsA < parentsB){
//         parents[parentsB] = parentsA;
//     }
//     else{
//         parents[parentsA] = parentsB;
//     }
// }
//parents[0] = 0 민호
vector<int> answer;
void divideProfit(int profit,int personIdx){
    int profitForReferral = profit/10;
    if(personIdx==0) return;
    if(profitForReferral==0) {
        answer[personIdx-1] += profit;
    }
    else{
        answer[personIdx-1] += profit - profitForReferral;
        divideProfit(profitForReferral,parents[personIdx]);
    }
    
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    //민호는 center
    //enroll : 판매원의 이름
    //referral : 추천인
    // seller : 집계 데이터의 판매인 이름
    // amount : 판매 수량 배열
    answer.resize(enroll.size(),0);
    unordered_map<string,int> um;
    um["center"] = 0;
    for(int i=0;i<enroll.size();i++){
        um[enroll[i]] = i+1;
    }
    for(int i=0;i<enroll.size();i++){
        string referralName = referral[i];
        if(referralName=="-"){
            parents[i+1] = 0;
        }
        else{
            int parentIdx = um[referralName];  
            parents[i+1] = parentIdx;
        }
    }
    ///추천인 parents에 저장 끝////
    
    for(int i=0;i<seller.size();i++){
        int totalProfit = amount[i] * 100;
        string sellerName = seller[i];
        divideProfit(totalProfit,um[sellerName]);
        //재귀
    }
    //이익이 발생할 때마다 계산?
    //아니면 한 번에 계산?
    
    //이익이 발생할 때마다 계산하는 듯하다.
    
    //for문으로? 10 ^ 5
    //유니온 파인드?
    
    
    return answer; //각 판매원의 이익금 배열 return - enroll 순서대로
}
//100원 판매
//이익의 10%는 자신을 조직에 참여시킨 추천인에게 배분
//1원 미만인 경우 모두 가진다.

//추천인이라서 받은 이익도 자신을 추천한 인원에세 10%를 나눠줘야 함