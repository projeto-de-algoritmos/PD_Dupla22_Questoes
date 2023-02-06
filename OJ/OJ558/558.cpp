#include <bits/stdc++.h>

using namespace std;
using Edge = struct edge {
  edge(int f, int t, int wg): u(t), v(f), w(wg){}
  int u;
  int v;
  int w;
};
int n, m;
vector<Edge> edges;
int dists[1003];
const int INF = 2000000 + 105;

bool has_cycle(int pos) {
  return dists[edges[pos].v] > dists[edges[pos].u] + edges[pos].w;
}

void solve () {
  // puts("Solving");
  for (int i = 0; i < n; ++i) {
    dists[i] = INF;
  }
  dists[0] = 0;

  for (int i = 0; i < n; ++i) {
    // puts("Bellman-Ford");
    for (int j = 0; j < m; ++j) {
      if (dists[edges[j].v] > dists[edges[j].u] + edges[j].w) {
        dists[edges[j].v] = dists[edges[j].u] + edges[j].w;
      }
    }
  }

  bool cycle = false;
  for (int j = 0; j < m; j++) {
    if (has_cycle(j)) {
      cycle = true; break;
    }
  }

  if (! cycle) cout << "not ";
  cout << "possible" << '\n';
}

int main () {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);

  int cs; cin >> cs;
  while (cs--){
    cin >> n >> m;
    edges.clear();

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w; 
      edges.push_back( *(new Edge(u, v, w)) ); 
    }

    solve();
  }

  return 0;
}


