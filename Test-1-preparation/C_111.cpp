#include <iostream>

using namespace std;

// Define the node struct
struct node {
    int data;
    node* next;
};

// Function to create a new node with the given data and next pointer
node* newNode(int data, node* next = nullptr) {
    node* n = new node;
    n->data = data;
    n->next = next;
    return n;
}

// Function to print the elements of a linked list
void printList(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}



void removeOddAfterTwoOdds(node* head) {
    node* curr = head;
    int counter = 0;
    node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data % 2 != 0) {  // Check if the data is odd
            counter++;
        } else {
            counter = 0;
        }

        if (counter > 2) {
            // Delete the subsequent node(s)
            node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
            continue;  // Skip the rest of the loop for this iteration
        }

        prev = curr;
        curr = curr->next;
    }
}

int main() {
    // Create a linked list: {-2, 3, -7, -4, 5}
    node* head = newNode(-9);
    head->next = newNode(1);
    head->next->next = newNode(-7);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(5);


    // Print the original list
    cout << "Original list: ";
    printList(head);
    removeOddAfterTwoOdds(head);
    cout << "Processed list: ";
    printList(head);

    // Free memory used by the list
    while (head != nullptr) {
        node* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
