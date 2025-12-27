#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;

    cin >> N >> M;
    int package_cost = INT_MAX;
    int each_cost = INT_MAX;
    for(int i=0;i<M;i++){ //브랜드 수
        int a,b;
        cin >> a >> b;
        package_cost = min(package_cost,a);
        each_cost = min(each_cost,b);
    }

    int answer = N/6;
    answer = min(answer*package_cost,each_cost*answer*6);
    answer = answer + min(N%6*each_cost,package_cost);
    cout << answer;
    return 0;
}