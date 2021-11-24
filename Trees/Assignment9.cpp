#include <iostream>
#include <queue>

using namespace std;

class Node{
  public:
  int value;
  Node *left, *right;

  Node() {
    value = 0;
    left = nullptr;
    right = nullptr;
  }
};

void addNode(Node *root, int value) {
    if (root->value == 0) {
        root->value = value;
        return;
    }

    Node *newNode = new Node();
    newNode->value = value;

    if (root->value > value && !root->left) {
        root->left = newNode;
        return;
    }
    if (root->value < value && !root->right) {
        root->right = newNode;
        return;
    }

    if (root->value > value && root->left) {
        addNode(root->left, value);
    } else if (root->value < value && root->right) {
        addNode(root->right, value);
    }
}

int getMaxWidth(Node* root) {
  if (!root) {
    return 0;
  }
  deque<Node*> q;
  int maxWidth =0;
  q.push_front(root);
        while (!q.empty()) {
            while(!q.empty() && q.back() == nullptr) {
                q.pop_back();
            }

            while(!q.empty() && q.front() == nullptr) {
                q.pop_front();
            }

            int size = q.size();
            maxWidth = max(maxWidth, size);

            for(int i = 0; i < size; i++) {
                Node *tmp = q.front();

                q.pop_front();

                if (tmp) {
                    q.push_back(tmp->left);
                    q.push_back(tmp->right);
                } else{
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                }
            }
        }
        return maxWidth;

}


int main() {
  Node *root = new Node();

  int user_option;
  cout << "How many nodes do you want in the tree?: ";
  cin >> user_option;

  for (int i = 0; i < user_option; i++) {
    int num;
    cout << "\nEnter a value for the node: ";
    cin >> num;
    addNode(root, num);
  }

  cout << "\n" << getMaxWidth(root) << endl;

}
