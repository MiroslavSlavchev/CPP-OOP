#include <iostream.h>
#include <stdlib.h>

class Stack
{
public:
    virtual bool push(int) = 0;
    virtual bool pop(int&) = 0;

    virtual int size() = 0;
    virtual ~Stack()
    {}
};

class ArrayStack : public Stack
{
public:
    ArrayStack()
    {
        count = 0;
    }

    int size()
    { 
        return count;
    }

    bool push(int x)
    { 
        if(!hasSpace())
            return false;
        getArray()[count] = x;
        count++;
        return true;
    }

    bool pop(int &x)
    { 
        if(isEmpty())
            return false;
        x = getArray()[count-1];
        count--;
        return true;
    }

protected:

    virtual int* getArray() = 0;

    virtual bool hasSpace() = 0;

    virtual bool isEmpty() = 0;

    int count;
};

class StaticArrayStack : public ArrayStack
{
public:
    StaticArrayStack() : ArrayStack()
    {}

private:
    int staticArray[10];

protected:
    bool hasSpace()
    {
        return count < 9;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int* getArray()
    {
        return staticArray;
    }
};

class DynamicArrayStack : public ArrayStack
{
public:
    DynamicArrayStack() : ArrayStack()
    {
        dynamicArray = new int[10];
        capacity = 10;
    }

    ~DynamicArrayStack()
    {
        delete dynamicArray;
    }

private:
   
    int capacity;
    int *dynamicArray;

    bool enlarge()
    { 
        int* newArray = new int[capacity*2];
        
        if(newArray == NULL)
            return false;
       
        for(int i = 0; i < capacity; i++)
            newArray[i] = dynamicArray[i];
       
        int *save = dynamicArray;
        dynamicArray = newArray;
        capacity *= 2;
        delete save;
        return true;
    }

protected:
    bool hasSpace()
    { 
        return count < capacity || enlarge();
    }

    bool isEmpty()
    { 
        return count == 0;
    }

    int* getArray()
    { 
        return dynamicArray;
    }
};

void equalizer(Stack* stacks[], int n)
{	 
    bool equilized = false;
    int i, x;
    for(int current = 0; current < n-1; current++)
    {
        do
        {	
            i = current+1;
            while(i < n && abs(stacks[current]->size() - stacks[i]->size()) <= 1)
                i++;
            if(i < n)
            { 
                if(stacks[current]->size() < stacks[i]->size())
                { 
                    stacks[i]->pop(x);
                    stacks[current]->push(x);
                } 
                else
                { 
                    stacks[current]->pop(x);
                    stacks[i]->push(x);
                }
            }
        } while(i < n);
    }
}

int main()
{
  
    Stack* stacks[3];
    stacks[0] = new StaticArrayStack;
    stacks[1] = new StaticArrayStack;
    stacks[2] = new DynamicArrayStack;
    int i, x;
    for(i = 0; i < 3; i++)
    {
        cout << "Въведете елементите на стек #" << i << ", -1 за край...";
        do
        cin >> x;
        while(x != -1 && stacks[i]->push(x));
    }
    equalizer(stacks, 3);
    for(i = 0; i < 3; i++)
    { 
        cout << "============\n";
        while(stacks[i]->pop(x))
            cout << x << endl;
    }
    return 0;
}
