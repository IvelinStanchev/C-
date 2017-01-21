#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

struct Element
{
    int value;
    Element* next;
};

class Queue
{
    Element* front;
    Element* back;
    int size;

public:
    Queue();
    ~Queue();
    Queue( const Queue& q );
    Queue& operator=( const Queue& q );

    int getSize() const;
    bool isEmpty() const;
    int getFront() const;
    int getBack() const;

    void push( const int& x );
    void pop( int& x );
    void clear();

    friend void print( const Queue& q);

private:
    void destroy();
    void copy( const Queue& q );
};

Queue::Queue()
{
    front = back = NULL;
    size = 0;
}

Queue::~Queue()
{
    destroy();
}

Queue::Queue( const Queue& q )
{
    copy(q);
}

Queue& Queue::operator=( const Queue& q )
{
    if( this != &q )
    {
        destroy();
        copy(q);
    }
    return *this;
}

void Queue::destroy()
{
    int value;
    while( !isEmpty() )
    {
        pop(value);
    }
}

void Queue::copy( const Queue& q )
{
    Element* tmp = q.front;
    while( tmp )
    {
        push(tmp->value);
        tmp = tmp->next;
    }
}

bool Queue::isEmpty() const
{
    return (size == 0);
}

int Queue::getSize() const
{
    return size;
}

int Queue::getFront() const
{
    assert(front != NULL);
    return front->value;
}

int Queue::getBack() const
{
    assert(back != NULL);
    return back->value;
}

void Queue::clear()
{
    destroy();
}

void Queue::push( const int& value )
{
    Element* el = new Element;
    el->value = value;
    el->next = NULL;
    if( size > 0 )
    {
        back->next = el;
        back = el;
    }
    else
    {
        front = back = el;
    }
    size++;
}

void Queue::pop( int& value )
{
    assert(size>0);
    Element* tmp = front;
    value = tmp->value;
    front = front->next;
    delete tmp;
    size--;
    if( size == 0 )
    {
        back = front;
    }
}

void print( const Queue& q )
{
    Element* tmp = q.front;
    while( tmp )
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Queue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    print(myQueue);

    return 0;
}
