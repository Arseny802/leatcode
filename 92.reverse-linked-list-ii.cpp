/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) { }
  ListNode(int x): val(x), next(nullptr) { }
  ListNode(int x, ListNode* next): val(x), next(next) { }
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left >= right) {
      return head;
    }

    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;
    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }

    ListNode* current = prev->next;
    ListNode* next = current->next;
    for (int i = 0; i < right - left; i++) {
      current->next = next->next;
      next->next = prev->next;
      prev->next = next;
      next = current->next;
    }

    ListNode* result = dummy->next;
    delete dummy;
    return result;
  }
};
// @lc code=end

int main() {
  Solution solution;
  {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left = 2;
    int right = 4;
    ListNode* result = solution.reverseBetween(head, left, right);
    while (result) {
      cout << result->val << " ";
      result = result->next;
    }
    cout << endl;
  }

  {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left = 1;
    int right = 5;
    ListNode* result = solution.reverseBetween(head, left, right);
    while (result) {
      cout << result->val << " ";
      result = result->next;
    }
    cout << endl;
  }

  {
    ListNode* head = new ListNode(1);
    int left = 1;
    int right = 1;
    ListNode* result = solution.reverseBetween(head, left, right);
    while (result) {
      cout << result->val << " ";
      result = result->next;
    }
    cout << endl;
  }

  {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left = 1;
    int right = 1;
    ListNode* result = solution.reverseBetween(head, left, right);
    while (result) {
      cout << result->val << " ";
      result = result->next;
    }
    cout << endl;
  }

  {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left = 1;
    int right = 2;
    ListNode* result = solution.reverseBetween(head, left, right);
    while (result) {
      cout << result->val << " ";
      result = result->next;
    }
    cout << endl;
  }

  {
    ListNode* head = new ListNode(1, new ListNode(2));
    int left = 1;
    int right = 2;
    ListNode* result = solution.reverseBetween(head, left, right);
    while (result) {
      cout << result->val << " ";
      result = result->next;
    }
    cout << endl;
  }

  return 0;
}