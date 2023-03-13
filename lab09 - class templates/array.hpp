/*!******************************************************************
 * \file      array.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 09
 * \date      12-03-2023
 *
 * \brief     Contains clone of std::array 
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
        /*!******************************************************************
         * \brief  Construct a new Array object
         *
         * \param values
         * the value to initialize array 
         *********************************************************************/
        Array(std::initializer_list<T> values)
        {
            if (values.size() != N)
            {
                throw std::invalid_argument("Wrong number of arguments");
            }
            std::copy(values.begin(), values.end(), elements);
        }

        /*!******************************************************************
         * \brief  Construct a new Array object
         *
         *********************************************************************/
        Array() : elements{} {}

        /*!******************************************************************
         * \brief Returns iterator to first element of the array
         *
         * \return iterator
         *********************************************************************/
        iterator begin();

        /*!******************************************************************
         * \brief returns const iterator to first element of the array
         *
         * \return const_iterator
         *********************************************************************/
        const_iterator begin() const;

        /*!******************************************************************
         * \brief returns iterator to the last element of the array
         *
         * \return iterator
         *********************************************************************/
        iterator end();

        /*!******************************************************************
         * \brief returns const iterator to the last element of the array
         *
         * \return const_iterator
         *********************************************************************/
        const_iterator end() const;

        /*!******************************************************************
         * \brief returns const iterator to first element of the array
         *
         * \return const_iterator
         *********************************************************************/
        const_iterator cbegin() const;

        /*!******************************************************************
         * \brief returns const iterator to last element of the array
         *
         * \return const_iterator
         *********************************************************************/
        const_iterator cend() const;

        /*!******************************************************************
         * \brief returns reference to the first element in the container
         *
         * \return reference
         *********************************************************************/
        reference front();

        /*!******************************************************************
         * \brief returns const reference to the first element in the container
         *
         * \return const_reference
         *********************************************************************/
        const_reference front() const;

        /*!******************************************************************
         * \brief returns reference to the last element in the container
         *
         * \return reference
         *********************************************************************/
        reference back();

        /*!******************************************************************
         * \brief returns const reference to the last element in the container
         *
         * \return const_reference
         *********************************************************************/
        const_reference back() const;

        /*!******************************************************************
         * \brief returns reference to the element at position indicated by index parameter
         *
         * \param index
         * \return reference
         *********************************************************************/
        reference operator[](size_type index);

        /*!******************************************************************
         * \brief returns const reference to element at position indicated by index param
         *
         * \param index
         * \return const_reference
         *********************************************************************/
        const_reference operator[](size_type index) const;

        /*!******************************************************************
         * \brief returns true if array is empty else return false
         *
         * \return true
         * \return false
         *********************************************************************/
        bool empty() const;

        /*!******************************************************************
         * \brief returns pointer to the first element in the array
         *
         * \return pointer
         *********************************************************************/
        pointer data();

        /*!******************************************************************
         * \brief returns const pointer to the first element in the array
         *
         * \return const_pointer
         *********************************************************************/
        const_pointer data() const;

        /*!******************************************************************
         * \brief returns the number of elements in the array
         *
         * \return size_type
         *********************************************************************/
        size_type size() const;

        /*!******************************************************************
         * \brief fills array with value param
         *
         * \param value
         *********************************************************************/
        void fill(const_reference value);

        /*!******************************************************************
         * \brief swap contents of array with another array
         *
         * \param other
         *********************************************************************/
        void swap(Array<T, N> &other) noexcept(std::is_nothrow_swappable_v<value_type>);

    private:
        value_type elements[N];
    };
    // Declare and document non-member functions

    /*!******************************************************************
     * \brief swap contents of lhs array with rhs array
     *
     * \param lhs
     * \param rhs
     *********************************************************************/
    template <typename T, size_t N>
    void swap(Array<T, N> &lhs, Array<T, N> &rhs) noexcept(noexcept(lhs.swap(rhs)));

    /*!******************************************************************
     * \brief overload operator== for Array
     *
     * \param lhs
     * \param rhs
     * \return true
     * \return false
     *********************************************************************/
    template <typename T, size_t N>
    bool operator==(const Array<T, N> &lhs, const Array<T, N> &rhs);

    /*!******************************************************************
     * \brief overload operator!= for Array
     *
     * \param lhs
     * \param rhs
     * \return true
     * \return false
     *********************************************************************/
    template <typename T, size_t N>
    bool operator!=(const Array<T, N> &lhs, const Array<T, N> &rhs);

    /*!******************************************************************
     * \brief overload operator> for Array
     *
     * \param lhs
     * \param rhs
     * \return true
     * \return false
     *********************************************************************/
    template <typename T, size_t N>
    bool operator>(const Array<T, N> &lhs, const Array<T, N> &rhs);

    /*!******************************************************************
     * \brief overload operatoc< for Array
     *
     * \param lhs
     * \param rhs
     * \return true
     * \return false
     *********************************************************************/
    template <typename T, size_t N>
    bool operator<(const Array<T, N> &lhs, const Array<T, N> &rhs);

    // EVERY member and non-member function must be defined
    // in separate file array.tpp

} // end namespace hlp2
#include "array.tpp"
#endif // end ARRAY_HPP_
