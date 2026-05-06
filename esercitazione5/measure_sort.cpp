#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstddef>
#include "timecounter.h"
#include "randfiller.h"
#include "sort.hpp"
int main(void)
{
	timecounter tc;
    const int Num_test = 300;
    randfiller rf;
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(0, 100000);
	std::vector<int> d_bs, d_ss, d_is, d_stds, d_qs, d_ms, d_hqs;
	std::vector<double> t_bs, t_ss, t_is, t_stds, t_qs, t_ms, t_hqs;


    std::vector<std::vector<int>> dataset;
    dataset.reserve((Num_test-2)*20);
    for (size_t i = 2; i < Num_test; i++)
	{
		for(size_t j=0; j<20; j++)
		{
        int random = dist(gen);
        std::vector<int> vec(i);
        rf.fill(vec, -random, random);
        dataset.push_back(vec);
		}
	}
	

    double elapsed;
	
    for (int i = 0; i < Num_test-2; i++)
	{
		double avg = 0.0;
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j];
			tc.tic();
			bubble_sort(tempo);
			elapsed = tc.toc();
			avg += elapsed; 
		}
		avg = avg/20;
		t_bs.push_back(avg);
		d_bs.push_back(i+2);
	}

    for (int i = 0; i < Num_test-2; i++)
	{
		double avg = 0.0;
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j];
			tc.tic();
			selection_sort(tempo);
			elapsed = tc.toc();
			avg += elapsed;
		}
		avg = avg/20;
		t_ss.push_back(avg);
		d_ss.push_back(i+2);
	}


    for (int i = 0; i < Num_test-2; i++)
	{

		double avg = 0.0;
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j];
			tc.tic();
			insertion_sort(tempo);
			elapsed = tc.toc();
			avg += elapsed;
		}
		avg = avg/20;
		t_is.push_back(avg);
		d_is.push_back(i+2);
		
	}


    for (int i = 0; i < Num_test-2; i++)
	{
		double avg = 0.0;
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j];
			tc.tic();
			merge_sort(tempo);
			elapsed = tc.toc();
			avg += elapsed;
		}
		avg = avg/20;
		t_ms.push_back(avg);
		d_ms.push_back(i+2);
	}


    for (int i = 0; i < Num_test-2; i++)
	{
		double avg = 0.0;
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j];
			tc.tic();
			quick_sort(tempo);
			elapsed = tc.toc();
			avg += elapsed;
		}
		avg = avg/20;
		t_qs.push_back(avg);
		d_qs.push_back(i+2);
	}


    for (int i = 0; i < Num_test-2; i++)
	{
		double avg = 0.0; 
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j]; /*prendo una copia di dataset j e la ordino in modo da non dover ripristinare il dataset*/
			tc.tic();
			std::sort(tempo.begin(), tempo.end());
			elapsed = tc.toc();
			avg += elapsed;
		}
		avg = avg/20;
		t_stds.push_back(avg);
		d_stds.push_back(i+2);
	}
	
	for (int i = 0; i < Num_test-2; i++)
	{
		double avg = 0.0;
		for(size_t j= i*20; j<i*20+20; j++)
		{
			auto tempo = dataset[j];
			tc.tic();
			hybrid_quick_sort(tempo);
			elapsed = tc.toc();
			avg += elapsed;
		}
		avg = avg/20;
		t_hqs.push_back(avg);
		d_hqs.push_back(i+2);
	}
	
	
	
	for(int i=2; i< Num_test; i++)
	{
		if(t_ss[i-2]<=t_qs[i-2])
		{
			std::cout << i << " " << "selection_sort su quick_sort: >>> " << t_ss[i-2] << "  " << t_qs[i-2] << "\n";
		}
		if(t_ss[i-2]<=t_ms[i-2])
		{
			std::cout << i << " " << "selection_sort su merge_sort: >>> " << t_ss[i-2] << "  " << t_ms[i-2] << "\n";
		}
		if(t_ss[i-2]<=t_hqs[i-2])
		{
			std::cout << i << " " << "selection_sort su hybrid_quick_sort: >>> " << t_ss[i-2] << "  " << t_qs[i-2] << "\n";
		}
		if(t_bs[i-2]<=t_qs[i-2])
		{
			std::cout << i << " " << "bubble_sort su quick_sort: >>> " << t_bs[i-2] << "  " << t_qs[i-2] << "\n";
		}
		if(t_bs[i-2]<=t_ms[i-2])
		{
			std::cout << i << " " << "bubble_sort su merge_sort: >>> " << t_bs[i-2] << "  " << t_ms[i-2] << "\n";
		}
		if(t_bs[i-2]<=t_hqs[i-2])
		{
			std::cout << i << " " << "bubble_sort su hybrid_quick_sort: >>> " << t_bs[i-2] << "  " << t_hqs[i-2] << "\n";
		}
		if(t_is[i-2]<=t_qs[i-2])
		{
			std::cout << i << " " << "insertion_sort su quick_sort: >>> " << t_is[i-2] << "  " << t_qs[i-2] << "\n";
		}
		if(t_is[i-2]<=t_ms[i-2])
		{
			std::cout << i << " " << "insertion_sort su merge_sort: >>> " << t_is[i-2] << "  " << t_ms[i-2] << "\n";
		}
		if(t_is[i-2]<=t_hqs[i-2])
		{
			std::cout << i << " " << "insertion_sort su hybrid_quick_sort: >>> " << t_is[i-2] << "  " << t_ms[i-2] << "\n";
		}
		
	}	
}