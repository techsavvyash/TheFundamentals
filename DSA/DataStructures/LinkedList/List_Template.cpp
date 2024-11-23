#include <iostream>

template <typename T>
class ListNode
{
protected:
    T data;
    ListNode *next;

public:
    // constructors
    ListNode()
    {
        next = NULL;
    }

    ListNode(T _data)
    {
        data = _data;
        next = NULL;
    }

    ListNode(T _data, ListNode *_next)
    {
        this->data = _data;
        this->next = _next;
    }

    // methods

    bool update(T val)
    {
        data = val;
        return true;
    }
};

template <typename T>
class List
{
private:
    int size;

public:
    ListNode<T> *head;
    ListNode<T> *tail;

    // constructors

    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    List(ListNode<T> *_head)
    {
        if (_head == NULL)
        {
            std::cout << "Invalid Head Pointer Value" << std::endl;
            return;
        }

        head = _head;
        size = 0;
    }

    // methods
    bool pushBack(T val)
    {
        ListNode<T> *newNode = new ListNode<T>(val);
        if (head == NULL && tail == NULL)
        {
            // case when the list would be empty
            head = newNode;
            tail = head;
            size++;
            return true;
        }
        this->tail->next = newNode;
        tail = tail->next;
        size++;
        return true;
    }

    bool pushFront(T val)
    {
        ListNode<T> newNode = new ListNode<T>(val);
        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
            size++;
            return true;
        }

        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }

    bool popBack()
    {
        /*This function is used to pop an element of the back of the
        list, return true if pop is successful and false if the
        list is empty*/

        ListNode<T> *temp = head;
        if (head == NULL)
        {
            std::cout << "List is empty!" << std::endl;
            return false;
        }
        if (head == tail)
        {
            head = tail = NULL;
            size--;
            return true;
        }

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        tail = temp;
        temp = temp->next;
        delete temp; //  free the memory
        size--;
        return true;
    }

    bool popFront()
    {
        /*A function to pop an element of the front of a list
        return false is the list is empty, and returns
        true if the pop operation succeeds*/

        if (head == NULL)
        {
            std::cout << "List Empty!" << std::endl;
            return false;
        }
        ListNode<T> *temp = head;
        head = head->next;

        delete temp; // free the memory
        size--;
        return true;
    }

    int len()
    {
        /*returns the current size of the linked list*/
        return size;
    }
};

int main()
{
    return 0;
}