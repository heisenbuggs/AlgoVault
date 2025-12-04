/**
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 *
 * Time Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

class Solution {
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
};
