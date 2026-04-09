#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>

class Exit; // Forward declaration

class Puzzle {
public:
    Puzzle(const std::string& question, const std::string& solution, Exit* linked_exit);
    ~Puzzle();

    bool CheckSolution(const std::string& attempt);
    std::string GetQuestion() const;
    bool IsSolved() const;

private:
    std::string question;
    std::string solution;
    Exit* linked_exit;
    bool is_solved = false;
};

#endif // PUZZLE_H