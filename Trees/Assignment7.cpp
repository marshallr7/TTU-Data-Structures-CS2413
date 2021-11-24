#include <iostream>

using namespace std;

class Node {
  public:
    Node *left, *right;
    int value;

    Node() {
      value = 0;
      right = nullptr;
      left = nullptr;
    }
};

void printBT(const string &prefix, const Node *node, bool isLeft) {
    if( node != nullptr ) {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        cout << node->value << endl;

        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node) {
    printBT("", node, false);    
}

void nullChildren(Node *node) {
  node->left = nullptr;
  node->right = nullptr;
}

// Add a node to the Binary Tree
void addNode(Node *node, int value) {
  if (!node->value) {
    node->value = value;
    nullChildren(node);
    return;
  }

  // recursively move down tree
  if (value > node->value && node->right) {  
    Node *tmp = node->right;
    addNode(tmp, value);
  } else if (value < node->value && node->left) {
    Node *tmp = node->left;
    addNode(node->left, value);
  }


  // if value can be added to right
  if (value > node->value && (!node->right)) {
    Node *newNode = new Node();
    newNode->value = value;
    node->right = newNode;
    return;
  } else if (value < node->value && (!node->left)) {
    Node *newNode = new Node();
    newNode->value = value;
    node->left = newNode;
    return;
  }
}


void postOrderTraversal(Node *node, Node *mirroredNode) {
  if (!node) {
    return;
  } 

  postOrderTraversal(node->left, mirroredNode);
  postOrderTraversal(node->right, mirroredNode);

  Node *tmp= new Node();
  tmp = node->left;
  node->left = node->right;
  node->right = tmp;
}

void convertToMirror(Node* root) {
    if (root == nullptr) {
        return;
    }
 
    convertToMirror(root->left);
    convertToMirror(root->right);
 
    swap(root->left, root->right);
}


int main() {

  Node *root= new Node();
  int numNodes;
  int i = 0;
  cout << "Enter a number of nodes you would like to add to the tree: \n";
  cin >> numNodes;

  while (i < numNodes) {
    int value;
    cout << "Enter a node value: \n";
    cin >> value;
    addNode(root, value);
    i++;
  }

  cout << "\n";
  printBT(root);
  cout << "\n\nMirrored\n\n";

  convertToMirror(root);
  printBT(root);

  return 0;
}
