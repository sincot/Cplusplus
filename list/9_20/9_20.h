#include <iostream>

using namespace std;

namespace AY
{
	// ���Ľṹ
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
	// ��ͨ������
	template<class T>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		// ����һ������ָ��
		Node* s_node;

		_list_iterator(Node* node)
			:s_node(node)
		{}

		// ���� * ����� --- �����ý���ָ�룬���ؽ�������
		// ����ֵ����Ϊ T& ,�����޸ķ���ֵ
		T& operator*()
		{
			return s_node->s_data;
		}

		const T& operator*() const
		{
			return s_node->s_data;
		}

		// ����ǰ�� ++ ����� --- ����++֮ǰ��ֵ
		// ����ֵ����Ϊ������
		_list_iterator<T>& operator++()
		{
			s_node = s_node->s_next;
			return *this;
		}

		// ���� != �����
		bool operator!=(const _list_iterator<T>& it) const
		{
			return s_node != it.s_node;
		}

		// ���� == �����
		bool operator==(const _list_iterator<T>& it) const
		{
			return s_node == it.s_node;
		}

		// ���غ��� ++ ����� --- ����++֮���ֵ
		_list_iterator<T> operator++(int)
		{
			_list_iterator<T> tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// ����ǰ��--�����
		_list_iterator<T>& operator--()
		{
			s_node = s_node->s_prev;
			return *this;
		}

		// ���غ���--�����
		_list_iterator<T> operator--(int)
		{
			_list_iterator<T> tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}
	};


	// const �汾������
	template<class T>
	struct _list_const_iterator
	{
		typedef list_node<T> Node;
		// ����һ������ָ��
		Node* s_node;

		_list_const_iterator(Node* node)
			:s_node(node)
		{
		}

		// ���� * ����� --- �����ý���ָ�룬���ؽ�������
		// ����ֵ����Ϊ T& ,�����޸ķ���ֵ
		const T& operator*()
		{
			return s_node->s_data;
		}

		// ����ǰ�� ++ ����� --- ����++֮ǰ��ֵ
		// ����ֵ����Ϊ������
		_list_const_iterator<T>& operator++()
		{
			s_node = s_node->s_next;
			return *this;
		}

		// ���� != �����
		bool operator!=(const _list_const_iterator<T>& it) const
		{
			return s_node != it.s_node;
		}

		// ���� == �����
		bool operator==(const _list_const_iterator<T>& it) const
		{
			return s_node == it.s_node;
		}

		// ���غ��� ++ ����� --- ����++֮���ֵ
		list_const_iterator<T> operator++(int)
		{
			_list_const_iterator<T> tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// ����ǰ��--�����
		_list_const_iterator<T>& operator--()
		{
			s_node = s_node->s_prev;
			return *this;
		}

		// ���غ���--�����
		_list_const_iterator<T> operator--(int)
		{
			_list_const_iterator<T> tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}
	};
	*/
     
    // Ref �� reference ���õ���д
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> Self; // ���Լ�������Ϊ Self

		// ����һ������ָ��
		Node* s_node;

		_list_iterator(Node* node)
			:s_node(node)
		{}

		// ���� * ����� --- �����ý���ָ�룬���ؽ�������
		// ����ֵ����Ϊ T& ,�����޸ķ���ֵ
		Ref& operator*()
		{
			return s_node->s_data;
		}

		// ���� -> �����
		Ptr operator->()
		{
			return &(s_node->s_data);
		}

		// ����ǰ�� ++ ����� --- ����++֮ǰ��ֵ
		// ����ֵ����Ϊ������
		Self& operator++()
		{
			s_node = s_node->s_next;
			return *this;
		}

		// ���� != �����
		bool operator!=(const Self& it) const
		{
			return s_node != it.s_node;
		}

		// ���� == �����
		bool operator==(const Self& it) const
		{
			return s_node == it.s_node;
		}

		// ���غ��� ++ ����� --- ����++֮���ֵ
		Self operator++(int)
		{
			Self tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// ����ǰ��--�����
		Self& operator--()
		{
			s_node = s_node->s_prev;
			return *this;
		}

		// ���غ���--�����
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

		// �������캯��
		list(const list<T>& lt)
		{
			empty_init();

			// ��������
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		// �����ų�ʼ��
		list(initializer_list<T> il)
		{
			empty_init();
			
			// ��������
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		// ��ֵ��������غ��� --- һ��д��
		list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				// ��� this �е�����
				clear();
				// ��������
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}

			return *this;
		}

		// swap ����
		void swap(list<T>& lt)
		{
			std::swap(m_head, lt.m_head);
		}

		// ��ֵ��������غ��� --- ����д��
		list<T>& operator=(list<T>& lt)
		{
			swap(lt);

			return *this;
		}

		// ��������
		~list()
		{
			clear();
			delete m_head;
			m_head = nullptr;
		}

		/*~list()
		{
			iterator it = begin();
			// ɾ�����
			while (it != end())
			{
				it = erase(it);
			}
			// ɾ���ڱ����
			delete m_head;
			// �ÿ�
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

		// insert ����
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

		// erase ����
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

		// push_front ����
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		// push_back ����
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		// pop_front ����
		void pop_front()
		{
			erase(begin());
		}

		// pop_back ����
		void pop_back()
		{
			erase(--end());
		}

		// clear ����
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				// ������ʧЧ
				it = erase(it);
			}
		}
        
		// size ����
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