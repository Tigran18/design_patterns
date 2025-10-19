#pragma once 

template <typename T>
class List {
private:
    struct node {
        T val;
        node* next;

        node(const T& val) : val(val), next(nullptr) {}
    };
    node* head = nullptr;
    size_t size = 0;
public:
    list() {

    }

    ~list() {
        clear();
    }

    void insert(const T& val) {
        node* new_node = new node(val);
        if(size == 0) {
            head = new_node;
        }
        else {
            node* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        ++size;
    }

    void remove(size_t k = 0) {
        if(k >= size) {
            throw std::runtime_error("Out of range");
        }
        if(k == 0) {
            node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        else{
            node* temp = head;
            while(k!=1) {
                temp = temp->next;
                --k;
            }
            node* to_delete = temp->next;
            temp->next = temp->next->next;
            delete to_delete;
        }
        --size;
    }

    void clear() {
        while(head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
    
    T& operator[](size_t k = 0) {
        if(k >= size) {
            throw std::runtime_error("Out of range index.");
        }
        if(k == 0) {
            return head->val;
        }
        else {
            node* temp = head;
            while(k > 0) {
                temp = temp->next;
                --k;
            }
            return temp->val;
        }
    }
};

template <typename T>
class IStack {
    virtual ~IStack() = default;

    virtual void push(const T& val) = 0;

    virtual void pop() = 0;

    virtual T& top() = 0;
};

template <typename T>
class Stack : public IStack<T> {
public:
    ~Stack() {
    }

    void push(const T& val) {
        stack.insert(val);
    }

    void pop() {
        stack.remove(stack.size()-1);
    }

    T& top() const { 
        return stack[size()-1];
    }

private:
    List<T> stack;
};