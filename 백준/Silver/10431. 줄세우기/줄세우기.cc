#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase = 0;
    cin >> testcase;
    int line[21] = {0,};
    for(int t=1;t<=testcase;t++){
        int answer = 0;
        int tt;
        cin >> tt;
        for(int i=1;i<=20;i++){
            cin >> line[i];
            for(int j=i-1;j>=0;j--){
                int tmp = line[j];
                // for(int k=0;k<20;k++){
                //     cout << line[k] << " ";
                // }
                // cout << "\n";
                if(tmp>line[j+1]){
                    ++answer;
                    line[j] = line[j+1];
                    line[j+1] = tmp;
                }
                else{
                    break;
                }
            }
        }
        cout << t << " " << answer << "\n";
    }

    return 0;
}