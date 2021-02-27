
#include "src/database.h" 
#include "src/includes.h" 

static constexpr char *data_dir_ = "/home/pi/alpaca/data/";

class file_iterator {
      public:
	void reset () {
		d = NULL;
	}
	bool run (char *filename) {
		if (!d) {
			d = opendir (data_dir_);
			assert (d);
		}

		struct dirent *dir;
again:
 		dir = readdir (d);

		if (!dir) {
			closedir (d);
			d = NULL;
			return false;
		}

		if (dir->d_type == DT_DIR)
			goto again;
		strcpy (filename, dir->d_name);
		return true;
	}
	~file_iterator () {
		if (d) {
			closedir (d);
			d = NULL;
		}
	}
      private:
	DIR *d;
};

bool database::load_problem(const char *name, problem &p)
{
	printf("+ %s + \n",name);
	p.id_ = atoi(name);
	strcpy(p.author_, "胖胖");
	strcpy(p.name_, "Black sabbath");
	p.grade_ = (problem_grade)(rand() % (int)V16);
	p.holds_[0].hold_id = 0;
	p.holds_[0].type = start;
	p.date_.day = 10;
	p.date_.month = 15;
	p.date_.year = 2020;

	return true;
}

bool database::get_problem(int problem_id, problem &p)
{
	char name[128];
	sprintf(name, "%d", problem_id);

	return load_problem(name, p);
}

bool compare(const problem &p1, const problem &p2)
{
	return p1.grade_ < p2.grade_;
}

bool database::get_all_problems(int &num, list<problem> &p_list)
{
	srand(time(NULL));
	file_iterator it;
	it.reset();
	char name[128];
	bool success = true;

	while(it.run(name)) {
		problem p;
		success |= load_problem(name, p);
		p_list.push_back(p);
	}

	p_list.sort(compare);

	return success;
}

