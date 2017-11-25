#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> restaurant_store;
    for (int i = 0; i < list1.size(); i++) {
      restaurant_store[list1[i]] = i;
    }
    vector<string> restaurant;
    int min = list1.size() + list2.size();
    for (int j = 0; j < list2.size(); j++) {
      if (restaurant_store.find(list2[j]) != restaurant_store.end()) {
        if (j + restaurant_store[list2[j]] < min) {
          restaurant.clear();
          restaurant.push_back(list2[j]);
          min = j + restaurant_store[list2[j]];
        } else if (j + restaurant_store[list2[j]] == min){
          restaurant.push_back(list2[j]);
        }
      }
    }
    return restaurant;
  }
};

int main() {
  vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  vector<string> list2 = {"KFC", "Shogun", "Burger King"};
  Solution s;
  vector<string> result = s.findRestaurant(list1, list2);
  for (string str : result) {
    cout << str << endl;
  }
  return 0;
}
