# Problem-1 Ackermann Function

## 1. 解題說明

Find solution for recursive and non-recursive ackermann function.

The rules for ackermann function is as follows:

$`A(m,n) = \begin{cases}n+1 & \mbox{if } m = 0 \\A(m-1, 1) & \mbox{if } n = 0 \\A(m-1, A(m, n-1)) & otherwise.\end{cases}`$


Refer to implementation in `problem1.cpp`, the recursive function:

```cpp
int ackermann_r(int m, int n)
{
	if (m == 0) return n + 1;
	if (n == 0) return ackermann_r(m - 1, 1);
	return ackermann_r(m - 1, ackermann_r(m, n - 1));
}
```

and non-recursive counterpart：

```cpp
int ackermann_nr(int m, int n)
{
	stack<int> tracker;
	tracker.push(m);

	while (!tracker.empty())
	{
		m = tracker.top();
		tracker.pop();

		if (m == 0)
		{
			n += 1;
		}
		else if (n == 0)
		{
			tracker.push(m - 1);
			n = 1;
		}
		else
		{
			tracker.push(m - 1);
			tracker.push(m);
			n -= 1;
		}
	}
	return n;
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

By the rule when $`m \not= 0  and  n \not= 0`$ we can get $`A(0,A(1,0))`$

when $`m=0`$ $`A(0,A(0,1))`$

when $`m=0`$ $`A(0,2)`$

and we can get our final result $`3`$.
