#include "graphnode.h"

#include <iostream>

#include "graphedge.h"

GraphNode::GraphNode(int id) {
  std::cout << "DEBUG: "
            << "GraphNode::GraphNode(int id)" << std::endl;
  _id = id;
}

GraphNode::~GraphNode() {
  std::cout << "DEBUG: "
            << "GraphNode::~GraphNode()" << std::endl;
  //// STUDENT CODE
  ////

  delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) {
  std::cout << "DEBUG: "
            << "GraphNode::AddToken(std::string token)" << std::endl;
  _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  std::cout << "DEBUG: "
            << "GraphNode::AddEdgeToParentNode(GraphEdge *edge)" << std::endl;
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge) {
  std::cout << "DEBUG: "
            << "GraphNode::AddEdgeToChildNode(GraphEdge *edge)" << std::endl;
  _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot) {
  std::cout << "DEBUG: "
            << "GraphNode::MoveChatbotHere(ChatBot *chatbot)" << std::endl;
  _chatBot = chatbot;
  _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  std::cout << "DEBUG: "
            << "GraphNode::MoveChatbotToNewNode(GraphNode *newNode)"
            << std::endl;
  newNode->MoveChatbotHere(_chatBot);
  _chatBot = nullptr;  // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  std::cout << "DEBUG: "
            << "GraphNode::GetChildEdgeAtIndex(int index)" << std::endl;
  //// STUDENT CODE
  ////

  return _childEdges[index];

  ////
  //// EOF STUDENT CODE
}