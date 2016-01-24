void Dijkstra(vector<vector<int>> &graph, int start) {
	const int n = graph.size();
	vector<int> dist(n, INT_MAX);
	vector<int> p(n, -1);
	vector<bool> s(n, false);
	s[start] = true;
	p[start] = -1;
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		if (i != start && graph[start][i] != INT_MAX) {
			dist[i] = graph[start][i];
			p[i] = start;
		}
	}
	
	int x = start;
	int minDist = INT_MAX;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!s[j] && dist[j] < minDist) {
				minDist = j;
				x = j;
			}
		}
		s[x] = true;
		for (int j = 0; j < n; j++) {
			if (!s[j] && dist[j] > dist[x] + graph[x]j[]) {
				dist[j] = dist[x] + graph[x][j];
				p[j] = x;
			}
		}
	}
}
