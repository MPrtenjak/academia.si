#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <map>

using namespace std;

#ifdef PRIM

struct Edge {
	string from, to;
	int weight = 0;
};

set<string> GetAllNodes(const vector<Edge> graph) {
	set<string> nodes;

	for (vector<Edge>::const_iterator i = graph.begin(); i != graph.end(); ++i)
	{
		nodes.insert(i->from);
		nodes.insert(i->to);
	}

	return nodes;
}

void printNodes(const set<string>& nodes) {
	for (set<string>::const_iterator i = nodes.begin(); i != nodes.end(); ++i)
		cout << *i << endl;
}

bool isUnvisited(const vector<string> unvisited, string node) {
	return find(unvisited.begin(), unvisited.end(), node) != unvisited.end();
}

bool isVisited(const vector<string> visited, string node) {
	return find(visited.begin(), visited.end(), node) != visited.end();
}

Edge getMinReminingEdge(const vector<Edge> graph, const vector<string> visited, const vector<string> unvisited) {
	int minWeight = numeric_limits<int>::max();
	Edge minEdge;

	for (vector<Edge>::const_iterator i = graph.begin(); i != graph.end(); ++i) {
		if ((isVisited(visited, i->from) && isUnvisited(unvisited, i->to)) ||
			(isUnvisited(unvisited, i->from) && isVisited(visited, i->to)))
		{
			if (i->weight < minWeight)
			{
				minWeight = i->weight;
				minEdge = *i;
			}
		}
	}

	return minEdge;
}

void prim(const std::vector<Edge>& graph)
{
	set<string> nodes = GetAllNodes(graph);
	printNodes(nodes);

	vector<string> visited;
	vector<string> unvisited(nodes.begin(), nodes.end());
	vector<Edge> primsPath;

	visited.push_back(*unvisited.begin());
	unvisited.erase(unvisited.begin());

	while (!unvisited.empty()) {
		Edge minEdge = getMinReminingEdge(graph, visited, unvisited);
		primsPath.push_back(minEdge);

		if (isVisited(visited, minEdge.from))
		{
			visited.push_back(minEdge.to);
			unvisited.erase(find(unvisited.begin(), unvisited.end(), minEdge.to));
		}
		else
		{
			visited.push_back(minEdge.from);
			unvisited.erase(find(unvisited.begin(), unvisited.end(), minEdge.from));
		}
	}

	int sumWeight = 0;
	cout << "Prims path:" << endl;
	for (vector<Edge>::const_iterator p = primsPath.begin(); p != primsPath.end(); ++p)
	{
		cout << p->from << " - " << p->to << " : " << p->weight << endl;
		sumWeight += p->weight;
	}
	cout << "Total weight: " << sumWeight << endl;
}

struct DijkstraNode {
	string node;
	int sumPathToNode = 0;
};

void dijkstra(const std::vector<Edge>& graph, string startNode, string endNode) {
	set<string> nodes = GetAllNodes(graph);
	printNodes(nodes);

	vector<string> visited;
	vector<string> unvisited(nodes.begin(), nodes.end());

	map<string, DijkstraNode> dijkstraNodes;
	for (set<string>::iterator i = nodes.begin(); i != nodes.end(); ++i)
		dijkstraNodes[*i] = { *i, numeric_limits<int>::max() };

	map<string, pair<string, int>> bestPathToNode;
	string currentNode = startNode;
	dijkstraNodes[currentNode].sumPathToNode = 0;

	while (!unvisited.empty()) {
		for (std::vector<Edge>::const_iterator g = graph.begin(); g != graph.end(); ++g) {
			if ((g->from == currentNode && isUnvisited(unvisited, g->to)) ||
				(g->to == currentNode && isUnvisited(unvisited, g->from)))
			{
				string otherNode = (g->from == currentNode) ? g->to : g->from;
				int newSumPathToOtherNode = dijkstraNodes[currentNode].sumPathToNode + g->weight;
				if (newSumPathToOtherNode < dijkstraNodes[otherNode].sumPathToNode) {
					dijkstraNodes[otherNode].sumPathToNode = newSumPathToOtherNode;
					bestPathToNode[otherNode] = make_pair(currentNode, newSumPathToOtherNode);
				}
			}
		}

		visited.push_back(currentNode);
		unvisited.erase(find(unvisited.begin(), unvisited.end(), currentNode));

		int shortestPath = numeric_limits<int>::max();
		for (vector<string>::const_iterator u = unvisited.begin(); u != unvisited.end(); ++u) {
			if (dijkstraNodes[*u].sumPathToNode < shortestPath) {
				shortestPath = dijkstraNodes[*u].sumPathToNode;
				currentNode = *u;
			}
		}
	}

	// print path from endNode to startNode
	string pathNode = endNode;
	while (pathNode != startNode) {
		pair<string, int> pathTo = bestPathToNode[pathNode];
		cout << pathTo.first << " - " << pathNode << " : " << pathTo.second << endl;
		pathNode = pathTo.first;
	}
}

int main() {
	vector<Edge> graph = {
		{ "A", "B", 8},
		{ "A", "C", 7 },
		{ "B", "C", 14 },
		{ "B", "D", 12 },
		{ "C", "E", 19 },
		{ "C", "G", 25 },
		{ "D", "E", 5 },
		{ "D", "F", 18 },
		{ "E", "G", 14 },
		{ "E", "F", 9 }
	};

	//prim(graph);
	dijkstra(graph, "A", "F");

	return 0;
}
#endif
