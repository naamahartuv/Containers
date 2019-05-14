


namespace itertools
{
template <typename T1, typename T2>
class chainClass
{
public:
    chainClass(const T1 &a,const T2 &b) : a(a), b(b)
    {
    }

private:
    T1 a;
    T2 b;

    class iterator
    {

    private:
        decltype(a.begin()) beginA;
        decltype(a.end()) endA;
        decltype(b.begin()) beginB;

    public:
        iterator(const decltype(a.begin()) &ptr1,const decltype(a.end()) &ptr2,const decltype(b.begin()) ptr3) : beginA(ptr1), endA(ptr2), beginB(ptr3)
        {
        }

        auto &operator*()
        {
            
            if(beginA==endA){
                return *beginB;
            }
            return *beginA;
        }

        // ++i;
        iterator &operator++()
        {
            if(beginA == endA){
                beginB++;
            }
            else{
             beginA++;   
            }
            

            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            if(beginA == endA){
                beginB++;
            }
            else{
              beginA++;  
            }
            
            return tmp;
        }

        bool operator==(const iterator &rhs) const
        {
            if(beginA == endA){
                return beginB == rhs.beginB;
            }
            
            
            return beginA == rhs.beginA;
        }

        bool operator!=(const iterator &rhs) const
        {
            if(beginA == endA){
                return beginB != rhs.beginB;
            }
            
            
            return beginA != rhs.beginA;
        }
    }; // END OF CLASS ITERATOR

public:
    iterator begin() const
    {
        return iterator{a.begin() , a.end(), b.begin()};
    }

    iterator end() const
    {
        return iterator{NULL, NULL, b.end()} ;
    }
};

template <typename T1, typename T2>
chainClass<T1, T2> chain(T1 a, T2 b)
{
    return chainClass<T1, T2>{a, b};
}

}; // namespace itertools