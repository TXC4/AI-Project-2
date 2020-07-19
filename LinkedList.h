#pragma once
#include <string>

struct List
{
	struct Node
	{	
		Node(std::string _city, Node* _adjacentCity1 = nullptr, Node* _adjacentCity2 = nullptr,
			Node* _adjacentCity3 = nullptr, Node* _adjacentCity4 = nullptr)
		{
			city = _city;
			if (_adjacentCity1 != nullptr)
				Node* adjacentCity1 = _adjacentCity1;
			if (_adjacentCity2 != nullptr)
				Node* adjacentCity2 = _adjacentCity2;
			if (_adjacentCity3 != nullptr)
				Node* adjacentCity3 = _adjacentCity3;
			if (_adjacentCity4 != nullptr)
				Node* adjacentCity4 = _adjacentCity4;
		}
		std::string city = "";
		Node* adjacentCity;
	};
};