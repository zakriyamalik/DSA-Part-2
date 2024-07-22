//#include<iostream>
//using namespace std;
//
//template<typename T>
//class UndoStack
//{
//    
//private:
//    template<typename T>
//    class Node
//    {
//    public:
//        T data;
//        Node<T>* nt;
//        Node<T>* pr;
//    };
//
//    Node<T>* top;
//    Node<T>* lat;
//    Node<T>* old;
//    int size;
//    int max_size = 5;
//
//public:
//    UndoStack() {
//        top = nullptr;
//        size = 0;
//        lat = nullptr;
//        old = nullptr;
//    }
//
//    ~UndoStack()
//    {
//        while (top)
//        {
//            Node<T>* temp = top;
//            top = top->nt;
//            delete temp;
//        }
//        /////////////////////////////////////
//
//        while (s[j] != '>' || s[j] != ' ')
//        {
//            c_tag[j] = s[j];
//            j++;
//            j++;
//            if (s[j] == '>')
//            {
//                c_tag[j] = s[j];
//                break;
//            }
//        }
//        c_tag[j + 1] = '\0';
//
//        ///////////////////////////////////
//
//    }
//    void display()
//    {
//        Node<T>* curr = old;
//        cout << "\n Printing Stack from Oldest to Latest:\n";
//        
//        while (curr!=lat&& curr!=NULL)
//        {
//            cout << curr->data << ",";
//            curr = curr->nt;
//           
//        }
//        /////////////////////////////////////
//
//        while (s[j] != '>' || s[j] != ' ')
//        {
//            c_tag[j] = s[j];
//            j++;
//            j++;
//            if (s[j] == '>')
//            {
//                c_tag[j] = s[j];
//                break;
//            }
//        }
//        c_tag[j + 1] = '\0';
//
//        ///////////////////////////////////
//
//        cout << lat->data;
//    }
//
//    void dequeue()
//    {
//        if (!top)
//            return;
//
//        Node<T>* curr = old;
//        
//
//        
//
//        if (prev)
//        {
//            prev->next = nullptr;
//            delete curr;
//        }
//
//        size--;
//    }
//
//    void push(T value)
//    {
//       
//        if (size == 100)
//        {
//            cout << "\nSize Exceeds 100, Deleting Oldest Data....\n";
//
//            //dequeue();
//           // Node<T>* n = new Node<T>();
//
//            lat = old;
//            lat->data = value;
//            old = old->nt;
//            /////////////////////////////////////
//
//            while (s[j] != '>' || s[j] != ' ')
//            {
//                c_tag[j] = s[j];
//                j++;
//                j++;
//                if (s[j] == '>')
//                {
//                    c_tag[j] = s[j];
//                    break;
//                }
//            }
//            c_tag[j + 1] = '\0';
//
//            ///////////////////////////////////
//           
//        }
//        else if(lat!=NULL&& max_size-size!=0 )
//        {
//            while (lat)
//            {
//                if (lat->nt != nullptr && lat->nt->data == -1)
//
//                    lat->nt->data = value;
//                lat = lat->nt;
//
//            }
//           
//        }
//        
//        else
//        {
//            size++;
//            Node<T>* n = new Node<T>();
//            n->data = value;
//
//            n->pr = lat;
//            if (n->pr==NULL)
//            {
//
//            }
//            else
//            {
//                n->pr->nt = n;
//            }  
//
//            /*lat = n;
//            lat->nt = old;
//            if (size == 1)
//            {
//                old = n;
//            }*/
//        }
//
//        
//    }
//
//    //bool pop()
//    //{
//    //   // if (top != nullptr)
//    //   // {
//    //        //Node<T>* temp = top;
//    //        lat->data = -1;
//    //        lat = lat->pr;
//    //        //top = top->next;
//    //       // delete temp;
//    //        size--;
//    //        return true;
//    //   // }
//    //    return false;
//    //}
//
//    //T topp()
//    //{
//    //    if (top)
//    //        return top->data;
//    //    else
//    //    {
//    //        cout << "Stack is empty." << endl;
//    //        return T(); // Return a default value for type T
//    //    }
//    //}
//};
//
//int main()
//{
//    UndoStack<int> n;
//    for (int i = 1; i <=100; i++)
//    {
//
//        n.push(i);
//    }
//
//
//    n.push(6);
//
//    n.display();
//    n.push(102);
//    n.display();
//
//    n.push(103);
//    n.display();
//    
//    n.push(343);
//    n.display();
//    
//
//    cout << "\n Lets Undo a Function:";
//
//   /* n.pop();
//    n.pop();*/
//    n.display();
//    n.push(232);
//    
//    n.display();
//
//
//    return 0;
//}