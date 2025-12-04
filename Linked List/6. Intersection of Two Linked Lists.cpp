/**
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
 * If the two linked lists have no intersection at all, return null.
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
    int getCount(Node *head) {
        int cnt = 0;
        Node *curr = head;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    Node *getIntersectionByDiff(int diff, Node *head1, Node *head2) {
        Node *curr1 = head1;
        Node *curr2 = head2;

        for (int i = 0; i < diff; i++) {
            if (curr1 == nullptr) return nullptr;
            curr1 = curr1->next;
        }

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1 == curr2) return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return nullptr;
    }

    Node *intersectPoint(Node *head1, Node *head2) {
        int len1 = getCount(head1);
        int len2 = getCount(head2);

        int diff = 0;

        if (len1 > len2) {
            diff = len1 - len2;
            return getIntersectionByDiff(diff, head1, head2);
        } else {
            diff = len2 - len1;
            return getIntersectionByDiff(diff, head2, head1);
        }
    }
};
