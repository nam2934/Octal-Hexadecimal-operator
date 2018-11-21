#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Calculator
{
  public:
	Calculator();
	void setNum(char arr[], int size, char type);
	friend const Calculator operator+(const Calculator &ref1, const Calculator &ref2);
	friend const Calculator operator-(const Calculator &ref1, const Calculator &ref2);
	friend const bool operator>(const Calculator &ref1, const Calculator &ref2);
	friend const bool operator<(const Calculator &ref1, const Calculator &ref2);
	friend const bool operator==(const Calculator &ref1, const Calculator &ref2);
	friend ostream &operator<<(ostream &outputStream, const Calculator &ref2);

  private:
	long long total_value;
};

int main()
{
	//make a Char variable : Welcome_Menu_Option
	//Welcome_Menu_Option is must be 0 or 1
	int length1, length2;
	char Welcome_Menu_Option;
	char Select_Option;
	char num1[6];
	char num2[6];

	//print Menu
	while (true)
	{
		cout << "===============Menu===============" << endl
			 << "1:Program start 0:program End" << endl
			 << "Menu Option : ";

		cin >> Welcome_Menu_Option;

		switch (Welcome_Menu_Option)
		{
		case '0':
			cout << "Exit the program" << endl;
			return 0;
		case '1':
			cout << "Welcome to Calculator!" << endl;
			break;
		default:
			cout << "Wrong Input!" << endl;
			continue;
		}
		while (true)
		{

			cout << "Select the Calculator(Octal calculator(O) Hexadecimal calculator(H)) : ";
			cin >> Select_Option;
			cout << endl;

			switch (Select_Option)
			{
			case 'O':
				while (true)
				{
					bool flag = true;

					cout << "Input num1 : ";
					cin >> num1;

					length1 = strlen(num1);
					for (int i = 0; i < length1; i++)
					{

						if ((48 <= num1[i]) && (num1[i] <= 55))
							continue;
						else
						{
							flag = false;
							break;
						}
					}

					if (flag == true)
						break;
					else
					{
						cout << "Wrong Input!" << endl;
						continue;
					}
				}
				while (true)
				{
					bool flag2 = true;

					cout << "Input num2 : ";
					cin >> num2;

					length2 = strlen(num2);

					for (int i = 0; i < length2; i++)
					{

						if ((48 <= num2[i]) && (num2[i] <= 55))
							continue;
						else
						{
							flag2 = false;
							break;
						}
					}

					if (flag2 == true)
						break;
					else
					{
						cout << "Wrong Input!" << endl;
						continue;
					}
				}
				break;
			case 'H':
				while (true)
				{
					bool flag = true;

					cout << "Input num1 : ";
					cin >> num1;

					length1 = strlen(num1);
					for (int i = 0; i < length1; i++)
					{

						if (((48 <= num1[i]) && (num1[i] <= 57)) || ((65 <= num1[i]) && (num1[i] <= 70)))
							continue;

						else
						{
							flag = false;
							break;
						}
					}

					if (flag == true)
						break;
					else
					{
						cout << "Wrong Input!" << endl;
						continue;
					}
				}

				while (true)
				{
					bool flag2 = true;
					cout << "Input num1 : ";
					cin >> num2;
					length1 = strlen(num2);

					for (int i = 0; i < length2; i++)
					{

						if (((48 <= num2[i]) && (num2[i] <= 57)) || ((65 <= num2[i]) && (num2[i] <= 70)))
							continue;
						else
						{
							flag2 = false;
							break;
						}
					}

					if (flag2 == true)
						break;

					else
					{
						cout << "Wrong Input!" << endl;
						continue;
					}
				}
				break;
			default:
				cout << "Wrong Input!" << endl;
				continue;
			}

			cal1.setNum(num1,length1,Select_Option);
			cal2.setNum(num2,length2,Select_Option);
			
			cout << endl;
			cout << "1. num1 + num2 : "<< cal1+cal2 <<endl;
			cout << "2. num2 – num1 : "<< cal2-cal1 <<endl;
			cout << "3. num1 == num2 : "<< ((cal1 == cal2) ? "true":"false") <<endl; 
			cout << "4. num1 > num2 : "<< ((cal1 > cal2) ? "true":"false") <<endl;
			cout << "5. num1 < num2 : "<< ((cal1 < cal2) ? "true":"false")<<endl;
			cout << "6. num1: " << num1 << " num2: " << num2 <<endl;
			cout << endl;
			break;
		}
	}
}

Calculator::Calculator()
{
	total_value = 0;
}

void Calculator::setNum(char arr[], int size, char type)
{

}
friend const Calculator operator+(const Calculator &ref1, const Calculator &ref2)
{
}
friend const Calculator operator-(const Calculator &ref1, const Calculator &ref2)
{
}
friend const bool operator>(const Calculator &ref1, const Calculator &ref2)
{
}
friend const bool operator<(const Calculator &ref1, const Calculator &ref2)
{
}
friend const bool operator==(const Calculator &ref1, const Calculator &ref2)
{
}
friend ostream &operator<<(ostream &outputStream, const Calculator &ref2)
{
}
