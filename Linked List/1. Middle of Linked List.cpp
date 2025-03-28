#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
};

Node* printMiddle(Node* head) {
  if (!head) return head;
  Node* slow = head;
  Node* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}