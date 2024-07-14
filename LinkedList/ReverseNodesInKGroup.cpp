//
// Created by Joel Jose Ginga on 14/07/2024.
//
/**
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 * Example 2:
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 * Constraints:
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 **/
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr, *next=nullptr;

        while(head!=nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr || k==1)
            return head;

        ListNode res(-1);
        res.next = head;
        ListNode* tail = &res;

        while(head!=nullptr){
            int count = 0;
            ListNode* tmp = head;

            //checks if we have k nodes
            while(count < k && tmp != nullptr){
                tmp = tmp->next;
                count++;
            }

            if(count < k){
                tail->next = head;
                break;
            }

            //start of the next group
            ListNode* p2 = tmp;
            ListNode* nextHead = head;
            ListNode* prev = tail;

            while (head != p2) {
                ListNode* next = head->next;
                head->next = prev->next;
                prev->next = head;
                head = next;
            }

            nextHead->next = p2;
            tail = nextHead;
            head = p2;

        }


        return res.next;
    }
};