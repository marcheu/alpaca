#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <list>

#include "src/background.h"
#include "src/hold.h"
#include "src/problem.h"

using namespace std;


class database {
public:
	std::list<background> backgrounds_;
	std::list<hold_use> holds_;
	std::list<problem> problems_;


	bool get_problem(int problem_id, problem &p);
	bool get_all_problems(int &num, list<problem> &p_list);

private:
	bool load_problem(const char *name, problem &p);


};

#endif
