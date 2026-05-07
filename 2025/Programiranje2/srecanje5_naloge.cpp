#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

#ifdef RESITEV_SRECANJE_5

struct Edge {
	string startNode;
	string endNode;
	int length;
};

class Graph
{
protected:
	vector<string> nodes;
	vector<Edge> edges;

public:
	bool hasNode(string nodeName) const;
	bool hasEdge(string startNode, string endNode) const;
	int length(string startNode, string endNode) const;
	vector<string> neighbors(string nodeName) const;

	void addNode(string nodeName);
	void addEdge(string startNode, string endNode, int length);
};

bool Graph::hasNode(string nodeName) const
{
	return find(nodes.begin(), nodes.end(), nodeName) != nodes.end();
}

bool Graph::hasEdge(string startNode, string endNode) const
{
	for (vector<Edge>::const_iterator i = edges.begin(); i != edges.end(); ++i)
	{
		if (i->startNode == startNode && i->endNode == endNode)
			return true;
	}

	return false;

	// lahko pa tudi z uporabo algoritma find_if in lambda funkcije:
	/*
	return find_if(edges.begin(), edges.end(), [startNode, endNode](const Edge& edge) {
		return edge.startNode == startNode && edge.endNode == endNode;
	}) != edges.end();
	*/
}

int Graph::length(string startNode, string endNode) const
{
	for (vector<Edge>::const_iterator i = edges.begin(); i != edges.end(); ++i)
	{
		if (i->startNode == startNode && i->endNode == endNode)
			return i->length;
	}

	return numeric_limits<int>::max();

	/* ali pa z uporabo find if...
	auto it = find_if(edges.begin(), edges.end(), [startNode, endNode](const Edge& edge) {
		return edge.startNode == startNode && edge.endNode == endNode;
	});

	return (it != edges.end()) ? it->length : numeric_limits<int>::max();
	*/
}

vector<string> Graph::neighbors(string nodeName) const
{
	vector<string> neighbors;
	for (const Edge& edge : edges) {
		if (edge.startNode == nodeName) {
			neighbors.push_back(edge.endNode);
		}
	}

	return neighbors;
}

void Graph::addNode(string nodeName)
{
	if (!hasNode(nodeName)) {
		nodes.push_back(nodeName);
	}
}	

void Graph::addEdge(string startNode, string endNode, int length)
{
	if (!hasEdge(startNode, endNode)) {
		Edge e = { startNode, endNode, length };

		edges.push_back(e);
	}
}


class Prim : public Graph
{
protected:
	bool isVisited(const vector<string>& visited, const string& node) const;
	bool isUnvisited(const vector<string>& unvisited, const string& node) const;

	Edge getMinReminingEdge(const vector<string>& visited, const vector<string>& unvisited) const;


public:
	vector<Edge> getPath();
};

bool Prim::isVisited(const vector<string>& visited, const string& node) const
{
	return find(visited.begin(), visited.end(), node) != visited.end();
}

bool Prim::isUnvisited(const vector<string>& unvisited, const string& node) const
{
	return find(unvisited.begin(), unvisited.end(), node) != unvisited.end();
}


Edge Prim::getMinReminingEdge(const vector<string>& visited, const vector<string>& unvisited) const
{
	Edge minEdge = { "", "", numeric_limits<int>::max() };

	for (const Edge& edge : edges) {
		if ((isVisited(visited, edge.startNode) && isUnvisited(unvisited, edge.endNode)) ||
			(isVisited(visited, edge.endNode) && isUnvisited(unvisited, edge.startNode)))
		{
			if (edge.length < minEdge.length) {
				minEdge = edge;
			}
		}
	}

	return minEdge;
}

vector<Edge> Prim::getPath()
{
	vector<string> visited;
	vector<string> unvisited(nodes.begin(), nodes.end());
	vector<Edge> primsPath;

	visited.push_back(*unvisited.begin());
	unvisited.erase(unvisited.begin());

	while (!unvisited.empty()) {
		Edge minEdge = getMinReminingEdge(visited, unvisited);
		primsPath.push_back(minEdge);

		if (isVisited(visited, minEdge.startNode))
		{
			visited.push_back(minEdge.endNode);
			unvisited.erase(find(unvisited.begin(), unvisited.end(), minEdge.endNode));
		}
		else
		{
			visited.push_back(minEdge.startNode);
			unvisited.erase(find(unvisited.begin(), unvisited.end(), minEdge.startNode));
		}
	}

	return primsPath;
}

struct DijkstraNode {
	string node;
	int sumPathToNode = 0;
};

class Dijkstra : public Prim
{
public:
	vector<Edge> getPath(string startNode, string endNode);
};

vector<Edge> Dijkstra::getPath(string startNode, string endNode)
{
	vector<string> visited;
	vector<string> unvisited(nodes.begin(), nodes.end());
	map<string, DijkstraNode> dijkstraNodes;

	for (const string& node : nodes)
		dijkstraNodes[node] = { node, numeric_limits<int>::max() };

	map<string, pair<string, int>> bestPathToNode;
	string currentNode = startNode;
	dijkstraNodes[currentNode].sumPathToNode = 0;

	while (!unvisited.empty()) {
		for (const Edge& edge : edges) {
			if ((edge.startNode == currentNode && isUnvisited(unvisited, edge.endNode)) ||
				(edge.endNode == currentNode && isUnvisited(unvisited, edge.startNode)))
			{
				string neighbor = (edge.startNode == currentNode) ? edge.endNode : edge.startNode;
				int newPathLength = dijkstraNodes[currentNode].sumPathToNode + edge.length;
				if (newPathLength < dijkstraNodes[neighbor].sumPathToNode) {
					dijkstraNodes[neighbor].sumPathToNode = newPathLength;
					bestPathToNode[neighbor] = { currentNode, edge.length };
				}
			}
		}

		visited.push_back(currentNode);
		unvisited.erase(find(unvisited.begin(), unvisited.end(), currentNode));
		if (currentNode == endNode) {
			break;
		}

		currentNode = *min_element(unvisited.begin(), unvisited.end(), [&dijkstraNodes](const string& a, const string& b) {
			return dijkstraNodes[a].sumPathToNode < dijkstraNodes[b].sumPathToNode;
		});
	}

	vector<Edge> path;
	string node = endNode;
	while (node != startNode) {
		auto it = bestPathToNode.find(node);
		if (it == bestPathToNode.end()) {
			return {}; 
		}

		string prevNode = it->second.first;
		int length = it->second.second;

		Edge edge = { prevNode, node, length };
		path.push_back(edge);
		node = prevNode;
	}

	reverse(path.begin(), path.end());
	return path;
}

struct CriticalPathNode {
	string node;
	int unvisitedParents = 0;
	int sumPathToNode = 0;
	string criticalParent;
};

class CriticalPath : public Graph
{
protected:
	vector<string> visitedNodes;
	vector<string> unvisitedNodes;
	map<string, CriticalPathNode> criticalPathNodes;

	void createInitalNodeStatus();
	string selectNextNode();

public:
	vector<string> getPath(string endNode, int& maxLen);
};

void CriticalPath::createInitalNodeStatus()
{
	criticalPathNodes.clear();

	for (const string& node : nodes) {
		int unvisitedParents = count_if(edges.begin(), edges.end(), [&node](const Edge& edge) {
			return edge.endNode == node;
		});

		CriticalPathNode cpNode = { node, unvisitedParents, 0, "" };
		criticalPathNodes[node] = cpNode;
	}
}

string CriticalPath::selectNextNode()
{
	auto nextNode = find_if(unvisitedNodes.begin(), unvisitedNodes.end(), [this](const string& node) {
		return criticalPathNodes[node].unvisitedParents == 0;
	});

	return (nextNode != unvisitedNodes.end()) ? *nextNode : "";
}

vector<string> CriticalPath::getPath(string endNode, int &maxLen)
{
	visitedNodes.clear();
	unvisitedNodes = nodes;
	createInitalNodeStatus();

	string nextNode = selectNextNode();
	while (nextNode != "" && nextNode != endNode) {
		visitedNodes.push_back(nextNode);
		unvisitedNodes.erase(find(unvisitedNodes.begin(), unvisitedNodes.end(), nextNode));

		for (const Edge& edge : edges) {
			if (edge.startNode == nextNode) {
				auto& cpNode = criticalPathNodes[edge.endNode];
				cpNode.unvisitedParents--;
				int pathLength = criticalPathNodes[nextNode].sumPathToNode + edge.length;
				if (pathLength > cpNode.sumPathToNode) {
					cpNode.sumPathToNode = pathLength;
					cpNode.criticalParent = nextNode;
				}
			}
		}

		nextNode = selectNextNode();
	}

	maxLen = 0;
	if (nextNode == endNode) {
		vector<string> criticalPath;

		string node = endNode;
		maxLen = criticalPathNodes[node].sumPathToNode;
		while (node != "") {
			criticalPath.push_back(node);
			node = criticalPathNodes[node].criticalParent;
		}
		reverse(criticalPath.begin(), criticalPath.end());

		return criticalPath;
	}
	else {
		return {};
	}
}

int main()
{
	Graph g;

	g.addNode("A");
	g.addNode("B");
	g.addNode("C");
	g.addNode("D");
	g.addNode("E");
	g.addNode("F");
	g.addNode("G");
	g.addEdge("A", "B", 8);
	g.addEdge("A", "C", 7);
	g.addEdge("B", "C", 14);
	g.addEdge("B", "D", 12);
	g.addEdge("G", "C", 25);
	g.addEdge("E", "C", 19);
	g.addEdge("E", "D", 5);
	g.addEdge("E", "F", 9);
	g.addEdge("D", "F", 18);
	g.addEdge("E", "G", 14);

	cout << "O grafu..." << endl;
	cout << "Ali ima vozlisce A: " << g.hasNode("A") << endl;
	cout << "Ali ima povezavo A -> B: " << g.hasEdge("A", "B") << endl;
	cout << "Dolžina povezave A -> C: " << g.length("A", "C") << endl;

	Prim *p = static_cast<Prim *>(&g);
	vector<Edge> primsPath = p->getPath();
	cout << "Primova pot:" << endl;
	for (const Edge& edge : primsPath) {
		cout << edge.startNode << " - " << edge.endNode << " : " << edge.length << endl;
	}
	cout << endl << endl;

	Dijkstra* d = static_cast<Dijkstra*>(&g);
	vector<pair<string, string>> dijkstraEdges = { { "A", "B"}, { "A", "C" }, { "A", "D" }, { "A", "E" }, { "A", "F" }, { "C", "F" } };
	for (const auto& edge : dijkstraEdges) {
		vector<Edge> path = d->getPath(edge.first, edge.second);
		cout << "Dijkstrajeva pot od " << edge.first << " do " << edge.second << ":" << endl;
		for (const Edge& e : path) {
			cout << e.startNode << " - " << e.endNode << " : " << e.length << endl;
		}
	}
	cout << endl << endl;


	CriticalPath cp;
	cp.addNode("A");
	cp.addNode("B");
	cp.addNode("C");
	cp.addNode("D");
	cp.addNode("E");
	cp.addNode("F");
	cp.addNode("G");
	cp.addNode("H");
	cp.addNode("I");
	cp.addNode("J");
	cp.addEdge("A", "C", 5);
	cp.addEdge("B", "D", 6);
	cp.addEdge("C", "E", 8);
	cp.addEdge("C", "F", 10);
	cp.addEdge("D", "F", 11);
	cp.addEdge("D", "G", 7);
	cp.addEdge("E", "H", 8);
	cp.addEdge("F", "H", 9);
	cp.addEdge("F", "I", 8);
	cp.addEdge("G", "I", 6);
	cp.addEdge("H", "J", 12);
	cp.addEdge("I", "J", 7);

	vector<string> criticalPathNodes = { "D", "E", "F", "G", "H", "I", "J" };
	for (const auto& endNode : criticalPathNodes) {
		int maxLen = 0;
		vector<string> criticalPath = cp.getPath(endNode, maxLen);
		cout << "Kriticna pot do vozlisca " << endNode << ":" << endl;
		for (const string& node : criticalPath) {
			cout << node << " ";
		}
		cout << "\tDolzina: " << maxLen << endl;
	}

	return 0; 
}

#endif