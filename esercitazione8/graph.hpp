#pragma once
#include <set>
#include <map>
#include <list>
#include <iostream>

template <typename K>
class unidirected_edge {

private:
    K nodo1;
    K nodo2;

public:
    // Costruttore: garantisce sempre che from < to
    unidirected_edge(const K& a, const K& b) 
	{
        if (a < b) 
		{
            nodo1 = a;
            nodo2 = b;
        } 
		else if (b < a) {
            nodo1 = b;
            nodo2 = a;
        } 
		else 
		{
           return;
        }
    }

    // Metodi getter
    const K& from() const { return nodo1; }
    const K& to()   const { return nodo2; }

    // operator< per ordinabilita' (necessario per std::set e std::map)
    bool operator<(const unidirected_edge<K>& other) const
    {
        if (nodo1 != other.nodo1)
            return nodo1 < other.nodo1;
        return nodo2 < other.nodo2;
    }

    // operator== per confronto tra archi
    bool operator==(const unidirected_edge<K>& other) const
    {
        return nodo1 == other.nodo1 && nodo2 == other.nodo2;
    }

    // operator<< per stampa
    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge<K>& e)
    {
        return os << "(" << e.nodo1 << ", " << e.nodo2 << ")";
    }
};  

template <typename K>
class unidirected_graph
{
private:
    // Struttura dati principale: mappa nodo -> insieme dei vicini
    std::map<K, std::set<K>> G;

    // Lista ordinata di archi per supportare edge_number() e edge_at()
    std::list<unidirected_edge<K>> _edges;

    std::size_t _next_index;

public:
    // Costruttore di default
    unidirected_graph() : _next_index(0) {}

    // Costruttore di copia
    unidirected_graph(const unidirected_graph<K>& other)
        : G(other.G), _edges(other._edges), _next_index(other._next_index) {}

    // Aggiunge un arco al grafo.
    // add_node() non e' richiesta: i nodi vengono aggiunti implicitamente.
    void add_edge(const K& a, const K& b)
    {
        unidirected_edge<K> e(a, b); //dati due tipi K qualsiasi creo un grafo

        // Controlla se l'arco esiste gia' nella lista degli archi
        for (const auto& existing : _edges)
		{
            if (existing == e)
			{
                return;  // arco duplicato: nulla da fare
			}
		}
        // Inserisce i due nodi nella mappa se non esistono ancora
        G[e.from()].insert(e.to());
        G[e.to()].insert(e.from());

        // Aggiunge l'arco alla lista
        _edges.push_back(e);
        _next_index++;
    }

    // Restituisce i vicini di un nodo
    const std::set<K>& neighbours(const K& node) const
    {
        auto it = G.find(node); //find cerca la chiave node nella mappa e restituisce un iteratore chiamato it
        if (it == G.end()) // se l'iteratore it arriva all'iteratore sentinella G.end allora il nodo non esiste nel grafo e stampo l'eccezione
            throw std::invalid_argument("Nodo non presente nel grafo.");
        return it->second; // se l'iteratore non ha avuto problemi allora ritorno il riferimento cost al membro in forma set puntato da it
    }

    // Restituisce tutti gli archi
    const std::list<unidirected_edge<K>>& all_edges() const
    {
        return _edges;
    }

    // Restituisce tutti i nodi
    std::set<K> all_nodes() const
    {
        std::set<K> nodes;
        for (const auto& pair : G)
            nodes.insert(pair.first);
        return nodes;
    }

    // Dato un arco, restituisce il suo indice (0-based) nella lista degli archi
    std::size_t edge_number(const unidirected_edge<K>& e) const
    {
        std::size_t idx = 0;
        for (const auto& existing : _edges)
        {
            if (existing == e)
			{
                return idx;
			}
            idx++;
        }
        throw std::invalid_argument("Arco non presente nel grafo.");
    }

    // Dato un indice, restituisce il corrispondente arco
    const unidirected_edge<K>& edge_at(std::size_t idx) const
    {
        if (idx >= _next_index)
            throw std::out_of_range("Indice arco fuori range.");
        auto it = _edges.begin();
        std::advance(it, idx);
        return *it;
    }
	

    // operator-: differenza G - G'
    // Restituisce un nuovo grafo con gli archi presenti in *this ma non in other
    unidirected_graph<K> operator-(const unidirected_graph<K>& other) const
    {
        unidirected_graph<K> result;
        for (const auto& e : _edges)
        {
            // Cerca l'arco nella lista dell'altro grafo
            bool found = false;
            for (const auto& oe : other._edges)
            {
                if (e == oe) 
				{
					found = true;
					break; 
				}
            }
            if (!found)
			{
                result.add_edge(e.from(), e.to());
			}
        }
        return result;
    }

    // operator<< per stampa del grafo
    friend std::ostream& operator<<(std::ostream& os, const unidirected_graph<K>& g)
    {
        os << "Nodi: { ";
        for (const auto& pair : g.G)
		{
            os << pair.first << " ";
		}
        os << "}\nArchi: { ";
        for (const auto& e : g._edges)
		{

            os << e << " ";
		}
        os << "}";
        return os;
    }
};
