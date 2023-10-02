#include"Node.h"

Node::Node(char _initial_letter) {
	character = _initial_letter;
	prev = nullptr;
	next = nullptr;
}