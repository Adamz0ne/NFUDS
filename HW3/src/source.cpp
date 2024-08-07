#include <iostream>

using namespace std;

template <class T> class CircularList;

struct Term {
	int coef;
	int exp;
	Term Set(int c, int e) { coef = c; exp = e; return *this; }
};

template <class T>
class Node {
	friend istream& operator>>(istream& is, Polynomial& x);
	friend ostream& operator<<(ostream& os, Polynomial& x);
	friend class CircularList<T>;
private:
	T data;
	Node<T>* link;
};

template <class T>
class CircularList {
private:
	Node<T>* headerNode;
	Node<T>* last;
	Node<T>* avalibleList;
public:
	CircularList()
	{
		avalibleList = nullptr;
		headerNode = new Node<T>;
		headerNode->link = headerNode;
		last = headerNode;
	}

	Node<T>* GetNode()
	{
		Node<T>* x;
		if (avalibleList)
		{
			x = avalibleList;
			avalibleList = avalibleList->link;
		}
		else
		{
			x = new Node<T>;
		}
		return x;
	}

	void RetNode(Node<T>*& x)
	{
		x->link = avalibleList;
		avalibleList = x;
		x = nullptr;
	}

	~CircularList()
	{
		if (last != headerNode)
		{
			Node<T>* first = headerNode->link;
			last->link = avalibleList;
			avalibleList = first;
			last = 0;
		}
	}
};

class Polynomial {
	friend istream& operator>>(istream& is, Polynomial& x);
	friend ostream& operator<<(ostream& os, Polynomial& x);
private:
	CircularList<Term> poly;
public:
	Polynomial() {}
	void NewTerm(int c, int e)
	{
		Node<Term> x
	}

};

istream& operator>>(istream& is, Polynomial& x) {

}
ostream& operator<<(ostream& os, Polynomial& x) {

}

int main()
{

	int a;
}
