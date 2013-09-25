#include <iostream>

#ifndef BIGINT 
#define BIGINT

#define MAXBIT 20
#define JINZHI 10000

class BigInt
{
private:
	unsigned int* m_element;
	bool m_isRefined;

private:
	void Init();
public:
	BigInt();
	BigInt(const BigInt& x);
	BigInt(char* n);
	~BigInt();
	int GetElement(int i) const;
	void SetElenemt(int i, int n);
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