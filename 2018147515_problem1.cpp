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
	friend ostream &operator<<(ostream& outputStream, const Calculator &ref2);
	void set_option(char select_option);
	int get_total_value();
  private:
	long long total_value;
	char option;
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
					bool flag1 = true;

					cout << "Input num1 : ";
					cin >> num1;

					length1 = strlen(num1);
					for (int i = 0; i < length1; i++)
					{

						if (((48 <= num1[i]) && (num1[i] <= 57)) || ((65 <= num1[i]) && (num1[i] <= 70)))
							continue;

						else
						{
							flag1 = false;
							
						}
					}

					if (flag1 == true)
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

						if (((48 <= num2[i]) && (num2[i] <= 57)) || ((65 <= num2[i]) && (num2[i] <= 70)))
							continue;
						else
						{
							flag2 = false;
						
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
			Calculator cal1;
        	Calculator cal2;

			cal1.setNum(num1,length1,Select_Option);
			cal2.setNum(num2,length2,Select_Option);
			cal1.set_option(Select_Option);
			cal2.set_option(Select_Option);

			cout << endl;
			Calculator plus = cal1 + cal2;
			Calculator minus = cal1 - cal2;
			plus.set_option(Select_Option);
			minus.set_option(Select_Option);

			cal1.set_option('D');
			cal2.set_option('D');

			cout << "1. num1 + num2 : "<< plus <<endl;
			cout << "2. num1 – num2 : "<< minus <<endl;
			cout << "3. num1 == num2 : "<< ((cal1 == cal2) ? "true":"false") <<endl; 
			cout << "4. num1 > num2 : "<< ((cal1 > cal2) ? "true":"false") <<endl;
			cout << "5. num1 < num2 : "<< ((cal1 < cal2) ? "true":"false")<<endl;
			cout << "6. num1: " << cal1 << " num2: " << cal2 << endl;
			cout << endl;
			break;
		}
	}
}

Calculator::Calculator()
{
	total_value = 0;
	option = 0;
}

void Calculator::setNum(char arr[], int size, char type)
{
	switch(type){
		case 'O':
			for(int i=0; i<size; i++){
				total_value = total_value + ((long long)arr[size-1-i]-48)*(long long)pow(8,i);
    		}
			break;
		case 'H':
			for(int i=0; i<size; i++){
        		if((48<=(int)arr[size-1-i])&&((int)arr[size-1-i]<=57))
            		total_value = total_value + ((long long)arr[size-1-i]-48)*(long long)pow(16,i);
        		else
            		total_value = total_value + ((long long)arr[size-1-i]-55)*(long long)pow(16,i);
    		}
			break;
	}
}
const Calculator operator+(const Calculator &ref1, const Calculator &ref2)
{
	Calculator plus;
	long long a = ref1.total_value + ref2.total_value;
	plus.total_value = a;
	return plus;
}
const Calculator operator-(const Calculator &ref1, const Calculator &ref2)
{
	Calculator minus;
	long long a = ref1.total_value - ref2.total_value;
	minus.total_value = a;
	return minus;
}
const bool operator>(const Calculator &ref1, const Calculator &ref2)
{
	if(ref1.total_value > ref2.total_value){
		return true;
	}
	else return false;

}
const bool operator<(const Calculator &ref1, const Calculator &ref2)
{
	if(ref1.total_value < ref2.total_value){
		return true;
	}
	else return false;
}
const bool operator==(const Calculator &ref1, const Calculator &ref2)
{
	if(ref1.total_value == ref2.total_value){
		return true;
	}
	else return false;
}
ostream &operator<<(ostream& outputStream, const Calculator &ref2)
{	
	long long total = ref2.total_value;
	char arr[100];
	int i=0;
	if(ref2.option == 'H'){
		if(total<0){
			total = pow(16,6) + total;
		}
		if(total==0)
			outputStream << "0";
		while(total > 0){
			if(total%16 < 10){
				arr[i] = (char)(total%16 + 48);
				i++;
			}
			else{
				arr[i] = (char)(total%16 + 55);
				i++;
			}
			total = total/16;
		}

	}
	else if(ref2.option == 'O'){
		if(total<0){
			total = pow(8,6) + total;
		}
		if(total==0)
			outputStream << "0";
		while(total > 0){
			arr[i] = (char)(total%8 + 48);
			total = total/8;
			i++;
		}
	}

	else if(ref2.option == 'D'){
		outputStream << total;
	}
	if(ref2.option == 'O' || ref2.option == 'H'){
		for(int j=1; j<=i; j++){
        	outputStream << (char)arr[i-j];
    	}
	}
	return outputStream;
}

void Calculator::set_option(char select_option){
	option = select_option;
}

int Calculator::get_total_value(){
	return total_value ;
}