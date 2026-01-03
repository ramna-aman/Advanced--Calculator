#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


double add(double a, double b) { return a + b;}
double sub(double a, double b) { return a - b;}
double mul(double a, double b) { return a * b;};
double divi(double a, double b) { return (b != 0) ? a / b : 0; }
double power(double a, double b) { return pow(a, b); }
double squareroot(double a) { return sqrt(a); }


double sine(double a) { return sin(a); }
double cosine(double a) { return cos(a); }
double tangent(double a) { return tan(a); }

int main() {
	int choice;
	double num1, num2, result;
	double history[50];
	int index = 0;
	
	ofstream file("calculaor_history.txt");
	
	do {
		cout << "\n=== Advanced Calculator ===\n";
		cout << "1. Addition (+)\n";
		cout << "2. Subtraction (-)\n";
		cout << "3. Multiplication (*)\n";
		cout << "4. Division (/)\n";
		cout << "5. Modulus (%)\n";
		cout << "6. Power (x^y)\n";
		cout << "7. Square root (vx)\n";
		cout << "8. Percentage (%)\n";
		cout << "9. Sine (sin x)\n";
		cout << "10. Cosine (cos x)\n";
		cout << "11. Tangent (tan x)\n";
		cout << "12. Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
		
		switch(choice) {
		case 1:
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			result = add(num1, num2);
			break;
				
		case 2:
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			result = sub(num1, num2);
			break;
				
		case 3:
			cout << "Enter two numbers:";
			cin >> num1 >> num2;
			result = mul(num1, num2);
			break;
				
		case 4:
			cout << "Enter two numbers: ";
			cin >> num1 >> num2;
			if (num2 == 0) {
				cout << "Division by zero not allowed!\n";
				continue;
			} 
			result = divi(num1, num2);
			break;
				
		case 5:{
			int n1, n2;
			cout << "Enter two intergers:";
			cin >> n1 >>n2;
			if(n2 == 0){
				cout << " Division by zero not allowed!\n";
				continue;
			}	
			result = n1 % n2;	
			break;
		}
		
		case 6:
			cout << "Enter base and exponent: ";
			cin >> num1 >> num2;
			result = pow(num1, num2);
			break;
			
		case 7:
			cout << "Enter number: ";
			cin >> num1;
			if(num1 < 0){
				cout << "Negative number not allowed!\n";
				continue;
			} 
			result = squareroot(num1);
			break;
			
		case 8:
			cout << "Enter obtained marks and total marks: ";
			cin >> num1 >> num2;
			if(num2 == 0){
				cout << "Invalid input!\n";
				continue;
			}
			result = (num1 / num2) * 100;
			cout << "Percentage:" << result << "%\n";
			break;
			
		case 9:
			cout << "Enter angle in radians:";
			cin >> num1;
			result = sine(num1);
			break;
				
		case 10:
			cout << "Enter angle in radians:";
			cin >> num1;
			result = cosine(num1);				break;
				
		case 11:
			cout << "Enter angle in radians:";
			cin >> num1;
			result = tangent(num1);
			break;
				
		case 12:
			cout << "Existing program...\n";
			break;
				
		default:
			cout << "Invalid choice!\n";
			continue;
		}
		
		if (choice != 12){
			cout << "Result:" << result << endl;
		     history[index] = result;
		     file << "Resuit" << index + 1 << ":" << result << endl;
		     index++;
		 }
		
	} while(choice != 9);
		
	file.close();
	
	cout << "\n--- Calculator History ---\n";
	for(int i = 0; i < index; i++){
		cout << history[i] << endl;
	}
	
	return 0;
}
