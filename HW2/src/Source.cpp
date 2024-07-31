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
		int aPos = 0;
		int bPos = 0;
		int biggest = -1;
		if (this->termArray[0].exp > other.termArray[0].exp) biggest = termArray[0].exp;
		else biggest = other.termArray[0].exp;

		while (biggest >= 0)
		{
			biggest--;
		}
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
	p.newTerm(2, 7);
	p.newTerm(2, 6);
	p.newTerm(2, 5);
	p.newTerm(2, 4);
	p.newTerm(2, 3);
	p.newTerm(2, 2);
	p.newTerm(2, 1);
	p.newTerm(2, 0);
	p.printPolynomial();
}
