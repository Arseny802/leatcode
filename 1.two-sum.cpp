/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      hash[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];

      auto found = hash.find(complement);
      if (found != hash.end() && hash[complement] != i) {
        if (found->second != i) {
          return {i, found->second};
        }

        hash.erase(found);
        found = hash.find(complement);
        if (found != hash.end()) {
          return {i, found->second};
        }
      }
    }
    return {};
  }
};
// @lc code=end

int main() {
  Solution solution;
  {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    for (auto i: solution.twoSum(nums, target)) {
      cout << i << " ";
    }
    cout << endl;
  }

  {
    vector<int> nums = {3, 3};
    int target = 6;
    for (auto i: solution.twoSum(nums, target)) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}