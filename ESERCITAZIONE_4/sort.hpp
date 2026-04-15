#pragma once
#ifndef SORTING_H
#define SORTING_H

#include <vector>      // per std::vector
#include <algorithm>   // per std::swap
#include <cstddef>     // per std::size_t 

template<typename T>
												/*la funzione template ha come parametro template T con tipo deciso dal compilatore*/
void bubble_sort(std::vector<T>& vec)           /*la funzione template torna un vettore*/
                                                /*scrivere #include <vector> nel main*/
												/*scrivere #include <algorithm> per poter usare std::swap*/
{
	std::size_t N = vec.size();
	bool swapped = true;
	while (swapped) 
	{
		swapped  = false;
		
		for(int i =0; i < N-1; i++) 
		{
			if(vec[i]>vec[i+1])
			{
				std::swap(vec[i], vec[i+1]);
				swapped = true;
			}
		}
		N--;
	}
	
}

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
	std::size_t N = vec.size();
	if(vec.size()<=1)
	{
		return true;
	}
	for (int i =0; i< N -1; i++)
	{
		if(vec[i]> vec[i+1])
		{
			return false;
		}
	}
	return true;
}	
	
template<typename T>
void insertion_sort(std::vector<T>& vec) 
{
	std::size_t N = vec.size();
	for(int j = 1; j < N; j++)
	{
		T k = vec[j];                            /*k e' la carta pescata dopo la precedente, lo stesso vale per vec[j]*/
		int i = j-1;                             /*parto dalla precedente*/
		while(i>=0 && vec[i]> k)                 /*verifico se la carta precedente ha valore maggiore della successiva*/
		{
			vec[i+1] = vec[i];       			 /*scambio carta precedente e successiva*/
			i--;                                 /*la condizione i>=0 e i-- mi permettono di iterare il procedimento per tutte le carte precedenti a quella pescata*/
		}
		vec[i+1] = k;
	}	
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{
	std::size_t N = vec.size();
	for(int i= 0; i< N-1; i++)
	{
		int min_ind = i;
		for(int j = i+1; j< N; j++)
		{
			if(vec[j]<vec[min_ind])
			{
				min_ind = j;
			}
		}
		std::swap(vec[i], vec[min_ind]);
	}
}

#endif