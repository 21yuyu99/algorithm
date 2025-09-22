#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
set<set<string>> st;
int need_size = 0;
vector<string> User_id;
vector<string> Banned_id;

void find_id(int bIdx,set<string> tmpST){
    for(int i=bIdx;i<Banned_id.size();i++){
        for(int j=0;j<User_id.size();j++){
            //이미 넣은 값이면 제외
            if(tmpST.find(User_id[j])!= tmpST.end()) continue;
            if(Banned_id[i].length()==User_id[j].length()){ //두 길이가 같으면
                //가능한지 비교
                bool isOk = true;
                for(int a=0;a<Banned_id[i].length();a++){
                    if(Banned_id[i][a]!= '*' && User_id[j][a]!=Banned_id[i][a]){
                        isOk = false;
                    }
                }
                //가능하면 나머지 제제아이디도 찾아보기
                if(isOk){
                    tmpST.insert(User_id[j]);
                    find_id(i+1,tmpST);
                    tmpST.erase(User_id[j]);
                }
            }
        }
    }
    if(tmpST.size()==need_size){
        st.insert(tmpST);
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
        need_size = banned_id.size();
        User_id = user_id;
        Banned_id = banned_id;
        set<string> t;
        find_id(0,t);
    int answer = st.size();
    // for(auto x:st){
    //     for(auto a:x){
    //         cout << a << " ";
    //     }
    //     cout << "\n";
    // }
    return answer;
}
// //아이디 당 최소 하나의 *(banned_id와 매칭되는 id는 길이가 같아야 함)
// //몇 가지 경우의 수가 가능한지 return
// //순서는 관계가 없음.

// //***중복해서 제제아이디에 들어가는 경우는 없음***
// //unique하게 구분하려면 map?
// //cf : ["fr*d*", "abc1**","fr*d*"]

// vector<vector<string>> arr;
// for x : banned_id
//  for y : user_id
//      if (x matching y){
//         arr[xIdx].push_back(x);
//      }
// //재귀?

// void req(int idx,arr){
//     for(xIdx : banned_id){
//         arr[i]에 있는지 먼저 확인해야 함.
//         없으면 넣어주기.
        
//     }
// }

// //다하면
// //정렬 후 중복제거

// //매번 visited 함수 제공하기
// //이건 충분히 가능함.
// //한 제제 아이디를 유니크하게 만드는 것


// //모든 배열을 unique하게 만드는 것은..?
// //*** *** ***
// //abc cde efg
// //cde efg abc
// vector<set<string>> arr;



