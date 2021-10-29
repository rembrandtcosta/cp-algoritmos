#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const int N = 1e5+7, INF = 1e9+7, L = 20;
lint anc[N][L], pai[N], nvl[N];
vector<int> g[N];

void dfs(int x, int p = -1){
    for (auto y : g[x]){
        if (y != p){
            nvl[y] = nvl[x] + 1;
            pai[y] = x;
            dfs(y, x);
        }
    }
}

void build(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < L; j++){
            anc[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++){
        anc[i][0] = pai[i];
    }

    for (int j = 0; j < L; j++){
        for (int i = 0; i < N; i++){
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
}

lint query(int a, int b){
    if (nvl[a] < nvl[b])
        swap(a, b);

    for (int j = L-1; j >= 0; j--){
        if (nvl[a] - (1<<j) >= nvl[b]){
            a = anc[a][j];
        }
    }

    if (a == b)
        return a;

    for (int j = L-1; j >= 0; j--){
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]){
            a = anc[a][j];
            b = anc[b][j];
        }
    }

    return anc[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}