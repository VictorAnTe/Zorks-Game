#include "Puzzle.h"
#include "Exit.h"
#include <algorithm>

Puzzle::Puzzle(const std::string& q, const std::string& s, Exit* e) :
    question(q), solution(s), linked_exit(e) {}

Puzzle::~Puzzle()
{
}

bool Puzzle::CheckSolution(const std::string& attempt) {
    // We check the original solution and in case the solution is "dracula", it will be valid if the attempt is "vampire"
    if (attempt == solution || (solution == "dracula" && attempt == "vampire")) {
        is_solved = true;
        if (linked_exit != nullptr) {
            linked_exit->locked = false;
        }
        return true;
    }
    return false;
}

std::string Puzzle::GetQuestion() const {
    return question;
}

bool Puzzle::IsSolved() const {
    return is_solved;
}