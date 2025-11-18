#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(tuple<int,int,string> a, tuple<int,int,string> b){
    if(get<0>(a)!=get<0>(b))
        return get<0>(a)>get<0>(b);
    if(get<1>(a)!=get<1>(b))
        return get<1>(a)>get<1>(b);
    return get<2>(a)<get<2>(b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;

    unordered_map<string,int> mapper;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string input;
        cin >> input;
        if(input.length()<M)
            continue;
        ++mapper[input];
    }

    vector<tuple<int,int,string>> vc;
    for(auto m:mapper){
        vc.push_back({m.second,m.first.length(),m.first});
    }
    sort(vc.begin(),vc.end(),compare);
    for(int i=0;i<vc.size();i++){
        cout << get<2>(vc[i]) << "\n";
    }
    return 0;
}

//M 길이 이하인 문자열은 x
//빈도수, 길이,사전 순