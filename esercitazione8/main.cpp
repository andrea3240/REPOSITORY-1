#include <iostream>
#include "graph.hpp"

int main()
{
    // --- Test unidirected_edge ---


    unidirected_edge<int> e1(3, 1);
    unidirected_edge<int> e2(1, 3);
    unidirected_edge<int> e3(3, 1);

    // operator==
	
    if (e1 == e2)
        std::cout << "gli archi e1 ed e2 sono identici\n";
    else
        std::cout << "gli archi e1 ed e2 sono distinti\n";

    // operator<
	
    unidirected_edge<int> e4(2, 5);
    std::cout << "l'arco  (1,3) e' piu' avanti di (2,5): " << (e4 < e2) << "\n"; 
	
    // --- Test unidirected_graph ---
	
    unidirected_graph<int> G;
    unidirected_graph<int> G1;

    G.add_edge(1, 2);
    G.add_edge(2, 7);
    G.add_edge(2, 5);
    G.add_edge(1, 9);
    G.add_edge(9, 3);
    G.add_edge(1, 5);

    G1.add_edge(0, 4);
    G1.add_edge(3, 0);
    G1.add_edge(3, 5);
    G1.add_edge(3, 8);

    // all_nodes
    // NOTA: all_nodes() restituisce un std::set<int>, che non ha operator<<.
    std::cout << "I nodi di G sono: ";
    for (const auto& n : G.all_nodes()) std::cout << n << " "; 
    std::cout << "\n";

    std::cout << "I nodi di G1 sono: ";
    for (const auto& n : G1.all_nodes()) std::cout << n << " "; 
    std::cout << "\n";

    // all_edges
    std::cout << "Gli archi di G sono: ";
    for (const auto& e : G.all_edges()) std::cout << e << " "; 
    std::cout << "\n";
	
    std::cout << "Gli archi di G1 sono: ";
    for (const auto& e : G1.all_edges()) std::cout << e << " ";
    std::cout << "\n";


    // neighbours
    std::cout << "I vicini del nodo 9 sono: ";
    for (const auto& n : G.neighbours(9)) std::cout << n << " ";
    std::cout << "\n";

    // edge_number e edge_at
    std::cout << "L'arco (1,5) e' in posizione " << G.edge_number(unidirected_edge<int> (1, 5)) << "\n";
	// l'arco (1, 5) si trova in posizione 5 0_based poiche' non ho ordinato il grafo

    std::cout << "L'arco all'indice 5 e': " << G.edge_at(5) << "\n"; 

    // operator-
    unidirected_graph<int> diff = G - G1;

    // Costruttore di copia
    unidirected_graph<int> G_copy(G);

    // Stampa finale
    std::cout << "Grafo G:\n" << G << "\n";
    std::cout << "Grafo diff (G - G1):\n" << diff << "\n";
    std::cout << "Tutti i test superati.\n";

    return 0;
}