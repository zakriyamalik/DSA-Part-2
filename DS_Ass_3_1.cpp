//#include <iostream>
//#include <ctime>
//using namespace std;
//
//template <typename T>
//class Node {
//public:
//    T data;
//    Node<T>* next;
//};
//
//template <typename T>
//class Queue {
//    Node<T>* front;        
//    Node<T>* rear;         
//    int totalSoldiers;     
//
//public:
//    Queue() {
//        front = nullptr;   
//        rear = nullptr;    
//        totalSoldiers = 0; 
//    }
//
//    void enqueue(T value) {
//        Node<T>* newNode = new Node<T>();
//        newNode->data = value; // Assign soldier number to the node
//        newNode->next = nullptr;
//
//        if (front == nullptr) {
//            front = newNode;
//            rear = newNode;
//            rear->next = front;  // creating circular link as there's only one soldier
//        }
//        else {
//            rear->next = newNode;
//            rear = newNode;
//            rear->next = front; 
//        }
//        totalSoldiers++; // Incrementing the count after insertion
//    }
//
//    void eliminateSoldiers(int total, int jump) {
//        srand(static_cast<unsigned>(time(0)));
//
//        int startingPoint = (rand() % total) + jump;
//        Node<T>* current = front;    
//        Node<T>* previous = rear;   
//        int i = 1;  // Counter for traversal
//
//        while (i < startingPoint) {
//            previous = current;
//            current = current->next;
//            i++;
//        }
//
//        while (totalSoldiers > 1) {
//            for (int i = 0; i < jump; i++) {
//                previous = current;
//                current = current->next;
//                if (current == nullptr || current->data == NULL) {
//                    current = front;
//                }
//            }
//
//            if (current == front) {
//                front = current->next;
//                rear->next = front; // Rear adjusts to the next soldier
//            }
//            else if (current == rear) {
//                previous->next = front;
//                rear = previous; // Rear updates after eliminating a soldier
//            }
//            else {
//                previous->next = current->next; // Remove the current soldier from the queue
//            }
//
//            cout << "Eliminated: " << current->data << endl;
//            Node<T>* temp = current->next;
//            delete current;  // Free memory of eliminated soldier
//            totalSoldiers--;
//
//            if (totalSoldiers > 0) {
//                displayRemainingSoldiers(); // Display the remaining soldiers
//            }
//            current = temp;
//        }
//    }
//
//    // Display the soldier numbers of the remaining soldiers in the queue
//    void displayRemainingSoldiers() {
//        Node<T>* current = front;
//        cout << "Remaining Soldiers: ";
//        for (int i = 0; i < totalSoldiers - 1; i++) {
//            cout << current->data << " -> ";
//            current = current->next;
//        }
//        cout << current->data << endl;
//    }
//};
//
//int main() {
//    Queue<int> soldiersQueue;
//    int totalSoldiers, jumpCount;
//
//    cout << "Enter Number of Soldiers (N): ";
//    cin >> totalSoldiers;
//
//    while (cin.fail() || totalSoldiers < 1) {
//        cout << "Invalid Input. Enter Number of Soldiers (N): ";
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cin >> totalSoldiers;
//    }
//
//    cout << "Enter Number of Jumps (k): ";
//    cin >> jumpCount;
//
//    while (cin.fail() || jumpCount < 1) {
//        cout << "Invalid Input. Enter Number of Jumps (k): ";
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cin >> jumpCount;
//    }
//
//    for (int i = 1; i <= totalSoldiers; i++) {
//        soldiersQueue.enqueue(i);
//    }
//    soldiersQueue.eliminateSoldiers(totalSoldiers, jumpCount);
//
//    return 0;
//}
