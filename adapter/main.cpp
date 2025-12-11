#include <iostream>
#include "adapter.hpp"

int main() {
    List<int> lst;

    lst.insert(10);
    lst.insert(20);
    lst.insert(30);

    std::cout << "List values:\n";
    std::cout << lst[0] << "\n";
    std::cout << lst[1] << "\n";
    std::cout << lst[2] << "\n";

    lst.remove(1);
    std::cout << "After removing index 1:\n";
    std::cout << lst[0] << "\n";
    std::cout << lst[1] << "\n";

    Stack<int> st;
    st.push(5);
    st.push(15);
    st.push(25);

    std::cout << "Stack top (via operator[]):\n";
    std::cout << st.top() << "\n";

    st.pop();
    std::cout << "Top after pop:\n";
    std::cout << st.top() << "\n";

    return 0;
}
