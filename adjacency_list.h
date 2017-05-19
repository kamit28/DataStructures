/*
 * adjacency_list.h
 *
 *  Created on: 12-May-2017
 *      Author: Amit
 */

#ifndef ADJACENCY_LIST_H_
#define ADJACENCY_LIST_H_

#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

struct weighted_edge {
private:
	int startVertex;
	int endVertex;
	int weight;

public:
	/**
	 * @param startVertex
	 * @param endVertex
	 * @param weight
	 */
	weighted_edge(int startVertex = 0, int endVertex = 0, int weight = 0) {
		this->startVertex = startVertex;
		this->endVertex = endVertex;
		this->weight = weight;
	}

	/**
	 * @return the startVertex
	 */
	const int getStartVertex() const {
		return startVertex;
	}

	/**
	 * @param startVertex
	 *            the startVertex to set
	 */
	void setStartVertex(int startVertex) {
		this->startVertex = startVertex;
	}

	/**
	 * @return the endVertex
	 */
	const int getEndVertex() const {
		return endVertex;
	}

	/**
	 * @param endVertex
	 *            the endVertex to set
	 */
	void setEndVertex(int endVertex) {
		this->endVertex = endVertex;
	}

	/**
	 * @return the weight
	 */
	const int getWeight() const {
		return weight;
	}

	/**
	 * @param weight
	 *            the weight to set
	 */
	void setWeight(int weight) {
		this->weight = weight;
	}

	std::string toString() const {
		std::stringstream ss;
		ss << "[Start Vertex: " << startVertex << ", End Vertex: " << endVertex
				<< ", Weight: " << weight << "]";
		return ss.str();
	}
};

class adjacency_list {
private:
	std::map<int, std::list<weighted_edge> > graph;

public:
	adjacency_list(int numVertices) {
		for (int i = 1; i <= numVertices; i++) {
			graph[i];
		}
	}

	void set_edge(const int start_vertex, const weighted_edge& edge) {
		if (graph.find(start_vertex) == graph.end()
				|| graph.find(edge.getEndVertex()) == graph.end()) {
			throw std::logic_error(
					"The vertex entered is not present in the graph");
		}
		graph.at(start_vertex).push_back(edge);
	}

	std::list<weighted_edge> get_edge(int source) const {
		std::cout << source << std::endl;
		if (graph.find(source) == graph.end()) {
			std::cout << source << std::endl;
			throw std::logic_error(
					"The vertex entered is not present in the graph");
		}
		return graph.at(source);
	}

	void remove_edge(const int source, const weighted_edge& edge) {
		if (graph.find(source) == graph.end()
				|| graph.find(edge.getEndVertex()) == graph.end()) {
			throw std::logic_error(
					"The vertex entered is not present in the graph");
		}
	}

	void remove(std::list<weighted_edge> edgeList, weighted_edge v) {
		for (std::list<weighted_edge>::iterator it = edgeList.begin();
				it != edgeList.end(); ++it) {
			if ((*it).getEndVertex() == v.getEndVertex()) {
				edgeList.erase(it);
				break;
			}
		}
	}

	const int size() const {
		return graph.size();
	}

	/**
	 const std::unordered_set<weighted_edge> get_vertices() {
	 std::unordered_set<weighted_edge> vertices;
	 for (std::map<int, std::list<weighted_edge> >::iterator it =
	 graph.begin(); it != graph.end(); ++it) {
	 vertices.insert(it->first);
	 }
	 return vertices;
	 }
	 **/

	void print_graph() {
		for (std::map<int, std::list<weighted_edge> >::iterator it =
				graph.begin(); it != graph.end(); ++it) {
			std::cout << it->first << " - > ";
			std::list<weighted_edge> edge_list = it->second;
			if (!edge_list.empty()) {
				for (std::list<weighted_edge>::iterator edge_iter =
						edge_list.begin(); edge_iter != edge_list.end();) {
					std::cout << (*edge_iter).getEndVertex() << ", "
							<< (*edge_iter).getWeight();
					++edge_iter;
					if (edge_iter != edge_list.end()) {
						std::cout << " -> ";
					}
				}
			}
			std::cout << std::endl;
		}
	}
};

#endif /* ADJACENCY_LIST_H_ */
