#pragma once
#include<vector>
#include <iostream>
#include <queue>

// �º���
template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

namespace AY
{
	// ���ȼ�������һ������������
	// priority_queue�ĵײ��Ƕ�
	// �ѵĵײ������飬ʹ��vector��Ϊ���ȶ��еĵײ����ݽṹ
	// ��� --- Less  С�� --- Greater
	template<class T, class Container = std::vector<T>, class Compare = Less<T>>
	class priority_queue
	{
		// Ĭ���Ǵ��
	private:
		// ��������
		template<class T>
		void swap(T& r1, T& r2)
		{
			T tmp = r1;
			r1 = r2;
			r2 = tmp;
		}
		// ���ϵ��������㷨
		// ����ָ���ǲ������������
		void AdjustUp(int child)
		{
			Compare cmp;
			// ѭ������
			// ������������ֹͣ����,�� child = 0
			while (child > 0)
			{
				int parent = (child - 1) / 2;
				// ������Ϸţ�С�����·�
				//if (_cont[child] > _cont[parent])
				// ��� --- Less  С�� --- Greater
				if(cmp(_cont[parent], _cont[child]))
				{
					swap(_cont[parent], _cont[child]);
					// �ƶ� child ��λ��
					child = parent;
				}
				// С�ڵ��ڣ��ͽ�������
				else
				{
					break;
				}
			}
		}
		// ���µ��������㷨
		// ����ָ���Ǹ��������
		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1; // ����
			Compare cmp;
			// �ø���������Һ����д���Ǹ������бȽ�
			// �ô�����Ϸţ�С�����·�
			// �����±겻��Խ��
			while (child < _cont.size())
			{
				// �����Һ����д���Ǹ�����
				// child + 1 < _cont.size() ��Ϊ���ж��Һ����Ƿ����
				if (child + 1 < _cont.size() && _cont[child + 1] > _cont[child])
				{
					child++;
				}
				
				// ���ӽ����ڸ���㣬����
				//if (_cont[child] > _cont[parent])
				// ��� --- Less  С�� --- Greater
				if (cmp(_cont[parent], _cont[child]))
				{
					swap(_cont[child], _cont[parent]);
					// child �� parnet ������
					parent = child;
					child = parent * 2 + 1;
				}
				// ���ӽ��С�ڵ��ڸ���㣬������ϣ�����ѭ��
				else
				{
					break;
				}
			}
		}

	public:
		// ǿ�Ʊ�����Ĭ�����ɹ��캯��
		// �Եײ��������ʼ��
		priority_queue() = default;

		// �����������ʼ��
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			: _cont(first, last)
		{
			// ʹ�����µ����㷨����,���µ������ѵ��㷨��Ч�ʸ���
			for (int i = (_cont.size() - 1 - 1) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}
		// ���
		void push(const T& val)
		{
			// β��
			_cont.push_back(val);
			
			// ���ϵ������� --- �Ӷ�β��ʼ����
			AdjustUp(_cont.size() - 1);
		}

		// ���Ѷ�����
		void pop()
		{
			// ���Ѷ��������β���ݽ���
			swap(_cont[0], _cont[_cont.size() - 1]);
			// ��ɾ����βԪ��
			_cont.pop_back();
			// ���µ������� --- �Ӷ�ͷ��ʼ
			AdjustDown(0);
		}

		// ȡ�Ѷ�����
		T& top()
		{
			// ȡ���ȼ����е�һ��Ԫ��
			return _cont[0];
		}

		// �ж϶��Ƿ�Ϊ��
		bool empty()
		{
			return _cont.empty();
		}

		// ��ȡ������ЧԪ�ظ���
		size_t size()
		{
			return _cont.size();
		}
	private:
		Container _cont;
	};
}