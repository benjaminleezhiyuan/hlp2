/*!******************************************************************
 * \file      array.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 09
 * \date      12-03-2023
 * 
 * \brief  
 *********************************************************************/

//-------------------------------------------------------------------------
#ifndef ARRAY_HPP_
#define ARRAY_HPP_
//-------------------------------------------------------------------------

#include <cstddef> // for size_t
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
        Array(std::initializer_list<T> values)
        {
            if (values.size() != N)
            {
                throw std::invalid_argument("Wrong number of arguments");
            }
            std::copy(values.begin(), values.end(), elements);
        }
        Array() : elements{} {}
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        reference operator[](size_type index);
        const_reference operator[](size_type index) const;
        bool empty() const;
        pointer data();
        const_pointer data() const;
        size_type size() const;
        void fill(const_reference value);
        void swap(Array<T, N> &other) noexcept(std::is_nothrow_swappable_v<value_type>);

    private:
        value_type elements[N];
    };
    //Declare and document non-member functions
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

} // end namespace hlp2
#include "array.tpp"
#endif // end ARRAY_HPP_
