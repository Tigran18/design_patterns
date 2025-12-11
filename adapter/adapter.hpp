#pragma once
#include <stdexcept>

template <typename T>
class List {
private:
    struct node {
        T val;
        node* next;

        node(const T& val) : val(val), next(nullptr) {}
    };

    node* head = nullptr;
    size_t sz = 0;

public:
    List() {}

    ~List() {
        clear();
    }

    size_t size() const {
        return sz;
    }

    void insert(const T& val) {
        node* new_node = new node(val);
        if (sz == 0) {
            head = new_node;
        } else {
            node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        ++sz;
    }

    void remove(size_t k = 0) {
        if (k >= sz) {
            throw std::runtime_error("Out of range");
        }

        if (k == 0) {
            node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        else {
            node* temp = head;
            for (size_t i = 0; i < k - 1; ++i) {
                temp = temp->next;
            }
            node* to_delete = temp->next;
            temp->next = to_delete->next;
            delete to_delete;
        }
        --sz;
    }

    void clear() {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        sz = 0;
    }

    T& operator[](size_t k) {
        if (k >= sz) {
            throw std::runtime_error("Out of range index.");
        }

        node* temp = head;
        for (size_t i = 0; i < k; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }

    const T& operator[](size_t k) const {
        if (k >= sz) {
            throw std::runtime_error("Out of range index.");
        }

        node* temp = head;
        for (size_t i = 0; i < k; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }
};

template <typename T>
class IStack {
public:
    virtual ~IStack() = default;

    virtual void push(const T& val) = 0;

    virtual void pop() = 0;

    virtual T& top() = 0;
};

template <typename T>
class Stack : public IStack<T> {
public:
    ~Stack() {}

    void push(const T& val) {
        stack.insert(val);
    }

    void pop() {
        if (stack.size() == 0) {
            throw std::runtime_error("Pop from empty stack");
        }
        stack.remove(stack.size() - 1);
    }

    T& top() {
        if (stack.size() == 0) {
            throw std::runtime_error("Top from empty stack");
        }
        return stack[stack.size() - 1];
    }

private:
    List<T> stack;
};
