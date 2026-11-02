#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> range_addition(int length, std::vector<std::vector<int>>& updates) {
    std::vector<int> diff(length, 0);
    int n = updates.size();
    for (int i = 0; i < n; i++) {
        diff[updates[i][0]] += updates[i][2];
        diff[updates[i][1] + 1] -= updates[i][2];
    }
    std::vector<int> res(length, 0);
    res[0] = diff[0];
    for (int i = 1; i < length; i++)
        res[i] = res[i-1] + diff[i];
    
    return res;
}
