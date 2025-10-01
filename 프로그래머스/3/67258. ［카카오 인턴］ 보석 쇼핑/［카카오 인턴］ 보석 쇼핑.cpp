#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
//투 포인터로 가능할 듯
//s,e 이동
//e+1씩 계속 이동하면서 mapper[e+1]++;
//mapper[s] 값 > 1이면 -1 하고 s+1 이동;
//가장 짧은 구간으로 확인되면 답 바꿔주기
vector<int> solution(vector<string> gems) {
    map<string,int> gems_mapper;
    int gems_cnt = 0;
    //총 보석 개수 확인용
    for(auto g:gems){
        if(gems_mapper[g]==0){
            ++gems_cnt;
        }
        ++gems_mapper[g];
    }
    ///////////
    vector<int> answer(2,100001);
    map<string,int> current_mapper;
    int s = 0;
    int e = 0;
    int current_cnt = 0;
    while(e<gems.size() && s<=e){
        if(current_mapper[gems[e]]==0){
            ++current_cnt;
        }
        ++current_mapper[gems[e]];
        while(s<=e && current_mapper[gems[s]]>1){//s랑 e가 같은 값이면?
            --current_mapper[gems[s]];
            ++s;
        }
        if(current_cnt == gems_cnt){ //만약 현재 범위가 모든 보석 종류를 포함하면
            int ans_len = answer[1]-answer[0] ;
            if(answer[0] == 100001 || ans_len > e-s || (ans_len == e-s && s<answer[0])){ //현재가 답인지
                answer[0] = s;
                answer[1] = e;
            }
        }
          ++e;   
    }
    ++answer[0];
    ++answer[1];
    return answer; //시작 인덱스와 끝 인덱스
}
//모든 종류 포함
//가장 짧은 구간

//인덱스는 1부터 시작
//답이 여러개라면 시작 인덱스가 작은 것 리턴

//10^5

//유니크한게 몇 개인지 알아야 함.
//각각 한 개씩 들어가는 구간이 어딜까
//이분탐색? 그리디?