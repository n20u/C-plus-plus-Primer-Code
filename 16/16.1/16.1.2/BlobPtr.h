#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Blob.h"

template<typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator><T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	T& deref() const;
	BlobPtr& incr();
	T& operator[](std::size_t);
	const T& operator[](std::size_t) const;
	T& operator*() const {
		auto p = check(curr, "dereference pase end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	BlobPtr& operator+=(std::size_t);
	BlobPtr& operator-=(std::size_t);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};
template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();
	if (!ret) {
		throw std::runtime_error("unbound BlobPtr<T>");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

template<typename T>
T& BlobPtr<T>::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::incr() {
	check(curr, "incremenet past end of BlobPtr<T>");
	++curr;
	return *this;
}
template<typename T>
T& BlobPtr<T>::operator[](std::size_t n) {
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}
template<typename T>
const T& BlobPtr<T>::operator[](std::size_t n) const {
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	check(curr, "increment past end of BlobPtr<T>");
	++curr;
	return *this;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	--curr;
	check(curr, "decrement past begin of BlobPtr<T>");
	return *this;
}
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template<typename T>
BlobPtr<T> Blob<T>::begin() {
	return BlobPtr<T>(*this);
}
template<typename T>
BlobPtr<T> Blob<T>::end() {
	return BlobPtr<T>(*this, data->size());
}

template<typename T>
bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&) {
	return lhs.curr == rhs.curr;
}
template<typename T>
friend bool operator!=<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs == rhs);
}
template<typename T>
friend bool operator< <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return lhs.curr < rhs.curr;
}
template<typename T>
friend bool operator><T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return lhs.curr > rhs.curr;
}
template<typename T>
friend bool operator<=<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return lhs.curr <= rhs.curr;
}
template<typename T>
friend bool operator>=<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return lhs.curr >= rhs.curr;
}