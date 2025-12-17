#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase = 0;
    cin >> testcase;
    for(int t=0;t<testcase;t++){
        int input;
        cin >> input;
        cout << input/25 << " ";
        input%=25;
        cout << input/10 << " ";
        input%=10;
        cout << input/5 << " ";
        input%=5;
        cout << input/1 << "\n";
    }
    return 0;
}

// 동전의 개수 최소
//25, 10, 5, 1
//124센트