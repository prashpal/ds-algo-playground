#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Node {
public:
    Node() = default;
    explicit Node(T input): data(std::move(input)), left(nullptr), right(nullptr) {}
    ~Node() = default;

    // Deleted copy constructor and assignment operator
    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

    // Defaulted move constructor and assignment operator
    Node(Node&&) = default;
    Node& operator=(Node&&) = default;

    const T& getData() const {
        return this->data;
    }
    Node<T>* getLeft() const {
        return this->left.get();
    }
    Node<T>* getRight() const {
        return this->right.get();
    }
    void setData(T&& input) {
        data = std::move(input);
    }
    void setLeft(std::unique_ptr<Node<T>> input) {
        this->left = std::move(input);
    }
    void setRight(std::unique_ptr<Node<T>> input) {
        this->right = std::move(input);
    }
private:
    T data;
    std::unique_ptr<Node<T>> left;
    std::unique_ptr<Node<T>> right;
};

template <typename T>
class BinaryTree {
public:
    explicit BinaryTree(Node<T> input): root(std::move(input)) {}
private:
    Node<T> root;
};