#include <bits/stdc++.h>

using namespace std;

int coins[103];
const int MAX_VAL = 250003;
vector<int> dp(MAX_VAL);

void solve(int sum, int m) {
  int opt = sum / 2;
  fill(dp.begin(), dp.begin() + opt +1, 0);

  for (int i = 1; i <= m; ++i) {
    for (int j = opt; j > 0; --j) {
      auto coin_val = coins[i];
      if (coin_val <= j) {
        dp[j] = max(
            dp[j],
            coin_val + dp[j - coin_val]
            );
      }
    }
  }

  cout << sum - dp[opt] * 2 << '\n';
}

int main () {
  iostream::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, sum; cin >> n;

  while (n--) {
    cin >> m;
    sum = 0; 

    for (int i = 1; i <= m; i++){
      cin >> coins[i];
      sum += coins[i];
    }

    solve(sum, m);
  }

  return 0;
}
