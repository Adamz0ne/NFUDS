# Polynoamil

## 1. 解題說明

Implement polynomial class as shown in its ADT,

including add, mult and eval,

also overload both cin(>>) and cout(<<).

For example:

$`p(x)=2x^5+3x^4+4x^3+8x^2+7x+9`$

$`q(x)=3x^4+7x^2+8x+19`$

The result of $`p(x)+q(x)`$ should be:

$`2x^5+6x^4+4x^3+15x^2+15x+28`$

Refer to implementation in `Source.cpp`, the add implementation:

```cpp
Polynomial Add(const Polynomial& other)
{
	Polynomial out;
	int aPos = 0;
	int bPos = 0;
	int biggest = -1;
	//Decide which polynomial contains greater degree
	if (this->termArray[0].exp > other.termArray[0].exp)
		biggest = this->termArray[0].exp;
	else
		biggest = other.termArray[0].exp;

	//Loop from max degree to 0
	//When finding the same as current degree add it's coefficient to output
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

```


The result of $`p(x)*q(x)`$ should be:

$`6x^9+9x^8+26x^7+61x^6+111x^5+172x^4+189x^3+271x^2+205x +171`$

Refer to implementation in `Source.cpp`, the mult implementation:

```cpp
Polynomial Mult(const Polynomial& other)
{
	Polynomial out;
	float cTemp = 0;
	int eTemp = 0;
	//Nested loop to multply each term of a function to the other
	for (int i = 0; i < this->terms; i++)
	{
		//Temporary variavle to store current result
		Polynomial temp;
		for (int j = 0; j < other.terms; j++)
		{
			//Multply the coefficient of both polynomial
			cTemp = this->termArray[i].coef * other.termArray[j].coef;
			//Add the exponent of both polynomial
			eTemp = this->termArray[i].exp + other.termArray[j].exp;
			//Store current result to temp
			temp.newTerm(cTemp, eTemp);
		}
		//Add current result to output
		out = out.Add(temp);
	}
	return out;
}
```

The result of $`p(2.5)`$ should be:

$`451.5`$

Refer to implementation in `Source.cpp`, the eval implementation:

```cpp
float Eval(float f)
{
	float out = 0;
	//Loop through all terms and adds the result to output
	//Following the rule c*f^e
	for (int i = 0; i < terms; i++)
	{
		out += termArray[i].coef * pow(f, termArray[i].exp);
	}
	return out;
}
```

When inputting data to class,should use overloaded cin(>>),

Refer to implementation in `Source.cpp`, the cin overloading implementation:

```cpp
istream& operator>>(istream& is, Polynomial& polynomial)
{
	float c;
	int e;
	//We suppose user doesn't do unallowed input
	//pipe from input stream to two temporary variable
	is >> c >> e;
	//Terminate condition
	//Implementing like this needs to clear failbit after
	if (c == 0 && e == 0.0f)
	{
		is.setstate(std::ios::failbit);
		return is;
	}
	//Adding new term by using newTerm member function
	polynomial.newTerm(c, e);
	return is;
}
```

When representing the result should use overloaded cout(<<),

Refer to implementation in `Source.cpp`, the cout overloading implementation:

```cpp
ostream& operator<<(ostream& os, const Polynomial& polynomial)
{
	int i = 0;//Index to loop through all terms
	//Loop through all terms and pipe into output stream
	//Then return the result 
	while (1)
	{
		//Handle constant case
		if (polynomial.termArray[i].exp == 0)
		{
			os << polynomial.termArray[i].coef;
		}
		//Handle exponent=1 case
		if (polynomial.termArray[i].exp == 1)
		{
			if (polynomial.termArray[i].coef == 1)
				os << "x";
			else
				os << polynomial.termArray[i].coef << "x";
		}
		//Handle any other case
		if (polynomial.termArray[i].exp > 1)
		{
			if (polynomial.termArray[i].coef == 1)
				os << "x^" << polynomial.termArray[i].exp;
			else
				os << polynomial.termArray[i].coef << "x^" << polynomial.termArray[i].exp;
		}
		i++;
		if (i == polynomial.terms)break;
		os << " + ";
	}
	return os;
}
```

## 2. 演算法設計與實作

```cpp
int main()
{
	Polynomial p;
	Polynomial q;

	while (cin >> p);//overloaded cin
	cin.clear();//clear cin state

	while (cin >> q);
	cin.clear();

	cout << "p(x) = " << p << endl;//overloaded cout
	cout << "q(x) = " << q << endl;
	cout << "p(x) + q(x) = " << p.Add(q) << endl;//Add p and q and cout
	cout << "p(x) * q(x) = " << p.Mult(q) << endl;//Multply p and q and cout

	cout << "p(2.5) = " << p.Eval(2.5) << endl;//Evaluate p(x) at 2.5
}
```

## 2. 效能分析

- Due to the complexity and non primitive recursive nature of ackermann function, I can't find a definitive answer for it.

## 3. 測試與過程

### Input

```plain
3 3

```

### Output

```plain

Recursive:    61
Non-Recursive:61

```

### 驗證

This function terminate and returns output when $`m=0`$ recursively.

In the recursive one we can just write an easy recursive function by following the rule set,

On the other hand the non-recursive one, we need to keep track of m,

by pushing m onto a stack manually we can get the same answer as the recursive way.

I tried to write the structure as similar as the recursive one.

Which for example: 

$`A(1,1)`$

By the rule when $`m \not= 0`$ and $`n \not= 0`$ we can get $`A(0,A(1,0))`$,

when $`n=0`$ we can get $`A(0,A(0,1))`$,

when $`m=0`$ we can get $`A(0,2)`$,

and we can get our final result of $`3`$.
