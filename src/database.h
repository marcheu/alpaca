#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <list>

#include "src/background.h"
#include "src/hold.h"
#include "src/problem.h"

using namespace std;

static const string base_dir = string ("/home/marcheu/alpaca/");


class database {
      public:
	database ();

	bool get_problem (int problem_id, problem & p);
	bool get_all_problems (list < problem > &p_list);
	bool get_all_holds (list < hold > &h_list);
	bool edit_problem_hold (int problem_id, int hold_id, hold_type type);
	bool edit_problem_grade (int problem_id, problem_grade grade);
	bool edit_problem_rating (int problem_id, problem_rating rating);
	bool add_problem (int &id);
	bool delete_problem (int id);

      private:
	  std::list < background > backgrounds_;
	  std::vector < hold > holds_;
	  std::list < problem > problems_;

	bool load_problem (const char *name, problem & p);
	bool load_holds ();
	bool load_problems ();
	bool save_problem (int problem_id, problem & p);

};

#endif
