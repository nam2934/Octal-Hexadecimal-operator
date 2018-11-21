#include<iostream>
using namespace std;

class Calculator{
public:
	Calculator();
	void setNum(char arr[], int size);
	friend const Calculator operator+(const Calculator& ref1, const Calculator& ref2, char type);
	friend const Calculator operator-(const Calculator& ref1, const Calculator& ref2, char type);
	friend const bool operator>(const Calculator& ref1, const Calculator& ref2, char type);
	friend const bool operator<(const Calculator& ref1, const Calculator& ref2, char type);
	friend const bool operator==(const Calculator& ref1, const Calculator& ref2, char type);
	friend ostream& operator <<(ostream & outputStream, const Calculator& ref, char type);
private:
;

void welcome(){
	cout << "===============Menu===============" << endl
	<< "1:Program start 0:program End" << endl
	<< "Menu Option: ";
	
}
int main(){

}