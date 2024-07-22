//#include <iostream>
//#include <string>
//#include<string.h>
//
//using namespace std;
//template<typename T>
//class Queue {
//private:
//    int front, rear, capacity;
//    T* array;
//
//public:
//    Queue()
//    {
//        front = rear = capacity = 0;
//        array = nullptr;
//    }
//    Queue(int size) {
//        capacity = size;
//        front = rear = -1;
//        array = new T[size];
//    }
//    bool isFull() {
//        return (rear == capacity - 1);
//    }
//    bool isEmpty() {
//        return (front == -1);
//    }
//    void enqueue(T item) {
//        if (isFull()) {
//            return;
//        }
//        if (front == -1) {
//            front = 0;
//        }
//        rear++;
//        array[rear] = item;
//    }
//
//    T dequeue() {
//        if (isEmpty()) {
//            return -1;
//        }
//        T item = array[front];
//        front++;
//        if (front > rear) {
//            front = rear = -1;
//        }
//        return item;
//    }
//    T* get_arr()
//    {
//        return array;
//    }
//
//
//
//};
//void radixSort(Queue<int> ar, int n, int k) {
//    const int m = 10; // Number of possible digit values
//    int* arr = ar.get_arr();
//    int exp = 1;
//
//    Queue<int>* buckets = new Queue<int>[m];
//    for (int i = 0; i < m; i++) {
//        buckets[i] = Queue<int>(n);
//    }
//
//    for (int i = 0; i < k; i++) { // Process all digits one by one
//        // Distribute keys into buckets based on the current digit
//        for (int j = 0; j < n; j++) {
//            int digit = (arr[j] / exp) % 10;
//            buckets[digit].enqueue(arr[j]);
//        }
//
//        // Collect keys from buckets and update the original array
//        int index = 0;
//        for (int j = 0; j < m; j++) {
//            while (!buckets[j].isEmpty()) {
//                arr[index++] = buckets[j].dequeue();
//            }
//        }
//
//        exp *= 10;
//    }
//    delete[] buckets;
//}
//
//
//
//
//int findMaxLength(Queue<string> ar, int n) {
//    string* arr = ar.get_arr();
//    int maxLength = 0;
//    for (int i = 0; i < n; i++) {
//        int length = arr[i].length();
//        if (length > maxLength) {
//            maxLength = length;
//        }
//    }
//    return maxLength;
//}
//
//void countingSort(Queue<string> ar, int n, int exp) {
//    string* arr = ar.get_arr();
//    const int m = 256;
//
//    std::string* output = new std::string[n];
//    int count[m] = { 0 };
//
//    for (int i = 0; i < n; i++) {
//        int length = arr[i].length();
//        int index = 0;
//
//        index = arr[i][exp];
//
//        count[index]++;
//    }
//
//    for (int i = 1; i < m; i++) {
//        count[i] += count[i - 1];
//    }
//
//    for (int i = n - 1; i >= 0; i--) {
//        int length = arr[i].length();
//        int index = 0;
//        index = arr[i][exp];
//
//        output[count[index] - 1] = arr[i];
//        count[index]--;
//    }
//
//    for (int i = 0; i < n; i++) {
//        arr[i] = output[i];
//    }
//
//    delete[] output;
//}
//
//void radixSort(Queue<string> arr, int n) {
//    int maxLength = findMaxLength(arr, n);
//
//    for (int exp = maxLength - 1; exp >= 0; exp--) {
//        countingSort(arr, n, exp);
//    }
//}
//
//int main() {
//    int n;
//    cout << "Enter the number of elements: ";
//    cin >> n;
//
//    int choice;
//    cout << "Choose the data type (1: Integer, 2: String): ";
//    cin >> choice;
//
//    if (choice == 1) {
//        Queue<int> q(n);
//
//
//        int numm;
//
//        cout << "Enter " << n << " integers:" << endl;
//        for (int i = 0; i < n; i++) {
//
//            cin >> numm;
//            q.enqueue(numm);
//        }
//
//        int k = 0;
//        int* intArr = q.get_arr();
//        int maxVal = *max_element(intArr, intArr + n);
//        while (maxVal > 0) {
//            k++;
//            maxVal /= 10;
//        }
//
//        radixSort(q, n, k);
//
//        intArr = q.get_arr();
//        cout << "Sorted Array: ";
//        for (int i = 0; i < n; i++) {
//            cout << intArr[i] << " ";
//        }
//        cout << endl;
//
//        delete[] intArr;
//    }
//    else if (choice == 2) {
//
//        Queue<string> s(n);
//        string strr;
//
//        cout << "Enter " << n << " strings:" << endl;
//        for (int i = 0; i < n; i++) {
//
//
//            cin >> strr;
//            s.enqueue(strr);
//
//        }
//        string* strArr = s.get_arr();
//
//        int k = 0;
//        for (int i = 0; i < n; i++) {
//            int len = strArr[i].length();
//            if (len > k) {
//                k = len;
//            }
//        }
//
//        radixSort(s, n);
//        strArr = s.get_arr();
//
//        cout << "Sorted Strings: ";
//        for (int i = 0; i < n; i++) {
//            cout << strArr[i] << " ";
//        }
//        cout << endl;
//
//        delete[] strArr;
//    }
//    else {
//        cout << "Invalid choice." << endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
class Queue {
private:
    int front, rear, capacity;
    T* array; 

public:
    Queue() {
        front = rear = capacity = 0;
        array = nullptr;
    }

    Queue(int size) {
        capacity = size;
        front = rear = -1; 
        array = new T[size];
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    bool isEmpty() {
        return (front == -1); 
    }

    void enqueue(T item) {
        if (!isFull()) {
            if (front == -1) {
                front = 0; 
            }
            rear++;
            array[rear] = item; 
        }
    }

    T dequeue() {
        if (isEmpty()) {
            return T(-1); 
        }
        T item = array[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }

    T* getArray() {
        return array; 
    }
};

void radixSort(Queue<int> arr, int n, int k) {
    int* intArr = arr.getArray(); // Get the array of integers
    int exp = 1;

    Queue<int>* buckets = new Queue<int>[10];

    for (int i = 0; i < 10; i++) { 
        buckets[i] = Queue<int>(n);
    }

    for (int i = 0; i < k; i++) { 
        for (int j = 0; j < n; j++) {
            int digit = (intArr[j] / exp) % 10;
            buckets[digit].enqueue(intArr[j]); 
        }

        int index = 0;
        for (int j = 0; j < 10; j++) { // Collecting keys from the buckets we have creted
            while (!buckets[j].isEmpty()) {
                intArr[index++] = buckets[j].dequeue();
            }
        }
        exp *= 10; // Move to the next digit place
    }

    delete[] buckets; 
}
//void radixSorrt(Queue<int> arr, int n, int k) {
//    int* intArr = arr.getArray(); 
//    int expression = 1;
//
//    Queue<int>* buckets = new Queue<int>[10];
//
//   /* for (int i = 0; i < 10; i++) {
//        buckets[i] = Queue<int>(n);
//    }*/
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < n; j++) {
//            int digit = (intArr[j] / expression) % 10;
//            buckets[digit].enqueue(intArr[j]);
//        }
//
//        for (int i = 0; i < k; i++) {
//            for (int j = 0; j < n; j++) {
//                int digit = (intArr[j] / expression) % 10;
//              //  buckets[digit].enqueue(intArr[j]);
//            }
//        }
//    }
//
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < n; j++) {
//            int digit = (intArr[j] / expression) % 10;
//            buckets[digit].enqueue(intArr[j]);
//        }
//
//        int index = 0;
//        for (int j = 0; j < 10; j++) { // Collecting keys from the buckets we have creted
//            while (!buckets[j].isEmpty()) {
//                intArr[index++] = buckets[j].dequeue();
//            }
//        }
//        expression *= 10; // Move to the next digit place
//    }
//
//    delete[] buckets;
//}

int findMaxLength(Queue<string> arr, int n) {
    string* strArr = arr.getArray();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int length = strArr[i].length();
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength; 
}

void countingSort(Queue<string> arr, int n, int exp) {
    string* strArr = arr.getArray(); 
    const int m = 256; 

    string* output = new string[n];
    int count[m] = { 0 };

    for (int i = 0; i < n; i++) {
        int index = (exp < strArr[i].length()) ? strArr[i][exp] : 0;
        count[index]++; 
    }

    for (int i = 1; i < m; i++) { 
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (exp < strArr[i].length()) ? strArr[i][exp] : 0; 
        output[count[index] - 1] = strArr[i]; 
        count[index]--; 
    }

    for (int i = 0; i < n; i++) {
        strArr[i] = output[i]; 
    }

    delete[] output;
}
//void radixSorrt(Queue<int> arr, int n, int k) {
//    int* intArr = arr.getArray();
//    int expression = 1;
//
//    Queue<int>* buckets = new Queue<int>[10];
//
//    /* for (int i = 0; i < 10; i++) {
//         buckets[i] = Queue<int>(n);
//     }*/
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < n; j++) {
//            int digit = (intArr[j] / expression) % 10;
//            buckets[digit].enqueue(intArr[j]);
//        }
//
//        for (int i = 0; i < k; i++) {
//            for (int j = 0; j < n; j++) {
//                int digit = (intArr[j] / expression) % 10;
//                //  buckets[digit].enqueue(intArr[j]);
//            }
//        }
//    }
//
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < n; j++) {
//            int digit = (intArr[j] / expression) % 10;
//            buckets[digit].enqueue(intArr[j]);
//        }
//
//        int index = 0;
//        for (int j = 0; j < 10; j++) { // Collecting keys from the buckets we have creted
//            while (!buckets[j].isEmpty()) {
//                intArr[index++] = buckets[j].dequeue();
//            }
//        }
//        expression *= 10; // Move to the next digit place
//    }
//
//    delete[] buckets;
//}

void radixSort(Queue<string> arr, int n) {
    int maxLength = findMaxLength(arr, n); 

    for (int exp = maxLength - 1; exp >= 0; exp--) {
        countingSort(arr, n, exp); // Sorting strings based on each position of the character
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int choice;
    cout << "Choose the data type (1: Integer, 2: String): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        Queue<int> intQueue(n);

        cout << "Enter " << n << " integers:" << endl;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            intQueue.enqueue(num);
        }

        int k = 0;
        int* intArr = intQueue.getArray();
        int maxVal = *max_element(intArr, intArr + n);
        while (maxVal > 0) {
            k++;
            maxVal /= 10;
        }

        radixSort(intQueue, n, k);

        intArr = intQueue.getArray();
        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) {
            cout << intArr[i] << " ";
        }
        cout << endl;

        delete[] intArr;
        break;
    }

    case 2: {
        Queue<string> stringQueue(n);

        cout << "Enter " << n << " strings:" << endl;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            stringQueue.enqueue(str);
        }

        radixSort(stringQueue, n);

        string* strArr = stringQueue.getArray();
        cout << "Sorted Strings: ";
        for (int i = 0; i < n; i++) {
            cout << strArr[i] << " ";
        }
        cout << endl;

        delete[] strArr;
        break;
    }

    default:
        cout << "Invalid choice." << endl;
    }

    return 0;
}
