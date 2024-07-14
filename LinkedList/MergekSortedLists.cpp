//
// Created by Joel Jose Ginga on 30/06/2024.
//
/**
* 23. Merge k Sorted Lists
 *You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 *Merge all the linked-lists into one sorted linked-list and return it.
 *
 *Example 1:
 *Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *Output: [1,1,2,3,4,4,5,6]
 *Explanation: The linked-lists are:
 *[
 *  1->4->5,
 *  1->3->4,
 *  2->6
 *]
 *merging them into one sorted list:
 *1->1->2->3->4->4->5->6
 *
 *Example 2:
 *Input: lists = []
 *Output: []
 *
 *Example 3:
 *Input: lists = [[]]
 *Output: []
 *
 *
 *Constraints:
 *k == lists.length
 *0 <= k <= 104
 *0 <= lists[i].length <= 500
 *-104 <= lists[i][j] <= 104
 *lists[i] is sorted in ascending order.
 *The sum of lists[i].length will not exceed 104.
*/

//functor
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //keeps elements ordered according to compare
        priority_queue<ListNode*, vector<ListNode*>, compare> queue;

        for(ListNode* list : lists)
            if(list != nullptr)
                queue.push(list);

        ListNode head(-1);
        ListNode* tail = &head;

        map<int, pair<ListNode*, ListNode*>> map;


        //get the first node of the queue and adds the next node of the same list to the queue
        while(!queue.empty()){
            ListNode* min = queue.top(); queue.pop();
            tail->next = min;
            tail = tail->next;
            if(min->next != nullptr)
                queue.push(min->next);

        }

        return head.next;


    }
};

/** First try with a map - Time Complexity O(N log N).
 *
 * class MergeKSortedList {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, pair<ListNode*, ListNode*>> map;

        //add elements to map
        for(auto list : lists){
            ListNode* node = list;
            while(node != nullptr){
                ListNode* tmp = node;
                int val = tmp->val;
                node = node->next;
                //O(log m) m->number of keys
                //this is done n times, where n is the total number of nodes
                if(map.find(val)==map.end()){
                    map[val]={tmp, tmp};
                    continue;
                }

                map[val].second->next = tmp;
                map[val].second = tmp;
            }
        }

        ListNode head(-1);
        ListNode* tail = &head;

        //complexity O(k) k-> number of nodes
        for(auto& entry: map){
            tail->next = entry.second.first;
            tail = entry.second.second;
        }

        return head.next;


    }
};
 */