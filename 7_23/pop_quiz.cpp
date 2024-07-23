#include <iostream>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

class Data
{
private:
	int date;
	int month;
	int day;
	string name;
public:
	Data() { month = 0; day = 0; name = ""; date = 0; }
	// Here we suppose all month having 30 days
	Data(int m, int d, string n) : month(m), day(d), name(n) { date = month * 30 + day; }
	void setData(int m, int d, string n)
	{
		month = m;
		day = d;
		name = n;
		date = month * 30 + day;
	}
	int getDate() { return date; }
	int getDay() { return day; }
	int getMonth() { return month; }
	string getName() { return name; }
};

int main()
{
	stack<int> a;
	int minimum = 365;
	int target = 7 * 30 + 23;
	string nTemp;
	int dTemp;
	int mTemp;
	Data all[10]; 
	//Consider that the quiz always having 10 data or else would've use stack
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter Name: ";
		cin >> nTemp;
		cout << "Enter Month: ";
		cin >> mTemp;
		cout << "Enter Day: ";
		cin >> dTemp;
		all[i].setData(mTemp, dTemp, nTemp);
	}
	for (int i = 0; i < 10; i++)
	{
		// If finds a new minimum, pop current minimum stack, and push new minimum index
		if (minimum > abs(all[i].getDate() - target))
		{
			while (!a.empty())
			{
				a.pop();
			}
			minimum = abs(all[i].getDate() - target);
			a.push(i);
		}
		else if (minimum > abs(target - all[i].getDate()))
		{
			while (!a.empty())
			{
				a.pop();
			}
			minimum = abs(target - all[i].getDate());
			a.push(i);
		}
		// If finds the same as current minimum, push index to stack
		else if (minimum == abs(all[i].getDate() - target))
		{
			a.push(i);
		}
		else if (minimum == abs(target - all[i].getDate()))
		{
			a.push(i);
		}
	}
	// Output according to index stack
	while(!a.empty())
	{
		cout << "Closest date is " << all[a.top()].getName() << " at "
			<< all[a.top()].getMonth() << "/" << all[a.top()].getDay() << endl;
		a.pop();
	}	
}

/*
Sample Data
A
1
31
B
3
2
C
5
1
D
7
22
E
7
24
F
4
9
G
5
20
H
12
15
I
10
10
J
2
19
*/