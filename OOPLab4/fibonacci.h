#pragma once
#include <typeinfo>
#include "stdafx.h"

template<class T>
class fibonacci {
private:
	int _size;
	T a;
	T b;

	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		int position;
		T current;
		T next;
	public:
		void operator--()
		{
			T tmp = current;
			current = next - current;
			next = tmp;
			position--;
		}
		void operator++()
		{
			T tmp = current;
			current = next;
			next = tmp + next;
			position++;
		}
		void operator+=(int ind)
		{
			for (int i = position+1; i < position + ind ; i++)
			{
				T tmp = current;
				current = next;
				next = tmp + next;
			}
			position = position + ind;
		}
		void operator-=(int ind)
		{
			for (int i = position; i < position + ind; i++)
			{
				T tmp = current;
				current = next - current;
				next = tmp;
			}
			position = position - ind;
		}
		const_iterator(int pos, T a, T b) : current(a), next(b)
		{
			position = 0;
			*this += pos;
		}

		const_iterator(const const_iterator& other)
		{
			position = other->position;
			current = other->current;
			next = other->next;
		}

		const_iterator operator+(int ind)
		{
			const_iterator it(position, a, b);
			it += ind;
			return it;
		}
		const_iterator operator-(int ind)
		{
			const_iterator it(position, a, b);
			it -= ind;
			return it;
		}
		T* operator ->()
		{
			return &operator*();
		}
		T operator *()
		{
			return current;
		}
		bool operator>(const_iterator &other)
		{
			return position > other.position;
		}
		bool operator<(const_iterator &other)
		{
			return position < other.position;
		}
		bool operator>=(const_iterator &other)
		{
			return position >= other.position;
		}
		bool operator<=(const_iterator &other)
		{
			return position <= other.position;
		}

		bool operator==(const_iterator &other)
		{
			return position == other.position;
		}
		bool operator!=(const_iterator &other)
		{
			return position != other.position;
		}
	};
	/*class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		friend class fibonacci<T>;
		int position;
		T a;
		T b;
	public:
		const_iterator(int position, T a, T b):position(position),a(a),b(b)
		{
		}
		T* operator ->()
		{
			return &operator*();
		}
		T operator *()
		{
			if (position == 1) return a;
			if (position == 2) return b;
			T tempA = a, tempB = b;
			for (int i = 2; i < position; i++)
			{
				T tmp = tempB;
				tempB = tempA + tempB;
				tempA = tmp;
			}
			return tempB;
		}
		const_iterator operator-(int ind)
		{
			return const_iterator(position - ind, a, b);
		}
		void operator-=(int ind)
		{
			position -= ind;
		}
		const_iterator operator+(int ind)
		{
			return const_iterator(position + ind, a, b);
		}
		void operator+=(int ind)
		{
			position += ind;
		}
		void operator--()
		{
			position--;
		}
		void operator++()
		{
			position++;
		}

		bool operator>(const_iterator &other)
		{
			return position > other.position;
		}
		bool operator<(const_iterator &other)
		{
			return position < other.position;
		}
		bool operator>=(const_iterator &other)
		{
			return position >= other.position;
		}
		bool operator<=(const_iterator &other)
		{
			return position <= other.position;
		}

		bool operator==(const_iterator &other)
		{
			return position == other.position;
		}
		bool operator!=(const_iterator &other)
		{
			return position != other.position;
		}
	};*/
public:
	fibonacci(int size);
	fibonacci(int size, T a, T b);
	const_iterator cbegin()
	{
		return  const_iterator(1, a, b);
	}
	const_iterator cend()
	{
		return  const_iterator(_size, a, b);
	}
	T at(int i)
	{
		if (i <= _size && i > 0)
		{
			const_iterator it(i, a, b);
			return *it;
		}
		return a;
	}
	int size();
	void resize(int s);
};

template<>
fibonacci<string>::fibonacci(int _size) : _size(_size)
{
	a = "a";
	b = "b";
}

template<class T>
fibonacci<T>::fibonacci(int _size) : _size(_size)
{
	a = 0;
	b = 1;
}

template<class T>
fibonacci<T>::fibonacci(int _size, T a, T b) : _size(_size), a(a), b(b)
{
}



template<class T>
int fibonacci<T>::size()
{
	return _size;
}

template<class T>
void fibonacci<T>::resize(int s)
{
	_size=s;
}

