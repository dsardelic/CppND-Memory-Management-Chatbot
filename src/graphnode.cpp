#include "graphnode.h"

#include <iostream>  // std::cout
#include <memory>    // std::unique_ptr
#include <string>    // std::string

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

  // delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) {
  std::cout << "DEBUG: "
            << "GraphNode::AddToken(std::string token)" << std::endl;
  _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge) {
  std::cout << "DEBUG: "
            << "GraphNode::AddEdgeToParentNode(GraphEdge *edge)" << std::endl;
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  std::cout << "DEBUG: "
            << "GraphNode::AddEdgeToChildNode(GraphEdge *edge)" << std::endl;
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  std::cout << "DEBUG: "
            << "GraphNode::MoveChatbotHere(ChatBot *chatbot)" << std::endl;
  _chatBot = std::move(chatbot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode) {
  std::cout << "DEBUG: "
            << "GraphNode::MoveChatbotToNewNode(GraphNode *newNode)"
            << std::endl;
  newNode->MoveChatbotHere(std::move(_chatBot));
  //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index) {
  std::cout << "DEBUG: "
            << "GraphNode::GetChildEdgeAtIndex(int index)" << std::endl;
  //// STUDENT CODE
  ////

  return _childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}