// Copyright 2023 <Victor Klimovich>

#pragma once
#include <iostream>
#include <utility>
#define STEP_CAPACITY 15
#define MAX_CAPACITY 100000


enum State { empty, busy, deleted };

namespace algorithms {
template<typename T>

inline void swap(T& val_1, T& val_2) noexcept {
    T tmp = val_1;
    val_1 = val_2;
    val_2 = tmp;
}
}

template <typename T>
class TDMassive {
    T* _data;                  // äèíàìè÷åñêèé ìàññèâ äàííûõ
    State* _states;            // ñîñòîÿíèÿ ÿ÷ååê
    size_t _capacity;          // ðåàëüíûé ðàçìåð ìàññèâà
    size_t _size;              // êîëè÷åñòâî õðàíèìûõ äàííûõ
    size_t _deleted;           // êîëè÷åñòâî "óäàë¸ííûõ" ïîçèöèé

 public:
    TDMassive();
    TDMassive(const TDMassive& archive);
    TDMassive(const T* arr, size_t n);
    TDMassive(size_t n, T value);
    TDMassive(const TDMassive& archive, size_t pos, size_t n);
    void pop_back_tvo();
    ~TDMassive();
    void print() const;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    size_t size();
    size_t capacity();
    const T* data() const;
    void swap(TDMassive& archive);

    TDMassive& assign(const TDMassive& archive);

    void clear();
    void resize(size_t n, T value);
    void reserve(size_t n = 15);

    void push_back(T value);             // âñòàâêà ýëåìåíòà (â êîíåö)
    void pop_back();                     // óäàëåíèå ýëåìåíòà (èç êîíöà)
    void push_front(T value);            // âñòàâêà ýëåìåíòà (â íà÷àëî)
    void pop_front();                    // óäàëåíèå ýëåìåíòà (èç íà÷àëà)

    TDMassive& insert(const T* arr, size_t n, size_t pos);
    TDMassive& insert(T value, size_t pos);

    TDMassive& replace(size_t pos, T new_value);

    TDMassive& erase(size_t pos, size_t n);
    TDMassive& remove_all(T value);
    TDMassive& remove_first(T value);
    TDMassive& remove_last(T value);
    TDMassive& remove_by_index(size_t pos);

    size_t* find_all(T value) const noexcept;
    size_t find_first(T value) const;
    size_t find_last(T value) const;

 private:
    size_t count_value(T value)  const noexcept;
    void repacking();
};

template <typename T>
TDMassive<T>::TDMassive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
TDMassive<T>::TDMassive(const TDMassive& archive) {
    _capacity = archive._capacity;
    _size = archive._size;
    _deleted = archive._deleted;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
        _states[i] = archive._states[i];
    }
}

// Êîíñòðóêòîð èíèöèàëèçàöèè ìàññèâîì
template <typename T>
TDMassive<T>::TDMassive(const T* arr, size_t n) {
    _capacity = n;
    _size = n;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = arr[i];
        _states[i] = State::occupied;
    }
}

// Êîíñòðóêòîð èíèöèàëèçàöèè çíà÷åíèÿìè
template <typename T>
TDMassive<T>::TDMassive(size_t n, T value) {
    _capacity = n;
    _size = n;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = value;
        _states[i] = State::occupied;
    }
}

// Êîíñòðóêòîð êîïèðîâàíèÿ ñ ó÷åòîì ïîçèöèè è êîëè÷åñòâà ýëåìåíòîâ
template <typename T>
TDMassive<T>::TDMassive(const TDMassive& archive, size_t pos, size_t n) {
    _capacity = n;
    _size = n;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < n; i++) {
        if (pos + i < archive._size) {
            _data[i] = archive._data[pos + i];
            _states[i] = archive._states[pos + i];
        } else {
            _data[i] = T();
            _states[i] = State::empty;
        }
    }
}

template <typename T>
size_t TDMassive<T>::size() {
    return _size;
}
template <typename T>
size_t TDMassive<T>::capacity() {
    return _capacity;
}

template <typename T>
const T* TDMassive<T>::data() const {
    return _data;
}

template <typename T>
void TDMassive <T>::swap(TDMassive& archive) {
    algorithms::swap(_size, archive._size);
    algorithms::swap(_capacity, archive._capacity);
    algorithms::swap(_data, archive._data);
    algorithms::swap(_states, archive._states);
}

template <typename T>
TDMassive<T>& TDMassive <T>::assign(const TDMassive& archive) {
    _size = archive._size;
    _capacity = archive._capacity;
    _data = new T[_capacity];
    _states = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
        _states[i] = archive.data[i];
    }
    return *this;
}

template <typename T>
void TDMassive<T>::clear() {
    if (_data) {
        delete[] _data;
        _data = nullptr;  // Установить в nullptr после удаления
    }
    if (_states) {
        delete[] _states;
        _states = nullptr;  // Установить в nullptr после удаления
    }
    _size = 0;
    _capacity = 0;
}


template <typename T>
void TDMassive <T>::resize(size_t n, T value) {
    if (empty()) {
        throw std::logic_error("archive empty ");
    }
    if (n <= _size) {
        for (size_t i = _size; i >= n; i--) {
            _states[i] = State::empty;
        }
        _size = n;
    } else {
        reserve(n);
        for (size_t i = _size; i < n; ++i) {
            _data[i] = value;
            _states[i] = State::busy;
        }
        _size = n;
    }
}

template <typename T>
void TDMassive <T>::reserve(size_t n) {
    repacking();
    if (n < _capacity || _size < _capacity) {
        return;
    }
    _capacity = ((n + STEP_CAPACITY - 1) / STEP_CAPACITY) * STEP_CAPACITY;
    if (_capacity > MAX_CAPACITY) {
        throw std::logic_error(R"(Error in function 'void TDMassive<T>::reserve(size_t n)': exceeded maximum capacity.)");
    }

    T* newData = new T[_capacity];
    std::memcpy(newData, _data, _size);
    delete[] _data;
    _data = newData;
    State* newDat = new State[_capacity];
    std::memcpy(newDat, _states, _size);
    delete[] _states;
    _states = newDat;
}

template <typename T>
void TDMassive<T>::repacking() {
    size_t step = 0;
    size_t newSize = 0;
    for (int i = 0; i < _size; i++) {
        if (_states[i] == State::deleted) {
            step++;
        } else {
            _data[i - step] = _data[i];
            _states[i - step] = _states[i];
        }
    }
    newSize = _size - step;
    for (int i = newSize; i < _size; i++) {
        _states[i] = State::empty;
    }
    _size = newSize;
}

template <typename T>
TDMassive<T>::~TDMassive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TDMassive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TDMassive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
TDMassive<T>& TDMassive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("wrong position value.");
    }
    if (this->full()) {
        this->reserve();
      }
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
TDMassive<T>& TDMassive<T>::insert(const T* arr, size_t n, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("wrong position value.");
    }
if((_capacity - _size) < n) {
        reserve(_size + n);
    }
    for (size_t i = _size; i > pos; i--) {
        _data[i + n - 1] = _data[i - 1];
        _states[i + n - 1] = _states[i - 1];
    }
    for (size_t i = 0; i < n; ++i) {
        _data[pos + i] = arr[i];
        _states[pos + i] = State::busy;
    }
    _size += n;
    return *this;
}

template <typename T>
void TDMassive<T>::push_back(T value) {
    if (this->full()) {
        this->reserve();
    }
    _data[_size] = value;
    _states[_size] = State::busy;
    _size++;
}

template <typename T>
void TDMassive<T>::push_front(T value) {
    if (this->full()) {
        this->reserve();
    }
    for (size_t i = _size; i > 0; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }
    _data[0] = value;
    _states[0] = State::busy;
    _size++;
}

template <typename T>
void TDMassive<T>::pop_front() {
    if (_size <= 0) {
        throw std::logic_error("archive clear");
    }
    for (size_t i = 1; i < _size; i++) {
        _data[i - 1] = _data[i];
        _states[i - 1] = _states[i];
    }
    _states[_size - 1] = State::deleted;
    _deleted++;
    _size--;
}

template <typename T>
void TDMassive<T>::pop_back() {
    if (_size <= 0) {
        throw std::logic_error("archive clear");
    }
    _states[_size - 1] = State::empty;
    --_size;
}

template <typename T>
void TDMassive<T>::pop_back_tvo() {
    if (_size <= 0) {
        throw std::logic_error("archive clear");
    }
    _states[_size - 1] = State::empty;
    --_size;
}

template <typename T>
TDMassive<T>& TDMassive<T> ::remove_by_index(size_t pos) {
    if (_size <= pos || pos < 0) {
        throw std::logic_error("wrong position value.");
    }
    _states[pos] = State::deleted;
    _deleted++;
    return *this;
}

template <typename T>
TDMassive<T>& TDMassive<T>::erase(size_t pos, size_t n) {
    if (_size < pos) {
        throw std::logic_error("wrong position value.");
    }
    for (size_t i = pos; i < pos + n; i++) {
        _states[i] = State::deleted;
    }
    _deleted = n;
}

template <typename T>
TDMassive<T>& TDMassive<T>::remove_all(T value) {
    if (_size <= 0) {
        throw std::logic_error("archive clear");
    }
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            _deleted++;
        }
    }
}

template <typename T>
TDMassive<T>& TDMassive<T>::remove_first(T value) {
    if (_size <= 0) {
        throw std::logic_error("archive clear");
    }
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            break;
        }
    }
    _deleted++;
}

template <typename T>
TDMassive<T>& TDMassive<T>::remove_last(T value) {
    if (_size <= 0) {
        throw std::logic_error("archive clear");
    }
    for (size_t i = _size; i > 0; i--) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            break;
        }
    }
    _deleted++;
}

template <typename T>
size_t TDMassive<T>::find_first(T value) const {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value && _states[i] != State::deleted) {
            return i;
        }
    }
    throw std::logic_error("No mathes");
}


template <typename T>
size_t TDMassive<T>::find_last(T value) const {
    for (size_t i = _size; i > 0; i--) {
        if (_data[i] == value && _states[i] != State::deleted) {
            return i;
        }
    }
    throw std::logic_error("No mathes");
}

template <typename T>
size_t* TDMassive<T>::find_all(T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) {
        return nullptr;
    }
    size_t* found_positions = new size_t[count + 1];
    found_positions[0] = count;
    size_t found_count = 0;

    for (size_t i = 0; i < _size; ++i) {
        if (_data[i] == value && _states[i] != State::deleted) {
            found_positions[++found_count] = i;
        }
    }

    return found_positions;
}

template <typename T>
TDMassive<T>& TDMassive<T>::replace(size_t pos, T new_value) {
    if (_data[pos] != State::busy) {
        throw std::logic_error("No mathes");
    }
    if (_data[pos]) {
    _data[pos] = new_value;
    }
    _states[pos] = State::busy;
    return *this;
}

template <typename T>
void TDMassive<T>::print() const  {
    if (empty()) {
        throw std::logic_error("archive empty ");
    }

    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}


template <typename T>
size_t TDMassive<T>::count_value(T value) const noexcept {
    size_t count = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            count++;
        }
    }
    return count;
}
