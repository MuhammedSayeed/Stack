#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int _data)
    {
        this->data = _data;
        this->next = NULL;
    }
};

class Stack
{
public:
    ListNode *top;
    bool unquie;
    int length;
    Stack(bool _unique)
    {
        this->unquie = _unique;
        this->top = NULL;
        this->length = 0;
    }
    bool isEmpty()
    {
        return this->top == NULL;
    }
    bool find(int _data)
    {
        ListNode *temp;
        for (temp = this->top; temp != NULL; temp = temp->next)
        {
            if (temp->data == _data)
            {
                return true;
            }
        }

        return false;
    }
    bool checkDuplicate(int _data)
    {
        if (this->unquie && this->find(_data))
        {
            return true;
        }

        return false;
    }
    void push(int _data)
    {

        bool isExist = checkDuplicate(_data);

        if (isExist)
        {
            cout << "Duplicate Element Not Allowed!" << endl;
            return;
        }
        ListNode *newNode = new ListNode(_data);

        if (this->top == NULL)
        {
            this->top = newNode;
        }
        else
        {
            newNode->next = this->top;
            this->top = newNode;
        }

        this->length++;
    }
    ListNode *peek()
    {
        return this->top;
    }
    ListNode *pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty! , No elemnts to Remove" << endl;
        }
        else
        {
            ListNode *temp = this->top;
            this->top = this->top->next;
            delete temp;
            this->length--;
        }
    }
    void print()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {

            ListNode *temp = this->top;
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << endl;
        }
    }
    int size()
    {
        return this->length;
    }
};

int main()
{
    Stack s1 = new Stack(true);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    int sizeOfStack = s1.size();
    while (sizeOfStack != 0)
    {
        s1.pop();
        sizeOfStack--;
    }
    s1.print();

    return 0;
}
