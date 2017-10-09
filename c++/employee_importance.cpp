#include <iostream>
#include <vector>

using namespace std;

using namespace std;

class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
  Employee(int id, int importance) : id(id), importance(importance) {}
};

class Solution {
public:
  int getImportance(vector<Employee*> employees, int id) {
    int importance_val = 0;
    for (Employee* employee : employees) {
      if (employee->id == id) {
        importance_val += employee->importance;
        for (int sub_id : employee->subordinates) {
          importance_val += getImportance(employees, sub_id);
        }
      }
    }
    return importance_val;
  }
};

int main() {
  Employee* employee1 = new Employee(1, 5);
  Employee* employee2 = new Employee(2, 3);
  Employee* employee3 = new Employee(3, 3);
  employee1->subordinates.push_back(2);
  employee1->subordinates.push_back(3);
  vector<Employee*> employees;
  employees.push_back(employee1);
  employees.push_back(employee2);
  employees.push_back(employee3);
  Solution s;
  int importance_val = s.getImportance(employees, 1);
  cout << importance_val << endl;
  return 0;
}
