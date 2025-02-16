#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    bool board[100][100] = {0,};
    int ans = 0;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b; //(3,7) +10 (13,7) //(3,17) (13,17)
        //점이 아니라 칸이어야 함.
        for(int i=a;i<a+10;i++){
            for(int j=b;j<b+10;j++){
                if(board[i][j]) continue;
                ++ans;
                board[i][j] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}