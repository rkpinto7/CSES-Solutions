#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, -1));
	grid[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();
		vector<pair<int, int>> dirs = {{2,-1}, {2,1}, {1,2}, {1,-2},{-2,-1}, {-2,1}, {-1,2}, {-1,-2}};
		for (auto& [di, dj] : dirs) {
			int ni = i + di;
			int nj = j + dj;
			if (ni >=0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == -1) {
				grid[ni][nj] = 1 + grid[i][j];
				grid[nj][ni] = grid[ni][nj];
				q.push({ni, nj});
			}
		}

	}

	// output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}