#include <iostream>
#include <fstream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    ~Node() { // Desctructor
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


// Function to find required node by given value recursively
Node* findNode(int value, Node* root) {
    if (root == nullptr) return nullptr;

    if (root->data == value) return root;

    Node* leftResult = findNode(value, root->left);
    if (leftResult != nullptr) return leftResult;

    Node* rightResult = findNode(value, root->right);
    return rightResult;
}

// Function to display data on each level of a binary tree in reverse order
void displayLevelsReverse(Node* root, ofstream& fout) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    vector<vector<int>> levels; // Vector of vectors to store levels

    q.push(root);
    int levelCount = -1; // Counter for level number

    while (!q.empty()) {
        int size = q.size();
        vector<int> levelData; // Store data of current level

        while (size > 0) {
            Node* current = q.front();
            q.pop();

            levelData.push_back(current->data);

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);

            size--;
        }

        if (!levelData.empty()) { // Add this condition to avoid pushing empty levels
            // Sort the data in array
            for (int i = 0; i < levelData.size() - 1; i++) {
                for (int j = i + 1; j < levelData.size(); j++) {
                    if (levelData[i] > levelData[j]) {
                        int temp = levelData[i];
                        levelData[i] = levelData[j];
                        levelData[j] = temp;
                    }
                }
            }

            levels.push_back(levelData); // Push current level data to the vector
        }

        levelCount++; // Increment the level number
    }

    for (int i = levels.size() - 1; i >= 0; i--) {
        vector<int> levelData = levels[i];

        fout << levelCount << ": ";

        for (int j = 0; j < levelData.size(); j++) {
            fout << levelData[j];
            if (j < levelData.size() - 1) {
                fout << " ";
            }
        }

        fout << endl;
        levelCount--; // Decrement the level number for the next level
    }
}

int main() {

    ifstream fin("team.in.txt");
    ofstream fon("team.out.txt");

    /*
    // Check if input files have been opened
    if (!fin.is_open() || !fon.is_open()) {
        fon << "Error opening files..." << endl;
        return 0;
    }*/

    int p, w, m;
    bool first_d = true;
    Node * first;
    int levels = 0;

    while(fin >> p >> w >> m) {// While there is data, read it

        if (p == 0  && w == 0 && m == 0) {// If data consists of 3 zeros, it's the end of the data (given in the task)
            break;
        }

        if (!first_d) { // For every data entry other than first one

            if (w != 0) { // Add data for women - left
                Node* select = findNode(p, first);
                select->left = createNode(w);
            }
            if (m != 0 ) { // Add data for men - right
                Node* select = findNode(p, first);
                select->right = createNode(m);
            }

        } else { // If it's the first data entry, create as first element
            Node* root = createNode(p);
            root->left = createNode(w);
            root->right = createNode(m);

            first = root; // Store the first Node
            first_d = false;
        }
    }

    // Use the function
    displayLevelsReverse(first, fon);

    fin.close();
    fon.close();
    delete first;


    return 0;
}
