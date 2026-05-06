#pragma once
#include <vector>      // per std::vector
#include <algorithm>   // per std::swap
#include <cstddef>     // per std::size_t 


template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    for(size_t i = 0; i + 1 < vec.size(); i++)
        if(vec[i] > vec[i+1]) return false;
    return true;
}

template<typename T>
int Partition1(std::vector<T>& vec,int p,int r)
{
	T x = vec[r];
	int i = p-1;
	for(int j =p; j <= r-1; j++)
	{
		if(vec[j]<=x)
		{	
			i++;
			std::swap(vec[i],vec[j]);
		}
	}
	if(i!=r)
	{
		std::swap(vec[i+1],vec[r]);
	}
	return i+1;
}

template<typename T>
void quick_sort(std::vector<T>& vec, int p,int r)
{
	if(p<r)
	{
		int q = Partition1(vec, p, r);
		quick_sort(vec, p, q-1);
		quick_sort(vec, q+1,r);
	}
}

template<typename T> /*wraper per il quicksort che gestisce le chiamate corrette in base alla dimensione del vettore*/
void quick_sort(std::vector<T>& vec)
{
    if(!vec.empty() && vec.size() < 50)
	{
        quick_sort(vec, 0, (int)vec.size() - 1);
	}
}

template<typename T>
void Merge(std::vector<T>& vec, int p, int q, int r)
{
    size_t n1 = q - p + 1;
    size_t n2 = r - q;

    std::vector<T> L(n1), R(n2);

    for (size_t i = 0; i < n1; i++)
        L[i] = vec[p + i];

    for (size_t j = 0; j < n2; j++)
        R[j] = vec[q + 1 + j];

    size_t i = 0, j = 0;

    for (int k = p; k <= r; k++)
    {
        if (i == n1)
        {
            vec[k] = R[j++];
        }
        else if (j == n2)
        {
            vec[k] = L[i++];
        }
        else if (L[i] <= R[j])
        {
            vec[k] = L[i++];
        }
        else
        {
            vec[k] = R[j++];
        }
    }
}

template<typename T>
void merge_sort(std::vector<T>& vec,int p,int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		merge_sort(vec,p,q);
		merge_sort(vec,q+1,r);
		Merge(vec,p,q,r);
	}
}

template<typename T> /*wrapper per il mergesort*/
void merge_sort(std::vector<T>& vec)
{
    if(!vec.empty())
        merge_sort(vec, 0, (int)vec.size() - 1);
}


template<typename T>
void bubble_sort(std::vector<T>& vec)
      
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


template<typename T> /*wraper per il quicksort che gestisce le chiamate corrette in base alla dimensione del vettore*/
void hybrid_quick_sort(std::vector<T>& vec)
{
    if(!vec.empty() && vec.size() < 50)
	{
        quick_sort(vec, 0, (int)vec.size() - 1);
	}
	else if(!vec.empty() && vec.size() >= 50)
	{
		insertion_sort(vec);
	}
}

/*
template<typename T>
void Merge(std::vector<T>& vec,int p,int q,int r) 
{
	size_t n1= q-p+1;
	size_t n2 = r - q;
	std::vector<T> L(n1), R(n2);
	for(int i =0; i<n1; i++)
	{
		L[i] = vec[p+i];
	}
	for (int j = 0; j< n2;j++)
	{
		R[j]= vec[q+1+j];
	}
	
	int i =0, j=0, k= p;
	while (i<n1 && j<n2)
	{
		if(L[i]<= R[j])
		{
			vec[k++]= L[i++];
		}
		else
		{
			vec[k++]= R[j++];
		}
	}
	while (i<n1)
	{
		vec[k++]= L[i++];
	}
	while (j<n2)
	{
		vec[k++]= R[j++];
	}
}
*/