#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int X;
    int N;
    cin >> X >> N;
    int total = 0;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        total+=a*b;
    }
    if(total==X)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}