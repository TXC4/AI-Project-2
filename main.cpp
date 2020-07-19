#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	Node Oradea("Oradea");
	Node Zerind("Zerind");
	Node Arad("Arad");
	Oradea.addCxn(&Zerind, 71);
	Zerind.addCxn(&Oradea, 71);
	Zerind.addCxn(&Arad, 75);
}
