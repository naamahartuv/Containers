
namespace itertools
{
template <typename T1, typename T2>
class chainClass
{
private:
    const T1 a;
    const T2 b;

    typedef decltype(a.begin()) T1ITER;
    typedef decltype(b.begin()) T2ITER;

public:
    chainClass(const T1 &a, const T2 &b) : a(a), b(b)
    {
    }

    class iterator
    {

    private:
        T1ITER beginA;
        T1ITER endA;
        T2ITER beginB;

    public:
        iterator(const T1ITER &ptr1, const T1ITER &ptr3, const T2ITER &ptr2)
            : beginA(ptr1), endA(ptr3), beginB(ptr2)
        {
        }

        iterator (const T2ITER &ptr1): beginB(ptr1), beginA(NULL), endA(NULL){}

        

        const auto &operator*() const
        {

            if (beginA == endA)
            {
                return *beginB;
            }
            return *beginA;
        }

        // ++i;
        iterator &operator++()
        {
            if (beginA == endA)
            {
                beginB++;
            }
            else
            {
                beginA++;
            }

            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            if (beginA == endA)
            {
                beginB++;
            }
            else
            {
                beginA++;
            }

            return tmp;
        }

        bool operator==(const iterator &rhs) const
        {
            if (beginA == endA)
            {
                return beginB == rhs.beginB;
            }

            return beginA == rhs.beginA;
        }

        bool operator!=(const iterator &rhs) const
        {
            if (beginA == endA)
            {
                return beginB != rhs.beginB;
            }

            return beginA != rhs.beginA;
        }
    }; // END OF CLASS ITERATOR

public:
    iterator begin() const
    {
        return iterator{a.begin(), a.end(), b.begin()};
    }

    iterator end() const
    {
        return iterator{ b.end()};
    }
};

template <typename T1, typename T2>
chainClass<T1, T2> chain(T1 a, T2 b)
{
    return chainClass<T1, T2>{a, b};
}

}; // namespace itertools