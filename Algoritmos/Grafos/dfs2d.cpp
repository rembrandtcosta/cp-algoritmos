
int vi[N][N];
char grid[N][N];
// int nvl[N], pai[N];
void dfs(int x, int y){
	if (vi[x][y])
		return;
	vi[x][y] = true;
	int dx[] = {
		1, 0, -1, 0
	}, dy[] = {
		0, -1, 0, 1
	};
	for (int i = 0; i < 4; i++){
		int a = x + dx[i], b = y + dy[i];
		if (a >= 0 && a < n && b >= 0 && b < m){
			dfs(a, b);
		}
	}
}
