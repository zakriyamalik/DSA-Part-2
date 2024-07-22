#include <iostream>
using namespace std;

template<class T>
class Sortedset
{
    struct node
    {
        T value;
        node* next;
    };
    node* head;

public:
    Sortedset()
    {
        head = nullptr;
    }
    void insert(T const data)
    {
        node* newnode = new node();
        newnode->value = data;
        newnode->next = nullptr;
        if (head == nullptr || data < head->value)
        {
            newnode->next = head;
            head = newnode;
            return;
        }
        node* current = head;
        while (current->next != nullptr && current->next->value < data)
        {
            current = current->next;
        }
        if (current->next != nullptr && current->next->value == data)
        {
            cout << "Duplicate data not allowed: " << data << endl;
            delete newnode;
            return;
        }
        newnode->next = current->next;
        current->next = newnode;
    }

    void print()
    {
        node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    void remove(int const index)
    {
        if (index < 0)
        {
            cout << "Invalid index. It must be non-negative." << endl;
            return;
        }

        if (index == 0)
        {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* current = head;
        node* previous = nullptr;

        for (int i = 0; current != nullptr && i < index; i++)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Index out of bounds." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }
    void unionWith(const Sortedset<T>& otherSet)
    {
        node* currentA = head;
        node* currentB = otherSet.head;
        Sortedset<T> result;

        while (currentA != nullptr || currentB != nullptr)
        {
            if (currentA == nullptr)
            {
                result.insert(currentB->value);
                currentB = currentB->next;
            }
            else if (currentB == nullptr)
            {
                result.insert(currentA->value);
                currentA = currentA->next;
            }
            else
            {
                if (currentA->value < currentB->value)
                {
                    result.insert(currentA->value);
                    currentA = currentA->next;
                }
                else if (currentB->value < currentA->value)
                {
                    result.insert(currentB->value);
                    currentB = currentB->next;
                }
                else
                {
                    result.insert(currentA->value);
                    currentA = currentA->next;
                    currentB = currentB->next;
                }
            }
        }
        *this = result;
    }
    void rotate()
    {

        node* newnode = n;
        node* tail = new node();
        node* last = new node();
        node* newnode1 = new node();
        node* newnode2 = new node();
        int rotation = 4;
        cout << "\nRotate function\n";
        cout << "Enter the number of rotations you want \n";
        cin >> rotation;
        while (rotation < 0 || rotation>6)
        {
            cout << "Invalid number of rotation\n";
            system("cls");
            cout << "Enter again\n";
            cin >> rotation;
        }
        int counter1 = 0, counter2 = 0;
        while (newnode->next != NULL)
        {
            counter1++;
            cout << newnode->value << " ";
            newnode = newnode->next;
        }
        counter1 = 1;
        tail = newnode;
        tail->next = n;
        newnode = n;
        while (newnode->next != NULL)
        {
            if (counter1 == rotation)
            {
                cout << "\nRotation index is\n";
                cout << newnode->value;

                newnode1 = newnode->next;
                newnode->next = NULL;
                n = newnode1;
                break;
            }
            newnode = newnode->next;
            counter1++;
        }
        cout << "\nAfter rotation linked list is\n";
        print(n);
    }
    void reverse()
    {
        node* prev = nullptr;
        node* node1 = head;
        node* node2 = nullptr;
        while (node1 != NULL)
        {
            cout << node1->value;
            node1 = node1->next;

        }
        node1 = head;
        while (node1 != nullptr)
        {
            node2 = node1->next;
            node1->next = prev;
            prev = node1;
            node1 = node2;
        }
        head = prev;
        cout << endl;
        node1 = head;
        cout << "\nReverse linked list is \n";
        while (node1 != NULL)
        {
            cout << node1->value<<" ";
            node1 = node1->next;

        }
    }
};
int main()
{
    Sortedset<int> setA;
    Sortedset<int> setB;
    int choice = 0;
    int data = 0;
    int index = 0;

    cout << "Enter 1 to insert data in Set A\n";
    cout << "Enter 2 to delete element from Set A\n";
    cout << "Enter 3 to insert data in Set B\n";
    cout << "Enter 4 to perform union of Set A and Set B\n";
    cin >> choice;

    while (choice >= 1 && choice <= 4)
    {
        if (choice == 1)
        {
            cout << "Enter value to insert into Set A\n";
            cin >> data;
            setA.insert(data);
        }
        else if (choice == 2)
        {
            cout << "Enter index to delete from Set A\n";
            cin >> index;
            setA.remove(index);
        }
        else if (choice == 3)
        {
            cout << "Enter value to insert into Set B\n";
            cin >> data;
            setB.insert(data);
        }
        else if (choice == 4)
        {
            setA.unionWith(setB);
            cout << "Set A after union: ";
            setA.print();
        }

        cout << "Enter 1 to insert data in Set A\n";
        cout << "Enter 2 to delete element from Set A\n";
        cout << "Enter 3 to insert data in Set B\n";
        cout << "Enter 4 to perform union of Set A and Set B\n";
        cin >> choice;
    }
    setA.rotate();
    setA.reverse();
    return 0;
}