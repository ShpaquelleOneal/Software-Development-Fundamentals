#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;

    Node(int id) : id(id), left(nullptr), right(nullptr) {}
};

void buildTree(Node* root, unordered_map<int, Node*>& nodes, ifstream& inputFile) {
    int womanId, manId;
    inputFile >> womanId >> manId;

    if (womanId != -1) {
        root->left = nodes[womanId] = new Node(womanId);
        buildTree(root->left, nodes, inputFile);
    }

    if (manId != -1) {
        root->right = nodes[manId] = new Node(manId);
        buildTree(root->right, nodes, inputFile);
    }
}

void printLevels(Node* root, ofstream& outputFile) {
    queue<Node*> levelQueue;
    levelQueue.push(root);

    int level = 0;
    while (!levelQueue.empty()) {
        outputFile << level << ":";
        int levelSize = levelQueue.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* node = levelQueue.front();
            levelQueue.pop();

            outputFile << " " << node->id;

            if (node->left)
                levelQueue.push(node->left);
            if (node->right)
                levelQueue.push(node->right);
        }

        outputFile << endl;
        ++level;
    }
}

int main() {
    unordered_map<int, Node*> nodes;

    int rootId;
    cin >> rootId;

    nodes[rootId] = new Node(rootId);
    buildTree(nodes[rootId], nodes, cin);

    // Rest of the code remains the same as before
}
