#include <bits/stdc++.h>

using namespace std;

int dephts[33];
int time_dephts[33];
int values[33];
int ans_ind[33];

const int MAX_VAL = 1003;
int t_i, w, t_n; 
bool has_line;

vector<vector<int>> dp(33, vector<int>(MAX_VAL, 0));
void find_solution() {
  int dives = 0, sum = 0;

  while (t_n > 0) {
    int curr_val = dp[t_n][t_i];
    int up_val = dp[t_n - 1][t_i];
    if (curr_val != up_val) {
      ans_ind[dives++] = t_n;
      t_i -= time_dephts[t_n];
      sum += values[t_n];
    }

    --t_n;
  }
  
  cout << sum << '\n';
  cout << dives << '\n';
  for (int i = dives - 1; i >= 0; --i) {
    cout << dephts[ans_ind[i] ]<< ' ' << values[ans_ind[i]] << '\n';
  }

}

void solve () {
  for (int i = 1; i <= t_n; ++i) {
    for (int j = 0; j <= t_i; ++j) {
      if (time_dephts[i] > j) dp[i][j] = dp[i-1][j];
      else {
        dp[i][j] = max(
            dp[i - 1][j],
            values[i] + dp[i - 1][j - time_dephts[i]]
            );
      }
    }
  }

  if (has_line) cout << '\n';
  has_line = true;

  find_solution();
}

int main () {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);
  
  has_line = false;

  while (cin >> t_i >> w) {
    cin >> t_n;
    for (int i = 1; i <= t_n; ++i) {
      cin >> dephts[i] >> values[i];
      time_dephts[i] = 3 * w * dephts[i];
      fill(dp[i].begin(), dp[i].begin() + t_i + 1, 0);
    }

    solve();
  }

  return 0;
}
