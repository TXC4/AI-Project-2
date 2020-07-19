#pragma once
#include <string>
#include <vector>



struct Node
{
	struct Cxn
	{
		Node* adjCity;
		int distance = 0;
	};
	std::string city = "";
	std::vector<Cxn>cxnList;
	Node(std::string _city)
	{
		city = _city;
	}
	void addCxn(Node* newNode1 = nullptr, int d1 = 0, Node* newNode2 = nullptr, int d2 = 0,
		Node* newNode3 = nullptr, int d3 = 0, Node* newNode4 = nullptr, int d4 = 0)
	{
		if (newNode1 != nullptr)
		{
			Cxn newCxn1;
			newCxn1.adjCity = newNode1;
			newCxn1.distance = d1;
			cxnList.push_back(newCxn1);
		}
		if (newNode2 != nullptr)
		{
			Cxn newCxn2;
			newCxn2.adjCity = newNode2;
			newCxn2.distance = d2;
			cxnList.push_back(newCxn2);
		}
		if (newNode3 != nullptr)
		{
			Cxn newCxn3;
			newCxn3.adjCity = newNode3;
			newCxn3.distance = d3;
			cxnList.push_back(newCxn3);
		}
		if (newNode4 != nullptr)
		{
			Cxn newCxn4;
			newCxn4.adjCity = newNode4;
			newCxn4.distance = d4;
			cxnList.push_back(newCxn4);
		}
	}
};
