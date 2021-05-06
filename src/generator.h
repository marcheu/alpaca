#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include "src/database.h"
#include "src/problem.h"

using namespace std;

class generator {
      public:
	generator ();
	void generate_view_problem (int problem_id);
	void generate_edit_problem (int problem_id);
	void edit_problem_hold (int problem_id, string change);
	void edit_problem_grade (int problem_id, string grade);
	void edit_problem_rating (int problem_id, string rating);
	void generate_view_all_problems ();
	void generate_main_redirect ();
	void generate_stats ();
	void add_problem ();
	void delete_problem (int problem_id);
      private:

	void output_head (problem * p);
	void output_css (problem * p);
	void output_css_heatmap ();
	void generate_header (int problem_id, bool delete_icon, bool list_icon);
	database database_;
};

#endif
