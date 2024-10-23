/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
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
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) {
      return false;
    }

    int i = 0;
    while (arr[i] < arr[i + 1] && i < arr.size() - 1) {
      ++i;
    }
    if (i == arr.size() - 1) {
      return false;
    }

    int j = arr.size() - 1;
    while (j && arr[j - 1] > arr[j]) {
      --j;
    }

    return i == j && j;
  }
};
// @lc code=end

int main() {
  std::vector<int> arr;

  arr = {0, 3};
  assert(Solution().validMountainArray(arr) == false);

  arr = {0, 3, 2, 1};
  assert(Solution().validMountainArray(arr) == true);

  arr = {0, 1, 2, 3, 4, 5};
  assert(Solution().validMountainArray(arr) == false);

  arr = {3, 5, 5};
  assert(Solution().validMountainArray(arr) == false);

  arr = {3, 5, 4};
  assert(Solution().validMountainArray(arr) == true);

  arr = {0, 2, 3, 4};
  assert(Solution().validMountainArray(arr) == false);

  arr = {0, 1, 2, 3, 4, 8, 9, 10, 11, 12, 11};
  assert(Solution().validMountainArray(arr) == true);

  arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  assert(Solution().validMountainArray(arr) == false);

  cout << "OK" << endl;
  return 0;
}
