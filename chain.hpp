
namespace itertools
{
template <typename T1, typename T2>
class chainClass
{
private:
    const T1 a;
    const T2 b;

public:
    chainClass(const T1 &a, const T2 &b) : a(a), b(b)
    {
    }

    class iterator
    {

    private:
        decltype(a.begin()) beginA;
        decltype(a.end()) endA;
        decltype(b.begin()) beginB;

    public:
        iterator(const T1 &ptr1, const T2 &ptr2, const T1 &ptr3)
            : beginA(ptr1), beginB(ptr2), endA(ptr3)
        {
        }

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
        return iterator{NULL, NULL, b.end()};
    }
};

template <typename T1, typename T2>
chainClass<T1, T2> chain(T1 a, T2 b)
{
    return chainClass<T1, T2>{a, b};
}

}; // namespace itertools