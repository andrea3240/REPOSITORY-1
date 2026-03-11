#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	string filename = argv[1];
	ifstream ifs(filename); //apertura file input
	if (ifs.is_open() ) { // controllo sia aperto correttamente
		while( !ifs.eof() ) { // fino alla fine del file
			string citta;
			ifs >> citta;
			double sum =0;
			for (int i = 1; i <=4; i++) {
				double temp;
				ifs >> temp;
				sum += temp;
			}
			double media = sum/4.0;
			cout << citta << " " << media << "\n";
		}
		return 0;
	}
}