#include <iostream>
#include <stdexcept>

template <typename T>
struct Vector {
    T* data;
    int current_size;
    int current_capacity;

    void init() {
        current_size = 0;
        current_capacity = 4;
        data = new T[current_capacity];
    }

    void free() {
        delete[] data;
    }

    int size() {
        return current_size;
    }

    int capacity() {
        return current_capacity;
    }

    void resize() {
        current_capacity *= 2;
        T* new_data = new T[current_capacity];
        for (int i = 0; i < current_size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    void push_back(T value) {
        if (current_size >= current_capacity) {
            resize();
        }
        data[current_size] = value;
        current_size++;
    }

    void insert(int index, T value) {
        if (index < 0 || index > current_size) {
            std::cout << "Oshibka: Neverniy index!" << std::endl;
            return;
        }
        if (current_size >= current_capacity) {
            resize();
        }
        for (int i = current_size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        current_size++;
    }

    void erase(int index) {
        if (index < 0 || index >= current_size) {
            std::cout << "Oshibka: Neverniy index!" << std::endl;
            return;
        }
        for (int i = index; i < current_size - 1; i++) {
            data[i] = data[i + 1];
        }
        current_size--;
    }

    T get(int index) {
        if (index < 0 || index >= current_size) {
            std::cout << "Oshibka: Neverniy index! Vozvrasheno pustoe znachenie." << std::endl;
            return T();
        }
        return data[index];
    }
};

int main() {
    Vector<int> v;
    v.init();

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Dobavit v konec\n";
        std::cout << "2. Dobavit po indexu\n";
        std::cout << "3. Udalit po indexu\n";
        std::cout << "4. Poluchit po indexu\n";
        std::cout << "5. Razmer i Bufer\n";
        std::cout << "6. Vivesti ves vector\n";
        std::cout << "0. Vihod\n";
        std::cout << "Viberite deistvie: ";
        
        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int val;
            std::cout << "Vvedite chislo: ";
            std::cin >> val;
            v.push_back(val);
        } 
        else if (choice == 2) {
            int idx, val;
            std::cout << "Vvedite index i chislo: ";
            std::cin >> idx >> val;
            v.insert(idx, val);
        } 
        else if (choice == 3) {
            int idx;
            std::cout << "Vvedite index: ";
            std::cin >> idx;
            v.erase(idx);
        } 
        else if (choice == 4) {
            int idx;
            std::cout << "Vvedite index: ";
            std::cin >> idx;
            int res = v.get(idx);
            std::cout << "Element: " << res << std::endl;
        } 
        else if (choice == 5) {
            std::cout << "Kolichestvo elementov: " << v.size() << std::endl;
            std::cout << "Razmer bufera: " << v.capacity() << std::endl;
        } 
        else if (choice == 6) {
            std::cout << "Vector: ";
            for (int i = 0; i < v.size(); i++) {
                std::cout << v.get(i) << " ";
            }
            std::cout << std::endl;
        }
    }

    v.free();
    return 0;
}