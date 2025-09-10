#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int cur_idx = 0;
    for(int i=0;i<A.size();i++){
       int idx = upper_bound(B.begin() + cur_idx,B.end(),A[i]) - B.begin();
        if(idx == B.size()){
            break;
        }
        else{
            ++answer;
            cur_idx = idx+1;
        }
    }
    return answer;
}
//N명씩 두 팀으로
//A팀과 B팀

//1. 랜덤 숫자
//2. 숫자가 큰 쪽이 승리 + 1점

//최종 승점을 가장 높이는 방법으로 출전 순서를 정했다.
//b팀이 얻는 승점을 구해주세요.

//배열 길이는 10^5
//원소값은 10^9

//여러번 이겨야 함.
//이분탐색?