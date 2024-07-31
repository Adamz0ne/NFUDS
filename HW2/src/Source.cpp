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
		}

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
};

int main()
{
	
}