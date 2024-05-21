//
// Created by Joel Jose Ginga on 16/05/2024.
//
 /**
 * 143. Reorder List
 * Medium
 * You are given the head of a singly linked-list. The list can be represented as:
 *
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 *
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * Example 2:
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 */

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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr, *next=nullptr;

        while(head!=nullptr){
            //save the next node
            next = head->next;
            //reverse the current nodes pointer
            head->next = prev;
            //move prev and head one step forward
            prev = head;
            head = next;
        }

        //after the loop prev is the next head
        return prev;
    }
    void mergeTwoLists(ListNode* list1, ListNode* list2) {


        while (list1 != nullptr && list2 != nullptr) {
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;

            list1->next = list2;
            if (temp1 == nullptr) break;
            list2->next = temp1;

            list1 = temp1;
            list2 = temp2;
        }
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* middle = head;
        ListNode* end = head;
        ListNode* prev;

        //we find the middle
        while(end != nullptr && end->next != nullptr){
            prev = middle;
            middle = middle->next;
            end = end->next->next;
        }
        prev->next = nullptr;
        ListNode* secondHalf = reverseList(middle);

        mergeTwoLists(head, secondHalf);
    }
};