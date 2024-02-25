//
// Created by Joel Jose Ginga on 15/02/2024.
//

/**
Design a Singly Linked List class.

Your LinkedList class should support the following operations:

LinkedList() will initialize an empty linked list.
int get(int i) will return the value of the ith node (0-indexed). If the index is out of bounds, return -1.
void insertHead(int val) will insert a node with val at the head of the list.
void insertTail(int val) will insert a node with val at the tail of the list.
int remove(int i) will remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true.
int[] getValues() return an array of all the values in the linked list, ordered from head to tail.
 * **/

#include <vector>

class LinkedList {

public:

    class Node{
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

private:
    Node* head;
    size_t size;

public:
    LinkedList():head(nullptr), size(0){}

    int get(int index) {

        if(index>=size) return -1;

        Node* current = head;

        while(index--)
            current = current->next;

        return current->val;
    }

    void insertHead(int val) {

        Node* newHead = new Node(val);

        newHead->next = head;

        head=newHead;

        size++;
    }

    void insertTail(int val) {

        Node* newNode = new Node(val);

        size++;

        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* current = head;

        while(current->next!= nullptr)
            current=current->next;

        current->next = newNode;



    }

    bool remove(int index) {

        if(index>=size) return false;

        Node* toDelete = nullptr;
        if(index==0){
            toDelete = head;
            head = head->next;
        } else {
            Node *current = head;
            //we find the node before the one we want to delete
            for(int i = 0 ; i < index - 1 ; i++){
                current = current->next;
            }
            toDelete = current->next;
            current->next = current->next->next;
        }
        delete toDelete;
        size--;
        return true;
    }

    vector<int> getValues() {
        std::vector<int> values(size);
        Node* current=head;
        while (current!=nullptr){
            values.push_back(current->val);
            current = current->next;
        }
        return values;
    }
};
