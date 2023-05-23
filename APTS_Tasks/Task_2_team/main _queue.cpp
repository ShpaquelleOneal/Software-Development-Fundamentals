#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

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

// Function to display data on each level of a binary tree
void displayLevelsReverse(Node* root, ofstream& fout) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    stack<vector<int>> levels; // Stack to store levels in reverse order

    q.push(root);
    int levelCount = -1; // Counter for level number

    while (!q.empty()) {
        int size = q.size();
        vector<int> levelData; // Store data of current level

        while (size > 0) {
            Node* current = q.front();
            q.pop();

            levelData.push_back(current->data); // Store current node's data

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);

            size--;
        }

        if (!levelData.empty()) // Add this condition to avoid pushing empty levels
            levels.push(levelData); // Push current level data to the stack

        levelCount++; // Increment the level number
    }

    while (!levels.empty()) {
        vector<int> levelData = levels.top();
        levels.pop();

        fout << levelCount << ": ";

        for (int i = 0; i < levelData.size(); i++) {
            fout << levelData[i];
            if (i < levelData.size() - 1) {
                fout << " ";
            }
        }

        fout << endl;
        levelCount--; // Decrement the level number for the next level
    }
}

int main() {

    ifstream fin("team.in");
    ofstream fon("team.out");

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


    displayLevelsReverse(first, fon);
    fin.close();
    fon.close();
    delete first;


    return 0;
}
