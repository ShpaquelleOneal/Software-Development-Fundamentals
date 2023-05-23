#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    ~Node() { // desctructor
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
    //cout << "test"<< endl;
    if (root == nullptr) return nullptr;

    if (root->data == value) return root;

    Node* leftResult = findNode(value, root->left);
    if (leftResult != nullptr) return leftResult;

    Node* rightResult = findNode(value, root->right);
    return rightResult;
}

/*
// display data using recursion
void displayTree(Node* root) {
    if (root == nullptr) return;
    cout << root->data << endl;
    displayTree(root->left);
    displayTree(root->right);
}*/

void countLevels (Node* root, int & times) {
    if (root == nullptr) return;
    if (root->data != 0) times++;
    countLevels (root -> left, times);
    countLevels (root -> right, times);
}

void displayTree(Node* root, int level) {
    if (root == nullptr) return;
    displayTree(root->right, level + 1);
    cout << root->data << " ";
    if (root->left != nullptr || root->right != nullptr) {
        cout << endl << level << ": ";
    }
    displayTree(root->left, level + 1);
}

int main() {

    ifstream fin("team.in.txt");
    ofstream fon("team.out.txt");

    /*
    // check if input files have been opened
    if (!fin.is_open() || !fon.is_open()) {
        fon << "Error opening files..." << endl;
        return 0;
    }*/

    int p, w, m;
    bool first_d = true;
    Node * first;
    int levels = 0;

    while(fin >> p >> w >> m) {// while there is data, read it

        if (p == 0  && w == 0 && m == 0) {// if data consists of 3 zeros, it's the end of the data (given in the task)
            break;
        }

        //cout << p<<w<<m << endl;
        if (!first_d) { // for every data entry other than first one

            if (w != 0) { // add data for women - left
                //cout << "Add a "<< w <<" to the left" << endl;
                Node* select = findNode(p, first);
                select->left = createNode(w);
            }
            if (m != 0 ) { // add data for men - right
                //cout << "Add a "<< m <<" to the right" << endl;
                Node* select = findNode(p, first);
                select->right = createNode(m);
            }

        } else { // if it's the first data entry, create as first element
            Node* root = createNode(p);
            root->left = createNode(w);
            root->right = createNode(m);

            first = root; // store the first Node
            first_d = false;
        }
    }
    countLevels(first, levels);
    cout << "Stored tree:" << endl;
    cout << "There are " << levels << " levels..." << endl;
    displayTree(first, 0);
    fin.close();
    fon.close();
    delete first;


    return 0;
}
