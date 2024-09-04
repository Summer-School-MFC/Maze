#include "pch.h"
#include "Maze.h"
#include <array>
#include <utility>
#include <algorithm>
#include <chrono>

Maze::Maze(int width, int height) : width(width), height(height) {
	grid.resize(height, std::vector<bool>(width, true));
	unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
	rng.seed(seed);
}

void Maze::generate() {
	// 初始化迷宫，所有格子都是墙
	grid.resize(height, std::vector<bool>(width, true));

	// 设置起点和终点
	generateStartAndEnd();

	// 从起点开始生成迷宫
	dfs(start.first, start.second);

	// 确保起点和终点是通路
	grid[start.second][start.first] = false;
	grid[end.second][end.first] = false;
}

void Maze::generateStartAndEnd() {
	std::uniform_int_distribution<int> dist(1, 4);
	int startSide = dist(rng);
	int endSide = dist(rng);

	auto getRandomPointOnSide = [&](int side) {
		std::uniform_int_distribution<int> distPos(1, (side % 2 == 0 ? width : height) - 2);
		switch (side) {
		case 1: return std::make_pair(distPos(rng), 1); // Top
		case 2: return std::make_pair(width - 2, distPos(rng)); // Right
		case 3: return std::make_pair(distPos(rng), height - 2); // Bottom
		case 4: return std::make_pair(1, distPos(rng)); // Left
		}
		return std::make_pair(1, 1); // Default case
		};

	start = getRandomPointOnSide(startSide);
	end = getRandomPointOnSide(endSide);

	// 确保起点和终点不相同
	while (start == end) {
		end = getRandomPointOnSide(endSide);
	}
}

std::pair<int, int> Maze::getStart() const {
	return start;
}

std::pair<int, int> Maze::getEnd() const {
	return end;
}

bool Maze::isWall(int x, int y) const {
	if (x < 0 || x >= width || y < 0 || y >= height) return true;
	return grid[y][x];
}

void Maze::dfs(int x, int y) {
	static const std::array<std::pair<int, int>, 4> directions = {
		std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(0, 1), std::make_pair(-1, 0)
	};

	std::vector<std::pair<int, int>> shuffledDirections(directions.begin(), directions.end());
	std::shuffle(shuffledDirections.begin(), shuffledDirections.end(), rng);

	grid[y][x] = false;

	for (const auto& dir : shuffledDirections) {
		int nx = x + dir.first * 2;
		int ny = y + dir.second * 2;

		if (nx > 0 && nx < width - 1 && ny > 0 && ny < height - 1 && grid[ny][nx]) {
			grid[y + dir.second][x + dir.first] = false;
			dfs(nx, ny);
		}
	}
}
