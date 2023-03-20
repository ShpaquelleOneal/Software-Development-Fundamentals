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

// Function to process a linked list of integers and increase/decrease odd numbers
void incDecOdd(node* head) {
    node* current = head;
    while (current != nullptr) {
        if (current->data % 2 != 0) { // check if odd
            if (current->data > 0) { // positive odd
                current->data--;
            } else { // negative odd
                current->data++;
            }
        }
        current = current->next;
    }
}

int main() {
    // Create a linked list: {-2, 3, -7, -4, 5}
    node* head = newNode(-2);
    head->next = newNode(3);
    head->next->next = newNode(-7);
    head->next->next->next = newNode(-4);
    head->next->next->next->next = newNode(5);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Process the list and print the result
    incDecOdd(head);
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
