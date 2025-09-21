#include <iostream>
#include <algorithm>

using namespace std;

namespace AY
{
	template<class T>
	struct list_node
	{
		T s_data;
		list_node<T>* s_prev;
		list_node<T>* s_next;

		list_node(const T& val = T())
			: s_data(val)
			, s_prev(nullptr)
			, s_next(nullptr)
		{}
	};

	/*
	template <class T>
	struct _list_iterator
	{
		typedef list_node Node;
		// ����һ��ָ��
		Node* s_node;

		// ��ʼ��ָ��
		_list_iterator(Node* node)
			: s_node(node)
		{}

		// ���� * ����� --- operator*
		T& operator*()
		{
			return s_node->s_data;
		}

		// ����ǰ��++ ����� --- ���ı���������
		_list_iterator<T>& operator++()
		{
			s_node = s_node->s_next;

			return *this;
		}

		// ����ǰ��-- ����� --- ���ı���������
		_list_iterator<T>& operator--()
		{
			s_node = s_node->s_prev;

			return *this;
		}

		// ���غ���++ �����
		_list_iterator<T>& operator++(T)
		{
			_list_iterator tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// ���غ���-- �����
		_list_iterator<T>& operator--(T)
		{
			_list_iterator tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}

		// ���� == �����
		bool operator==(const _list_iterator<T>& it) const
		{
			return s_node == it.s_node;
		}

		// ���� != �����
		bool operator!=(const _list_iterator<T>& it) const
		{
			return s_node != it.s_node;
		}
	};

	// const ������
	template <class T>
	struct _list_const_iterator
	{
		typedef list_node Node;

		Node* s_node;

		// ��ʼ��ָ��
		_list_const_iterator(Node* node)
			: s_node(node)
		{}

		// ���� * �����
		const T& operator*()
		{
			return s_node->s_data;
		}
	};
	*/

	template <class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> Self;
		// ����һ��ָ��
		Node* s_node;

		// ��ʼ��ָ��
		_list_iterator(Node* node)
			: s_node(node)
		{}

		// ���� * ����� --- operator*
		Ref& operator*()
		{
			return s_node->s_data;
		}

		// ���� -> �����
		Ptr operator->()
		{
			return &(s_node->s_data);
		}

		// ����ǰ��++ ����� --- ���ı���������
		Self& operator++()
		{
			s_node = s_node->s_next;

			return *this;
		}

		// ����ǰ��-- ����� --- ���ı���������
		Self& operator--()
		{
			s_node = s_node->s_prev;

			return *this;
		}

		// ���غ���++ �����
		Self& operator++(int)
		{
			Self tmp(*this);
			s_node = s_node->s_next;

			return tmp;
		}

		// ���غ���-- �����
		Self& operator--(int)
		{
			Self tmp(*this);
			s_node = s_node->s_prev;

			return tmp;
		}

		// ���� == �����
		bool operator==(const Self& it) const
		{
			return s_node == it.s_node;
		}

		// ���� != �����
		bool operator!=(const Self& it) const
		{
			return s_node != it.s_node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
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
		list()
		{
			m_head = new Node;
			m_head->s_prev = m_head;
			m_head->s_next = m_head;
		}

		// �������캯��
		list(const list<T>& lt)
		{
			//�����½ڵ�
			m_head = new Node;
			m_head->s_prev = m_head;
			m_head->s_next = m_head;

			// ��������
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		// �����ų�ʼ��
		list(initializer_list<T> il)
		{
			//�����½ڵ�
			m_head = new Node;
			m_head->s_prev = m_head;
			m_head->s_next = m_head;

			// ��������
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		// ��ֵ���غ��� --- ��һ��д��
		list<T>& operator=(const list<T>& lt)
		{
			// �����Լ���ֵ�Լ�
			if (*this != lt)
			{
				// ��� this �����е�����
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

		// ��ֵ���غ��� --- �ڶ���д��
		list<T>& operator=(list<T>& lt)
		{
			swap(lt);
		}

		// clear ����
		void clear()
		{
			// ɾ�����н��
			auto it = begin();
			while (it != end())
			{
				// ������ʧЧ --- ���µ�����
				it = erase(it);
			}
		}

		// ��������
		~list()
		{
			clear();
			// ɾ���ڱ����
			delete m_head;
			m_head = nullptr;
		}

		// push_back ���� --- β�庯��
		void push_back(const T& val)
		{
			// �����½ڵ�
			Node* newnode = new Node(val);
			// �ҵ�β���
			Node* tail = m_head->s_prev;

			// m_head newnode tail
			m_head->s_prev = newnode;
			newnode->s_prev = tail;
			newnode->s_next = m_head;
			tail->s_next = newnode;
		}

		// insert ����
		iterator insert(iterator pos, const T& val)
		{
			// �����½ڵ�
			Node* newnode = new Node(val);
			Node* cur = pos.s_node;
			Node* prev = cur->s_prev;

			// prev newnode cur
			prev->s_next = newnode;
			newnode->s_prev = prev;
			newnode->s_next = cur;
			cur->s_prev = newnode;

			// ����ָ���һ������Ԫ�صĵ����� --- nenwode
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

			// ����ɾ��Ԫ�ص���һ��Ԫ�صĵ����� --- next
			return next;
			// return iterator(next);
		}

		// push_front ���� -- ͷ��
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		// push_back ���� --- β��
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		// pop_front ���� --- ͷɾ
		void pop_front()
		{
			earse(begin());
		}

		// pop_back ���� --- βɾ
		void pop_back()
		{
			// end �����ķ���ֵΪ m_head�������ܶ�
			// ɾ������ m_head->s_prev��Ҳ���� --end()
			erase(--end());
		}

		// size ����
		size_t size()
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
}