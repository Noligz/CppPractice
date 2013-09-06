#include <vector>

template <typename T>
class Heap
{
private:
	std::vector<T> data;

protected:
	void FixUp(int idx);
	void FixDown(int idx);
	virtual bool Compare(const T a, const T b) const = 0;
	void Copy(const Heap<T>& origin);

public:
	Heap();
	Heap(const Heap<T>& origin);
	~Heap();
	void Add(const T element);
	T Top() const;
	void Pop();
	void Print() const;
	Heap<T>& operator=(const Heap<T>& origin);
};

template<typename T>
class MinHeap : public Heap<T>
{
protected:
	bool Compare(const T a, const T b) const { return a < b; }
};

template<typename T>
class MaxHeap : public Heap<T>
{
protected:
	bool Compare(const T a, const T b) const { return a > b; }
};





template <typename T>
Heap<T>::Heap()
{
	data.reserve(10);
}

template <typename T>
Heap<T>::~Heap()
{
	data.clear();
}

template<typename T>
void Heap<T>::Copy(const Heap<T>& origin)
{
	if (this == &origin)
		return;

	data.clear();
	data = origin.data;
}

template <typename T>
Heap<T>::Heap(const Heap<T>& origin)
{
	Copy(origin);
}

template<typename T>
Heap<T>& Heap<T>::operator=(const Heap<T>& origin)
{
	Copy(origin);
	return *this;
}

template <typename T>
void Heap<T>::FixDown(int idx)
{
	if (idx < 0 || idx >= data.size())
		return;

	T tmp = data[idx];
	int parentIdx = idx;
	int childIdx = idx * 2 + 1;
	while (childIdx < data.size())
	{
		if (childIdx + 1 < data.size() && Compare(data[childIdx + 1], data[childIdx]))
			childIdx++;
		if (Compare(data[childIdx], tmp))
		{
			data[parentIdx] = data[childIdx];
		}
		else
		{
			break;
		}
		parentIdx = childIdx;
		childIdx = childIdx * 2 + 1;
	}
	data[parentIdx] = tmp;
}

template <typename T>
void Heap<T>::FixUp(int idx)
{
	if (idx < 0 || idx >= data.size())
		return;

	T tmp = data[idx];
	int parentIdx = (idx - 1) / 2;
	int childIdx = idx;
	while (childIdx > 0)
	{
		if (Compare(tmp, data[parentIdx]))
			data[childIdx] = data[parentIdx];
		else
			break;
		childIdx = parentIdx;
		parentIdx = (parentIdx - 1) / 2;
	}
	data[childIdx] = tmp;

	FixDown(0);
}

template <typename T>
void Heap<T>::Add(const T element)
{
	data.push_back(element);
	FixUp(data.size() - 1);
}

template <typename T>
T Heap<T>::Top() const
{
	if (data.size() > 0)
		return data[0];
	else
		return NULL;
}

template <typename T>
void Heap<T>::Pop()
{
	if (data.size() > 0)
	{
		data[0] = data[data.size() - 1];
		data.pop_back();
		FixDown(0);
	}
}

template <typename T>
void Heap<T>::Print() const
{
	std::vector<T>::const_iterator iter;
	for (iter = data.begin(); iter != data.end(); iter++)
	{
		cout << *iter << "\t";
	}
	cout << endl;
}