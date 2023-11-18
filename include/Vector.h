#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <memory>
#include <cstring>

template<typename T> //объявление шаблонного класса Vector
class Vector {
private:
  size_t capacity = 0; //емкость вектора 
  size_t size = 0; //размер вектора 
  T* array = nullptr; //указатель на массив элементов

public:
  Vector(); //конструктор по умолчанию
  Vector(size_t); //конструктор с заданной емкостью
  Vector(const std::initializer_list<T>&); // Конструктор с инициализацией списком инициализации
  Vector(const Vector&); //конструктор копирования
  Vector(Vector&&) noexcept; //конструктор перемещения
  Vector& operator=(const Vector<T>&); //оператор присваивания копированием
  Vector& operator=(Vector&&) noexcept; //оператор присваивания перемещением
  virtual ~Vector(); //виртуальный деструктор

  size_t get_size() const; //получение размера вектора
  size_t get_capacity() const; //получение емкости вектора

  bool empty() const; //проверка на пустоту
  bool operator==(const Vector<T>&) const; //проверка на равенство двух векторов
  bool operator!=(const Vector<T>&) const; //проверка на неравенство двух векторов

  void resize(size_t, const T& = T()); //изменение размера вектора
  void push_back(const T&); //добавление элемента в конец вектора
  void reserve(size_t n); //выделение памяти для заданного количества элементов
  void pop_back(); //удаление последнего элемента вектора
  void clear(); //очистка вектора
  void shrink_to_fit(); //уменьшение выделенной памяти до размера вектора

  template <typename... Args>
  void emplace_back(const Args& ...args); //добавление элемента в конец вектора с использованием списка аргументов

  T& operator[](size_t); //перегрузка оператора индексации для доступа к элементу по индексу
  T& at(size_t); // получение элемента по индексу с проверкой границ
  T& front(); //получение первого элемента
  T& back(); //получение последнего элемента
  const T& operator[](size_t) const; //перегрузка оператора индексации для доступа к элементу по индексу
  const T& at(size_t) const; //получение элемента по индексу с проверкой границ 
  const T& back() const; //получение последнего элемента вектора 
  const T& front() const; //получение первого элемента вектора 
};


#endif 