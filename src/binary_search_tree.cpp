#include "assignment/binary_search_tree.hpp"

using namespace std;

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    Node* curr_node = root_;
    bool flag = false;
    Node* new_node = new Node(key, value);
    if (curr_node == nullptr) {
      root_ = new_node;
    } else {
      while (curr_node != nullptr) {
        if (curr_node->key == key) {
          flag = true;
          curr_node->value = value;
          break;
        }
        if (key < curr_node->key) {
          if (curr_node->left == nullptr) {
            curr_node->left = new_node;
            break;
          }
          curr_node = curr_node->left;
        } else {
          if (curr_node->right == nullptr) {
            curr_node->right = new_node;
            break;
          }
          curr_node = curr_node->right;
        }
      }
    }
  }

  bool BinarySearchTree::Remove(int key) {

    return true;
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return nullopt;
    } else {
      return found_node->value;
    }
  }

  bool BinarySearchTree::Contains(int key) const {

    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return false;
    } else {
      return true;
    }
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return nullopt;
    }
    Node* curr_node = root_;
    while (curr_node->left != nullptr) {
      curr_node = curr_node->left;
    }
    return curr_node->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return nullopt;
    }
    Node* curr_node = root_;
    while (curr_node->right != nullptr) {
      curr_node = curr_node->right;
    }
    return curr_node->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {}

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    delete node;
    /*if (node->left != nullptr){
      clear(node->left);
      clear(node->right);
      delete node;
    }*/
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->key == key) {
      return node;
    }
    if (key < node->key) {
      return find(key, node->left);
    }
    if (key > node->key) {
      return find(key, node->right);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    return nullptr;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment