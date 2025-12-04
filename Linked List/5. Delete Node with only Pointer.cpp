/**
 * Given only a pointer to a node to be deleted in a singly linked list. The task is to delete that node from the list.
 *
 * Time Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
};

class Solution {
    void deleteNode(Node *ptr) {
        Node *temp = ptr->next;
        ptr->data = temp->data;
        ptr->next = temp->next;
        delete (temp);
    }
};
