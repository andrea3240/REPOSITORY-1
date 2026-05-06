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
    const int Num_test = 100;
    const int size = 100;
    randfiller rf;
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(0, 100000);
	std::vector<double> t_bs;
	std::vector<double> t_is;
	std::vector<double> t_ss;
	std::vector<double> t_stds;
	std::vector<double> t_qs;
	std::vector<double> t_ms;

    // --- Preparazione dataset ---
    std::vector<std::vector<int>> dataset;
    dataset.reserve(Num_test);
    for (int i = 0; i < Num_test; i++)
    {
        int random = dist(gen);
        std::vector<int> vec(size);
        rf.fill(vec, -random, random);
        dataset.push_back(vec);
    }

    // reset del dataset
    std::vector<std::vector<int>> backup = dataset;
    auto reset = [&]() 
	{ 
	dataset = backup; 
	};

    double elapsed;


    reset();
    tc.tic();
    for (int i = 0; i < Num_test; i++)
        bubble_sort(dataset[i]);
    elapsed = tc.toc();
    std::cout << "Bubblesort     media: " << elapsed / Num_test * 1000.0 << " ms\n";


    reset();
    tc.tic();
    for (int i = 0; i < Num_test; i++)
        selection_sort(dataset[i]);
    elapsed = tc.toc();
    std::cout << "Selectionsort  media: " << elapsed / Num_test * 1000.0 << " ms\n";


    reset();
    tc.tic();
    for (int i = 0; i < Num_test; i++)
        insertion_sort(dataset[i]);
    elapsed = tc.toc();
    std::cout << "Insertionsort  media: " << elapsed / Num_test * 1000.0 << " ms\n";


    reset();
    tc.tic();
    for (int i = 0; i < Num_test; i++)
        merge_sort(dataset[i], 0, (int)dataset[i].size() - 1);
    elapsed = tc.toc();
    std::cout << "Mergesort      media: " << elapsed / Num_test * 1000.0 << " ms\n";


    reset();
    tc.tic();
    for (int i = 0; i < Num_test; i++)
        quick_sort(dataset[i], 0, (int)dataset[i].size() - 1);
    elapsed = tc.toc();
    std::cout << "Quicksort      media: " << elapsed / Num_test * 1000.0 << " ms\n";


    reset();
    tc.tic();
    for (int i = 0; i < Num_test; i++)
        std::sort(dataset[i].begin(), dataset[i].end());
    elapsed = tc.toc();
    std::cout << "std::sort      media: " << elapsed / Num_test * 1000.0 << " ms\n";


    std::vector<std::string> svec = {
        "banana", "mela", "arancia", "kiwi", "pera",
        "uva", "limone", "mango", "pesca", "fragola"
    };
    std::cout << "\nTest ordinamento stringhe:\n";
    std::cout << "  Prima:  ";
    for (auto& s : svec) std::cout << s << " ";
    std::cout << "\n";

    merge_sort(svec, 0, (int)svec.size() - 1);

    std::cout << "  Dopo:   ";
    for (auto& s : svec) std::cout << s << " ";
    std::cout << "\n";

    return 0;
	
}
