#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> st;
    
    for(auto op:operations){        
        if(op[0]=='I'){
            int num = stoi(op.substr(2));
            st.insert(num);
        }
        else if(op[2] == '1'){ //max delete
            if(!st.empty()){
                if(st.size()>1){
                    st.erase(--st.end());   
                }
                else{
                    st.erase(st.begin());
                }
            }
        }
        else{ //min delete
            if(!st.empty()){
                st.erase(st.begin());   
            }
        }
    }
    vector<int> answer;
    if(st.size()==1){
        answer = {*st.begin(),*st.begin()};
    }
    else if(st.size()==0){
        answer = {0,0};
    }
    else{
        answer = {*(--st.end()),*st.begin()};
    }
    return answer;
}
//정렬이 되어있어야 함.
// set? logn
