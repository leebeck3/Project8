/**
 * @file main.cpp
 * @brief This is a class assignment for a DLL
 * @details Based on stuff covered in class
 * @author Lee Beckermeyer
 * @date 2021 February 14
 * 
 */

#include <iostream>
using namespace std;

class Node {
public:
    int data; // data in the node
    Node* nextNode; // pointer to the next node
    Node* prevNode; // pointer to the previous node

    /**
     * Constructor
     */
    Node(int d) {
        data = d;
        nextNode = NULL;
        prevNode = NULL;
    }
};

class SLL {
public:
    Node* head; // pointer to the first node in the list
    Node* tail; // pointer to the last node in the list
    int n; // count of how many nodes are in the list

    /**
     * Constructor
     */
    SLL() {
        head = NULL;
        tail = NULL;
        n = 0;
    }

    /**
     * Adds node to tail of list
     */
    bool addToTail(int d) {
        Node* newNode = new Node(d);
        if(n == 0) { // the list is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->nextNode = newNode; // update the last node's next node to newNode
            tail = newNode; // update the tail pointer to newNode
        }
        n++;
        return(true);
    }

    /**
     * Returns the data from the iith node
     * 
     * @param ii the number of the node to collect data from
     */
    int get(int ii) {
        Node* curNode;
        if(head == NULL) { // the list is empty
            return(-999999);
        } else if(ii >= n) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(-999998);
        } else if(ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(-999997);
        } else {
            curNode = head;
            // traverse list to desired node
            for(int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode; 
            }
            return(curNode->data);
        }
    }

    /**
     * Adds node after the iith node
     * 
     * @param ii the node to insert after
     * @param d the data in the new node
     * @returns true if successful
     */
    bool addMiddle(int ii, int d) {
        Node* curNode;
        Node* newNode = new Node(d);
        if(head == NULL) { // the list is empty
            return(false);
        } else if(ii >= n) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(false);
        } else if(ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(false);
        } else {
            curNode = head;
            // traverse list to desired node
            for(int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode; 
            }
            // At this point curNode points to the node we want to add after
            newNode->nextNode = curNode->nextNode;
            curNode->nextNode = newNode;
            n++;
            return(true);
        }
     }

    /**
     * Removes the head node and returns the data value from the removed node
     * 
     * @param d pointer to integer to return value
     * @returns true if successful
     */
    bool removeHead(int &d) {
        int val;
        Node* old; // save off the old node
        if(head != NULL) {
            val = head->data; // collect the data from node to be removed
            old = head; // save off pointer to node we are removing
            head = head->nextNode; // update head to new node
            delete old; // release the memory from the removed node
            n--; // decrement n to show shorter list
            d = val;
            return(true);
        } else { //list is empty
            return(false);
        }
    }


    /**
     * function to remove the tail of the LL
     * 
     * inspiration taken from here: https://www.geeksforgeeks.org/remove-last-node-of-the-linked-list/
     */
    bool removeTail() {
        int val;
        Node* curNode; 
        Node* newNode;
        Node* second_last = head; 
        if (head != NULL){ 
            while (second_last->nextNode->nextNode != NULL){
                second_last = second_last->nextNode; 
            };
            // Delete last node 
            val = second_last->nextNode->data;
            delete (second_last->nextNode); 
    
            // Change next of second last 
            second_last->nextNode = NULL;
            std::cout << "Here is the number you removed: " << val << "\n";
            return(true);
        }else { //list is empty
            return(false);
        }
    }

    /**
     * Adds a new node to the Head of the list
     * 
     * @param d pointer to integer to return value
     * @returns true if successful
     */
    bool addHead(int d) {
       Node* curNode;
       Node* old;
        Node* newNode = new Node(d);
        if(head == NULL) { // the list is empty
            return(false);
        } else {
            old = head;
            head = newNode;
            curNode = head;
            // At this point curNode points to the node we want to add after
            curNode->nextNode = newNode->nextNode;
            curNode->nextNode = old;
            n++;
            return(true);
        }
    };
    /**
     * Prints the list to stdout
     */
    void printList() {
        Node* curNode;
        if(head == NULL) { // the list is empty
            cout << "Empty list" << endl;
        } else { // the list is not empty
            curNode = head; // start at the beginning
            while(curNode->nextNode != NULL){
                cout << curNode->data << " -> ";
                curNode = curNode->nextNode; // update to next node
            }
            cout << curNode->data;
            cout << endl;
        }
    }
};

class DLL {
public:
    Node* head; // pointer to the first node in the list
    Node* tail; // pointer to the last node in the list
    int n; // count of how many nodes are in the list

    /**
     * Constructor
     */
    DLL() {
        head = NULL;
        tail = NULL;
        n = 0;
    }

    /**
     * done
     * Adds node to tail of list, done
     */
    bool addToTail(int d) {
        Node* newNode = new Node(d);
        Node* old;
        Node* curNode;
        
        if(n == 0) { // the list is empty
            head = newNode;
            tail = newNode;
        } else {
            curNode = head;
            tail->nextNode = newNode;
            head->prevNode = newNode; // update the last node's next node to newNode
            newNode->prevNode = tail;
            tail = newNode; // update the tail pointer to newNode
        }
        n++;
        return(true);
    }

    /**
     * done
     * Returns the data from the iith node
     * 
     * @param ii the number of the node to collect data from, note that currently it can't go beyond n-1.
     */
    int get(int ii) {
        Node* curNode;
        if(head == NULL) { // the list is empty
            return(-999999);
        } else if(ii >= n-1) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(-999998);
        } else if(ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(-999997);
        } else {
            curNode = head;
            // traverse list to desired node
            for(int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode; 
            }
            return(curNode->data);
        }
    }

    /**
     * done
     * Adds node after the iith node
     * 
     * @param ii the node to insert after, note that currently you can't go beyond n-1 as it will reference the head.
     * @param d the data in the new node
     * @returns true if successful
     */
    bool addMiddle(int ii, int d) {
        Node* curNode;
        Node* oldNode;
        Node* newNode = new Node(d);
        if(head == NULL) { // the list is empty
            return(false);
        } else if(ii >= n-1) {
            cout << "ERROR: Asked for node beyond tail, check your .addMiddle() format" << endl;
            return(false);
        } else if(ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(false);
        } else {
            curNode = head;
            // traverse list to desired node
            for(int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode; 
            }
            oldNode = curNode->nextNode;
            cout << curNode->data;
            // At this point curNode points to the node we want to add after
            newNode->prevNode = curNode;
            newNode->nextNode = curNode->nextNode;
            oldNode->prevNode = newNode;
            curNode->nextNode = newNode;
            
            n++;
            return(true);
        }
     }

    /**
     * done
     * Removes the head node and returns the data value from the removed node
     * 
     * @param d pointer to integer to return value
     * @returns true if successful
     */
    bool removeHead(int &d) {
        int val;
        Node* old; // save off the old node
        if(head != NULL) {
            val = head->data; // collect the data from node to be removed
            old = head; // save off pointer to node we are removing
            head = head->nextNode; // update head to new node
            delete old; // release the memory from the removed node
            n--; // decrement n to show shorter list
            d = val;
            return(true);
        } else { //list is empty
            return(false);
        }
    }


    /**
     * done
     * function to remove the tail of the DLL
     * 
     * inspiration taken from here: https://www.geeksforgeeks.org/remove-last-node-of-the-linked-list/
     */
    bool removeTail() {
        int val;
        Node* curNode; 
        Node* secondNode = head; 
        if (head != NULL){ 
            //points to the node right before your tail. please note that prevNode makes this a lot simpler.
            secondNode = tail->prevNode;
             
            val = secondNode->nextNode->data;//saves old data
            
            //deletion and redoing pointers
            delete (secondNode->nextNode);//deletes the old node in memory 
            head->prevNode = secondNode;//points head to its new node
            secondNode->nextNode = NULL;//remove the previous node's pointer
            tail = secondNode;//set the tail equal to the previous node
            std::cout << "Here is the number you removed: " << val << "\n";
            n--;//decrements the counter
            return(true);
        }else { //list is empty
            return(false);
        }
    }

    /**
     * done
     * Adds a new node to the Head of the list
     * 
     * @param d pointer to integer to return value
     * @returns true if successful
     */
    bool addHead(int d) {
       Node* curNode;
       Node* old;
        Node* newNode = new Node(d);
        if(head == NULL) { // the list is empty
            return(false);
        } else {
            old = head;
            head = newNode;
            curNode = head;
            curNode->nextNode = newNode->nextNode;
            curNode->nextNode = old;
            old->prevNode = head;
            n++;
            return(true);
        }
    };
    /**
     * Prints the list to stdout, done
     */
    void printList() {
        Node* curNode;
        if(head == NULL) { // the list is empty
            cout << "Empty list" << endl;
        } else { // the list is not empty
            curNode = head; // start at the beginning
            cout << "Forward: \n";
            while(curNode->nextNode != NULL){
                cout << curNode->data << " -> ";
                curNode = curNode->nextNode; // update to next node
            }
            cout << curNode->data;
            cout << endl;
            curNode = tail; // reverse list for DLL(Double Linked List)
            cout << "Backward: \n";
            for(int jj = 0; jj < n-1; jj++) { 
                cout << curNode->data << " -> ";
                curNode = curNode->prevNode;
            }
            cout << curNode->data;
            cout << endl;
        }
    }
};

int main(int, char**) {
    DLL myList;
    int retData;

    myList.addToTail(1);
    myList.addToTail(2);
    myList.addToTail(3);
    myList.addToTail(4);
    myList.addToTail(5);
    myList.addToTail(6);
    myList.printList();
    myList.addMiddle(4,10);
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty." << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty." << endl;
    myList.printList();

    myList.removeTail();
    myList.printList();

    myList.addHead(1);
    myList.printList();

    /**
    SLL myList;
    int retData; // for data from remove

    
    myList.printList();
    myList.addToTail(1);
    myList.printList();
    myList.addToTail(2);
    myList.printList();
    myList.addToTail(3);
    myList.printList();
    myList.addToTail(4);
    myList.printList();
    myList.addToTail(15);
    myList.printList();

    
    cout << "get(0) = " << myList.get(0) << endl;
    cout << "get(1) = " << myList.get(1) << endl;
    cout << "get(4) = " << myList.get(4) << endl;
    cout << "get(5) = " << myList.get(5) << endl;
    cout << "get(7) = " << myList.get(7) << endl;
    cout << "get(-3) = " << myList.get(-3) << endl;
    

    myList.addMiddle(3,10);
    myList.printList();
    myList.addMiddle(3,11);
    myList.printList();
    myList.addMiddle(6,12);
    myList.printList();
    myList.addMiddle(0,13);
    myList.printList();
    myList.addHead(5);
    myList.printList();

    myList.removeTail();
    myList.printList();

    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    if(myList.removeHead(retData))
        cout << "Removed " << retData << endl;
    else
        cout << "list was empty" << endl;
    myList.printList();
    */
}
