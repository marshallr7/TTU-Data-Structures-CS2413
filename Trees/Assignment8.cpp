#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    int value;
    Node *right, *left;
    Node() {
      value = 0;
      left = nullptr;
      right = nullptr;
    }
};

void inOrder(Node *root, vector<int> &t) {
  if (root == nullptr) {
    return;
    }

    inOrder(root->left, t);
    t.push_back(root->value);
    inOrder(root->right, t);
}

bool isBST(Node *root) {
  if (root->left == nullptr && root->right == nullptr) {
    return true;
  }
  vector<int> t;

  inOrder(root, t);

  for (int i = 0; i < t.size(); i++) {
    if(t[i-1] >= t[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  Node *root = new Node();
  root->value = 2;
  root->left = new Node();
  root->left->value = 1;
  root->right = new Node();
  root->right->value = 3;
  isBST(root) ? cout << "Is BST" : cout << "Is not BST";
}
