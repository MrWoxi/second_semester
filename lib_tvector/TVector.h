// Copyright 2024 <Victor Klimovich>
#pragma once

#include <iostream>
#include "../lib_dmassive/massive.h"
using std::cout;
using std::cin;



template <typename T>

class TVector {
 private:
TDMassive<T> _data;
size_t _start_index;

 public:
TVector();
TVector(size_t size, size_t start_index = 0);
    TVector(const T* arr, size_t size, size_t start_index = 0);
    TVector(const TVector<T>& other);
    ~TVector();
    TVector<T>& operator=(const TVector<T>& other);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    TVector<T> operator+(const TVector<T>& other) const;
    TVector<T> operator-(const TVector<T>& other) const;
    T operator*(const TVector<T>& other) const;
    TVector<T>& operator+=(const TVector<T>& other);
    TVector<T>& operator-=(const TVector<T>& other);
    bool operator==(const TVector<T>& other) const;
    bool operator!=(const TVector<T>& other) const;
    TVector<T> operator*(const T& scalar) const;
    TVector<T>& operator*=(const T& scalar);
    size_t size() const;
    size_t get_start_index() const;
    void set_start_index(size_t start_index);
    void resize(size_t new_size);
    void clear();

    void print(std::ostream& out = std::cout) const;
};

template <typename T>
TVector<T>::TVector() : _data(), _start_index(0) {}

template <typename T>
TVector<T>::TVector(size_t size, size_t start_index) :
    _data(size), _start_index(start_index) {}

template<typename T>
TVector<T>::TVector(const T* arr, size_t size, size_t start_index) :
_data(arr, size), _start_index(start_index) {}

template<typename T>
TVector<T>::TVector(const TVector<T>& other) {
    _data = other._data;
    _start_index = other._start_index;
}

template<typename T>
TVector<T>::~TVector() {
    // Удаление не нужно, если _data управляется автоматически
}

template<typename T>
TVector<T>& TVector<T>::operator=(const TVector<T>& other) {
    if (this != &other) {
    _data = other._data;
    _start_index = other._start_index;
    }
    return *this;
}

// Остальные методы необходимо реализовать

