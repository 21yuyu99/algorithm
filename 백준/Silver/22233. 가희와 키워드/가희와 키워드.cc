#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_set<string> keyword_set;
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string input;
        cin >> input;
        keyword_set.insert(input);
    }

    for(int i=0;i<M;i++){
        string input;
        cin >> input;
        stringstream ss(input);
        string s;
        while(getline(ss,s,',')){
            keyword_set.erase(s);
        }
        cout << keyword_set.size() << "\n";
    }
    return 0;
}

//메모장 키워드 N개
//블로그 글 M개