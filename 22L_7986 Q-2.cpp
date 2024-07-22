#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename K, typename V>
class SpecialBST {
public:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(const K& k, const V& v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    bool insertHelper(Node*& node, const K& key, const V& value) {
        if (node == nullptr) {
            node = new Node(key, value);
            return true;
        }

        if (key < node->key) {
            return insertHelper(node->left, key, value);
        } else if (key > node->key) {
            return insertHelper(node->right, key, value);
        } else {
            return false;
        }
    }

    V searchHelper(Node* node, const K& key) {
        if (node == nullptr) {
            return V();
        }

        if (key < node->key) {
            return searchHelper(node->left, key);
        } else if (key > node->key) {
            return searchHelper(node->right, key);
        } else {
            return node->value;
        }
    }

    Node* deleteHelper(Node*& node, const K& key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = deleteHelper(node->left, key);
        } else if (key > node->key) {
            node->right = deleteHelper(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteHelper(node->right, temp->key);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void levelOrderTraversalHelper(Node* node, vector<V>& result) {
        if (node == nullptr) {
            return;
        }

        vector<Node*> queue;
        queue.push_back(node);

        while (!queue.empty()) {
            Node* current = queue.front();
            queue.erase(queue.begin());
            result.push_back(current->value);

            if (current->left) queue.push_back(current->left);
            if (current->right) queue.push_back(current->right);
        }
    }

    void inOrderTraversalHelper(Node* node, vector<V>& result) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversalHelper(node->left, result);
        result.push_back(node->value);
        inOrderTraversalHelper(node->right, result);
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    SpecialBST() : root(nullptr) {}

    bool insert(const K& key, const V& value) {
        return insertHelper(root, key, value);
    }

    V search(const K& key) {
        return searchHelper(root, key);
    }

    Node* remove(const K& key) {
        return deleteHelper(root, key);
    }

    vector<V> getValuesLevelWise() {
        vector<V> result;
        levelOrderTraversalHelper(root, result);
        return result;
    }

    vector<V> getValuesInOrder() {
        vector<V> result;
        inOrderTraversalHelper(root, result);
        return result;
    }

    ~SpecialBST() {
        destroyTree(root);
    }
};

class Student {
public:
    int rollNumber;
    string firstName;
    string lastName;
    int batch;
    string department;
    float cgpa;

    Student(int roll, const string& first, const string& last, int b, const string& dept, float c)
        : rollNumber(roll), firstName(first), lastName(last), batch(b), department(dept), cgpa(c) {}
};

class StudentList {
private:
    SpecialBST<int, Student*> studentBST;

public:
    bool insertNewStudent(int rollNumber, const string& firstName, const string& lastName,
                          int batch, const string& department, float cgpa) {
        if (studentBST.search(rollNumber) != nullptr) {
            return false;
        }

        Student* newStudent = new Student(rollNumber, firstName, lastName, batch, department, cgpa);
        studentBST.insert(rollNumber, newStudent);

        return true;
    }

    bool deleteStudent(int rollNumber) {
        SpecialBST<int, Student*>::Node* deletedStudent = studentBST.remove(rollNumber);
        if (deletedStudent != nullptr) {
            delete deletedStudent;
            return true;
        }

        return false;
    }

    bool updateStudent(int oldRollNumber, int newRollNumber, const string& newFirstName,
                       const string& newLastName, int newBatch, const string& newDepartment,
                       float newCgpa) {
        Student* studentToUpdate = studentBST.search(oldRollNumber);

        if (studentToUpdate != nullptr) {
            if (oldRollNumber != newRollNumber) {
                if (studentBST.search(newRollNumber) != nullptr) {
                    return false;
                }

                studentBST.remove(oldRollNumber);
                studentToUpdate->rollNumber = newRollNumber;
                studentBST.insert(newRollNumber, studentToUpdate);
            }

            studentToUpdate->firstName = newFirstName;
            studentToUpdate->lastName = newLastName;
            studentToUpdate->batch = newBatch;
            studentToUpdate->department = newDepartment;
            studentToUpdate->cgpa = newCgpa;

            return true;
        }

        return false;
    }

    void printAllStudents() {
        vector<Student*> studentValues = studentBST.getValuesInOrder();

        for (const auto& student : studentValues) {
            cout << "Roll Number: " << student->rollNumber << ", Name: "
                 << student->firstName << " " << student->lastName
                 << ", Batch: " << student->batch << ", Department: "
                 << student->department << ", CGPA: " << student->cgpa << endl;
        }
    }

    ~StudentList() {
        vector<Student*> studentValues = studentBST.getValuesInOrder();
        for (const auto& student : studentValues) {
            delete student;
        }
    }
};

int main() {
    StudentList studentList;

    studentList.insertNewStudent(101, "John", "Doe", 2022, "Computer Science", 3.8);
    studentList.insertNewStudent(102, "Jane", "Smith", 2023, "Electrical Engineering", 3.5);
    studentList.insertNewStudent(103, "Alice", "Johnson", 2022, "Mechanical Engineering", 3.2);

    cout << "All Students:\n";
    studentList

.printAllStudents();

    studentList.updateStudent(101, 104, "John", "Doe", 2022, "Computer Science", 3.9);

    cout << "\nAll Students after Update:\n";
    studentList.printAllStudents();

    studentList.deleteStudent(102);

    cout << "\nAll Students after Delete:\n";
    studentList.printAllStudents();

    return 0;
}