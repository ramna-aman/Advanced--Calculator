#include<iostream>
#include<fstream>
using namespace std;

int factorial(int n){
	if (n == 0) return 1;
	int f = 1;
	for (int i = 1; i <= n; i++){
		f *= i;
	}
	return f;
}

bool isPrime(int n){
	if ( n <= 1) return false;
	for(int i =2; i <= n; i++){
		if (n % i == 0)
		    return false;
	}
	return true;
}

void saveHistory(const string& text){
	ofstream file("history.txt, ios::app");
	file << text << endl;
	file.close();
}

void showHistory(){
	ifstream file("histort.txt");
	string line;
	cout << "\n--- Calculation history ---\n";
	while (getline(file, line)){
		cout << line << endl;
	}
	file.close();
}



int main(){
	int choice, n;
	
	do {
		cout << "\n=== Advanced Calculator ===\n";
		cout << "1. Factorial\n";
		cout << "2. Prime Check\n";
		cout << "3. Even / Odd\n";
		cout << "4. View History\n";
		cout << "0. Exit\n";
		cout << "Enter Choice:";
		cin >> choice;
		
		switch(choice) {
			
		case 1:
		    cout << "Enter number";
		    cin >> n;
		    cout << "Factorial =" << factorial(n) << endl;
		
		    { 
		        ofstream file("history.txt", ios::app);
		        file << "Factorial:" << n << "! =" << factorial(n) << endl;
		        file.close();
			}
			break;
			
		case 2:
			cout << "Enter number";
			cin >> n;
			
			if (isPrime(n)) {
				cout << "Prime Number\n";
				ofstream file("history.txt, ios::app");
				file << "Prime Check:" << n << " is Prime" << endl;
				file.close();
			} else {
				cout << "Not Prime\n";
				ofstream file("history.txt, ios::app");
				file << "Prime Check:" << n << " is not Prime" << endl;
				file.close();
			}
			break;
				
		case 3:
			cout << "Enter number";
			cin >> n;
			
			if ( n % 2 == 0){
				cout << "Even Number\n";
				ofstream file("history.txt. ios::app");
				file << "Even/Odd:" << n << " is Even " << endl;
				file.close();
			} else {
				cout << "Odd Number\n";
				ofstream file("history.txt, ios::app");
				file << "Even/Odd:" << n << "is Odd" << endl;
				file.close();
			}
			break;
			
		case 4:
			showHistory();
			break;
			
		case 0:
			cout << " Exiting Program...\n";
			break;
			
		default:
			cout << "Invalid Choice!\n";
		}
	} while (choice != 0);
	
	return 0;
}
