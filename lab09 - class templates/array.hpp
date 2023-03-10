//-------------------------------------------------------------------------
#ifndef ARRAY_HPP_
#define ARRAY_HPP_
//-------------------------------------------------------------------------

#include <cstddef> // for size_t
// Don't include <array> [remove this line!!!]
// Otherwise, your submission will not compile!!!

namespace hlp2
{

    // Define class template Array<T,N> and document each member function

    template <typename T, size_t N>
    class Array
    {
    public:
        using value_type = T;
        using size_type = size_t;
        using pointer = value_type *;
        using iterator = value_type *;
        using reference = value_type &;
        using const_reference = const value_type &;
        using const_pointer = const value_type *;
        using const_iterator = const value_type *;

    public:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cbegin();
        const_iterator cend();
        reference front();
        const_reference front();
        reference back();
        const_reference back();
        reference operator[](size_type index);
        const_reference operator[](size_type index);
        bool empty const();
        pointer data();
        const_pointer data();
        size_type size const();
        void fill(const_reference value);
        void swap(Array<T, N> &other) noexcept(std::is_nothrow_swappable_v<value_type>);

    private:
        template <typename T>
        struct ValueWithComment
        {
            T value;
            std::string comment;
        };
        value_type data[N];
    };
    // Declare and document non-member functions
    template <typename T, size_t N>
    void swap(Array<T, N> &lhs, Array<T, N> &rhs) noexcept(noexcept(lhs.swap(rhs)));

    template <typename T, size_t N>
    bool operator==(const Array<T, N> &lhs, const Array<T, N> &rhs);

    template <typename T, size_t N>
    bool operator!=(const Array<T, N> &lhs, const Array<T, N> &rhs);

    template <typename T, size_t N>
    bool operator>(const Array<T, N> &lhs, const Array<T, N> &rhs);

    template <typename T, size_t N>
    bool operator<(const Array<T, N> &lhs, const Array<T, N> &rhs);

// EVERY member and non-member function must be defined
// in separate file array.tpp
#include "array.tpp"

} // end namespace hlp2

#endif // end ARRAY_HPP_
