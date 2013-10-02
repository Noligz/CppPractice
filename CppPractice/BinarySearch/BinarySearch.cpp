/* binsearch Ѱ��key�±꣬������ return -1 */

/* binsearch ע��㡾�Ҳ��� vs ��ѭ����
* 1. left <= right ���Ϊ left < right �����Ҳ���key
*    ���� 1 2 3 4 5��key=5; left==rightʱ����ѵ�key
* 2. left = mid + 1;
*    ����left��Ϊ=mid��������ѭ���������������ӣ�
*    ��leftָ��4ʱ��rightָ��5����ʱ����ѭ����
*    ��ѭ���ĸ���ԭ������left��������ָ��left��right����
*    left������Զ����mid����right������Ϊ����mid��ѭ��
*/
int binsearch(int * arr, int lef, int rig, int key)
{
	if (!arr)    return -1;
	int left = lef, right = rig;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}

/* binsearch_min ����key(�������ظ�)��һ�γ��ֵ��±꣬����return -1
*
* binsearch_min ע��㡾��ѭ����
* 1. ���while(left < right)��Ϊ(left <= right)������ѭ����
* 2. ѭ������������left == right
*
* �ô����Ҳ����˺ܶ�������û���ַ���������Ϊ�ǶԵ�
* �����϶����õ�left<right-1���������ֱ��arr[left]��arr[right]
* ���м�飻����Ϊ��д�ĸ�������ϣ������Ȥ�Ķ��߰�æreview��δ���
* �緢�ַ���ָ�����󣬸м���������
*/
int binsearch_min(int * arr, int lef, int rig, int key)
{
	if (!arr)    return -1;
	int left = lef, right = rig;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	if (arr[left] == key)    return left;
	return -1;
}

/* binsearch_max ����key(�������ظ�)���һ�γ��ֵ��±꣬����return -1
*
* binsearch_max ע��㡾��ѭ�� vs Խ��Ŀ��λ�á�
* 1. �����Ϊwhile(left < right)������ѭ����
* 2. ���left=mid��Ϊleft=mid+1�����п���Խ��Ŀ��λ��
* 3. ѭ������������left == right || left == right -1
*
* ���Ҫ���ǣ������ĵȺŷ�<=key��λ�ã�����С�ĵȺŷ�>=keyλ��
*/
int binsearch_max(int * arr, int lef, int rig, int key)
{
	if (!arr)    return -1;
	int left = lef, right = rig;
	while (left < right - 1)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] <= key)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	if (arr[right] == key) // ��max�����ж�right
	{
		return right;
	}
	else if (arr[left] == key)
	{
		return left;
	}
	else
		return -1;
}

/* binsearch_justsmall ���ظպ�С��key��Ԫ���±꣬����return -1
*
* binsearch_justsmall ע��㡾��ѭ�� vs Խ��Ŀ��λ�á�
* 1. �����Ϊwhile(left < right)������ѭ������Ϊleft=mid��Ե��
* 2. ���left=mid��Ϊleft=mid+1�����п���Խ��Ŀ��λ��
* 3. ѭ������������left == right || left == right -1
*/
int binsearch_justsmall(int * arr, int lef, int rig, int key)
{
	if (!arr)    return -1;
	int left = lef, right = rig;
	while (left < right - 1)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] < key)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (arr[right] < key) // �Ҹպ�С�ڣ����ж�right
	{
		return right;
	}
	else if (arr[left] < key)
	{
		return left;
	}
	else
		return -1;
}

/* binsearch_justgreat ���ظպô���key��Ԫ���±꣬����return -1
*
* binsearch_justgreat ע��㡾��ѭ�� vs ���Ԫ���Ƿ����key��
* 1. �����Ϊwhile(left <= right)������ѭ������Ϊright = mid��
* 2. ���ע����arr[right]�Ƿ����key
* 3. ѭ������������left == right
*/
int binsearch_justgreat(int * arr, int lef, int rig, int key)
{
	if (!arr)    return -1;
	int left = lef, right = rig;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] <= key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	if (arr[right] > key) return right;
	return -1;
}