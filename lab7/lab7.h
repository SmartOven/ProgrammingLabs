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
        using difference_type = std::iterator<std::random_access_iterator_tag, T>::difference_type;
        difference_type operator- (const iterator& other) const { return _data - other._data; }
    	// end Хрень
    	
        iterator(T*); // Скрытый конструктор для создания итератора в классе буффера
        iterator(const iterator& src); // Конструктор для неявного копирования
    	~iterator() = default; // Дефолтный деструктор
        T& operator*(); // Разыменовывание указателя
        T* operator->(); // Получение данных по указателю
        
        // Операторы сложения и вычитания
        iterator operator++();
        iterator operator++(int);
        T* operator--();
        iterator operator+(int);
        iterator operator-(int) const;
        // end Операторы сложения и вычитания

    	// Операторы сравнения
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        // end Операторы сравнения
    private:
        T* _data = nullptr;
    };

    // Получение начала и конца массива
    iterator begin() const {
        return iterator(data);
    }
    iterator end() const {
        return iterator(data + _size + 1);
    }
    // Получение капасити и размера массива
    size_t capacity() const {
	    return this->_capacity;
    }
    size_t size() const {
	    return this->_size;
    }
	
    // Конструкторы класса
    explicit CircleBuffer(size_t capacity) :
        _capacity(capacity),
        data(new T[_capacity]) {
    }
    CircleBuffer(std::initializer_list<T> list) :
        _capacity(list.size()),
        data(new T[list.size()]) {
        for (auto it = list.begin(); it != list.end(); ++it)
            push_back(*it);
    }
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
    void push_front(T x)
    {
        
    }
    void pop_front()
    {

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
    void pop_back()
	{

    }
	void insert(size_t ind)
    {
	    
    }
	void remove(size_t ind)
    {
	    
    }
	void resize(size_t new_capacity)
    {
	    
    }

	// Операторы класса
	T operator[] (size_t ind) {
        return data[ind % _capacity];
    }
private:
    size_t _size = 0;
    size_t _capacity = 0;
    T* data = nullptr;
};
