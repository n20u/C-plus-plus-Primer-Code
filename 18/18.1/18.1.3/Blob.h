#pragma once
#include <vector>
#include <initializer_list>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <new>

template <typename> class BlobPtr;

template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
	friend bool operator><T>(const Blob<T>&, const Blob<T>&);
	friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> il);
	size_type size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(const T &t) {
		data->push_back(t);
	}
	void push_back(T &&t) {
		data->push_back(t);
	}
	void pop_back();
	T& front();
	T& back();
	T& front() const;
	T& back() const;
	BlobPtr<T> begin();
	BlobPtr<T> end();
	T& operator[](size_type i);
	const T& operator[](size_type i) const;
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type, const std::string&) const;
};
template<typename T>
Blob<T>::Blob() try
{
	: data(std::make_shared<std::vector<T>>()) {}
}
catch (const std::bad_alloc &e)
{
	std::cerr << e.what() << std::endl;
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) try
{
	: data(std::make_shared<std::vector<T>>(il)) {}
}
catch (const std::bad_alloc &e)
{
	std::cerr << e.what() << std::endl;
}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

template<typename T>
T& Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}
template<typename T>
T& Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}
template<typename T>
T& Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}
template<typename T>
T& Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}
template<typename T>
T& Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}
template<typename T>
const T& Blob<T>::operator[](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}
template<typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return *lhs.data == *rhs.data;
}
template<typename T>
bool operator!=<T>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(lhs == rhs);
}
template<typename T>
bool operator< <T>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}
template<typename T>
bool operator><T>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return rhs < lhs;
}
template<typename T>
bool operator<=<T>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(rhs < lhs);
}
template<typename T>
bool operator>=<T>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(lhs < rhs);
}