//#include <iostream>
//#include <fstream>
//#include <string>
//#include<string.h>
//#include<cstring>
//using namespace std;
//template <typename U>
//class Node {
//public:
//    U data;
//    Node<U>* next;
//};
//
//class XMLData
//{
//    string data;
//public:
//    XMLData()
//    {
//        data = ""; // Initialize data with a default value for type A
//    }
//    void setData(string s)
//    {
//        data = s;
//    }
//    string getData()
//    {
//        return data;
//
//    }
//    friend ostream& operator<<(ostream& output, const XMLData& D) {
//        output << D.data;
//        return output;
//    }
//    bool h_check()
//    {
//
//        int i = 0;
//        int size = 0;
//        while (data[i] != '\0')
//        {
//            i++;
//            size++;
//
//        }
//        size--;
//
//        if (data[0] == '<' && data[1] == '?' && data[size - 1] == '?' && data[size] == '>')
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//};
//
//template <class T>
//class Stack {
//private:
//
//
//    Node<T>* top;
//
//public:
//    Stack() : top(nullptr) {}
//    /*~Stack() {
//        while (!IsEmpty())
//            pop();
//    }*/
//
//    bool IsEmpty() {
//        return top == nullptr;
//    }
//
//    bool push(const T& val) {
//        Node<T>* n = new Node<T>();
//        n->data = val;
//        n->next = top;
//        top = n;
//        return true;
//    }
//
//    bool pop() {
//        if (IsEmpty())
//            return false;
//
//        Node<T>* pt = top;
//        top = top->next;
//        delete pt;
//        return true;
//    }
//
//    Node<T>* topp() {
//
//        if (top == nullptr)
//            return NULL;
//        return top;
//    }
//
//    Stack<T> reverse() const {
//
//        Stack<T> r_stack;
//
//        Node<T>* curr = this->top;
//        while (curr != nullptr) {
//            r_stack.push(curr->data);
//            curr = curr->next;
//        }
//
//        return r_stack;
//    }
//
//    void print() {
//        cout << "\n Printing Data:_____\n";
//
//        Node<T>* curr = top;
//        while (curr) {
//            cout << curr->data << "\n";
//            curr = curr->next;
//        }
//
//        cout << endl;
//    }
//
//};
//bool compare_string(string st, char*& c)
//{
//    bool check = false;
//    int lenght = 0;
//    int length2 = st.length();
//    for (int i = 0; c[i] != '\0'; i++)
//    {
//        lenght++;
//    }
//    if (lenght != length2)
//    {
//        return false;
//    }
//    if (lenght == length2)
//    {
//        for (int i = 0; i < length2; i++)
//        {
//            if (st[i] != c[i])
//            {
//                check = true;
//                return false;
//                break;
//            }
//        }
//    }
//    if (check == false)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//
//}
//
//string convertToClosingTag(string& openingTag) {
//    return "</" + openingTag.substr(1);
//}
//
//void comment_error(Node<XMLData>* curr)
//{
//    //////////////////
//    /////////////////
//    int l_c = 2;
//
//    while (curr)
//    {
//       
//        string s = curr->data.getData();
//        bool open_check = false;
//        bool close_check = false;
//        int i = 0, j = 0;
//        char* opening_tagintion;
//        char t = NULL;
//        char* closing_tagition;
//        bool faltu_check = false;
//        for (int i = 0; s[i] != '\0';)
//        {
//
//
//            if (s[i] == '<' && s[i + 1] != '/' && s[i + 1] != '-')
//            {
//
//                faltu_check = true;
//
//            }
//            if (s[i] == '>')
//            {
//                faltu_check = false;
//            }
//
//            if (s[i] == '<' && s[i + 1] == '!')
//            {
//
//
//                if (s[i + 2] == '-' && s[i + 3] == '-')
//                {
//                    cout << "\n Comment Identified at line:" << l_c << endl;
//                    bool comm_flag = true;
//                    int x_lc = l_c;
//                    Node<XMLData>* temporary_current = curr;
//                    int d = 0;
//                    ////////////////////////////////
//
//                    while (s[j] != '>' || s[j] != ' ')
//                    {
//                        closing_tagition[j] = s[j];
//                        j++;
//                        j++;
//                        if (s[j] == '>')
//                        {
//                            closing_tagition[j] = s[j];
//                            break;
//                        }
//                    }
//
//                    ////////////////////////////////
//                    while (temporary_current && comm_flag)
//                    {
//                        string s = temporary_current->data.getData();
//                        if (x_lc == l_c)
//                        {
//                            d = i + 4;
//                        }
//                        else
//                        {
//                            d = 0;
//                        }
//
//                        int fsdf = 0;
//                        while (s[d] != '\0' && comm_flag)
//                        {
//                            cout << "\ncount:" << ++fsdf;
//                            if (s[d] == '<' && s[d + 1] == '!' && s[d + 2] == '-' && s[d + 3] == '-')
//                            {
//                                cout << "\nNested Comment Error at Line Count:" << l_c;
//                            }
//                            if (s[d] == '-' && s[d + 1] == '-' && s[d + 2] == '>')
//                            {
//                                comm_flag = false;
//
//
//
//
//                            }
//                            d++;
//                            t = s[d];
//                        }
//
//                        temporary_current = temporary_current->next;
//                        x_lc++;
//                    }
//                    if (comm_flag)
//                    {
//                        cout << "\n Comment Error at \t" << l_c << endl;
//                    }
//                    //////////////////////////////
//
//                    while (s[j] != '>' || s[j] != ' ')
//                    {
//                        closing_tagition[j] = s[j];
//                        j++;
//                        j++;
//                        if (s[j] == '>')
//                        {
//                            closing_tagition[j] = s[j];
//                            break;
//                        }
//                    }
//
//
//                    /////////////////////////////
//                }
//                else
//                {
//                    cout << "Comment error at \t" << l_c << endl;
//                }
//            }
//           
//
//            i++;
//        }
//
//
//        curr = curr->next;
//        l_c++;
//    }
//
//
//
//    ///////////////////
//    ////////////////////
//}
//void tags_error(Node<XMLData>* curr)
//{
//    int l_c = 2;
//    Stack<XMLData> tags;
//    while (curr)
//    {
//
//        string s = curr->data.getData();
//        bool o_flag = false;
//        bool c_flag = false;
//        int i = 0, j = 0;
//        char* o_tag;
//        char t = NULL;
//        char* c_tag;
//        bool flag_ins = false;
//        for (int i = 0; s[i] != '\0';)
//        {
//            if (s[i] == '<' && s[i + 1] != '/' && s[i + 1] != '!')
//            {
//                int z = i;
//                int x = 0;
//                o_flag = true;
//                while (s[z] != '>' || s[z] != ' ')
//                {
//                    x++;
//                    z++;
//                    if (s[z] == '>')
//                    {
//                        break;
//                    }
//                }
//                x = x + 1;
//                o_tag = new char[x + 1];
//                //o_tag[0] = '<';
//                z = i;
//                x = 0;
//                while (s[z] != '>' && s[z] != ' ')
//                {
//                    o_tag[x] = s[z];
//                    x++;
//                    z++;
//                    if (s[z] == '>')
//                    {
//                        o_tag[x] = s[z];
//                        break;
//                    }
//                    if (s[z] == ' ')
//                    {
//
//                        o_tag[x] = '>';
//                        break;
//                    }
//                }
//                o_tag[x + 1] = '\0';
//                XMLData* x1 = new XMLData();
//                x1->setData(o_tag);
//                tags.push(*x1);
//
//                ////////////////////////
//                while (s[j] != '>' || s[j] != ' ')
//                {
//                    c_tag[j] = s[j];
//                    j++;
//                    j++;
//                    if (s[j] == '>')
//                    {
//                        c_tag[j] = s[j];
//                        break;
//                    }
//                }
//
//
//                //////////////////////////
//
//            }
//            else if (s[i] == '<' && s[i + 1] == '/')
//            {
//
//                int z = i;
//                int x = 0;
//                c_flag = true;
//                while (s[z] != '>')
//                {
//                    x++;
//                    z++;
//                }
//                x++;
//                c_tag = new char[x + 1];
//                //c_tag[0] = '<';
//                z = i;
//                x = 0;//1
//                while (s[z] != '>' || s[z] != ' ')
//                {
//                    c_tag[x] = s[z];
//                    x++;
//                    z++;
//                    if (s[z] == '>')
//                    {
//                        c_tag[x] = s[z];
//                        break;
//                    }
//                }
//                c_tag[x + 1] = '\0';
//                string t = tags.topp()->data.getData();
//                t = convertToClosingTag(t);
//                if (compare_string(t, c_tag))
//                {
//                    tags.pop();
//                }
//                else
//                {
//                    cout << "\nError at Line: " << l_c << ", " << t << " doesnt matches with " << c_tag;
//                    tags.pop();
//                }
//               
//            }
//            i++;
//           
//        }
//        l_c++;
//        curr = curr->next;
//    }
//}
//void attribute_error(Node<XMLData>* curr)
//{
//    int l_c = 2;
//
//    while (curr)
//    {
//
//        string s = curr->data.getData();
//        bool o_flag = false;
//        bool c_flag = false;
//        int i = 0, j = 0;
//        char* o_tag;
//        char t = NULL;
//        char* c_tag;
//        bool flag_ins = false;
//        for(int i=0;s[i]!='\0';)
//        {
//            if (s[i] == ' ' && flag_ins)
//            {
//
//                int j = i;
//                while (s[j] != '=')
//                {
//                    j++;
//                }
//                if (s[j + 1] == '"')
//                {
//                    char start = s[j + 1];
//                    while (s[j] != ' ' && s[j] != '?' && s[j] != '>')
//                    {
//                        j++;
//                        ///////////////////
//
//                        while (s[j] != '>' || s[j] != ' ')
//                        {
//                            c_tag[j] = s[j];
//                            j++;
//                            j++;
//                            if (s[j] == '>')
//                            {
//                                c_tag[j] = s[j];
//                                break;
//                            }
//                        }
//                        c_tag[j + 1] = '\0';
//
//                        //////////////////////
//                    }
//                    if (start == s[j - 1])
//                    {
//
//                    }
//                    else
//                    {
//                        cout << "Attribute error on line\t" << l_c << endl;
//                    }
//                }
//                else if (s[j + 1] == '\'')
//                {
//                    char start = s[j + 1];
//                    while (s[j] != ' ' && s[j] != '?' && s[j] != '>')
//                    {
//                        j++;
//                    }
//                    if (start == s[j - 1])
//                    {
//
//                    }
//                    else
//                    {
//                        cout << "Attribute error on line:\t" << l_c << endl;
//                    }
//                }
//                else
//                {
//                    cout << "Attribute error on line:\t" << l_c << endl;
//                }
//            }
//            i++;
//        }
//
//        l_c++;
//        curr = curr->next;
//    }
//}
//void ErrorCheck(Stack<XMLData> s1)
//{
//
//    XMLData headder = s1.topp()->data;
//    bool flag = headder.h_check();
//    if (!flag)
//    {
//        cout << "\n Error in header";
//    }
//    Node<XMLData>* current = s1.topp()->next;
//    attribute_error(current);
//    comment_error(current);
//    tags_error(current);
//
//    
//}
//
//int main() {
//    ifstream iff("Text.txt");
//    Stack<XMLData> sexy_stack;
//    Stack<XMLData> s1;
//    string s;
//    XMLData d;
//
//    while (getline(iff, s)) {
//        d.setData(s);
//        sexy_stack.push(d);
//    }
//
//    cout << "Original Stack:";
//    sexy_stack.print();
//
//    s1 = sexy_stack.reverse();
//
//    cout << "Reversed Stack:";
//    s1.print();
//
//
//    ErrorCheck(s1);
//
//
//
//    return 0;
//}