#include <string>
#include <vector>
#include <algorithm>
//n개의 원소(숫자 중복 가능)
//합이 S
//곱이 최대

using namespace std;

vector<int> solution(int n, int s) {
    int cur_num = s;
    vector<int> answer;
    for(int cur_cnt=n;cur_cnt>0;--cur_cnt){
        int tmp = cur_num/cur_cnt;
        if(tmp==0){
            return {-1};
        }
        cur_num -= tmp;
        answer.push_back(tmp);
    }
    sort(answer.begin(),answer.end());
    return answer; //존재하지 않으면 [-1] //오름차순 정렬
}