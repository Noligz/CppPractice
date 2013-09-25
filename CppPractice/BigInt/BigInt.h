#include <iostream>

#ifndef BIGINT 
#define BIGINT

#define MAXBIT 20
#define JINZHI 1000000000

class BigInt
{
private:
	unsigned long long* m_element;
	bool m_isRefined;

private:
	void Init();
public:
	BigInt();
	BigInt(const BigInt& x);
	BigInt(char* n);
	~BigInt();
	long long GetElement(long long i) const;
	void SetElenemt(long long i, long long n);
	bool isNegtive() const;
	void Refine();
	void ToComplement();
	void ToOposite();
	BigInt& Abs() const;
	void Print() const;
	BigInt& operator+ (const BigInt& x) const;
	BigInt& operator- (const BigInt& x) const;
	BigInt& operator* (const BigInt& x) const;
	BigInt& operator/ (const BigInt& x) const;
	BigInt& operator% (const BigInt& x) const;
};

#endif