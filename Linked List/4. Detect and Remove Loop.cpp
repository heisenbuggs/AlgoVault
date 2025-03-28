#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
};

void detectAndRemoveLoop(Node *head) {
  Node *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
  }

  if (slow != fast) return;

  slow = head;
  while (slow->next != fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  fast->next = NULL;
}