
/*
// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};
*/

class Solution {
public:
	int getImportance(vector<Employee*>& employees, int id) {

		auto emp = find_if(employees.begin(), employees.end(), [id](const Employee* e) {
					return e->id == id;
				});
		int res = (*emp)->importance;
		for (int em : (*emp)->subordinates) 
			res += getImportance(employees, em);
		return res;
	}
};
