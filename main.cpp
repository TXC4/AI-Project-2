#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include "LinkedList.h"

using namespace std;

string getStartLocation();
string getSearchType();
void BFS(Node*);
void DFS(Node*);
void IDS(Node*);

int stepCount = 0;

int main()
{
	while (true)
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

	
		cout << endl;
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

		ofstream outFile;
		outFile.open("stepCount.txt");
		outFile << stepCount;
		outFile.close();

		stepCount = 0;
	}
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

	//check if we start in Bucharest
	if (currentNode->city == "Bucharest")
	{
		std::ofstream oStr;
		oStr.open("visited.txt");
		oStr << "Bucharest";
		oStr.close();
		std::ofstream oStr2;
		oStr2.open("path.txt");
		oStr2 << "Bucharest";
		oStr2.close();
		cout << "Visited:  Bucharest" << endl;
		cout << "Path:  Bucharest.. just don't move and you are there" << endl;
		return;
	}
	
	while (!bfsq.empty())
	{
		currentNode = bfsq.front();
		bfsq.pop_front();
		

		for (auto i : currentNode->cxnList)
		{
			
			if (!i.adjCity->visited)
			{
				stepCount++;
				vList.push_back(i.adjCity->city);

				std::ofstream oStr;
				oStr.open("visited.txt");
				for (int j = 0; j < vList.size() - 1; j++)
				{
					oStr << vList[j] << ",";
				}
				oStr.close();

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

				std::ofstream oStr;
				oStr.open("path.txt");
				cout << "BFS Path: ";
				for (int j = tempList.size() - 1; j >= 0; j--)
				{
					cout << tempList[j];
					oStr << tempList[j];
					if (j != 0)
					{
						cout << ", ";
						oStr << ",";
					}
				}
				oStr.close();
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

	//check if we start in Bucharest
	if (root->city == "Bucharest")
	{
		std::ofstream oStr;
		oStr.open("visited.txt");
		oStr << "Bucharest";
		oStr.close();
		std::ofstream oStr2;
		oStr2.open("path.txt");
		oStr2 << "Bucharest";
		oStr2.close();
		cout << "Visited:  Bucharest" << endl;
		cout << "Path:  Bucharest.. just don't move and you are there" << endl;
		return;
	}

	while (!dStack.empty())
	{
		currentNode = dStack.back();
		
		if (!currentNode->visited)
		{
			stepCount++;
			vList.push_back(currentNode->city);
			currentNode->visited = true;
		}
		oldNode = dStack.back();
		for (auto i : currentNode->cxnList)
		{
			if (!i.adjCity->visited)
			{
				dStack.push_back(i.adjCity);
				///////////
				vList.push_back(i.adjCity->city);

				std::ofstream oStr;
				oStr.open("visited.txt");
				for (int j = 0; j < vList.size() - 1; j++)
				{
					oStr << vList[j] << ",";
				}
				oStr.close();

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
					std::ofstream oStr;
					oStr.open("path.txt");
					for (int j = 0; j < dStack.size(); j++)
					{
						cout << dStack[j]->city;
						oStr << dStack[j]->city;
						if (j < dStack.size() - 1)
						{
							cout << ", ";
							oStr << ",";
						}
					}
					oStr.close();
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

vector<string>pathList;
vector<string>visitedList;
bool idsLoop(Node* root, int max)
{
	Node* currentNode = root;
	cout << currentNode->city << ", ";
	visitedList.push_back(currentNode->city);
	stepCount++;
	if (root->city == "Bucharest")
	{
		return true;
	}

	if (max <= 0)
		return false;

	for (auto i : currentNode->cxnList)
	{
		if (idsLoop(i.adjCity, max - 1) == true)
		{
			pathList.push_back(i.adjCity->city);
			return true;
		}
	}
	return false;
}
void IDS(Node* root)
{
	int maxDepth = 10;
	cout << "Visited:  ";
	for (int i = 0; i < maxDepth; i++)
	{
		if (idsLoop(root, i) == true)
		{
			cout << "loop returned true" << endl;
			pathList.push_back(root->city);
			break;
		}
	}
	std::ofstream oStr;
	oStr.open("path.txt");
	cout << "Path:  ";
	for (int i = pathList.size() - 1; i >= 0; i--)
	{
		oStr << pathList[i] << ",";
		cout << pathList[i];
		if (i > 0)
		{
			cout << ", ";
		}
	}
	std::ofstream oStr2;
	oStr2.open("visited.txt");
	for (int i = visitedList.size() - 1; i >= 0; i--)
	{
		oStr2 << visitedList[i];
		if (i > 0)
			oStr2 << ",";
	}
	oStr2.close();
	cout << endl;
	pathList.clear();
	visitedList.clear();
}
