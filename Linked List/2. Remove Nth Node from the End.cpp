#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int val, Node* nextNode = nullptr) {
    data = val;
    next = nextNode;
  }
};

Node* removeNthFromEnd(Node* head, int n) {
  Node* res = new Node(0, head);
  Node* dummy = res;

  for (int i = 0; i < n; i++) {
    head = head->next;
  }

  while (head) {
    head = head->next;
    dummy = dummy->next;
  }
  dummy->next = dummy->next->next;

  return res->next;
}