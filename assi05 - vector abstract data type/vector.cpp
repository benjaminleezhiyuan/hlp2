/*!*****************************************************************************
 \file vector.cpp
 \author Sun Wei Hao
 \par DP email: s.weihao@digipen.edu
 \par Course: HLP2
 \par Section: A
 \par Programming Assignment #5
 \date 24-02-2023
 \brief This file contains the implemention of the functions used of classes vector in vector.hpp  

*******************************************************************************/

#include "vector.hpp"
// make sure to have a file-level Doxygen documentation block!!!
// read the specs to know which standard library headers cannot be included!!!

namespace hlp2
{
    // initallize everythig to zero
    vector::vector() : sz{0}, space{0}, allocs{0}, data{nullptr} {}
    // single-argument conversion constructor that allocates memory for n elements
    vector::vector(size_type n) : sz{n}, space{n}, allocs{1}, data{new value_type[n]} {}
    // single-argument conversion constructor that allocates memory to store values
    vector::vector(std::initializer_list<int> rhs) : sz{rhs.size()}, space{rhs.size()}, allocs{1}, data{new value_type[rhs.size()]}
    {
        std::copy(rhs.begin(), rhs.end(), data);
    }
    // copy constructor
    vector::vector(vector const &rhs) : sz{rhs.sz}, space{rhs.sz}, allocs{1}, data{new value_type[rhs.sz]}
    {
        std::copy(rhs.begin(), rhs.end(), data);
    }
    // deconstructor
    vector::~vector()
    {
        delete[] data;
    }

    // ==================
    // Overload operator=
    // ==================
    vector &vector::operator=(vector const &rhs)
    {
        vector tmp{rhs};
        std::swap(sz, tmp.sz);
        std::swap(space, tmp.space);
        ++allocs;
        std::swap(data, tmp.data);
        return *this;
    }
    vector &vector::operator=(std::initializer_list<int> rhs)
    {
        vector temp{rhs};
        std::swap(sz, temp.sz);
        std::swap(space, temp.space);
        ++allocs;
        std::swap(data, temp.data);

        return *this;
    }

    // ==================
    // Overload operator[]
    // ==================
    vector::reference vector::operator[](size_type index)
    {
        // return const_cast<vector::reference>(static_cast<vector const&>(*this)[index]);
        return *(data + index);
    }
    vector::const_reference vector::operator[](size_type index) const
    {
        return *(data + index);
    }
    /***************************************************************************/
    /*!
    \brief
    stores value at the back of the vector array

    \param value
    value to be stored at the end of the vector array

      */
    /**************************************************************************/
    void vector::push_back(value_type value)
    {
        //if vector memory space == 0
        if (space == 0)
        {
            //make one memory block to store value
            this->reserve(1);
        }
        //if there is exisiting memory
        if (sz == space)
        {
            //double the memory space and store value at last empty memory location
            this->reserve(2 * space);
        }
        //store value in last empty memory location
        data[sz] = value;
        //increment last empty memory location after storing
        ++sz;
    }

    /***************************************************************************/
    /*!
    \brief
    new memory for the vector array

    \param value
    the size of the new-ed memory
      */
    /**************************************************************************/
    void vector::reserve(size_type newsize)
    {
        //check if we need to new more memory
        if (newsize > space)
        {
            //dynamically allocate memory
            pointer newdata = new value_type[newsize];
            //copy old elements into the new memory
            std::copy(begin(), end(), newdata);
            //delete old memory
            delete[] data;
            //change data pointer pointing at old memory to new memory
            data = newdata;
            //update space
            space = newsize;
            //increment allocs
            ++allocs;
        }
    }

    /***************************************************************************/
    /*!
    \brief
    new memory for the vector array

    \param value
    the size of the new-ed memory
      */
    /**************************************************************************/
    void vector::resize(size_type newsize)
    {
        //dynamically allocate memory
        reserve(newsize);
        //iterate over the whole new array
        for (size_t i = sz; i < newsize; ++i)
        {
            //zero out array
            data[i] = 0;
        }
        //update last empty memory location
        sz = newsize;
    }

    /***************************************************************************/
    /*!
    \brief
    check if (this)current object's data is empty

    \return bool
    true - vector array is empty
    false - vector array is not empty
      */
    /**************************************************************************/
    bool vector::empty() const
    {
        return data == nullptr ? true : false;
    }

    /***************************************************************************/
    /*!
    \brief
    check last empty memory location

    \return vector::size_type
    (this)current object's sz
      */
    /**************************************************************************/
    vector::size_type vector::size() const
    {
        return sz;
    }

    /***************************************************************************/
    /*!
    \brief
    check the max memory space

    \return vector::size_type
    (this)current object's space
      */
    /**************************************************************************/
    vector::size_type vector::capacity() const
    {
        return space;
    }

    /***************************************************************************/
    /*!
    \brief
    check the number of "growths"

    \return vector::size_type
    (this)current object's allocs
      */
    /**************************************************************************/
    vector::size_type vector::allocations() const
    {
        return allocs;
    }

    /***************************************************************************/
    /*!
    \brief
    The start of an array

    \return vector::pointer
    pointer to the start of an array
      */
    /**************************************************************************/
    vector::pointer vector::begin()
    {
        return data;
    }

    /***************************************************************************/
    /*!
    \brief
    The end of an array

    \return vector::pointer
    pointer to the end of an array
      */
    /**************************************************************************/
    vector::pointer vector::end()
    {
        return (data + sz);
    }

    /***************************************************************************/
    /*!
    \brief
    The start of an array

    \return vector::const_pointer
    const pointer to the start of an array
      */
    /**************************************************************************/
    vector::const_pointer vector::begin() const
    {
        return data;
    }

    /***************************************************************************/
    /*!
    \brief
    The end of an array

    \return vector::const_pointer
    const pointer to the end of an array
      */
    /**************************************************************************/
    vector::const_pointer vector::end() const
    {
        return (data + sz);
    }

    /***************************************************************************/
    /*!
    \brief
    The start of an array

    \return vector::const_pointer
    const pointer to the end of an array
      */
    /**************************************************************************/
    vector::const_pointer vector::cbegin() const
    {
        return data;
    }

    /***************************************************************************/
    /*!
    \brief
    The end of an array

    \return vector::const_pointer
    const pointer to the end of an array
      */
    /**************************************************************************/
    vector::const_pointer vector::cend() const
    {
        return (data + sz);
    }

}