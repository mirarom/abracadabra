// ���� Array.h

#pragma once
#include <cstdio>
#include <new>

#define  CHECK_IND  // ��� ����� �������� � ��������� �������� ��������

template <class T>
class Array
{
 private:
    T * value;       // ������� ������ �������� 
    size_t size;     // ������� ������
    size_t maxsize;  // ����������� ��������� ������
    const char * ArrangeMessage(const char * text, size_t s, size_t ms);
    bool TestInd(size_t i) const { return i < size; }
 public:
    Array(size_t s = 0) : value(nullptr) { SetSize(s, s); }
    Array(size_t s, size_t ms) : value(nullptr) { SetSize(s, ms); };
    Array(const Array<T> & other);
    ~Array() { delete [] value; }

    void SetSize(size_t s, size_t ms);  // �������� ������ �������

    void Add(const T &x);
    void Insert(size_t i, const T &x);
    void Remove(size_t i);
                                        
    T & operator[] (size_t i);              // lvalue
    const T & operator[](size_t i) const;   // rvalue;
                                               
    size_t Size()  const {return size;}
    size_t MaxSize()  const {return maxsize;}
};

template <class T>
void Array<T>::SetSize(size_t s, size_t ms)
{
    if (s > ms) {
       throw new MyException(EC_RANGE, 
          ArrangeMessage("SetSize: size > maxsize ", s, ms));
    }
    if (value) { delete [] value; }  // ����������� ������ ��������� �������
                                     // ��� ������ ������������ 
try {
       value = new T[ms];
       maxsize = ms;
       size = s;
    } catch (std::bad_alloc &e) {
       throw new MyException(EC_MEMORY,
          ArrangeMessage("SetSize: allocation error: size, maxsize", s, ms));
    }
}                      

// ����������� ����������� --- �������� ��� �������� �������
template <class T>
Array<T>::Array(const Array<T> & other)
{
    value = nullptr;
    SetSize(other.size, other.maxsize);
    for (size_t i = 0; i < size; ++i) {
        value[i] = other[i];
    }
}

// ��� ���������� ���� ������ ����������� ������
// ������� ��������� �����, � ����� ������������
// ������� �� ����������� �� �������� ���������

#define  DBL_LENGTH_MAX   4096  // ��� ���, � ������� �����

template <class T>
void Array<T>::Add(const T &x)
{
 try {
   if (size == maxsize) {
       maxsize = (maxsize < DBL_LENGTH_MAX) ? 2*maxsize : maxsize + DBL_LENGTH_MAX; 
       T * new_value = new T[maxsize];
       for (size_t i = 0; i < size; ++i) { new_value[i] = value[i]; }
       delete [] value;
       value = new_value;
   }
   value[size++] = x;
 } catch (std::bad_alloc &e) {
       throw new MyException(EC_MEMORY,
          ArrangeMessage("Add: allocation error: size, maxsize", size, maxsize));
 }
}

template <class T>
void Array<T>::Remove(size_t i)
{
#ifdef CHECK_IND
    if (!TestInd(i)) {
       throw new MyException(EC_RANGE,
          ArrangeMessage("Remove: bad index: ind, size ", i, size));
    }
#endif
    for ( ; i < size - 1; i++) value[i] = value[i+1];  // �� ������ ������ �������
    --size;
}                                 

template <class T>
void Array<T>::Insert(size_t insert_index, const T & x)
{
#ifdef CHECK_IND
   if (!TestInd(insert_index)) {
         throw new MyException(EC_RANGE,
          ArrangeMessage("Remove: bad index: ind, size ", insert_index, size));
   }
#endif
   try {
      if (size == maxsize) {
         
         maxsize = (maxsize < DBL_LENGTH_MAX) ? 2*maxsize : maxsize + DBL_LENGTH_MAX; 
         T * new_value = new T[maxsize];

         for (size_t i = 0; i < insert_index; ++i) { new_value[i] = value[i]; }
         for (size_t i = insert_index+1; i < size+1; ++i) { new_value[i] = value[i-1]; }
         new_value[insert_index] = x;

         delete [] value;
         value = new_value;
         size++;
      }
      else {
         for (size_t i = size; i > insert_index; --i) { value[i] = value[i-1]; }
         value[insert_index] = x;
         size++;
      }
   } catch (std::bad_alloc &e) {
         throw new MyException(EC_MEMORY,
            ArrangeMessage("Insert: allocation error: size, maxsize", size, maxsize));
   }

//  �������� ������� �� ��������� � ������� �������
//  try ���� �� ��������� ������
//  �������� ���������� �� ������� maxsize ��� ���������� �������
//     ���� ������ ������������, �� �������� ����� ������ 
//     � ����������� � ���� �������� c �������� �� 0 �� i-1
//  �������� ����� ������� �� i �� size-1 �� ���� ������� �����
//  value[i] = x;
}

template <class T>
T & Array<T>::operator[](size_t i)
{
#ifdef CHECK_IND
    if (!TestInd(i)) {
       throw new MyException(EC_RANGE,
          ArrangeMessage("[]: bad index: ind, size ", i, size));
    }
#endif
   return value[i];
}

template <class T>
const T & Array<T>::operator[](size_t i) const
{
#ifdef CHECK_IND
    if (!TestInd(i)) {
       throw new MyException(EC_RANGE,
          ArrangeMessage("[] const: bad index: ind, size ", i, size));
    }
#endif
   return value[i];
}

template <class T>
const char *Array<T>::ArrangeMessage(const char *text, size_t s, size_t ms)
{
   static char msg[256];
   sprintf(msg, "%s %lu %lu\n", text, s, ms);
   return msg;
}


