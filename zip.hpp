#include <utility> 
#include <iostream>
#include <ostream>
using std::pair;


namespace itertools
{
template <typename T1, typename T2>
class zipClass
{
public:
    zipClass(const T1 &a,const T2 &b) : a(a), b(b)
    {
    }

private:
     const T1 a;
     const T2 b;

    typedef decltype(a.begin()) T1ITER;
    typedef decltype(b.begin()) T2ITER;

    class iterator
    {

    private:
        T1ITER beginA;
        T2ITER beginB;

    public:
        iterator(const T1ITER &ptr1, const T2ITER &ptr2) : beginA(ptr1),  beginB(ptr2)
        {
        }

        auto operator*()
        {
            
            return pair(*beginA , *beginB);
        }

        // ++i;
        iterator &operator++()
        {
            beginA++;
            beginB++;

            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            beginA++;
            beginB++;

            return tmp;
        }

        bool operator==(const iterator &rhs) const
        {
            
            return (beginA == rhs.beginA && beginB == rhs.beginB);
        }

        bool operator!=(const iterator &rhs) const
        {
            return (beginA != rhs.beginA && beginB != rhs.beginB);
        }
    }; // END OF CLASS ITERATOR
public:
    iterator begin() const
    {
        return iterator{a.begin(), b.begin()};
    }

    iterator end() const
    {
        return iterator{a.end(), b.end()};
    }
};

template <typename T1, typename T2>
zipClass<T1, T2> zip(T1 a, T2 b)
{
    return zipClass<T1, T2>(a, b);
}

template <typename T1, typename T2>
 std :: ostream& operator<<(std :: ostream &os, const std :: pair<T1, T2>& pair) {
        os <<  pair.first << "," << pair.second;
        return os;

    }

} // namespace itertools