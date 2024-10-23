/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size();
    }

    int left = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[left] != nums[i]) {
        nums[++left] = nums[i];
      }
    }
    return left + 1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 4, 4};
  int n = 0;
  Solution s;
  {
    n = s.removeDuplicates(nums);
    assert(n == 5);
    assert(vector<int>(nums.begin(), nums.begin() + n) == vector<int>({0, 1, 2, 3, 4}));
  }

  return 0;
}