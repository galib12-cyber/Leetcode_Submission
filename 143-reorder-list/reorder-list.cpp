/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;

        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
        }

        ListNode* sec = s->next;
        s->next = NULL;

        ListNode* prev = NULL;
        ListNode* current = sec;

        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        sec = prev;

        ListNode* first = head;
        while (sec != NULL) {
            ListNode* n1 = first->next;
            ListNode* n2 = sec->next;

            first->next = sec;
            sec ->next = n1;

            first = n1;
            sec = n2;
        }
    }
};