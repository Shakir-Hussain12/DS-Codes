#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;

    Node() : key(0), data(0), next(nullptr) {}

    Node(int data, int key) : key(key), data(data), next(nullptr) {}
};

class SinglyLinkedList
{

public:
    Node *head;

    SinglyLinkedList()
    {
        head = nullptr;
    }

    SinglyLinkedList(int data, int key)
    {
        Node *newNode = new Node(data, key);
        head = newNode;
    }

    void display()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << "key:" << current->key << " data:" << current->data << " -> ";
//			cout << current->data << endl;
            current = current->next;
        }

        cout << " * " << endl;
    }

    void append(int data, int key)
    {
        Node *newNode = new Node(data, key);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void sort()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *prev;
        Node *current;
        Node *temp;
        bool swapped;
        swapped = false;
        prev = NULL;
        current = head;

        while (current->next != nullptr)
        {
            if (current->data > (current->next)->data)
            {
                swapped = true;
                temp = current->next;
                current->next = current->next->next;
                temp->next = current;
                if (prev == nullptr)
                {
                    head = temp;
                }
                else
                {
                    prev->next = temp;
                }
                prev = temp;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        if (swapped == false)
        {
            return;
        }
        else
        {
            sort();
        }
    }
};

int main()
{
    SinglyLinkedList sll;

    sll.append(6, 1);
    sll.append(5, 2);
    sll.append(4, 3);
    sll.append(3, 1);
    sll.append(2, 2);
    sll.append(1, 3);


    sll.sort();
    sll.display();
}
   
