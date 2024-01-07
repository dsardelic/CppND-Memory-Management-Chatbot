#include "graphedge.h"

#include <iostream>

#include "graphnode.h"

GraphEdge::GraphEdge(int id) {
  std::cout << "DEBUG: "
            << "GraphEdge::GraphEdge(int id)" << std::endl;
  _id = id;
}

void GraphEdge::SetChildNode(GraphNode* childNode) {
  std::cout << "DEBUG: "
            << "GraphEdge::SetChildNode(GraphNode *childNode)" << std::endl;
  _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode* parentNode) {
  std::cout << "DEBUG: "
            << "GraphEdge::SetParentNode(GraphNode *parentNode)" << std::endl;
  _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token) {
  std::cout << "DEBUG: "
            << "GraphEdge::AddToken(std::string token)" << std::endl;
  _keywords.push_back(token);
}