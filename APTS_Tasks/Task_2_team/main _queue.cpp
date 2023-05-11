#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    ~Node() { // destructor
        delete left;
        delete right;
    }
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// function to find required node by given value recursively
Node* findNode(int value, Node* root) {
    if (root == nullptr) return nullptr;

    if (root->data == value) return root;

    Node* leftResult = findNode(value, root->left);
    if (leftResult != nullptr) return leftResult;

    Node* rightResult = findNode(value, root->right);
    return rightResult;
}

// display tree using level-order traversal
void displayTree(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

int main() {
    ifstream fin("team.in.txt");
    ofstream fon("team.out.txt");

    int p, w, m;
    bool first_d = true;
    Node* first;

    while (fin >> p >> w >> m) {
        if (p == 0 && w == 0 && m == 0) {
            break;
        }

        if (!first_d) {
            if (w != 0) {
                Node* select = findNode(p, first);
                select->left = createNode(w);
            }
            if (m != 0) {
                Node* select = findNode(p, first);
                select->right = createNode(m);
            }
        } else {
            Node* root = createNode(p);
            root->left = createNode(w);
            root->right = createNode(m);

            first = root;
            first_d = false;
        }
    }

    cout << "Stored tree:" << endl;
    displayTree(first);

    fin.close();
    fon.close();
    delete first;

    return 0;
}
