#include <iostream>

template <typename T>
struct ArrayList {
    T* buffer;
    int element_count;
    int buffer_capacity;

    void init() {
        element_count = 0;
        buffer_capacity = 4;
        buffer = new T[buffer_capacity];
    }

    void destroy() {
        delete[] buffer;
    }

    int get_size() {
        return element_count;
    }

    int get_capacity() {
        return buffer_capacity;
    }

    void expand() {
        buffer_capacity *= 2;
        T* new_buffer = new T[buffer_capacity];
        for (int i = 0; i < element_count; i++) {
            new_buffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = new_buffer;
    }

    void push_back(T item) {
        if (element_count >= buffer_capacity) {
            expand();
        }
        buffer[element_count] = item;
        element_count++;
    }

    void insert(int index, T item) {
        if (index < 0 || index > element_count) {
            std::cout << "Blad: Neverniy index!" << std::endl;
            return;
        }
        if (element_count >= buffer_capacity) {
            expand();
        }
        for (int i = element_count; i > index; i--) {
            buffer[i] = buffer[i - 1];
        }
        buffer[index] = item;
        element_count++;
    }

    void erase(int index) {
        if (index < 0 || index >= element_count) {
            std::cout << "Blad: Neverniy index!" << std::endl;
            return;
        }
        for (int i = index; i < element_count - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
        element_count--;
    }

    T get(int index) {
        if (index < 0 || index >= element_count) {
            std::cout << "Blad: Index vne granic! Pustoe znachenie." << std::endl;
            return T();
        }
        return buffer[index];
    }
};

int main() {
    ArrayList<int> list;
    list.init();

    while (true) {
        std::cout << "\n--- LIST MENU ---\n";
        std::cout << "1. V konec\n";
        std::cout << "2. Po indexu\n";
        std::cout << "3. Udalit\n";
        std::cout << "4. Poluchit\n";
        std::cout << "5. Info (size/buf)\n";
        std::cout << "6. Pechat\n";
        std::cout << "0. Vihod\n";
        std::cout << "Vibor: ";
        
        int action;
        std::cin >> action;

        if (action == 0) break;

        if (action == 1) {
            int val;
            std::cout << "Chislo: ";
            std::cin >> val;
            list.push_back(val);
        } 
        else if (action == 2) {
            int idx, val;
            std::cout << "Index i chislo: ";
            std::cin >> idx >> val;
            list.insert(idx, val);
        } 
        else if (action == 3) {
            int idx;
            std::cout