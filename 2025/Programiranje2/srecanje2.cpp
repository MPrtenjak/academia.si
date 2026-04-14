#include "constants.h"
#include <iostream>
#include <random>
#include <iomanip> // For std::setw


#ifdef HEAP_10

class Heap {
private:
    int arr[100];
    int size;
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent]) {
                std::swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    
    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && arr[left] < arr[smallest]) {
                smallest = left;
            }
            if (right < size && arr[right] < arr[smallest]) {
                smallest = right;
            }
            
            if (smallest != index) {
                std::swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }
    
public:
    Heap() : size(0) {}
    
    bool add(int value) {
        if (size >= 100) {
            return false;
        }
        
        arr[size] = value;
        heapifyUp(size);
        size++;
        return true;
    }
    
    bool deleteMin(int& value) {
        if (size == 0) {
            return false;
        }
        
        value = arr[0];
        arr[0] = arr[size - 1];
        size--;
        
        if (size > 0) {
            heapifyDown(0);
        }
        
        return true;
    }

    void printInternalReprezentation()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << std::setw(4) << arr[i] << ",";
        }

        std::cout << std::endl;
    }
    
    int getSize() const {
        return size;
    }
    
    bool isEmpty() const {
        return size == 0;
    }
    
    int peek() const {
        if (size > 0) {
            return arr[0];
        }
        return -1;
    }
};

int main() {
    Heap heap;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 10; ++i) {
        int randomNumber = dis(gen);
        std::cout << "Dodajam število " << randomNumber << std::endl;
        heap.add(randomNumber);
        std::cout << "Vsebina polja ";
        heap.printInternalReprezentation();
    }
    
    std::cout << "Heap size: " << heap.getSize() << std::endl;
    
    int value;
    while (heap.deleteMin(value)) {
        std::cout << "Deleted: " << value << std::endl;
    }
    
    return 0;
}

#endif