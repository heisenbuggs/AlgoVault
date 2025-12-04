/**
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Time Complexity: O(n)
 */

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

class Solution {
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
};
