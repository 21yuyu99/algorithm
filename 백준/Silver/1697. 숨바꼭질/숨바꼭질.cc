#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,K;
    cin >> N >> K;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; //{cnt,num}
    q.push({0,N});
    vector<bool> visited(200001,false);

    while(!q.empty()){
        int cnt = q.top().first;
        int num = q.top().second;
        visited[num] = true;
        if(num == K){
            cout << cnt;
            break;
        }
        q.pop();
        int a = num - 1, b = num + 1, c = num*2;
        //cout << num << " : " << a << " " << b << " " << c << "\n";
        if(a>=0 && !visited[a])
            q.push({cnt+1,a});
        if(b<=200000 && !visited[b])
            q.push({cnt+1,b});
        if(c<=200000 && !visited[c]){
            q.push({cnt+1,c});
        }

    }
    return 0;
}