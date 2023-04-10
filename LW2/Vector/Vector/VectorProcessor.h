#pragma once
#include <fstream>
#include <vector>

bool ParseVector(std::istream& input, std::vector<float>& vec);
std::vector<float> ProcessVector(std::vector<float>& vec);
void SortVector(std::vector<float>& vec);
