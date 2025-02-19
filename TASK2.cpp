#include <iostream>
using namespace std;

int main()
{
	char op;
	float n1, n2;
	cout<<"Enter the operation:"<<endl;
	cin>>op;
	cout<<"Enter the num1 and num2"<<endl;
	cin>>n1>> n2;

	switch (op) {
	case '+':
		cout<<n1 + n2;
		break;
	case '-':
		cout<<n1 - n2;
		break;
	case '*':
		cout<<n1 * n2;
		break;
	case '/':
		cout<< n1 / n2;
		break;
	default:
		cout<<"Operator not found";
	}
	return 0;
}