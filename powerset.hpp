#include <set>
#include <iostream>
#include <vector>


namespace itertools
{
template <typename T>
class powersetClass
{
public:
    powersetClass(const T &a) : a(a)
    {
    }

private:
    T a;
    

    class iterator
    {

    private:
        T itr;

    public:
        iterator(const T &ptr) : itr(ptr)
        {
        }

        auto &operator*()
        {
            string s ="";
             return s;
        }

        // ++i;
        iterator &operator++()
        {
            //itr++;
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            //itr++;
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
            return false;
        }
    }; // END OF CLASS ITERATOR

public:
    iterator begin() const
    {
        return iterator{ a};
    }

    iterator end() const
    {
        return iterator{ a};
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