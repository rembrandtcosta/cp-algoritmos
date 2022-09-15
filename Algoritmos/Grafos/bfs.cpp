int vi[N];
// int dist[N];
void bfs(int x){
	queue<int> q;
	q.push(x);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto v : g[x]){
			if (!vi[v]){
				//dist[v] = dist[u] + 1;
				vi[v] = true;
				q.push(v);
			}
		}
	}
}
