namespace itertools
{

template <typename T>
class rangeClass
{
public:
    rangeClass(const T &a,const T &b) : a(a), b(b)
    {
    }

private:
     const T a;
     const T b;

    class iterator
    {

    private:
        T itr;

    public:
        iterator(const T &ptr) : itr(ptr)
        {
        }

        const T &operator*() const
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
    iterator begin() const
    {
        return iterator{a};
    }

    iterator end() const
    {
        return iterator{b};
    }
};

template <typename T>
rangeClass<T> range(T a, T b)
{
    return rangeClass<T>{a, b};
}

} // namespace itertools


