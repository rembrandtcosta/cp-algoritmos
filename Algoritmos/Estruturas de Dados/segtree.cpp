#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const int N = 1e5+7;

int il[4*N], ir[4*N];

struct Node{
    lint x;
    Node(){this->x = 0;}
    Node(lint x){this-> x = x;}
    Node operator+(Node o){
        return Node(o.x + x);
    }
} seg[4*N];

void build(int u, int l, int r){
    il[u] = l;
    ir[u] = r;
    if (l == r){
        seg[u] = Node(0);
        return;
    }

    int mid = (l + r)/2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    seg[u] = Node(seg[2 * u] + seg[2 * u + 1]);
    return;
}

Node query(int u, int l, int r){
    if (il[u] > r || ir[u] < l){
        return Node(0);
    }
    if (il[u] >= l && ir[u] <= r){
        return seg[u];
    }
    return Node(query(2 * u, l , r) + query(2 * u + 1, l , r));
}

void update(int u, int i, lint x){
    if (il[u] == ir[u]) seg[u] = {x};
    int mid = (il[u] + ir[u])/2;
    if (i <= mid)
        update(2*u, i, x);
    else
        update(2*u+1, i, x);
    seg[u] = Node(seg[2 * u] + seg[2 * u + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
