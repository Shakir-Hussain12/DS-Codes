#include<iostream>

using namespace std;

class FAST {
	string **departments;
	int no;
	int *sizes;
	
	public:
		FAST(int depts) {
			no = depts;
			sizes = new int[no]{};
		}
		
		void setDepts(){
			departments = new string*[no];
			for (int i = 0; i < no; i++) {
				cout << "Number of courses for Department " << i + 1 << ": "; 
				cin >> sizes[i];
				departments[i] = new string[sizes[i]];
				for (int j = 0; j < sizes[i]; j++){
					cout << "Course " << j + 1 << " title: ";
					cin >> departments[i][j]; 
				}
			}
		}
		
		void getDepts() {
			for (int i = 0; i < no; i++) {
				cout << "Course List for Dept " << i + 1 <<endl;
				for (int j = 0; j < sizes[i]; j++){
					cout << "Course "<< j + 1 << ": " << departments[i][j] << "\t"; 
				}
			cout<< endl;
			}
		}
		
		~FAST() {
			for (int i = 0; i < no; i++) {
				delete[] departments[i];
				departments[i] = NULL;
			}
			
			delete[] departments;
			departments = NULL;
		}
};


int main() {
	
	int depts;
	cout << "Enter Number of Departments : ";
	cin >> depts;
	FAST F(depts);
	F.setDepts();
	F.getDepts();
	F.~FAST();
	return 0;
}
