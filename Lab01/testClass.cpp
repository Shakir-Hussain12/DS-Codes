#include<iostream>

using namespace std;

class myClass {
	private:
		string name;
		int age;
	public:
		myClass(string n, int a);
		
		void printDetails() {
			cout<<"Name : "<<name<<endl;
			cout<<"Age : "<<age<<endl;	
		}
};

myClass::myClass(string n, int a) {
	name = n;
	age = a;
}

int main() {
	myClass mc("Shakir", 24);
	mc.printDetails();
	return 0;
}

