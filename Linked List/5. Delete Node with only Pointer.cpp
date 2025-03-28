#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
};

void deleteNode(Node *ptr) {
  Node *temp = ptr->next;
  ptr->data = temp->data;
  ptr->next = temp->next;
  delete (temp);
}