/*!******************************************************************
 * \file      vct.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Assignment 06
 * \date      14-03-2023
 * 
 * \brief     File contains functions to help build our own version of std::vector - the
 *            most useful container in the standard library
 *********************************************************************/
////////////////////////////////////////////////////////////////////////////////
#ifndef VCT_HPP
#define VCT_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>
// read the specs to know which standard library headers cannot be included!!!
#include <algorithm>
namespace hlp2
{
    //syntax for creating template for a class 
    template <typename T>
    class vector
    {
    public:
        // @todo: using declarations required!!!
        // types to declare: size_type, value_type,
        using size_type = size_t;
        using value_type = T;
        using pointer = value_type *;
        using reference = value_type &;
        using const_reference = const value_type &;
        using const_pointer = const value_type *;
        // reference, const_reference, pointer, const_pointer

    public:
        // @todo: declare default constructor
        /*!***********************************************************************
        \brief Construct a new vector::vector object
        *************************************************************************/
        vector(); // default ctor

        /*!***********************************************************************
        \brief Construct a new vector::vector object
        Single-argument conversion constructor that allocates memory for n elements with each
        element initialized to 0
        \param n
        num of elements
        *************************************************************************/
        // explicit keyword prevents implicit conversion from happening
        explicit vector(size_type n); // non-default, conversion ctor

        /*!***********************************************************************
        \brief Construct a new vector::vector object
        Another single-argument conversion constructor that allocates memory to store values in an
        initializer_list<int>
        \param rhs
        *************************************************************************/
       
        vector(std::initializer_list<T> rhs); // non-default, conversion ctor

        // @todo: declare non-default ctor for std::initializer_list<int>

        // @todo: declare copy ctor
        /*!***********************************************************************/
        //\brief Construct a new vector::vector object
        //Copy constructor
        //\param rhs
        /*************************************************************************/

        vector(vector const &rhs);

        // @todo: declare destructor
        /*!***********************************************************************
        \brief
        Destroy the vector::vector object
        *************************************************************************/
        ~vector();

        // @todo: declare copy assignment operator for assignment with vector object
        /**
        \brief Copy assignment operator.
        Creates a copy of the right-hand side vector and assigns it to the left-hand side vector.
        \param rhs The vector to be copied and assigned.
        \return A reference to the modified left-hand side vector.
        */
        vector &operator=(vector const &);

        // @todo: declare copy assignment operator for std::initializer_list<int>
        /**
        \brief Copy assignment operator overload for std::initializer_list<int>.
        Creates a vector from the given initializer list and assigns it to the left-hand side vector.
        \param rhs The initializer list to be copied and assigned.
        \return A reference to the modified left-hand side vector.
        \todo Declare copy assignment operator for std::initializer_list<int>.
        */
        vector &operator=(std::initializer_list<T> rhs);

        // @todo: declare overloaded subscript operator and overload subscript
        /**
        \brief Overloaded subscript operator.
        Provides access to the element at the specified index in the vector.
        Returns a reference to the element at the specified location.
        \param index The index of the element to access.
        \return A reference to the element at the specified index.
        \todo Declare overloaded subscript operator and overload subscript.
        */
        reference operator[](size_type index);

        /**
        \brief Const overloaded subscript operator.
        Provides read-only access to the element at the specified index in the vector.
        Returns a const reference to the element at the specified location.
        \param index The index of the element to access.
        \return A const reference to the element at the specified index.
        */
        const_reference operator[](size_type index) const;
        // operator for const objects

        // i'am declaring push_back(), reserve(), and resize()
        /***************************************************************************/
        /*!
        \brief
        stores value at the back of the vector array

        \param value
        value to be stored at the end of the vector array

          */
        /**************************************************************************/
        void push_back(value_type value);

        /***************************************************************************/
        /*!
        \brief
        Reserve new memory for the vector array.

        \param value
        the size of the new-ed memory
          */
        /**************************************************************************/
        void reserve(size_type newsize);

        /***************************************************************************/
        /*!
        \brief
        Resize the vector array.

        \param value
        the size of the new-ed memory
          */
        /**************************************************************************/
        void resize(size_type newsize);

        // @todo: declare empty()
        // @todo: declare size()
        // @todo: declare capacity()
        /***************************************************************************/
        /*!
        \brief
        Check if the vector array is empty.

        \return bool
        true - vector array is empty
        false - vector array is not empty
          */
        /**************************************************************************/
        bool empty() const; // is container empty?

        /***************************************************************************/
        /*!
        \brief
        check last empty memory location

        \return vector::size_type
        (this)current object's sz
          */
        /**************************************************************************/
        size_type size() const; // what is sz?

        /***************************************************************************/
        /*!
        \brief
        check the max memory space

        \return vector::size_type
        (this)current object's space
          */
        /**************************************************************************/
        size_type capacity() const; // what is space?

        /***************************************************************************/
        /*!
        \brief
        check the number of "growths"

        \return vector::size_type
        (this)current object's allocs
          */
        /**************************************************************************/
        size_type allocations() const; // how many allocations or "growths"?

        // @todo: declare iterators [described in spec]
        /***************************************************************************/
        /*!
        \brief
        The start of an array

        \return vector::pointer
        pointer to the start of an array
          */
        /**************************************************************************/
        pointer begin(); // pointer to first element

        /***************************************************************************/
        /*!
        \brief
        The end of an array

        \return vector::pointer
        pointer to the end of an array
          */
        /**************************************************************************/
        pointer end(); // pointer to one past last element

        /***************************************************************************/
        /*!
        \brief
        The start of an array

        \return vector::const_pointer
        const pointer to the start of an array
          */
        /**************************************************************************/
        const_pointer begin() const;

        /***************************************************************************/
        /*!
        \brief
        The end of an array

        \return vector::const_pointer
        const pointer to the end of an array
          */
        /**************************************************************************/
        const_pointer end() const;

        /***************************************************************************/
        /*!
        \brief
        The start of an array

        \return vector::const_pointer
        const pointer to the end of an array
          */
        /**************************************************************************/
        const_pointer cbegin() const;

        /***************************************************************************/
        /*!
        \brief
        The end of an array

        \return vector::const_pointer
        const pointer to the end of an array
          */
        /**************************************************************************/
        const_pointer cend() const;

        /***************************************************************************/
        /*!
        \brief
        Deletes the last element in the vector
        */
        /**************************************************************************/
        void pop_back();

        /***************************************************************************/
        /*!
        \brief
        Swaps the current vector with the given vector

        \param rhs
        The other given vector
        */
        /**************************************************************************/
        void swap(vector &rhs);

        

    private:
        size_type sz;     // the number of elements in the array
        size_type space;  // the allocated size (in terms of elements) of the array
        size_type allocs; // number of times space has been updated
        pointer data;     // the dynamically allocated array
    };
    /***************************************************************************/
        /*!
        \brief
        Deletes the last element in the vector
        */
        /**************************************************************************/
        // removes the last element in the vector, effectively reducing
        // the container size by one.
        template <typename T>
        void vector<T>::pop_back()
        {
            sz--;
        }


        /***************************************************************************/
        /*!
        \brief
        Swaps the current vector with the given vector

        \param rhs
        The other given vector
        */
        /**************************************************************************/
        template <typename T>
        void vector<T>::swap(vector<T> &rhs)
        {
            std::swap(allocs, rhs.allocs);
            std::swap(space, rhs.space);
            std::swap(sz, rhs.sz);
            std::swap(data, rhs.data);
        }
        template <typename T>
        vector<T>::vector()
        {
            sz = 0;         // the number of elements in the array
            space = 0;      // the allocated size (in terms of elements) of the array
            allocs = 0;     // number of times space has been updated
            data = nullptr; // the dynamically allocated array
        }
        /*!***********************************************************************
        \brief Construct a new vector::vector object
        Single-argument conversion constructor that allocates memory for n elements with each
        element initialized to 0
        \param n
        num of elements
        *************************************************************************/
        template <typename T>    
        vector<T>::vector(size_type n) // non-default, conversion ctor
        {
            // takes in n num of variables and initialise them to 0
            sz = n;
            space = n;
            allocs = 1;
            data = new value_type[n];
            for (size_type i = 0; i < n; ++i)
            {   
                T t{};
                data[i] = t;
            }
        }

        /*!***********************************************************************
        \brief Construct a new vector::vector object
        Another single-argument conversion constructor that allocates memory to store values in an
        initializer_list<int>
        \param rhs
        *************************************************************************/
        // how does an initialiser list work?
        template <typename T>
        vector<T>::vector(std::initializer_list<T> rhs) // non-default, conversion ctor
        {
            sz = rhs.size();
            space = rhs.size();
            allocs = 1;
            data = new value_type[rhs.size()];

            // what does this line below do? is this essential for initialiser lists?
            std::copy(rhs.begin(), rhs.end(), data);
        }

        /*!***********************************************************************
        \brief Construct a new vector::vector object
        Copy constructor
        \param rhs
        *************************************************************************/
        template <typename T>
        vector<T>::vector(vector<T> const &rhs) // copy ctor
        {
            sz = rhs.sz;
            space = rhs.sz;
            data = new value_type[rhs.sz];
            allocs = 1;

            // what is the difference between this for loop and std::copy
            std::copy(rhs.begin(), rhs.end(), data);
        }

        /*!***********************************************************************
        \brief
        Destroy the vector::vector object
        *************************************************************************/
        template <typename T>
        vector<T>::~vector()
        {
            delete[] data;
        }

        // @todo: declare copy assignment operator for assignment with vector object
        /**
        \brief Copy assignment operator.
        Creates a copy of the right-hand side vector and assigns it to the left-hand side vector.
        \param rhs The vector to be copied and assigned.
        \return A reference to the modified left-hand side vector.
        */
        template <typename T>
        vector<T> &vector<T>::operator=(vector const &rhs)
        {
            vector temp{rhs};
            std::swap(sz, temp.sz);
            std::swap(space, temp.space);
            ++allocs;
            std::swap(data, temp.data);
            return *this;
        }
        /**
        \brief Copy assignment operator overload for std::initializer_list<int>.
        Creates a vector from the given initializer list and assigns it to the left-hand side vector.
        \param rhs The initializer list to be copied and assigned.
        \return A reference to the modified left-hand side vector.
        \todo Declare copy assignment operator for std::initializer_list<int>.
        */
        template <typename T>
        vector<T> &vector<T>::operator=(std::initializer_list<T> rhs)
        {
            vector temp{rhs};
            std::swap(sz, temp.sz);
            std::swap(space, temp.space);
            ++allocs;
            std::swap(data, temp.data);
            return *this;
        }
        /**
        \brief Overloaded subscript operator.
        Provides access to the element at the specified index in the vector.
        Returns a reference to the element at the specified location.
        \param index The index of the element to access.
        \return A reference to the element at the specified index.
        \todo Declare overloaded subscript operator and overload subscript.
        */
        template <typename T>
        typename vector<T>::reference vector<T>::operator[](size_type index)
        {
            return *(data + index);
        }
        /**

        \brief Const overloaded subscript operator.
        Provides read-only access to the element at the specified index in the vector.
        Returns a const reference to the element at the specified location.
        \param index The index of the element to access.
        \return A const reference to the element at the specified index.
        */
        template <typename T>
        typename vector<T>::const_reference vector<T>::operator[](size_type index) const
        {
            return *(data + index);
        }
        // operator for const objects

        // i'am declaring push_back(), reserve(), and resize()
        /***************************************************************************/
        /*!
        \brief
        stores value at the back of the vector array

        \param value
        value to be stored at the end of the vector array

          */
        /**************************************************************************/
        template <typename T>
        void vector<T>::push_back(value_type value)
        {
            // if vector memory space == 0
            if (space == 0)
            {
                // make one memory block to store value
                this->reserve(1);
            }
            // if there is exisiting memory
            if (sz == space)
            {
                // double the memory space and store value at last empty memory location
                this->reserve(2 * space);
            }
            // store value in last empty memory location
            data[sz] = value;
            // increment last empty memory location after storing
            ++sz;
        }

        /***************************************************************************/
        /*!
        \brief
        Reserve new memory for the vector array.

        \param value
        the size of the new-ed memory
          */
        /**************************************************************************/
        template <typename T>
        void vector<T>::reserve(size_type newsize)
        {
            // check if we need to new more memory
            if (newsize > space)
            {
                // dynamically allocate memory
                pointer newdata = new value_type[newsize];
                // copy old elements into the new memory
                std::copy(begin(), end(), newdata);
                // delete old memory
                delete[] data;
                // change data pointer pointing at old memory to new memory
                data = newdata;
                // update space
                space = newsize;
                // increment allocs
                ++allocs;
            }
        }

        /***************************************************************************/
        /*!
        \brief
        Resize the vector array.

        \param value
        the size of the new-ed memory
          */
        /**************************************************************************/
        template <typename T>
        void vector<T>::resize(size_type newsize)
        {
            // dynamically allocate memory
            reserve(newsize);
            // iterate over the whole new array
            for (size_t i = sz; i < newsize; ++i)
            {   
                T t{};
                // zero out array of type t
                data[i] = t;
            }
            // update last empty memory location
            sz = newsize;
        }

        /***************************************************************************/
        /*!
        \brief
        Check if the vector array is empty.

        \return bool
        true - vector array is empty
        false - vector array is not empty
          */
        /**************************************************************************/
        template <typename T>
        bool vector<T>::empty() const
        {
                if (sz)
    {
        return false;
    }

    return true;
            //return sz != nullptr ? true : false;
        }

        /***************************************************************************/
        /*!
        \brief
        check last empty memory location

        \return vector::size_type
        (this)current object's sz
          */
        /**************************************************************************/
        template <typename T>
        typename vector<T>::size_type vector<T>::size() const
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
        template <typename T>
        typename vector<T>::size_type vector<T>::capacity() const
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
        template <typename T>
        typename vector<T>::size_type vector<T>::allocations() const
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
        template <typename T>
        typename vector<T>::pointer vector<T>::begin()
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
        template <typename T>
        typename vector<T>::pointer vector<T>::end()
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
        template <typename T>
        typename vector<T>::const_pointer vector<T>::begin() const
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
        template <typename T>
        typename vector<T>::const_pointer vector<T>::end() const
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
        template <typename T>
        typename vector<T>::const_pointer vector<T>::cbegin() const
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
        template <typename T>
        //typename key word required as function is trying to access member 
        //variables of vector class
        typename vector<T>::const_pointer vector<T>::cend() const
        {
            return (data + sz);
        }
} // namespace hlp2

#endif // VCT_HPP
