#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if (nums.empty()) return 0;
      if (nums.size() == 1) return 1;

      vector<int> dp(nums.size(), 1);

      for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j ) {
          if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }

      }
      return *max_element(begin(dp), end(dp)); 

    }
};

// int main ()
// {
//   iostream::sync_with_stdio(false);
//   cin.tie(NULL);
//   vector<int> nums;
//   
//   int a;
//   while (cin >> a) {
//     nums.push_back(a);
//   }

//   Solution sol;
//   cout << sol.lengthOfLIS(nums) << '\n';
//   
//   return 0;
// }
