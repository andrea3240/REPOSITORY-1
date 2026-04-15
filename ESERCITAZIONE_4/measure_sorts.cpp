#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstddef>
#include "timecounter.h"
#include "randfiller.h"
#include "sort.hpp"


struct Scores
{ 
	int bubble =0;
	int insertion = 0;
	int selection = 0;
	int standard =0;
};

Scores calcolo_punteggio(const std::vector<double>& bubble, const std::vector<double>& insertion, const std::vector<double>& selection, const std::vector<double>& standard)
{

	Scores scores {0,0,0,0};
	
	for(int i=0; i<13; i++)
	{
		double tb = bubble[i];
		double ti = insertion[i];
		double ts = selection[i];
		double tstd = standard[i];
		
		if(tb<ti) scores.bubble++;
		if(tb<ts) scores.bubble++;
		if(tb<tstd) scores.bubble++;
			
		if(ti<tb) scores.insertion++;
		if(ti<ts) scores.insertion++;
		if(ti<tstd) scores.insertion++;
			
		if(ts<tb) scores.selection++;
		if(ts<ti) scores.selection++;
		if(ts<tstd) scores.selection++;
			
		if(tstd<tb) scores.standard++;
		if(tstd<ti) scores.standard++;
		if(tstd<ts) scores.standard++;
			
	}
	
	return scores;
}


int main(void)
{
	randfiller rf;
    timecounter tc; /* instantiate the timecounter */
	std::mt19937 gen(42);
	std::uniform_int_distribution<int> dist(0,100000);
	std::vector<double> t_bs;
	std::vector<double> t_is;
	std::vector<double> t_ss;
	std::vector<double> t_stds;
		
	for(int i=2; i<14; i++)
	{
		int random = dist(gen);
		size_t n = static_cast<size_t>(1) << i; /*definisco n come dimensione size_t al posto di int e questo mi permette di salvarlo come 64bit*/
		std::vector<int>  vec;			/*allora do il valore 1 a n cosi' la rappresentazione inizia con 000... 01 e tramite l'operatore di shift a sinistra associo ad n il numero decimale che corrisponde al binario con l'1 shiftato di i posizioni a sinistra cioe' 2^i*/
		vec.resize(n);
		rf.fill(vec,-random,random);
		tc.tic();       /* start it */
						/* sleep for some time */
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		bubble_sort(vec);
		double secs = tc.toc(); /* stop the timecounter, get time and print it */
		t_bs.push_back(secs);
	}
	
		for(int i=2; i<14; i++)
	{
		
		int random = dist(gen);
		size_t n = static_cast<size_t>(1) << i;
		std::vector<int> vec;
		vec.resize(n);
		rf.fill(vec,-random,random);
		tc.tic();       /* start it */
						/* sleep for some time */
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		insertion_sort(vec);
		double secs = tc.toc(); /* stop the timecounter, get time and print it */
		t_is.push_back(secs);
	}
	
		for(int i=2; i<14; i++)
	{
		
		int random = dist(gen);
		size_t n = static_cast<size_t>(1) << i;
		std::vector<int> vec;
		vec.resize(n);
		rf.fill(vec,-random,random);
		tc.tic();       /* start it */
						/* sleep for some time */
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		selection_sort(vec);
		double secs = tc.toc(); /* stop the timecounter, get time and print it */
		t_ss.push_back(secs);
	}
	
		for(int i=2; i<14; i++)
	{
		
		int random = dist(gen);
		size_t n = static_cast<size_t>(1) << i;
		std::vector<int> vec;
		vec.resize(n);
		rf.fill(vec,-random,random);
		tc.tic();       /* start it */
						/* sleep for some time */
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		std::sort(vec.begin(), vec.end());
		double secs = tc.toc(); /* stop the timecounter, get time and print it */
		t_stds.push_back(secs);
	}
	
	Scores punti = calcolo_punteggio(t_bs, t_is, t_ss,t_stds);
	std::cout << "\n=== PUNTEGGI FINALI ===\n";
    std::cout << "bubble     -> " << punti.bubble     << " punti\n";
    std::cout << "insertion  -> " << punti.insertion  << " punti\n";
    std::cout << "selection  -> " << punti.selection  << " punti\n";
    std::cout << "standard   -> " << punti.standard   << " punti\n";


    return 0;
}
