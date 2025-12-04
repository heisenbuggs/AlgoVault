/**
 *  Given the head of a linked list that may contain a loop. A loop means that the last node of the linked list is 
 * connected back to a node in the same list. 
 * The task is to remove the loop from the linked list (if it exists).
 * 
 * Time Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
};

class Solution {
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
};
