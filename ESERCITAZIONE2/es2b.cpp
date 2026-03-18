#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	static const int N = 5;
	
	double arr[N] = {1.1,2.2,3.3,4.4,5.5};
	
	double min_a = 1.1;
	for (int i = 1; i <=4 ; i++) {
		min_a = min(min_a, arr[i]);
	}
	
	double max_a = 0.0;
	for (int i = 1; i <=4; i++) {
		max_a = max(max_a, arr[i]);
	}
	
	double sum = 0.0;
	for (int i = 0; i<= 4; i++) {
		sum += arr[i];
	}
	
	double media = sum/5.0;
	
	double dev = 0.0;

	for (int i=0; i <=4; i++) {
		dev = (arr[i]*arr[i] - media)/5.0;
	}
	
	dev = sqrt(dev);
	
	cout << "min: " << min_a << "\n"; 
	cout << "max: " << max_a <<  "\n"; 
	cout << "media: " << media << "\n"; 
	cout << "dev: " << dev << "\n"; 

}