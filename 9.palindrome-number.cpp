/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
  public:
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;
    if (x < 10)
      return true;
    int rev = 0;
    while (rev < x) {
      rev = rev * 10 + x % 10;
      x /= 10;
      if (x == rev || x / 10 == rev)
        return true;
    }

    return false;
  }
};
// @lc code=end
