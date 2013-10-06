#ifndef __SEGTREE
#define __SEGTREE
#include <iostream>

#define DATA_TYPE long long
#define IDX_TYPE unsigned long long
#define RET_TYPE unsigned long long

class SegTree
{
public:
	SegTree();
	SegTree(DATA_TYPE min, DATA_TYPE max);
	~SegTree();
	void Insert(DATA_TYPE start, DATA_TYPE end);
	RET_TYPE CoverLength();
	RET_TYPE CoverLength(DATA_TYPE start, DATA_TYPE end);
	bool IsInitialized();

private:
	class SegNode
	{
		friend class SegTree;
		bool isCovered;
		DATA_TYPE left, right;
	};
	SegNode* data;
	DATA_TYPE min, max;
	void Construct(IDX_TYPE idx, DATA_TYPE left, DATA_TYPE right);
	void Insert(IDX_TYPE idx, DATA_TYPE start, DATA_TYPE end);
	RET_TYPE CoverLength(IDX_TYPE idx);
	RET_TYPE CoverLength(IDX_TYPE idx, DATA_TYPE start, DATA_TYPE end);
};

#endif