#pragma once
#include <iterator>
#include <initializer_list>

template <class T>
class CircleBuffer {
public:
    // Вложенный класс итератора
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
    	// Хрень для stl алгоритмов
        using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
        difference_type operator- (const iterator& other) const { return _data - other._data; }
    	// end Хрень
    	
        explicit iterator(T* start) {
            _data = start;
        } // Скрытый конструктор для создания итератора в классе буффера
        iterator(const iterator& src) { _data = src._data; } // Конструктор для неявного копирования
    	~iterator() = default; // Дефолтный деструктор
        T& operator*() { return *(_data); } // Разыменовывание указателя
        T* operator->() { return _data; } // Получение данных по указателю
        
        // Операторы сложения и вычитания
        iterator operator++() {++_data; return *this;}
        iterator operator--() {--_data; return *this;}
        iterator operator+(int x) {_data = _data + x; return *this;}
        iterator operator-(int x) {_data = _data - x; return *this;}
        // end Операторы сложения и вычитания

    	// Операторы сравнения
        bool operator==(const iterator& other) const {return _data == other._data;}
        bool operator!=(const iterator& other) const {return _data != other._data;}
        bool operator<(const iterator& other) const {return _data < other._data;}
        bool operator<=(const iterator& other) const {return _data <= other._data;}
        bool operator>(const iterator& other) const {return _data > other._data;}
        bool operator>=(const iterator& other) const {return _data >= other._data;}
        // end Операторы сравнения
    private:
        T* _data = nullptr;
    };

    // Получение начала и конца массива
    iterator begin() const {
        return iterator(data);
    }
    iterator end() const {
        return iterator(data + _size);
    }
    // Получение капасити и размера массива
    [[nodiscard]] size_t capacity() const {
	    return this->_capacity;
    }
    [[nodiscard]] size_t size() const {
	    return this->_size;
    }
	
    // Конструкторы класса
    explicit CircleBuffer(size_t capacity) {
        _capacity = capacity;
        data = new T[_capacity];
    }
    /*explicit CircleBuffer(std::initializer_list<T> list) {
        _capacity = list.size();
        data = new T[list.size()];
        for (auto it = list.begin(); it != list.end(); ++it)
            push_back(*it);
    }*/
    CircleBuffer(const CircleBuffer& other) :
		_size(other._size),
        _capacity(other._capacity),
        data(other.data) {
    };
	// Деструктор класса
    ~CircleBuffer() {
        delete data;
    }
	
	// Методы класса
    void push_front(T x) {
        if (_size < _capacity) {
            for (size_t i = _size; i >= 1; i--) {
                data[i] = data[i - 1];
            }
            data[0] = x;
            _size++;
        }
        else {
            for (size_t i = _capacity - 1; i >= 1; i--) {
                data[i] = data[i - 1];
            }
            data[0] = x;
        }
    }
    void pop_front() {
        for (size_t i = 0; i < _size - 1; i++) {
            data[i] = data[i + 1];
        }
        _size--;
    }
    void push_back(T x) {
        if (_size < _capacity) {
            data[_size] = x;
            _size++;
        }
        else {
            for (size_t i = 1; i < _capacity; i++) {
                data[i - 1] = data[i];
            }
            data[_capacity - 1] = x;
        }
    }
    void pop_back() {
        if (_size > 0) {
            _size--;
        }
    }
	void insert(size_t ind, T x) {
        data[ind % _capacity] = x;
    }
    void insert(iterator ind, T x) {
        *(begin() + (ind - begin()) % _size) = x;
    }
	void remove(size_t ind) {
        for (size_t i = ind + 1; i < _size; i++) {
            data[(i - 1) % _capacity] = data[i % _capacity];
        }
        _size--;
    }
	void resize(size_t new_capacity) {
	    T* new_data = new T[new_capacity];
	    _size = std::min(_size, new_capacity);
	    for (size_t i = 0; i < _size; i++) {
	        new_data[i] = data[i];
	    }
	    delete data;
	    data = new_data;
	    _capacity = new_capacity;
    }

	// Операторы класса
	T operator[] (size_t ind) {
        return data[ind % _capacity];
    }

    CircleBuffer& operator=(std::initializer_list<T> list) {
        _capacity = list.size();
        data = new T[list.size()];
        for (auto it = list.begin(); it != list.end(); ++it)
            push_back(*it);
        return *this;
    }
private:
    size_t _size = 0;
    size_t _capacity = 0;
    T* data = nullptr;
};
