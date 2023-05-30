// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 public:
  BST() :root(nullptr) {}
  void AddValue(const T& value) {
    root = addNode(root, value);
  }
  int SearchValue(const T& value) {
    return searchNode(root, value);
  }
  int depthTree() {
    return getDepth(root) - 1;
  }

 private:
  struct Node {
    Node() :count(0), left(nullptr), right(nullptr) {}
    T value;
    int count;
    Node* left;
    Node* right;
  };
  Node* root;

  Node* addNode(Node* root, const T& value) {
    if (!root) {
      root = new Node;
      root->value = value;
      root->left = nullptr;
      root->right = nullptr;
      root->count = 1;
    } else if (root->value > value) {
      root->left = addNode(root->left, value);
    } else if (root->value < value) {
      root->right = addNode(root->right, value);
    } else {
      root->count++;
    }
    return(root);
  }

  int searchNode(Node* root, const T& value) {
    if (!root) {
      return;
    } else if (root->value < value) {
      return searchNode(root->left, value);
    } else if (root->value > value) {
      return searchNode(root->right, value);
    } else if (root->value == value) {
      return root->count;
    }
  }

  int getDepth(Node* root) {
    if (!root) {
      return 0;
    }
    int rightTree = getDepth(root->right);
    int leftTree = getDepth(root->left);
    if (rightTree > rightTree) {
      return right + 1;
    } else {
      return left + 1;
    }
  }
}
#endif  // INCLUDE_BST_H_
