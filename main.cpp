#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include "LinkedList.h"

using namespace std;

string getStartLocation();
string getSearchType();
void BFS(Node*);
void DFS(Node*);
void IDS(Node*);

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
	Iasi.addCxn(&Vaslui, 92, &Neamt, 87);
	Neamt.addCxn(&Iasi, 92);

	string sl = getStartLocation();
	string st = getSearchType();

	Node* startNode = nullptr;
	if (sl == "Oradea")
		startNode = &Oradea;
	else if (sl == "Zerind")
		startNode = &Zerind;
	else if (sl == "Arad")
		startNode = &Arad;
	else if (sl == "Timisoara")
		startNode = &Timisoara;
	else if (sl == "Lugoj")
		startNode = &Lugoj;
	else if (sl == "Mehadia")
		startNode = &Mehadia;
	else if (sl == "Drobeta")
		startNode = &Drobeta;
	else if (sl == "Craiova")
		startNode = &Craiova;
	else if (sl == "Remnicu Vilcea")
		startNode = &RV;
	else if (sl == "Sibiu")
		startNode = &Sibiu;
	else if (sl == "Fagarus")
		startNode = &Fagarus;
	else if (sl == "Pitesti")
		startNode = &Pitesti;
	else if (sl == "Bucharest")
		startNode = &Bucharest;
	else if (sl == "Giurgiu")
		startNode = &Giurgiu;
	else if (sl == "Urziceni")
		startNode = &Urziceni;
	else if (sl == "Hirsova")
		startNode = &Hirsova;
	else if (sl == "Eforie")
		startNode = &Eforie;
	else if (sl == "Vaslui")
		startNode = &Vaslui;
	else if (sl == "Iasi")
		startNode = &Iasi;
	else if (sl == "Neamt")
		startNode = &Neamt;

	if (st == "b")
		BFS(startNode);
	else if (st == "d")
		DFS(startNode);
	else if (st == "i")
		IDS(startNode);

	/*
	for (auto i : Zerind.cxnList)
	{
		cout << i.adjCity->city << ", " << i.distance << endl;
	}
	*/
	
}

string getStartLocation()
{
	string startingLocation;
	cout << "Where will you be departing from in your travels to Bucharest?" << endl;
	cin >> startingLocation;
	return startingLocation;
}

string getSearchType()
{
	string searchType;
	cout << "What type of search would you like to do?" << endl <<
		"Type 'b' for breadth first search" << endl <<
		"Type 'd' for depth first search" << endl <<
		"Type 'i' for iterative deepening search" << endl <<
		"Then press ENTER" << endl << endl;
	cin >> searchType;
	return searchType;
}

void BFS(Node* root)
{
	Node* currentNode = root;
	std::list<Node*>bfsq;
	bool bucharestFound = false;
	std::vector<string>vList;

	//root is visited, add to queue
	root->visited = true;
	bfsq.push_back(root);
	
	while (!bfsq.empty())//(!bfsq.empty() && !bucharestFound)
	{
		currentNode = bfsq.front();
		bfsq.pop_front();

		for (auto i : currentNode->cxnList)
		{
			
			if (!i.adjCity->visited)
			{
				vList.push_back(i.adjCity->city);
				i.adjCity->visited = true;
				bfsq.push_back(i.adjCity);
				i.adjCity->parent = currentNode;
			}
			
			if (i.adjCity->city == "Bucharest")
			{
				Node* temp = i.adjCity;
				vector<string>tempList;

				while (temp->city != root->city)
				{
					tempList.push_back(temp->city);
					temp = temp->parent;
				} 
				if (temp->city == root->city)
					tempList.push_back(temp->city);
				
				cout << "Visited:  ";
				for (int k = 0; k < vList.size(); k++)
				{
					cout << vList[k];
					if (k < vList.size() - 1)
						cout << ", ";
				}
				cout << endl;

				cout << "BFS Path: ";
				for (int j = tempList.size() - 1; j >= 0; j--)
				{
					cout << tempList[j];
					if (j != 0)
						cout << ", ";
				}
				cout << endl;

				return;
			}
		}
	}
}


void DFS(Node* root)
{
	vector<string>vList;
	vector<Node*>dStack;
	dStack.push_back(root);
	Node* currentNode = nullptr;
	Node* oldNode = nullptr;
	while (!dStack.empty())
	{
		currentNode = dStack.back();
		
		if (!currentNode->visited)
		{
			vList.push_back(currentNode->city);
			currentNode->visited = true;
		}
		oldNode = dStack.back();
		for (auto i : currentNode->cxnList)
		{
			if (!i.adjCity->visited)
			{
				dStack.push_back(i.adjCity);
				if (i.adjCity->city == "Bucharest")
				{
					vList.push_back(i.adjCity->city);
					cout << "Visited:  ";
					for (int j = 0; j < vList.size(); j++)
					{
						cout << vList[j];
						if (j < vList.size()-1)
							cout << ", ";
					}
					cout << endl;
					cout << "Path:  ";
					for (int j = 0; j < dStack.size(); j++)
					{
						cout << dStack[j]->city;
						if (j < dStack.size() - 1)
							cout << ", ";
					}
					cout << endl;
					return;
				}
				break;
			}
		}
		if (oldNode == dStack.back())
			dStack.pop_back();
	}
}

void idsLoop(Node* root)
{
	Node* currentNode = root;
	for (auto i : currentNode->cxnList)
	{
		if (i.adjCity->city == "Bucharest")
		{
			cout << "Found";
			return;
		}
		if (i.adjCity->visited == false)
			idsLoop(i.adjCity);
	}
}
void IDS(Node* root)
{
	idsLoop(root);
}
