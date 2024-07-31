#include <iostream>

using namespace std;

class Polynomial;

class Term
{
	friend Polynomial;
private:
	float coef;
	int exp;
};

class Polynomial {
private:
	Term* termArray;
	int capacity;
	int terms;
public:
	Polynomial()
	{
		capacity = 2;
		terms = 0;
		termArray = new Term[capacity];
	}
	void newTerm(float c, int e)
	{
		if (capacity == terms)
		{
			Term* temp = new Term[capacity];
			copy(termArray,termArray + terms, temp);
			capacity *= 2;
			delete[] termArray;
			termArray = new Term[capacity];
			copy(temp, temp + terms, termArray);
			delete[] temp;
			cout << capacity << endl;
		}
		termArray[terms].coef = c;
		termArray[terms].exp = e;
		cout << "(" << c << ", " << e << ")" << endl;
		terms++;
	}
	Polynomial Add(Polynomial other)
	{
		Polynomial out;
		int aPos = 0;
		int bPos = 0;
		int biggest = -1;
		if (this->termArray[0].exp > other.termArray[0].exp) biggest = termArray[0].exp;
		else biggest = other.termArray[0].exp;

		while (biggest >= 0)
		{
			int c = 0;
			if (this->termArray[aPos].exp == biggest)
			{
				c += this->termArray[aPos].coef;
				aPos++;
			}
			if (other.termArray[bPos].exp == biggest)
			{
				c += other.termArray[bPos].coef;
				bPos++;
			}
			if (c != 0)
			{
				out.newTerm(c, biggest);
			}
			biggest--;
		}
		return out;
	}
	void printPolynomial()
	{
		int i = 0;
		while (1)
		{
			if (termArray[i].exp == 0)
			{
				cout << termArray[i].coef;
			}
			if (termArray[i].exp == 1)
			{
				cout << termArray[i].coef << "x";
			}
			if (termArray[i].exp > 1)
			{
				cout << termArray[i].coef << "x^" << termArray[i].exp;
			}
			i++;
			if (i == terms)break;
			cout << " + ";
		}
		cout << endl;
	}
};

int main()
{
	Polynomial p;
	Polynomial q;
	p.newTerm(1, 7);
	p.newTerm(2, 6);
	p.newTerm(3, 5);
	p.newTerm(4, 4);
	q.newTerm(5, 3);
	q.newTerm(6, 2);
	q.newTerm(7, 1);
	q.newTerm(8, 0);
	p.printPolynomial();
	q.printPolynomial();
	cout << "--------------------" << endl;
	p = p.Add(q);
	p.printPolynomial();
}
