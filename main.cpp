#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
	Node Oradea("Oradea");
	Node Zerind("Zerind");
	Node Arad("Arad");
	Node Timisoara("Timisoara");
	Node Lugoj("Lugoj");
	Node Mehadia("Mehadia");
	Node Drobeta("Drobeta");
	Node Sibiu("Sibiu");
	Node Fagarus("Fagarus");
	Node RV("Rimnicu Vilcea");
	Node Pitesti("Pitesti");
	Node Craiova("Craiova");
	Node Bucharest("Bucharest");
	Node Giurgiu("Giurgiu");
	Node Urziceni("Urziceni");
	Node Vaslui("Vaslui");
	Node Iasi("Iasi");
	Node Neamt("Neamt");
	Node Hirsova("Hirsova");
	Node Eforie("Eforie");
	Oradea.addCxn(&Zerind, 71, &Sibiu, 151);
	Zerind.addCxn(&Oradea, 71, &Arad, 75);
	Arad.addCxn(&Zerind, 75, &Sibiu, 151, &Timisoara, 118);
	Timisoara.addCxn(&Arad, 118, &Lugoj, 111);
	Lugoj.addCxn(&Timisoara, 111, &Mehadia, 70);
	Mehadia.addCxn(&Lugoj, 70, &Drobeta, 75);
	Drobeta.addCxn(&Mehadia, 75, &Craiova, 120);
	Craiova.addCxn(&Drobeta, 120, &RV, 146, &Pitesti, 138);
	RV.addCxn(&Sibiu, 80, &Craiova, 146, &Pitesti, 101);
	Sibiu.addCxn(&Oradea, 151, &Arad, 140, &RV, 80, &Fagarus, 99);
	Fagarus.addCxn(&Sibiu, 99, &Bucharest, 211);
	Pitesti.addCxn(&RV, 97, &Craiova, 138, &Bucharest, 101);
	Bucharest.addCxn(&Pitesti, 101, &Fagarus, 211, &Giurgiu, 90, &Urziceni, 85);
	Giurgiu.addCxn(&Bucharest, 90);
	Urziceni.addCxn(&Bucharest, 85, &Hirsova, 98, &Vaslui, 142);
	Hirsova.addCxn(&Urziceni, 98, &Eforie, 86);
	Eforie.addCxn(&Hirsova, 86);
	Vaslui.addCxn(&Urziceni, 142, &Iasi, 92);
	Neamt.addCxn(&Iasi, 92);

	for (auto i : Bucharest.cxnList)
	{
		cout << i.adjCity->city << ", " << i.distance << endl;
	}
}
