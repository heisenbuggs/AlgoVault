#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
};

Node *reverseList(Node *head) {
  Node *curr = head, *prev = nullptr, *next;

  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}