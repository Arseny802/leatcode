/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <bits.h>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
  public:
  int romanToInt(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (roman_[s[i + 1]] <= roman_[s[i]]) {
        result += roman_[s[i]];
      } else {
        result -= roman_[s[i]];
        result += roman_[s[i++ + 1]];
      }
    }

    return result;
  }

  private:
  std::unordered_map<string::value_type, int> roman_ =
      {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
};
// @lc code=end
