#include "BigInt.h"

void BigInt::Init()
{
	m_element = new unsigned int[MAXBIT];
	for(int i = 0; i < MAXBIT; i++)
		m_element[i] = 0;
	m_isRefined = false;
}

inline BigInt::BigInt()
{
	Init();
}

BigInt::BigInt(const BigInt& x)
{
	m_element = new unsigned int[MAXBIT];
	m_isRefined = false;
	for(int i = 0; i < MAXBIT; i++)
		m_element[i] = x.GetElement(i);
	Refine();
}

inline bool BigInt::isNegtive() const
{
	return m_element[MAXBIT - 1] > 0;
}

BigInt::BigInt(char* n)
{
	if(n == NULL)
		return;

	Init();
	int len = strlen(n);
	int numBegin = 0;

	if(*n == '-')
	{
		if(len <= 1)
			return;
		numBegin = 1;
	}

	int index = 0;
	for(int i = len - 1; i >= numBegin && index <= MAXBIT;)
	{
		m_element[index] = 0;
		for(int j = 1; j < JINZHI && i >= numBegin; j *= 10)
		{
			//if(n[i] == ' ' || n[i] == ',')
			//	continue;
			if(n[i] < '0' || n[i] > '9')
				return;
			m_element[index] += (n[i] - '0') * j;
			i--;
		}
		index++;
	}


	if(*n == '-')
	{
		m_element[MAXBIT - 1] = JINZHI - 1;
		ToComplement();
	}

	m_isRefined = false;
}

inline BigInt::~BigInt()
{
	delete[] m_element;
}

int BigInt::GetElement(int i) const
{
	if(i < 0 || i >= MAXBIT)
		return -1;
	return m_element[i];
}

void BigInt::SetElenemt(int i, int n)
{
	if(i < 0 || i >= MAXBIT)
		return;
	if(n < 0)
		return;
	m_element[i] = n;
	m_isRefined = false;
}

void BigInt::Refine()
{
	if(m_isRefined)
		return;
	int carry = 0;
	for(int i = 0; i < MAXBIT; i++)
	{
		m_element[i] += carry;
		if(m_element[i] >= JINZHI)
		{
			carry = m_element[i] / JINZHI;
			m_element[i] = m_element[i] % JINZHI;
		}
		else
			carry = 0;
	}
	m_isRefined = true;
}

void BigInt::ToComplement()
{
	Refine();
	for(int i = 0; i < MAXBIT - 1; i++)
		m_element[i] = JINZHI - 1 - m_element[i];
	m_element[0] += 1;
	Refine();
}

void BigInt::ToOposite()
{
	m_element[MAXBIT - 1] = JINZHI - 1 - m_element[MAXBIT - 1];
	ToComplement();
}

void BigInt::Print() const
{
	if(isNegtive())
	{
		std::cout << "-";
		BigInt tmp(*this);
		tmp.ToOposite();
		tmp.Print();
	}
	else
	{
		int i = MAXBIT - 2;
		while(m_element[i] == 0 && i > 0)
			i--;
		std::cout << m_element[i] << " ";
		i--;
		for(; i >= 0; i--)
		{
			for(int tmp = JINZHI / 10; m_element[i] / tmp == 0 && tmp > 1; tmp /= 10)
				std::cout << 0;
			std::cout << m_element[i] << " ";
		}
	}
}

BigInt& BigInt::Abs() const
{
	BigInt* result = new BigInt(*this);
	if(isNegtive())
		result->ToOposite();
	return *result;
}

BigInt& BigInt::operator+(const BigInt& x) const
{
	BigInt* result = new BigInt();

	for(int i = 0; i < MAXBIT; i++)
		result->SetElenemt(i, GetElement(i) + x.GetElement(i));

	result->Refine();
	return *result;
}

BigInt& BigInt::operator-(const BigInt& x) const
{
	BigInt tmp(x);
	tmp.ToOposite();
	return *this + tmp;
}

BigInt& BigInt::operator*(const BigInt& x) const
{
	BigInt* result = new BigInt();
	BigInt a = Abs();
	BigInt b = x.Abs();

	for(int i = 0; i < MAXBIT - 1; i++)
	{
		if(x.GetElement(i) == 0)
			continue;
		for(int j = 0; j < MAXBIT - 1; j++)
		{
			if(a.GetElement(j) == 0)
				continue;
			result->SetElenemt(i + j, result->GetElement(i + j) + a.GetElement(j) * x.GetElement(i));
		}

		result->Refine();
	}

	if(isNegtive() == x.isNegtive())
		result->SetElenemt(MAXBIT - 1, 0);
	else
		result->SetElenemt(MAXBIT - 1, JINZHI - 1);

	return *result;
}