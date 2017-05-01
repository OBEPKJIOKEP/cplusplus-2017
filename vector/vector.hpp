//
//  vector.hpp
//  vector
//
//  Created by Greg Pevnev on 22/04/2017.
//  Copyright © 2017 Greg Pevnev. All rights reserved.
//

#include <cassert>
#include <new>
#include <JavaScriptCore/JavaScriptCore.h>

template <typename T, typename = void>
void desroy_all(T*  data, size_t size,
                typename std::enable_if<!std::is_trivially_destructible<T>::value>::type* = nullptr) // if not trivially destructible
{
    for (size_t i = 0; i < size; ++i)
    {
        data[i].~T();
    }
}

template <typename T, typename = void>
void destroy_all(T* data, size_t size,
                 typename std::enable_if<std::is_trivially_destructible<T>::value>::type* = nullptr) // if trivially destructible
{
}

template <typename T>
class vector {
    T* data_;
    size_t size_;
    size_t capacity_;
    
public:
    typedef T* iterator;
    typedef T const* const_iterator;
    
    vector();
    vector(vector const& other);
    vector(size_t new_size);
    ~vector();
    vector& operator=(vector const& other);
    
    T& operator[](size_t index);
    T const& operator[](size_t index) const;
    size_t size() const;
    
    T& front();
    T const& front() const;
    
    T& back();
    T const& back() const;
    
    bool empty() const;
    
    T* data();
    T const* data() const;
    
    size_t capacity() const;
    
    void shrink_to_fit();
    
    void push_back(T const& element);
    void pop_back();
    
    void swap(vector& other);
    
    iterator begin();
    const_iterator begin() const;
    
    iterator end();
    const_iterator end() const;
    
    iterator insert(iterator pos, T const&);
//    iterator insert(const_iterator pos, T const&);
//    
//    iterator erase(iterator first, iterator last);
//    iterator erase(const_iterator first, const_iterator last);
    
    void reserve(size_t new_capacity);
    void resize(size_t new_size);
    
    void clear();
};

template <typename T>
vector<T>::vector()
: data_(nullptr)
, size_(0)
, capacity_(0)
{
}

template <typename T>
vector<T>::vector(vector const& other)
{
    data_ = static_cast<T*>(operator new(other.size_ * sizeof(T)));
    for (int i = 0; i < other.size_; ++i)
        data_[i] = other.data_[i];
    size_ = other.size_;
    capacity_ = size_;
}

template <typename T>
vector<T>::vector(size_t new_size)
{
    resize(new_size);
}

template <typename T>
vector<T>::~vector()
{
    for (int i = 0; i < size_; ++i)
        data_[i].~T();
    operator delete (data_);
}

template <typename T>
vector<T>& vector<T>::operator=(vector const& other)
{
    vector copy(other);
    swap(copy);
    ~copy();
    return *this;
}

template <typename T>
T& vector<T>::operator[](size_t index)
{
    if (index >= size_)
        assert("Index out of bounds");
    return data_[index];
}

template <typename T>
T const& vector<T>::operator[](size_t index) const
{
    if (index >= size_)
        assert("Index out of bounds");
    return data_[index];
}

template <typename T>
size_t vector<T>::size() const
{
    return size_;
}

template <typename T>
T& vector<T>::front()
{
    if (size_ == 0)
        assert("Vector is empty");
    return *data_;
}

template <typename T>
T const& vector<T>::front() const
{
    if (size_ == 0)
        assert("Vector is empty");
    return *data_;
}

template <typename T>
T& vector<T>::back()
{
    if (size_ == 0)
        assert("Vector is empty");
    return data_[size_ - 1];
}

template <typename T>
T const& vector<T>::back() const
{
    if (size_ == 0)
        assert("Vector is empty");
    return data_[size_ - 1];
}

template <typename T>
bool vector<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
T* vector<T>::data()
{
    return data_;
}

template <typename T>
T const* vector<T>::data() const
{
    return data_;
}

template <typename T>
size_t vector<T>::capacity() const
{
    return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit()
{
    reserve(size_);
}

template <typename T>
void vector<T>::push_back(T const& element)
{
    if (capacity_ == size_)
    {
        if(capacity_ == 0)
            reserve(2);
        else
            reserve((capacity_ * 3) >> 1);
    }
    new (data_ + size_) T(element);
    ++size_;
}

template <typename T>
void vector<T>::pop_back()
{
    if (size_ == 0)
        assert("Vector is empty");
    data_[size_ - 1].~T();
    --size_;
}

template <typename T>
void vector<T>::swap(vector<T>& other)
{
    using std::swap;
    swap(data_, other.data_);
    swap(size_, other.size_);
    swap(capacity_, other.capacity_);
}

template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
    return data_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const
{
    return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
    return data_ + size_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const
{
    return data_ + size_;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos, const T& element)
{
    
}

template <typename T>
void vector<T>::reserve(size_t new_capacity)
{
    T* new_data = static_cast<T*>(operator new(new_capacity * sizeof(T)));
    for (int i = 0; i < size_; ++i)
    {
        new_data[i] = data_[i];
        data_[i].~T();
    }
    capacity_ = new_capacity;
    operator delete(data_);
    data_ = new_data;
}

template <typename T>
void vector<T>::resize(size_t new_size)
{
    if(new_size > capacity_)
        reserve(new_size);
    while(size_ != new_size)
    {
        new(end()) T();
        ++size_;
    }
}

template <typename T>
void vector<T>::clear()
{
    for (int i = 0; i < size_; ++i)
        data_[i].~T();
}

