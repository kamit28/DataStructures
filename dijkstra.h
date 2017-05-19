/*
 * dijkstra.h
 *
 *  Created on: 12-May-2017
 *      Author: Amit
 */
#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include "adjacency_list.h"

weighted_edge getMinUnvistedEdge(const adjacency_list& graph,
		std::unordered_set<int>& visited, int i) {
	std::list<weighted_edge> edges = graph.get_edge(i);
	weighted_edge minEdge;
	minEdge.setWeight(10000000);
	for (std::list<weighted_edge>::iterator it = edges.begin();
			it != edges.end(); ++it) {
		if (!visited.count((*it).getEndVertex())) {
			if ((*it).getWeight() < minEdge.getWeight()) {
				minEdge = *it;
			}
		}
	}
	return minEdge;
}

void dijkstra(adjacency_list& graph, int source) {
	std::unordered_set<int> visited;
	int dist[graph.size() + 1];
	std::fill_n(dist, graph.size() + 1, 1000000);
	std::string sequence[graph.size() + 1];

	dist[source] = 0;
	sequence[source] = std::to_string(source);
	weighted_edge edge;
	visited.insert(source);
	int i = source;
	int temp;
	while (visited.size() < graph.size()) {
		edge = getMinUnvistedEdge(graph, visited, i);
		if (edge.getStartVertex() != 0) {
			temp = edge.getWeight() + dist[i];
			if (temp < dist[edge.getEndVertex()]) {
				dist[edge.getEndVertex()] = edge.getWeight() + dist[i];
				sequence[edge.getEndVertex()] = sequence[i] + ", "
						+ std::to_string(edge.getEndVertex());
			}
		}
		visited.insert(edge.getEndVertex());
		i = edge.getEndVertex();
	}

	for (int count = 1; count <= graph.size(); count++) {
		std::cout << "(" << sequence[count] << ") : " << dist[count] << "\t";
	}
	std::cout << std::endl;
}

template<typename Out>
void split(const std::string& s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

inline std::string trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ')+1);
    return str;
}

void create_graph_from_file(adjacency_list& graph,
		const std::string& file_name) {
	std::string sCurrentLine;
	std::ifstream graph_file(file_name);
	if (graph_file.is_open()) {
		while (std::getline(graph_file, sCurrentLine)) {
			std::vector<std::string> tokens = split(sCurrentLine, '\t');
			std::string token;
			int sVertex = std::stoi(trim(tokens[0]), nullptr, 0);
			std::vector<std::string> edgeData;
			for (int i = 1; i < tokens.size(); i++) {
				token = trim(tokens[i]);
				if (token.length() == 0)
					continue;
				edgeData = split(token, ',');
				weighted_edge edge(sVertex,
						std::stoi(trim(edgeData[0]), nullptr, 0),
						std::stoi(trim(edgeData[1]), nullptr, 0));

				graph.set_edge(sVertex, edge);
			}
		}
		graph_file.close();
	}
}

#endif
