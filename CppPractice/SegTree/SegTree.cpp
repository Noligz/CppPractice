#include "SegTree.h"

SegTree::SegTree()
{
	data = NULL;
	min = max = 0;
}

SegTree::SegTree(DATA_TYPE min, DATA_TYPE max)
{
	this->min = min;
	this->max = max;
	IDX_TYPE size = max - min;
	IDX_TYPE maxSize = -1;
	IDX_TYPE currSize = maxSize / 4 > size ? 4 * size : maxSize;
	data = new SegNode[currSize];
	Construct(0, min, max);
}

SegTree::~SegTree()
{
	delete [] data;
}

bool SegTree::IsInitialized()
{
	return data != NULL && min < max;
}

void SegTree::Construct(IDX_TYPE idx, DATA_TYPE left, DATA_TYPE right)
{
	if (!IsInitialized() || idx <0 || left > right)
		return;
	data[idx].left = left;
	data[idx].right = right;
	data[idx].isCovered = false;
	if (left < right - 1)//
	{
		DATA_TYPE mid = left + ((right - left) >> 1);
		Construct((idx << 1) + 1, left, mid);
		Construct((idx << 1) + 2, mid, right);//
	}
}

void SegTree::Insert(DATA_TYPE start, DATA_TYPE end)
{
	if (!IsInitialized())
		return;
	if (start < min)
		start = min;
	if (end > max)
		end = max;
	Insert(0, start, end);
}

void SegTree::Insert(IDX_TYPE idx, DATA_TYPE start, DATA_TYPE end)
{
	if (data[idx].isCovered)
		return;
	if (start == data[idx].left && end == data[idx].right)
	{
		data[idx].isCovered = true;
		return;
	}
	DATA_TYPE mid = data[idx].left + ((data[idx].right - data[idx].left) >> 1);
	if (mid >= end)
		Insert((idx << 1) + 1, start, end);
	else if (mid <= start)
		Insert((idx << 1) + 2, start, end);
	else
	{
		Insert((idx << 1) + 1, start, mid);//
		Insert((idx << 1) + 2, mid, end);//
	}
}

RET_TYPE SegTree::CoverLength()
{
	if (!IsInitialized())
		return -1;
	return CoverLength(0);
}

RET_TYPE SegTree::CoverLength(IDX_TYPE idx)
{
	if (data[idx].isCovered)
		return data[idx].right - data[idx].left;
	if (data[idx].left >= data[idx].right - 1)
		return 0;
	return CoverLength((idx << 1) + 1) + CoverLength((idx << 1) + 2);
}

RET_TYPE SegTree::CoverLength(DATA_TYPE start, DATA_TYPE end)
{
	if (!IsInitialized())
		return -1;
	if (start < min)
		start = min;
	if (end > max)
		end = max;
	return CoverLength(0, start, end);
}

RET_TYPE SegTree::CoverLength(IDX_TYPE idx, DATA_TYPE start, DATA_TYPE end)
{
	if (data[idx].isCovered)
		return end - start;
	if (data[idx].left >= data[idx].right - 1)
		return 0;
	DATA_TYPE mid = data[idx].left + ((data[idx].right - data[idx].left) >> 1);
	if (mid >= end)
		return CoverLength((idx << 1) + 1, start, end);
	else if (mid <= start)
		return CoverLength((idx << 1) + 2, start, end);
	else
		return CoverLength((idx << 1) + 1, start, mid) + CoverLength((idx << 1) + 2, mid, end);//
}