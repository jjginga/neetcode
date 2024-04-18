//
// Created by Joel Jose Ginga on 11/04/2024.
//
/**
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 * Example 2:
 * Input: list1 = [], list2 = []
 * Output: []
 *
 * Example 3:
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 */

class MergeTwoSortedLists {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode* head = new ListNode(-1), *curr;
        curr = head;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
                continue;
            }

            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
        }

        if(list1==nullptr){
            curr->next = list2;
            return head->next;
        }

        curr->next = list1;
        return head->next;
    }
};