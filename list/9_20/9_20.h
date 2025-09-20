#include <iostream>

using namespace std;

namespace AY
{
	// 结点的结构
	template<class T>
	struct list_node
	{
		T s_data;
		list_node<T>* s_next;
		list_node<T>* s_prev;

		list_node(const T& val = T())
			: s_data(val)
			, s_next(nullptr)
			, s_prev(nullptr)
		{}
	};

	/*
	// 普通迭代器
	template<class T>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		// 创建一个结点的指针
		Node* s_node;

		_list_iterator(Node* node)
			:s_node(node)
		{}

		// 重载 * 运算符 --- 解引用结点的指针，返回结点的数据
		// 返回值类型为 T& ,方便修改返回值
		T& operator*()
		{
			return s_node->s_data;
		}

		const T& operator*() const
		{
			return s_node->s_data;
		}

		// 重载前置 ++ 运算符 --- 返回++之前的值
		// 返回值类型为迭代器
		_list_iterator<T>& operator++()
		{
			s_node = s_node->s_next;
			return *this;
		}

		// 重载 != 运算符
		bool operator!=(const _list_iterator<T>& it) const
		{
			return s_node != it.s_node;
		}

		// 重载 == 运算符
		bool operator==(const _list_iterator<T>& it) const
		{
			return s_node == it.s_node;
		}

		// 重载后置 ++ 运算符 --- 返回++之后的值
		_list_iterator<T> operator++(int)
		{
			_list_iterator<T> tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// 重载前置--运算符
		_list_iterator<T>& operator--()
		{
			s_node = s_node->s_prev;
			return *this;
		}

		// 重载后置--运算符
		_list_iterator<T> operator--(int)
		{
			_list_iterator<T> tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}
	};


	// const 版本迭代器
	template<class T>
	struct _list_const_iterator
	{
		typedef list_node<T> Node;
		// 创建一个结点的指针
		Node* s_node;

		_list_const_iterator(Node* node)
			:s_node(node)
		{
		}

		// 重载 * 运算符 --- 解引用结点的指针，返回结点的数据
		// 返回值类型为 T& ,方便修改返回值
		const T& operator*()
		{
			return s_node->s_data;
		}

		// 重载前置 ++ 运算符 --- 返回++之前的值
		// 返回值类型为迭代器
		_list_const_iterator<T>& operator++()
		{
			s_node = s_node->s_next;
			return *this;
		}

		// 重载 != 运算符
		bool operator!=(const _list_const_iterator<T>& it) const
		{
			return s_node != it.s_node;
		}

		// 重载 == 运算符
		bool operator==(const _list_const_iterator<T>& it) const
		{
			return s_node == it.s_node;
		}

		// 重载后置 ++ 运算符 --- 返回++之后的值
		list_const_iterator<T> operator++(int)
		{
			_list_const_iterator<T> tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// 重载前置--运算符
		_list_const_iterator<T>& operator--()
		{
			s_node = s_node->s_prev;
			return *this;
		}

		// 重载后置--运算符
		_list_const_iterator<T> operator--(int)
		{
			_list_const_iterator<T> tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}
	};
	*/
     
    // Ref 是 reference 引用的缩写
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> Self; // 将自己重命名为 Self

		// 创建一个结点的指针
		Node* s_node;

		_list_iterator(Node* node)
			:s_node(node)
		{}

		// 重载 * 运算符 --- 解引用结点的指针，返回结点的数据
		// 返回值类型为 T& ,方便修改返回值
		Ref& operator*()
		{
			return s_node->s_data;
		}

		// 重载 -> 运算符
		Ptr operator->()
		{
			return &(s_node->s_data);
		}

		// 重载前置 ++ 运算符 --- 返回++之前的值
		// 返回值类型为迭代器
		Self& operator++()
		{
			s_node = s_node->s_next;
			return *this;
		}

		// 重载 != 运算符
		bool operator!=(const Self& it) const
		{
			return s_node != it.s_node;
		}

		// 重载 == 运算符
		bool operator==(const Self& it) const
		{
			return s_node == it.s_node;
		}

		// 重载后置 ++ 运算符 --- 返回++之后的值
		Self operator++(int)
		{
			Self tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// 重载前置--运算符
		Self& operator--()
		{
			s_node = s_node->s_prev;
			return *this;
		}

		// 重载后置--运算符
		Self operator--(int)
		{
			Self tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		//typedef _list_iterator<T> iterator;
		//typedef _list_const_iterator<T> const_iterator;

		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(m_head->s_next);
		}

		iterator end()
		{
			return iterator(m_head);
		}

		const_iterator begin() const
		{
			return iterator(m_head->s_next);
		}

		const_iterator end() const
		{
			return iterator(m_head);
		}

	public:
		empty_init()
		{
			m_head = new Node;
			m_head->s_next = m_head;
			m_head->s_prev = m_head;
		}

		list()
		{
			empty_init();
		}

		// 拷贝构造函数
		list(const list<T>& lt)
		{
			empty_init();

			// 拷贝数据
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		// 花括号初始化
		list(initializer_list<T> il)
		{
			empty_init();
			
			// 拷贝数据
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		// 赋值运算符重载函数 --- 一般写法
		list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				// 清空 this 中的数据
				clear();
				// 拷贝数据
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}

			return *this;
		}

		// swap 函数
		void swap(list<T>& lt)
		{
			std::swap(m_head, lt.m_head);
		}

		// 赋值运算符重载函数 --- 特殊写法
		list<T>& operator=(list<T>& lt)
		{
			swap(lt);

			return *this;
		}

		// 析构函数
		~list()
		{
			clear();
			delete m_head;
			m_head = nullptr;
		}

		/*~list()
		{
			iterator it = begin();
			// 删除结点
			while (it != end())
			{
				it = erase(it);
			}
			// 删除哨兵结点
			delete m_head;
			// 置空
			m_head = nullptr;
		}*/

		/*
		void push_back(const T& val)
		{
			Node* newnode = new Node(val);
			Node* tail = m_head->s_prev;

			newnode->s_prev = tail;
			newnode->s_next = m_head;
			m_head->s_prev = newnode;
			tail->s_next = newnode;
		}
		*/

		// insert 函数
		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos.s_node;
			Node* prev = cur->s_prev;

			prev->s_next = newnode;
			newnode->s_prev = prev;
			newnode->s_next = cur;
			cur->s_prev = newnode;

			return newnode;
			// return iterator(newnode);
		}

		// erase 函数
		iterator erase(iterator pos)
		{
			Node* cur = pos.s_node;
			Node* prev = cur->s_prev;
			Node* next = cur->s_next;

			prev->s_next = next;
			next->s_prev = prev;
			delete cur;

			return next;
			//return iterator(next);
		}

		// push_front 函数
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		// push_back 函数
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		// pop_front 函数
		void pop_front()
		{
			erase(begin());
		}

		// pop_back 函数
		void pop_back()
		{
			erase(--end());
		}

		// clear 函数
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				// 迭代器失效
				it = erase(it);
			}
		}
        
		// size 函数
		size_t size() const
		{
			size_t count = 0;
			for (auto& e : *this)
			{
				++count;
			}

			return count;
		}

	private:
		Node* m_head;
	};
};