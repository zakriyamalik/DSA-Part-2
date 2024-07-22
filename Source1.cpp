#include<iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    int counter;
    bool mode;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        counter = 0;
        mode = true;
        
    } 

    void push(T value) {
        counter++;

        Node* n = new Node();
        n->data = value;
        n->next = nullptr;

        if (mode) {
            if (tail != nullptr) {
                n->prev = tail;
                tail->next = n;
                tail = n;  // Update the tail
            }
            else {
                n->prev = nullptr;
                head = n;
                tail = n;
            }
        }
        else {
            if (counter != 0) {
                n->next = head;
                head->prev = n;
                head = n;  // Update the head
            }
            else {
                n->next = nullptr;
                n->prev = nullptr;
                head = n;
                tail = n;
            }
        }
    }

    void pop() {
      /*  if (counter <= 0)
            return;

        counter--;

        if (mode) {
            Node* temp = tail->prev;
            delete tail;
            tail = temp;

            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;
        }
        else {
            Node* temp = head->next;
            delete head;
            head = temp;

            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        }*/
        /////////////////////////////////////

        while (s[j] != '>' || s[j] != ' ')
        {
            c_tag[j] = s[j];
            j++;
            j++;
            if (s[j] == '>')
            {
                c_tag[j] = s[j];
                break;
            }
        }
        c_tag[j + 1] = '\0';

        ///////////////////////////////////
 /////////////////////////////////////

        while (s[j] != '>' || s[j] != ' ')
        {
            c_tag[j] = s[j];
            j++;
            j++;
            if (s[j] == '>')
            {
                c_tag[j] = s[j];
                break;
            }
        }
        c_tag[j + 1] = '\0';

        ///////////////////////////////////

    }

    void display() {
        if (mode) {
          /*  cout << "\n";
            Node* curr = head;
            while (curr != nullptr) {
                cout << curr->data << "->";
                curr = curr->next;
            }
            cout << "NULL\n";*/
            /////////////////////////////////////

            while (s[j] != '>' || s[j] != ' ')
            {
                c_tag[j] = s[j];
                j++;
                j++;
                if (s[j] == '>')
                {
                    c_tag[j] = s[j];
                    break;
                }
            }
            c_tag[j + 1] = '\0';

            ///////////////////////////////////
 /////////////////////////////////////

            while (s[j] != '>' || s[j] != ' ')
            {
                c_tag[j] = s[j];
                j++;
                j++;
                if (s[j] == '>')
                {
                    c_tag[j] = s[j];
                    break;
                }
            }
            c_tag[j + 1] = '\0';

            ///////////////////////////////////

        }
        else {
            cout << "\n";
            Node* curr = tail;
            while (curr != nullptr) {
                cout << curr->data << "->";
                curr = curr->prev;
            }
            cout << "NULL\n";
        }
    }

    void flipStack() {
        mode = !mode;
    }
};

int main() {
    LinkedList<int> n;
    n.push(1);
    n.push(2);
    n.push(3);
    cout << "\nInitially Stack:\n";
    n.display();
    n.flipStack();
    cout << "\nStack after flipStack():\n";
    n.display();
    n.push(4);
    cout << "\nStack after push(4):\n";
    n.display();
    cout << "\nStack after pop():\n";
    n.pop();
    n.display();

    return 0;
}