namespace itertools
{

template <typename T>
class rangeClass
{
public:
    rangeClass(T &a, T &b) : a(a), b(b)
    {
    }

private:
    T a;
    T b;

    class iterator
    {

    private:
        T itr;

    public:
        iterator(T ptr) : itr(ptr)
        {
        }

        T &operator*()
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
            return itr == rhs.itr;
        }

        bool operator!=(const iterator &rhs) const
        {
            return itr != rhs.itr;
        }
    }; // END OF CLASS ITERATOR

public:
    iterator begin()
    {
        return iterator{a};
    }

    iterator end()
    {
        return iterator{b};
    }
};

template <typename T>
rangeClass<T> range(T a, T b)
{
    return rangeClass<T>{a, b};
}

}; // namespace itertools