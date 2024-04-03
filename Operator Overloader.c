#ifndef SET_H
#define SET_H
#include <iostream>

using namespace std;
template <typename i>
class Set
{
    private:
        int items;
        int cap;
        i *arr;
    public:
    //Default Constructor.
    Set()
    {
        cap = 10;
        arr = new i [10];
        items = 0;
    }
    //Parametrized Constructor.
    Set(int c, int num)
    {
        cap = c;
        items = num;
        arr = new i [cap];
    }
    //Destructor
    ~Set()
    {
        delete arr[];
        cout << "Destructor was called." << endl;
    }
    //Copy Constructor
    Set(const Set& S)
    {
        int j;
        items = S.items;
        cap = S.cap;
        arr = new i[cap];
        for (j=0; j<items; j++)
        {
           arr[j] = S.arr[j];
        }
    }
    //Add element function,adds an element if it is not already present in the array.
    void addElement(i element)
    {
        int j,flag = 0;
        if (items == 0)
        {
            arr[0] = element;
            items++;
            cout << "Element has been added to the array." << endl;
        }
        else
        {
            for (j=0; j<items; j++)
            {
                if (arr[j] == value)
                {
                    flag = 1;
                    j = items;
                    cout << "Element already in set." << endl;
                }
            }
            if (flag != 1)
            {
                arr[items] = value;
                items++;
                cout << "Element has been added to array." << endl;
            }
        }
    }
    //Remove element function,removes an element from the array if present else returns false
    bool removeElement(i element)
    {
        int j;
        if (items==0)
            cout << "Set is empty,therefore element can't be removed." << endl;
            return false;
        else
        {
            for (j=0;j<items;j++)
            {
                if (arr[j] == element)
                {
                    for(int k=j ; k<items-1; k++)
                    {
                       arr[k] = arr[k+1];
                    }
                    items--;
                    cout << "Element has been removed." << endl;
                    return true;
                }
            }
            cout << "Element not found in the array." << endl;
            return false;
        }
    }
    //+ operator overloaded to give the union f the sets.
    friend void operator+(Set<i>& left, Set<i>& right)
    {
        int j,flag,flag2=0;
        if (right.items < left.items)//checks if left has more elements switches right and left.
        {
           flag2=1
           Set<i> temp=right;
           right=left;
           left=temp;
        }
        cout << "(";
        for (j=0; j<right.items-1; j++)
        {
            cout << right.arr[j] << ", ";
        }
        cout << right.arr[items];
        for (j=0; j<left.items; j++)
        {
            flag=0
            for (int k=0; k<right.items; k++)
            {
                if (left.arr[j] == right.arr[j])
                {
                    flag=1;
                    k=right.items;
                }
            }
            if(flag==0)
                cout << "," << left.arr[j];
        }
        cout << ")" << endl;
        if(flag2==1)//if the switch was made in the beginning it is reversed so that they return to there initial state.
        {
            Set<i> temp=left;
            left=right;
            right=temp;
        }
    }
    //- operator overloaded to give the difference of sets.
    friend void operator-(Set<i>& left, Set<i>& right)
    {
        int j,k,flag;
        cout << "(";
        for (j=0; j<left.items; j++)
        {
            flag = 0;
            for (k=0; k<right.items; k++)
            {
                if (left.arr[j] == right.arr[k])
                {
                    flag = 1;
                    k=right.items;
                }
            }
            if (flag != 1)
            {
                cout << left.arr[j];
                if (j< left.items-1)
                    cout << ",";
            }
        }
        cout << ")" << endl;
    }
    //== operator overloaded to return true if 2 sets are equal else return false.
    friend int operator==(Set<i>& left, Set<i>& right)
    {
        int j,k,flag=1;
        for (j=0; j<right.items; j++)
        {
            for (k=0; k<left.items; k++)
            {
                if (right.arr[j] != left.arr[k])
                {
                    flag = 0;
                    return flag;
                }
            }
        }
        for (j=0; j<left.items; j++)
        {
            for (k=0; k<right.items; k++)
            {
                if (left.arr[j] != right.arr[k])
                {
                    flag = 0;
                    return flag;
                }
            }
        }
        return flag;
    }
    // != operator overloaded to return true if they are not same else return false.
    friend int operator!=(Set<i>& left, Set<i>& right)
    {
        int k=(right==left);
        if(k==0)
            k=1;
        else
            k=0;
        return k;
    }
    //= operator is overloaded to copy the elements of right set to the left set.
    friend void operator=(Set<i>& left, Set<i>& right)
    {
        int j;
        left.items=right.items;
        left.cap=right.cap;
        delete left.arr;
        left.arr= new i[cap];
        for(j=0 ; j<right.items; j++)
        {
            left.arr[j]=right.arr[j];
        }
    }
    //+= operator stores the union of the 2 sets in the left set and also returns it.
    friend Set<i>& operator+=(Set<i>& left, Set<i>& right)
    {
        left = left + right;
        return left;
    }
    // < returns true if left is a subset of right
    friend int operator<(Set<i>& left, Set<i>& right)
    {
        int j,k,flag;
        for (j=0; j<left.items; j++)
        {
            flag=0
            for (k=0; k<right.items; k++)
            {
                if(left.arr[j] == right.arr[k])
                {
                    flag = 1;
                    k=right.items;
                }
            }
            if(flag==0)
                return flag;
        }
        return flag;
    }
    //outputs the content of the set.
    friend std::ostream& operator<<(std::ostream& os, const Set<i>& S)
    {
        int j;
        os << "(";
        for(j=0; j<S.items-1; j++)
            os << S.arr[j] << ",";
        os << S.arr[items-1];
        os << ")" << endl;
        return os;
    }
    // fills the empty spaces of the set so it is equal to the capacity of the set.
    friend std::istream& operator>>(std::istream& in, Set<i>& S)
    {
        int j;
        i value;
        for(j=S.items; j<S.cap; j++)
        {
            cout << j << ". element: ";
            in >> value;
            S.addElement(value);
        }
        return in;
    }

};
#endif
