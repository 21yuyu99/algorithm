#include <iostream>
#include <set>
using namespace std;
int parent[1001] = {0,};
int Find(int a){
    if(parent[a]==a) return parent[a];
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    int pA = Find(a);
    int pB = Find(b);
    if(pA<pB){
        parent[pB] = pA;
    }
    else{
        parent[pA] = pB;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N >> M;
    int u,v;
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }
    int ans = 1;
    set<int> st;
    st.insert(parent[1]);
    for(int i=2;i<=N;i++){
        int pa = Find(parent[i]);
        if(st.find(pa)==st.end()){
            ++ans;
            st.insert(pa);
        }
    }
    cout << ans;
    return 0;
}