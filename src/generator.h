#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include "src/database.h"
#include "src/problem.h"

using namespace std;

class generator {
      public:
	generator ();
	void generate_problem (int problem_id);
	void edit_problem_hold (int problem_id, string change);
	void edit_problem_grade (int problem_id, string grade);
	void generate_all_problems ();
	void add_problem ();
      private:

	void output_head (problem *p);
	void output_css (problem *p);
	void generate_header ();
	database database_;
};

#endif
