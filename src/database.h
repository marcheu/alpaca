#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <list>

#include "src/background.h"
#include "src/hold.h"
#include "src/problem.h"

using namespace std;


class database {
      public:
	database ();

	bool get_problem (int problem_id, problem & p);
	bool get_all_problems (list < problem > &p_list);
	bool get_all_holds (list < hold > &h_list);

      private:
	  std::list < background > backgrounds_;
	  std::vector < hold > holds_;
	  std::list < problem > problems_;

	bool load_problem (const char *name, problem & p);
	bool load_holds ();
	bool load_problems ();

};

#endif
