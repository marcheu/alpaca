#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include "src/database.h"
#include "src/problem.h"

class generator {
      public:
	void generate_problem (int problem_id);
	void generate_all_problems ();
	void output_css ();
      private:

	void generate_header ();
	database database_;
};

#endif
