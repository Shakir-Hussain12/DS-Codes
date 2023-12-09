#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node() {}
    node(int dta)
    {
        data = dta;
        next = NULL;
    }
};
class SinglyLinkedList
{
public:
    node *head;
    node *tail;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(int data)
    {
        node *n = new node(data);
        head = n;
        tail = n;
    }

    void insert(int data)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
            tail->next = NULL;
        }
        else
        {
            tail->next = n;
            n->next = NULL;
            tail = n;
        }
    }

    void display_list()
    {
        node *temp = head;
        cout << "The list contain :";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void delete_tail()
    {
        if (head == NULL)
        {
            cout << "Empty\n";
        }
        else if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            node *temp = head;
            node *pre = NULL;
            while (temp->next != NULL)
            {

                pre = temp;
                temp = temp->next;
            }
            pre->next = NULL;
            tail = pre;
            delete temp;
        }
    }
    void delete_by_value(int value)
    {
        if (head == NULL)
        {
            cout << "Empty\n";
        }
        else if (head->data == value)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            node *temp = head;
            node *pre = NULL;
            while (temp->data != value && temp->next != NULL)
            {

                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            delete temp;
        }
    }
    void delete_by_index(int index)
    {
        if (head == NULL)
        {
            cout << "Empty\n";
        }
        if (index == 0)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            node *temp = head;
            node *pre = NULL;
            int i = 0;
            while (i != index && temp->next != NULL)
            {

                pre = temp;
                temp = temp->next;
                i++;
            }
            pre->next = temp->next;
            delete temp;
        }
    }
    bool update_data(int d, int index)
    {
        node *temp = head;
        int i = 0;
        while (i < index - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
            // cout<<i<<endl;
        }
        if (i == index - 1 && temp != NULL)
        {
            temp->data = d;
            // cout<<"Done\n";
            return true;
        }
        return false;
    }

    void sort_even_odd()
    {
    	node *temp = head;
        while (temp->next != NULL) {
        	if ((temp->next->data % 2) == 0) {
				node *temp2 = temp->next;
				temp->next = temp->next->next;
				temp2->next = head;				
				head = temp2;
			} else {
				temp = temp->next;
			}
		}
    }
};

int main()
{
    SinglyLinkedList liist2;
    liist2.insert(1);
    liist2.insert(2);
    liist2.insert(3);
    liist2.insert(4);
    liist2.insert(6);
    liist2.insert(8);
//    liist2.display_list();
//      cout << liist2.tail->data << endl;
//    cout << liist2.head->data<<endl;
    liist2.sort_even_odd();
    liist2.display_list();

//    cout << liist2.tail->data << endl;
//    cout << liist2.head->data;
}
