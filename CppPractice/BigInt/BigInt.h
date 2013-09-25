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
	void Refine();
	void ToComplement();
	void ToOposite();
	long long GetElement(long long i) const;
	void SetElenemt(long long i, long long n);
public:
	BigInt();
	BigInt(const BigInt&);
	BigInt(char* n);
	BigInt(long long);
	virtual ~BigInt();
	bool isNegtive() const;
	BigInt& Abs() const;
	BigInt& operator + (const BigInt&) const;
	BigInt& operator - (const BigInt&) const;
	BigInt& operator * (const BigInt&) const;
	BigInt& operator / (const BigInt&) const;
	BigInt& operator % (const BigInt&) const;
	BigInt& operator = (const BigInt&) const;
	bool operator == (const BigInt& x) const;
	bool operator > (const BigInt& x) const;
	bool operator >= (const BigInt& x) const;
	bool operator < (const BigInt& x) const;
	bool operator <= (const BigInt& x) const;
	friend std::istream& operator >> (std::istream&, BigInt&);
	friend std::ostream& operator << (std::ostream&, const BigInt&);
	friend BigInt& abs(const BigInt&);
};

#endif