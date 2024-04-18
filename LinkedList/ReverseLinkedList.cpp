//
// Created by Joel Jose Ginga on 11/04/2024.
//

/**
 *
 *Given the head of a singly linked list, reverse the list, and return the reversed list.
 *
 *Example 1:
 *Input: head = [1,2,3,4,5]
 *Output: [5,4,3,2,1]
 *
 *Example 2:
 *Input: head = [1,2]
 *Output: [2,1]
 *
 *Example 3:
 *Input: head = []
 *Output: []
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
class ReverseLinkedList {
public:
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
};