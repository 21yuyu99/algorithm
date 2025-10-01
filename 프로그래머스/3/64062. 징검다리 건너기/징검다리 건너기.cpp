#include <string>
#include <vector>
#include <set>
#include <iostream>
//각 범위에서 가장 큰 값끼리 비교. 가장 작은 경우가 답임
//매번 어떻게 비교할 건데?
using namespace std;

int solution(vector<int> stones, int k) {
    multiset<int> mst;
    int s = 0;
    int e = k-1;
    int answer = 0;
    for(int i=s;i<k;i++){
        mst.insert(stones[i]);
    }
    //첫번째 경우에서 가장 큰 값
    answer = *mst.rbegin();
    ++e; 
    ++s; 
    //각 범위에서 가장 큰 값 구하기
    while(s<=e && e<stones.size()){
        auto itr = mst.find(stones[s-1]);
        mst.erase(itr); 
        mst.insert(stones[e]);            
        //cout << *mst.rbegin() << " ";
        // for(auto x:mst){
        //     cout << x << " ";
        // }
        // cout << "\n";
        answer = min(*mst.rbegin(),answer);
        ++s;
        ++e;
    }
    return answer; //최대 몇명
}
//밟으면 -1
//0이 되면 밟을 수 없음 => 그 다음 디딤돌로 바로 이동 가능함
//가장 가까운 디딤돌로만 건너기 가능

//stones 배열 길이 2*10^5
//디딤돌 power 최대 2*10^8
//한 번에 건너띌 수 있는 제한 수

//브루트포스 불가
//연속으로 0인 디딤돌 개수 < k까지 가능함
//최대 몇명인지만 알면 됨

/////////즉, 연속으로 0인 디딤돌의 개수 < k인 최대 round//////////
//이분탐색? 1 1 5 100
// 0 0 3 100
//그리디? 이중포인터? 이분탐색?
//연속으로 되있는 값 중 가장 큰 값
//연속으로 되있는 값 중 가장 작은 값?
//해당 범위가 가장 작은 값?
//범위의 합? // 5 5 10 (20) // 8 8 4
//아니면... 각각의 값이?




//k가 3일 때
//2 4 5 3 2 1 4 2 5 1
//1 3 4 2 1 0 3 1 4 0
//0 2 3 1 0 0 2 0 3 0
//0 1 2 0 0 0 1 0 2 0



//각 범위에서 가장 큰 값끼리 비교. 가장 작은 경우가 답임
//매번 어떻게 비교할 건데?
//슬라이딩 윈도우? 중간값이 가장 작으면?
//multiset으로 정렬시키기?


//아니면 우선 합을 봐야 하나? 아님
//5 1 1 //4 4 4


//2 (4) <5>
//(4) <5> {3}
//<5> {3} 2
//{3} 2 1
//k가 3이면 이것도 3번까지는 존재함
//맨 첫번째 경우 빼고.
