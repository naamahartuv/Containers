#include <set>
#include <iostream>
#include <vector>


namespace itertools
{
template <typename T>
class powersetClass
{
public:
    powersetClass(T &a) : a(a)
    {
    }

private:
    T a;
    

    class iterator
    {

    private:
        T itr;

    public:
        iterator(T ptr) : itr(ptr)
        {
        }

        auto &operator*()
        {
             return itr;
        }

        // ++i;
        iterator &operator++()
        {
            itr++;
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            itr++;
            return tmp;
        }

        bool operator==(const iterator &rhs) const
        {
            //return itr == rhs.itr;
            return true;
        }

        bool operator!=(const iterator &rhs) const
        {
            //return itr != rhs.itr;
            return true;
        }
    }; // END OF CLASS ITERATOR

public:
    iterator begin()
    {
        return iterator{ a};
    }

    iterator end()
    {
        return iterator{a};
    }
};

template <typename T>
powersetClass<T> powerset(T a)
{
    return powersetClass<T> {a};
}
template <typename T>
 std :: ostream& operator<<(std :: ostream &os, const set<T> &t) {
        os <<  "{" ;
        for (auto i : t) {
            os << i << ",";
        } 
        os << "}"  ;
        return os;

    }

}; // namespace itertools