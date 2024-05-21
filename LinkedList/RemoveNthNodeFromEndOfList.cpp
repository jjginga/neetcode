//
// Created by Joel Jose Ginga on 17/05/2024.
//
/**
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 * Constraints:
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
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
class RemoveNthNodeFromEndOfList {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy;

        //move the pointer n+1 positions
        for (int i = 0; i <= n; i++) {
            curr=curr->next;
        }

        //move the curr until the end. the prev will be point to end-n
        while(curr!=nullptr){
            curr = curr->next;
            prev = prev->next;
        }


        ListNode* nodeToRemove = prev->next;

        prev->next = prev->next->next;

        delete nodeToRemove;
        head = dummy->next;
        delete dummy;
        return head;


    }
};