/**
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
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
};
