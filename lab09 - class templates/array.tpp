/*!******************************************************************
 * \file      array.tpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 09
 * \date      12-03-2023
 * 
 * \brief     Contains definitions for the functions needed in clone of
 *            std::array
 *********************************************************************/
#include "array.hpp"

namespace hlp2
{
    template <typename T, size_t N>
    typename Array<T, N>::iterator Array<T, N>::begin()
    {
        return elements;
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_iterator Array<T, N>::begin() const
    {
        return elements;
    }

    template <typename T, size_t N>
    typename Array<T, N>::iterator Array<T, N>::end()
    {
        return elements + N;
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_iterator Array<T, N>::end() const
    {
        return elements + N;
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_iterator Array<T, N>::cbegin() const
    {
        return elements;
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_iterator Array<T, N>::cend() const
    {
        return elements + N;
    }

    template <typename T, size_t N>
    typename Array<T, N>::reference Array<T, N>::front()
    {
        return elements[0];
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_reference Array<T, N>::front() const
    {
        return elements[0];
    }

    template <typename T, size_t N>
    typename Array<T, N>::reference Array<T, N>::back()
    {
        return elements[N - 1];
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_reference Array<T, N>::back() const
    {
        return elements[N - 1];
    }

    template <typename T, size_t N>
    typename Array<T, N>::reference Array<T, N>::operator[](size_type index)
    {
        return elements[index];
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_reference Array<T, N>::operator[](size_type index) const
    {
        return elements[index];
    }

    template <typename T, size_t N>
    bool Array<T, N>::empty() const
    {
        return N == 0;
    }

    template <typename T, size_t N>
    typename Array<T, N>::pointer Array<T, N>::data()
    {
        return elements;
    }

    template <typename T, size_t N>
    typename Array<T, N>::const_pointer Array<T, N>::data() const
    {
        return elements;
    }

    template <typename T, size_t N>
    typename Array<T, N>::size_type Array<T, N>::size() const
    {
        return N;
    }

    template <typename T, size_t N>
    void Array<T, N>::fill(const_reference value)
    {
        std::fill(begin(), end(), value);
    }

    template <typename T, size_t N>
    void Array<T, N>::swap(Array<T, N> &other) noexcept(std::is_nothrow_swappable_v<value_type>)
    {
        std::swap_ranges(begin(), end(), other.begin());
    }

    template <typename T, size_t N>
    void swap(Array<T, N> &lhs, Array<T, N> &rhs) noexcept(noexcept(lhs.swap(rhs)))
    {
        lhs.swap(rhs);
    }

    template <typename T, size_t N>
    bool operator==(const Array<T, N> &lhs, const Array<T, N> &rhs)
    {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <typename T, size_t N>
    bool operator!=(const Array<T, N> &lhs, const Array<T, N> &rhs)
    {
        return !(lhs == rhs);
    }

    template <typename T, size_t N>
    bool operator>(const Array<T, N> &lhs, const Array<T, N> &rhs)
    {
        return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template <typename T, size_t N>
    bool operator<(const Array<T, N> &lhs, const Array<T, N> &rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

}