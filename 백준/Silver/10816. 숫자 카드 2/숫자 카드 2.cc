#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N;
    unordered_map<int,int> cards;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        ++cards[a];
    }
    cin >> M;
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        cout << cards[a] << " ";
    }
    return 0;
}