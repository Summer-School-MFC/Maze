#pragma once
#include <vector>
#include <random>
class Maze {
public:
    Maze(int width, int height);
    void generate();
    bool isWall(int x, int y) const;
    std::pair<int, int> getStart() const;
    std::pair<int, int> getEnd() const;

private:
    void generateStartAndEnd();
    void dfs(int x, int y);

    int width;
    int height;
    std::vector<std::vector<bool>> grid;
    std::pair<int, int> start;
    std::pair<int, int> end;
    std::mt19937 rng;
};