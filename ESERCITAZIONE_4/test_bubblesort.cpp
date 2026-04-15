#include "sort.hpp"
#include <vector>
#include "randfiller.h"
#include <iostream>
#include <cstdlib>

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) 
	{
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int random_int_gen(int max)
{
	if(max<1) return 1;
	
	static std::random_device rd; /*generatore di semi casuali da hardware*/ /*static permette di generare solo una volta il seme durante l'esecuzione del programma e tramite rd di usarlo per generare altri numeri*/
	static std::mt19937 generator(rd());/*generatore di numeri casuali dal seme generato precedentemente tra 1 e circa 2^31*/
	std::uniform_int_distribution<int> distribution(1,max); /*definisco un distributore che prende i numeri di generator e li trasforma in numeri distribuiti uniformemente da 1 a max */
	
	return distribution(generator);
}

int main(void)
{
	randfiller rf;
	
	std::vector<std::string> vec_alpha1 = {"banana", "mela","arancia","kiwi"};
	std::vector<std::string> vec_alpha2 = {"Palermo", "Catania", "Torino", "Roma"};
	std::vector<std::string> vec_alpha3 = {"Ingegnere", "maestro", "operaio", "commesso", "matematico", "programmatore", "CEO"};
	std::vector<std::string> vec_alpha4 = {"Andrea", "Luca", "Giuseppe", "Marta"};
	std::vector<std::string> vec_alpha5 = {"verde", "blu", "rosso", "arancione"};
	std::vector<std::string> vec_alpha6 = {"peperone", "broccolo","carota"};
	std::vector<std::string> vec_alpha7 = {"deltoide", "bicipite", "core", "quadricipite"};
	std::vector<std::string> vec_alpha8	= {"coca-cola", "sprite", "aranciata", "chinotto"};
	std::vector<std::string> vec_alpha9 = {"termosifone", "forno", "micronde", "cappa"};
	std::vector<std::string> vec_alpha10 = {"ammorbidente", "igienizzante", "sapone", "detersivo"};
	
	bubble_sort(vec_alpha1);
	bubble_sort(vec_alpha2);
	bubble_sort(vec_alpha3);
	bubble_sort(vec_alpha4);
	bubble_sort(vec_alpha5);
	bubble_sort(vec_alpha6);
	bubble_sort(vec_alpha7);
	bubble_sort(vec_alpha8);
	bubble_sort(vec_alpha9);
	bubble_sort(vec_alpha10);
	
	
	
	for(int i=0;i<100; i++)
	{
		int dim = random_int_gen(8192);

		std::vector<int> vec(dim);
		
		rf.fill(vec,-dim,dim);
		
		std::cout << "Vettore " << (i + 1) << " Dimensione: " << dim << "\n";
		
		bubble_sort(vec);
		
		if(is_sorted(vec))
		{
			std::cout << " il vettore numerico e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	}
	if(is_sorted(vec_alpha1))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha2))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha3))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha4))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha5))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha6))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha7))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha8))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha9))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}
	if(is_sorted(vec_alpha10))
		{
			std::cout << " il vettore stringa e' correttamente ordinato\n";
			
		}
		else
		{
				std::cout <<" il vettore NON E' ORDINATO";
				return EXIT_FAILURE;
		}

	std::cout << "tutti i vettori numerici e letterali sono stati ordinati correttamente da bubble_sort! \n";
		
return EXIT_SUCCESS;
}
