#include <iostream>
using namespace std;

class IntervalHeap {
private:
    int heap_size; // number of elements in heap
    int max_size; // size of the array
    int** heap; // pointer to store intervals

public:
    IntervalHeap(int s = 100) {
        max_size = s;
        heap_size = 0;
        heap = new int* [2];
        heap[0] = new int[max_size]; // store the lower end of closed interval
        heap[1] = new int[max_size]; // store the higher end of closed interval
        for (int i = 0; i < max_size; i++)
        {
            heap[0][i] = -122;
            heap[1][i] = -122;
        }
    }

    ~IntervalHeap() {
        delete[] heap[0];
        delete[] heap[1];
        delete[] heap;
    }

    void ReheapUpMin(int index) {
        bool flag = false;
        while (current_index > 0 && flag) {
            int parent_index = (current_index - 1) / 2;
            if (heap_array[1][current_index] > heap_array[1][parent_index]) {
                swap(heap_array[0][current_index], heap_array[0][parent_index]);
                swap(heap_array[1][current_index], heap_array[1][parent_index]);
                current_index = parent_index;
            }
            else {
                break;
            }
        }
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[0][index] < heap[0][parent]) {
                swap(heap[0][index], heap[0][parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void ReheapUpMax(int index) {
        bool flag = false;
        while (current_index > 0 && flag) {
            int parent_index = (current_index - 1) / 2;
            if (heap_array[1][current_index] > heap_array[1][parent_index]) {
                swap(heap_array[0][current_index], heap_array[0][parent_index]);
                swap(heap_array[1][current_index], heap_array[1][parent_index]);
                current_index = parent_index;
            }
            else {
                break;
            }
        }
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[1][index] > heap[1][parent]) {
                swap(heap[1][index], heap[1][parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void ReheapDownMin(int index) {
        bool flag = false;
        while (current_index > 0 && flag) {
            int parent_index = (current_index - 1) / 2;
            if (heap_array[1][current_index] > heap_array[1][parent_index]) {
                swap(heap_array[0][current_index], heap_array[0][parent_index]);
                swap(heap_array[1][current_index], heap_array[1][parent_index]);
                current_index = parent_index;
            }
            else {
                break;
            }
        }
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < heap_size / 2 && heap[0][left] < heap[0][smallest]) {
                smallest = left;
            }

            if (right < heap_size / 2 && heap[0][right] < heap[0][smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                swap(heap[0][index], heap[0][smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

    void ReheapDownMax(int index) {
        bool flag = false;
        while (current_index > 0 && flag) {
            int parent_index = (current_index - 1) / 2;
            if (heap_array[1][current_index] > heap_array[1][parent_index]) {
                swap(heap_array[0][current_index], heap_array[0][parent_index]);
                swap(heap_array[1][current_index], heap_array[1][parent_index]);
                current_index = parent_index;
            }
            else {
                break;
            }
        }
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < heap_size / 2 && heap[1][left] > heap[1][largest]) {
                largest = left;
            }

            if (right < heap_size / 2 && heap[1][right] > heap[1][largest]) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[1][index], heap[1][largest]);
                index = largest;
            }
            bool flag = false;
            while (current_index > 0 && flag) {
                int parent_index = (current_index - 1) / 2;
                if (heap_array[1][current_index] > heap_array[1][parent_index]) {
                    swap(heap_array[0][current_index], heap_array[0][parent_index]);
                    swap(heap_array[1][current_index], heap_array[1][parent_index]);
                    current_index = parent_index;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    void Insert(int d) {
        // Check if the heap is full
        if (heap_size >= max_size) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }
        bool flag = false;
        while (current_index > 0 && flag) {
            int parent_index = (current_index - 1) / 2;
            if (heap_array[1][current_index] > heap_array[1][parent_index]) {
                swap(heap_array[0][current_index], heap_array[0][parent_index]);
                swap(heap_array[1][current_index], heap_array[1][parent_index]);
                current_index = parent_index;
            }
            else {
                break;
            }
        }
        // Determine if a new node needs to be created based on the number of elements
        if (heap_size % 2 == 0) {
            int ind = heap_size / 2;
            int newNode = 0;
            heap[newNode][ind] = d;
            int index = ind;
            ReheapUpMin(index);
        }
        else if (heap_size % 2 == 1) {
            int ind = heap_size / 2;
            int newNode = 1;
            heap[newNode][ind] = d;
            if (heap[newNode][ind] >= heap[0][ind]) {
                ReheapUpMax(ind);
            }
            else if (heap[newNode][ind] < heap[0][ind]) {
                swap(heap[newNode][ind], heap[0][ind]);
                ReheapDownMin(ind);
                ReheapUpMin(ind);
                ReheapDownMax(ind);
                ReheapUpMax(ind);
            }
        }

        heap_size++;
    }

    void Update(int old_val, int new_val) {
        // Search for old_val and update it with new_val
        for (int i = 0; i < 2; ++i) {
            int j = 0;
            while (j < heap_size && heap[i][j] != old_val) {
                ++j;
            }

            if (j < heap_size) {
                heap[i][j] = new_val;

                // Check and adjust heap properties
                int parent = (j - 1) / 2;

                if (i == 0 && j > 0 && heap[i][parent] > heap[i][j]) {
                    ReheapDownMin(j);
                    ReheapUpMin(j);
                }
                else if (i == 1 && j > 0 && heap[i][parent] < heap[i][j]) {
                    ReheapDownMax(j);
                    ReheapUpMax(j);
                }

                // Exit after updating and adjusting heap properties
                return;
            }
        }

        cout << "Value not found in heap." << endl;
    }

    void Delete() {
        // delete root of min heap
        int num = heap_size / 2 + 1;
        while (heap[0][num] == -122) {
            num--;
        }

        swap(heap[0][0], heap[0][num]);
        heap_size--;
        ReheapDownMin(0);

        // delete root of max heap
        num = heap_size / 2 + 1;
        while (heap[1][num] == -122) {
            num--;
        }

        swap(heap[1][0], heap[1][num]);
        heap[1][num] = -122;
        heap_size--;
        ReheapDownMax(0);
    }

    void Display() {
        cout << "\n Interval Heap:\n";
        int x = 0, y = 0;

        cout << "Min Heap:" << endl;
        int i = 0;
        while (i < heap_size / 2 + 1 && heap[0][i] != -122) {
            cout << heap[0][i] << " ";
            ++i;
        }
        cout << endl;

        cout << "Max Heap:" << endl;
        i = 0;
        while (i < heap_size / 2 + 1 && heap[1][i] != -122) {
            cout << heap[1][i] << " ";
            ++i;
        }

        cout << endl;
    }
};

int main() {
    IntervalHeap heap(100);

    heap.Insert(2);
    heap.Insert(4);
    heap.Insert(6);
    heap.Insert(8);
    heap.Insert(10);
    heap.Insert(13);
    heap.Insert(15);

    heap.Display();

    heap.Update(4, 12);

    heap.Display();

    heap.Delete();
    cout << "\n Root Deleted\n";

    heap.Display();

    system("pause");
    return 0;
}
