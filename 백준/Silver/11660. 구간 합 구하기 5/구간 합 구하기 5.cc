#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    vector<vector<int>> memo(N+1,vector<int>(N+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> memo[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1] + memo[i][j];
            //cout << memo[i][j] << " ";
        }
        //cout << "\n";
    }

    //////문제////////
    for(int i=0;i<M;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << memo[x2][y2] - memo[x2][y1-1] - memo[x1-1][y2] + memo[x1-1][y1-1] << "\n"; 
    }
    return 0;
}