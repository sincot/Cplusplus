#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

template<class T>
class stack
{
public:
	//��ջ
	void push(const T& val)
	{
		// β��
		_v.push_back(val);
	}

	// ��ջ
	void pop()
	{
		// βɾ
		_v.pop_back();
	}

	// ȡջ������
	T& top()
	{
		// ȡ vector �����һ��Ԫ��
		return  _v.back();
	}

	// ��ȡջ����Ч���ݸ���
	size_t size() const
	{
		return _v.size();
	}

	// �ж�ջ�Ƿ�Ϊ��
	bool empty() const
	{
		return _v.empty();
	}

private:
	vector<T> _v;
};

template<class T>
class queue
{
public:
	// ���캯��
	queue()
	{}

	// �������Ƿ�Ϊ��
	bool empty() const
	{
		return _lt.empty();
	}

	// ��ȡ��������ЧԪ�ظ���
	size_t size() const
	{
		return _lt.size();
	}

	// ���ض�ͷԪ�ص�����
	T& front()
	{
		return _lt.front();
	}

	// ���ض�βԪ�ص�����
	T& back()
	{
		return _lt.back();
	}

	// �����(��β)
	void push(const T& val)
	{
		_lt.push_back(val);
	}

	// ������(��ͷ)
	void pop()
	{
		_lt.pop_front();
	}

private:
	list<T> _lt;
};

// ����������
template<class T, class Container = deque<T>>
class stack
{
public:
	// ��ջ -- push ����
	void push(const T& val)
	{
		_cont.push_back(val);
	}

	// ��ջ --- pop ����
	void pop()
	{
		_cont.pop_back();
	}

	// ȡջ������ --- top ����
	T& top()
	{
		// ���е�����������ʵ����front/back�ӿ�
		_cont.back();
	}

	// ��ȡջ����Ч���ݸ��� --- size ����
	size_t size()
	{
		_cont.size();
	}

	// �ж�ջ�Ƿ�Ϊ��
	bool empty()
	{
		_cont.empty();
	}

private:
	Container _con;
};

// ����������
template<class T, class Container = deque<T>>
class queue
{
public:
	// ���캯�� --- queue
	queue() {}

	// �������Ƿ�Ϊ�� --- empty����
	bool empty()
	{
		return _cont.empty();
	}

	// ��ȡ��������ЧԪ�ظ��� --- size ����
	size_t size()
	{
		return _cont.size();
	}

	// ���ض�ͷԪ�ص����� --- front ����
	T& front()
	{
		return _cont.front();
	}
	 
	// ���ض�βԪ�ص����� --- back ����
	T& back()
	{
		return _cont.back();
	}

	// �����(��β) --- push ����
	void push(const T& val)
	{
		_cont.push_back(val);
	}

	// ������(��ͷ) --- pop ����
	void pop()
	{
		_cont.pop_front();
	}

private:
	Container _cont;
};



template <class T, class Ref, class Ptr, size_t BufSiz>
struct __deque_iterator {
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;  // ģ�����
	typedef Ptr pointer;   // ָ��
	typedef Ref reference; // ����
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T** map_pointer;

	typedef __deque_iterator self;
	__deque_iterator(T* x, map_pointer y)
		: cur(x), first(*y), last(*y + buffer_size()), node(y) {
	}

	reference operator*() const { return *cur; }

	difference_type operator-(const self& x) const {
		return difference_type(buffer_size()) * (node - x.node - 1) +
			(cur - first) + (x.last - x.cur);
	}

	self& operator++() {
		++cur;
		// ��ǰbuff������
		if (cur == last)  
		{
			// ������Ҫָ����һ��buff�ĵ�һ������
			set_node(node + 1);
			cur = first;
		}
		return *this;
	}
	self operator++(int) {
		self tmp = *this;
		++*this;
		return tmp;
	}

	self& operator--() {
		if (cur == first) {
			set_node(node - 1);
			cur = last;
		}
		--cur;
		return *this;
	}
	self operator--(int) {
		self tmp = *this;
		--*this;
		return tmp;
	}

	self& operator+=(difference_type n) {
		difference_type offset = n + (cur - first);
		if (offset >= 0 && offset < difference_type(buffer_size()))
			cur += n;
		else {
			difference_type node_offset =
				offset > 0 ? offset / difference_type(buffer_size())
				: -difference_type((-offset - 1) / buffer_size()) - 1;
			set_node(node + node_offset);
			cur = first + (offset - node_offset * difference_type(buffer_size()));
		}
		return *this;
	}

	self operator+(difference_type n) const {
		self tmp = *this;
		return tmp += n;
	}

	self& operator-=(difference_type n) { return *this += -n; }

	self operator-(difference_type n) const {
		self tmp = *this;
		return tmp -= n;
	}

	reference operator[](difference_type n) const { return *(*this + n); }

	void set_node(map_pointer new_node) {
		// ���µ�������ָ��
		node = new_node;   // node ָ����һ�� node 
		first = *new_node; // first ָ��ָ����һ��buff�Ŀ�ʼ
		// last ָ��ָ����һ��buff��ĩβ
		last = first + difference_type(buffer_size()); 
	}
};

//reference operator[](size_type n) { return start[difference_type(n)]; }
//reference operator[](difference_type n) const {
//	return *(*this + n);
//self operator+(difference_type n) const {
//		self tmp = *this;
//		return tmp += n;
//}
//
//self& operator+=(difference_type n) {
//	difference_type offset = n + (cur - first);
//	if (offset >= 0 && offset < difference_type(buffer_size()))
//		cur += n;
//	else {
//		difference_type node_offset =
//			offset > 0 ? offset / difference_type(buffer_size())
//			: -difference_type((-offset - 1) / buffer_size()) - 1;
//		set_node(node + node_offset);
//		cur = first + (offset - node_offset * difference_type(buffer_size()));
//	}
//	return *this;
//}