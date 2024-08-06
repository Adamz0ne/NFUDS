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
	if (this->termArray[0].exp > other.termArray[0].exp)
		biggest = this->termArray[0].exp;
	else
		biggest = other.termArray[0].exp;

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
	for (int i = 0; i < this->terms; i++)
	{
		Polynomial temp;
		for (int j = 0; j < other.terms; j++)
		{
			cTemp = this->termArray[i].coef * other.termArray[j].coef;
			eTemp = this->termArray[i].exp + other.termArray[j].exp;
			temp.newTerm(cTemp, eTemp);
		}
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
		for (int i = 0; i < terms; i++)
		{
			cout << termArray[i].coef * pow(f, termArray[i].exp) << endl;
			out += termArray[i].coef * pow(f, termArray[i].exp);
		}
		return out;
	}
```
## 2. 演算法設計與實作

```cpp
int main()
{
	int m, n;
	cin >> m >> n; //Input m and n	
	cout << "Recursive:    " << ackermann_r (m, n) << endl; //Output for recusive solution
	cout << "Non-Recursive:" << ackermann_nr(m, n) << endl; //Output for non-recusive solution
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
