#include "src/database.h"
#include "src/includes.h"

static constexpr char *data_dir_ = "/home/pi/alpaca/data/";

database::database ()
{
	load_holds ();
	load_problems ();
}

class file_iterator {
      public:
	void reset () {
		d = NULL;
	} bool run (char *filename) {
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
	DIR * d;
};

static void add_hold (int id, float xpos, float ypos, float radius, vector < hold > &l)
{
	hold h;
	h.id = id;
	h.xpos = xpos;
	h.ypos = ypos;
	h.radius = radius;
	l.push_back (h);
}

bool database::load_holds ()
{
	// Row 1
	add_hold (0, 15.f, 17.f, 13.f, holds_);
	add_hold (1, 51.f, 9.f, 21.f, holds_);
	add_hold (2, 102.f, 12.f, 14.f, holds_);
	add_hold (3, 150.f, 17.f, 14.f, holds_);
	add_hold (4, 192.f, 15.f, 14.f, holds_);
	add_hold (5, 240.f, 11.f, 16.f, holds_);

	add_hold (6, 288.f, 15.f, 12.f, holds_);
	add_hold (7, 333.f, 13.f, 15.f, holds_);
	add_hold (8, 378.f, 13.f, 17.f, holds_);
	add_hold (9, 427.f, 10.f, 15.f, holds_);
	add_hold (10, 473.f, 9.f, 15.f, holds_);

	// Row 2
	add_hold (11, 17.f, 62.f, 13.f, holds_);
	add_hold (12, 60.f, 65.f, 13.f, holds_);
	add_hold (13, 103.f, 57.f, 14.f, holds_);
	add_hold (14, 149.f, 62.f, 12.f, holds_);
	add_hold (15, 192.f, 60.f, 14.f, holds_);
	add_hold (16, 238.f, 60.f, 16.f, holds_);

	add_hold (17, 288.f, 60.f, 12.f, holds_);
	add_hold (18, 326.f, 58.f, 20.f, holds_);
	add_hold (19, 373.f, 58.f, 15.f, holds_);
	add_hold (20, 423.f, 57.f, 15.f, holds_);
	add_hold (21, 464.f, 58.f, 20.f, holds_);

	// Row 2.5
	add_hold (22, 125.f, 85.f, 15.f, holds_);
	add_hold (23, 216.f, 85.f, 14.f, holds_);
	add_hold (24, 312.f, 88.f, 11.f, holds_);
	add_hold (25, 400.f, 88.f, 13.f, holds_);

	// Row 3
	add_hold (26, 21.f, 112.f, 13.f, holds_);
	add_hold (27, 65.f, 115.f, 12.f, holds_);
	add_hold (28, 105.f, 112.f, 14.f, holds_);
	add_hold (29, 150.f, 112.f, 13.f, holds_);
	add_hold (30, 194.f, 114.f, 14.f, holds_);
	add_hold (31, 241.f, 110.f, 13.f, holds_);

	add_hold (32, 286.f, 114.f, 11.f, holds_);
	add_hold (33, 330.f, 113.f, 12.f, holds_);
	add_hold (34, 375.f, 114.f, 11.f, holds_);
	add_hold (35, 418.f, 110.f, 14.f, holds_);
	add_hold (36, 470.f, 115.f, 11.f, holds_);

	// Row 3.5
	add_hold (37, 135.f, 137.f, 10.f, holds_);
	add_hold (38, 307.f, 139.f, 12.f, holds_);

	// Row 4
	add_hold (39, 24.f, 158.f, 13.f, holds_);
	add_hold (40, 68.f, 158.f, 12.f, holds_);
	add_hold (41, 110.f, 158.f, 12.f, holds_);
	add_hold (42, 150.f, 152.f, 18.f, holds_);
	add_hold (43, 197.f, 160.f, 12.f, holds_);
	add_hold (44, 232.f, 146.f, 13.f, holds_);
	add_hold (45, 245.f, 170.f, 13.f, holds_);

	add_hold (46, 288.f, 164.f, 11.f, holds_);
	add_hold (47, 324.f, 156.f, 15.f, holds_);
	add_hold (48, 365.f, 155.f, 18.f, holds_);
	add_hold (49, 417.f, 160.f, 12.f, holds_);
	add_hold (50, 463.f, 162.f, 11.f, holds_);
	add_hold (51, 507.f, 162.f, 11.f, holds_);

	// Row 4.5
	add_hold (52, 135.f, 187.f, 10.f, holds_);
	add_hold (53, 222.f, 186.f, 8.f, holds_);
	add_hold (54, 308.f, 189.f, 10.f, holds_);

	// Row 5
	add_hold (55, 27.f, 200.f, 13.f, holds_);
	add_hold (56, 72.f, 202.f, 10.f, holds_);
	add_hold (57, 113.f, 204.f, 11.f, holds_);
	add_hold (58, 154.f, 206.f, 16.f, holds_);
	add_hold (59, 192.f, 202.f, 17.f, holds_);
	add_hold (60, 242.f, 204.f, 12.f, holds_);

	add_hold (61, 284.f, 206.f, 11.f, holds_);
	add_hold (62, 324.f, 206.f, 13.f, holds_);
	add_hold (63, 370.f, 205.f, 14.f, holds_);
	add_hold (64, 410.f, 200.f, 18.f, holds_);
	add_hold (65, 460.f, 204.f, 11.f, holds_);
	add_hold (66, 502.f, 205.f, 11.f, holds_);

	// Row 6
	add_hold (67, 34.f, 244.f, 12.f, holds_);
	add_hold (68, 75.f, 248.f, 10.f, holds_);
	add_hold (69, 114.f, 246.f, 11.f, holds_);
	add_hold (70, 137.f, 230.f, 15.f, holds_);
	add_hold (71, 200.f, 249.f, 13.f, holds_);
	add_hold (72, 254.f, 228.f, 9.f, holds_);
	add_hold (73, 252.f, 250.f, 9.f, holds_);

	add_hold (74, 276.f, 254.f, 7.f, holds_);
	add_hold (75, 278.f, 232.f, 7.f, holds_);
	add_hold (76, 294.f, 248.f, 7.f, holds_);
	add_hold (77, 328.f, 251.f, 9.f, holds_);
	add_hold (78, 456.f, 250.f, 11.f, holds_);
	add_hold (79, 500.f, 251.f, 12.f, holds_);

	// Row 7
	add_hold (80, 37.f, 286.f, 11.f, holds_);
	add_hold (81, 80.f, 290.f, 10.f, holds_);
	add_hold (82, 118.f, 292.f, 11.f, holds_);
	add_hold (83, 158.f, 280.f, 14.f, holds_);
	add_hold (84, 205.f, 294.f, 11.f, holds_);
	add_hold (85, 238.f, 268.f, 8.f, holds_);
	add_hold (86, 248.f, 295.f, 7.f, holds_);
	add_hold (87, 256.f, 280.f, 7.f, holds_);

	add_hold (88, 276.f, 274.f, 6.f, holds_);
	add_hold (89, 280.f, 288.f, 6.f, holds_);
	add_hold (90, 289.f, 275.f, 6.f, holds_);
	add_hold (91, 290.f, 298.f, 6.f, holds_);
	add_hold (92, 324.f, 292.f, 14.f, holds_);
	add_hold (93, 451.f, 290.f, 11.f, holds_);
	add_hold (94, 495.f, 290.f, 12.f, holds_);

	// Row 7.5
	add_hold (95, 142.f, 304.f, 11.f, holds_);
	add_hold (96, 225.f, 309.f, 11.f, holds_);
	add_hold (97, 310.f, 316.f, 7.f, holds_);

	// Row 8
	add_hold (98, 44.f, 325.f, 11.f, holds_);
	add_hold (99, 83.f, 325.f, 10.f, holds_);
	add_hold (100, 125.f, 328.f, 11.f, holds_);
	add_hold (101, 167.f, 328.f, 10.f, holds_);
	add_hold (102, 205.f, 330.f, 12.f, holds_);
	add_hold (103, 240.f, 327.f, 16.f, holds_);

	add_hold (104, 290.f, 333.f, 8.f, holds_);
	add_hold (105, 324.f, 328.f, 13.f, holds_);
	add_hold (106, 448.f, 330.f, 11.f, holds_);
	add_hold (107, 490.f, 330.f, 12.f, holds_);

	// Row 8.5
	add_hold (108, 144.f, 345.f, 10.f, holds_);

	// Row 9
	add_hold (109, 46.f, 365.f, 11.f, holds_);
	add_hold (110, 86.f, 362.f, 15.f, holds_);
	add_hold (111, 124.f, 366.f, 11.f, holds_);
	add_hold (112, 162.f, 366.f, 15.f, holds_);
	add_hold (113, 208.f, 369.f, 8.f, holds_);
	add_hold (114, 246.f, 366.f, 9.f, holds_);

	add_hold (115, 276.f, 360.f, 18.f, holds_);
	add_hold (116, 327.f, 371.f, 8.f, holds_);
	add_hold (117, 445.f, 370.f, 11.f, holds_);
	add_hold (118, 486.f, 368.f, 12.f, holds_);

	// Row 9.5
	add_hold (119, 150.f, 390.f, 8.f, holds_);
	add_hold (120, 217.f, 383.f, 7.f, holds_);
	add_hold (121, 215.f, 395.f, 7.f, holds_);
	add_hold (122, 228.f, 389.f, 8.f, holds_);
	add_hold (123, 305.f, 391.f, 8.f, holds_);

	// Row 10
	add_hold (124, 49.f, 405.f, 11.f, holds_);
	add_hold (125, 86.f, 396.f, 13.f, holds_);
	add_hold (126, 127.f, 403.f, 11.f, holds_);
	add_hold (127, 164.f, 404.f, 11.f, holds_);
	add_hold (128, 208.f, 409.f, 10.f, holds_);
	add_hold (129, 248.f, 406.f, 10.f, holds_);

	add_hold (130, 290.f, 406.f, 8.f, holds_);
	add_hold (131, 323.f, 411.f, 12.f, holds_);
	add_hold (132, 364.f, 407.f, 11.f, holds_);
	add_hold (133, 403.f, 407.f, 10.f, holds_);
	add_hold (134, 445.f, 408.f, 11.f, holds_);
	add_hold (135, 485.f, 408.f, 10.f, holds_);

	// Row 10.5
	add_hold (136, 150.f, 425.f, 8.f, holds_);
	add_hold (137, 228.f, 425.f, 8.f, holds_);
	add_hold (138, 305.f, 429.f, 8.f, holds_);
	add_hold (139, 385.f, 429.f, 8.f, holds_);

	// Row 11
	add_hold (140, 54.f, 440.f, 9.f, holds_);
	add_hold (141, 87.f, 440.f, 12.f, holds_);
	add_hold (142, 127.f, 439.f, 12.f, holds_);
	add_hold (143, 168.f, 444.f, 10.f, holds_);
	add_hold (144, 202.f, 439.f, 15.f, holds_);
	add_hold (145, 248.f, 440.f, 9.f, holds_);

	add_hold (146, 280.f, 440.f, 13.f, holds_);
	add_hold (147, 323.f, 447.f, 12.f, holds_);
	add_hold (148, 361.f, 443.f, 11.f, holds_);
	add_hold (149, 403.f, 447.f, 10.f, holds_);
	add_hold (150, 442.f, 446.f, 9.f, holds_);
	add_hold (151, 480.f, 444.f, 9.f, holds_);

	// Row 11.5
	add_hold (152, 150.f, 459.f, 8.f, holds_);
	add_hold (153, 230.f, 460.f, 8.f, holds_);
	add_hold (154, 384.f, 463.f, 8.f, holds_);

	// Row 12
	add_hold (155, 57.f, 476.f, 9.f, holds_);
	add_hold (156, 93.f, 476.f, 10.f, holds_);
	add_hold (157, 129.f, 478.f, 11.f, holds_);
	add_hold (158, 168.f, 476.f, 10.f, holds_);
	add_hold (159, 204.f, 473.f, 12.f, holds_);
	add_hold (160, 248.f, 476.f, 10.f, holds_);

	add_hold (161, 280.f, 473.f, 16.f, holds_);
	add_hold (162, 320.f, 477.f, 11.f, holds_);
	add_hold (163, 361.f, 476.f, 10.f, holds_);
	add_hold (164, 400.f, 480.f, 10.f, holds_);
	add_hold (165, 442.f, 476.f, 12.f, holds_);
	add_hold (166, 480.f, 481.f, 9.f, holds_);

	// Row 13
	add_hold (167, 60.f, 509.f, 9.f, holds_);
	add_hold (168, 94.f, 510.f, 10.f, holds_);
	add_hold (169, 134.f, 510.f, 9.f, holds_);
	add_hold (170, 170.f, 512.f, 11.f, holds_);
	add_hold (171, 204.f, 510.f, 12.f, holds_);
	add_hold (172, 248.f, 512.f, 10.f, holds_);

	add_hold (173, 284.f, 512.f, 9.f, holds_);
	add_hold (174, 320.f, 512.f, 11.f, holds_);
	add_hold (175, 361.f, 512.f, 10.f, holds_);
	add_hold (176, 396.f, 512.f, 10.f, holds_);
	add_hold (177, 438.f, 514.f, 10.f, holds_);
	add_hold (178, 474.f, 512.f, 11.f, holds_);

	// Row 14
	add_hold (179, 62.f, 544.f, 9.f, holds_);
	add_hold (180, 96.f, 543.f, 10.f, holds_);
	add_hold (181, 134.f, 544.f, 9.f, holds_);
	add_hold (182, 170.f, 542.f, 11.f, holds_);
	add_hold (183, 208.f, 542.f, 12.f, holds_);
	add_hold (184, 245.f, 542.f, 11.f, holds_);

	add_hold (185, 285.f, 547.f, 9.f, holds_);
	add_hold (186, 318.f, 548.f, 14.f, holds_);
	add_hold (187, 360.f, 546.f, 10.f, holds_);
	add_hold (188, 396.f, 546.f, 10.f, holds_);
	add_hold (189, 435.f, 548.f, 10.f, holds_);
	add_hold (190, 470.f, 546.f, 11.f, holds_);

	// Row 15
	add_hold (191, 62.f, 576.f, 9.f, holds_);
	add_hold (192, 96.f, 576.f, 10.f, holds_);
	add_hold (193, 137.f, 577.f, 9.f, holds_);
	add_hold (194, 170.f, 574.f, 11.f, holds_);
	add_hold (195, 205.f, 573.f, 15.f, holds_);
	add_hold (196, 243.f, 577.f, 14.f, holds_);

	add_hold (197, 285.f, 580.f, 9.f, holds_);
	add_hold (198, 318.f, 580.f, 10.f, holds_);
	add_hold (199, 360.f, 580.f, 10.f, holds_);
	add_hold (200, 396.f, 580.f, 10.f, holds_);
	add_hold (201, 432.f, 580.f, 10.f, holds_);
	add_hold (202, 469.f, 580.f, 11.f, holds_);

	// Row 16
	add_hold (203, 65.f, 609.f, 9.f, holds_);
	add_hold (204, 100.f, 609.f, 10.f, holds_);
	add_hold (205, 138.f, 610.f, 9.f, holds_);
	add_hold (206, 173.f, 607.f, 10.f, holds_);
	add_hold (207, 210.f, 605.f, 10.f, holds_);
	add_hold (208, 246.f, 607.f, 10.f, holds_);

	add_hold (209, 285.f, 610.f, 9.f, holds_);
	add_hold (210, 318.f, 610.f, 10.f, holds_);
	add_hold (211, 356.f, 610.f, 10.f, holds_);
	add_hold (212, 392.f, 610.f, 10.f, holds_);
	add_hold (213, 428.f, 610.f, 10.f, holds_);
	add_hold (214, 462.f, 610.f, 11.f, holds_);

	// Row 17
	add_hold (215, 68.f, 638.f, 9.f, holds_);
	add_hold (216, 104.f, 638.f, 10.f, holds_);
	add_hold (217, 138.f, 639.f, 9.f, holds_);
	add_hold (218, 174.f, 637.f, 11.f, holds_);
	add_hold (219, 211.f, 638.f, 10.f, holds_);
	add_hold (220, 245.f, 637.f, 10.f, holds_);

	add_hold (221, 282.f, 640.f, 9.f, holds_);
	add_hold (222, 318.f, 640.f, 10.f, holds_);
	add_hold (223, 353.f, 640.f, 10.f, holds_);
	add_hold (224, 392.f, 642.f, 10.f, holds_);
	add_hold (225, 426.f, 644.f, 10.f, holds_);
	add_hold (226, 460.f, 642.f, 11.f, holds_);

	return true;
}

bool database::load_problem (const char *name, problem & p)
{
	ifstream problem_file;
	string full_name = string (data_dir_) + string (name);
	problem_file.open (full_name);
	string line;

	getline (problem_file, line);
	p.id_ = stoi (line);
	getline (problem_file, line);
	strcpy (p.name_, line.c_str ());
	getline (problem_file, line);
	strcpy (p.author_, line.c_str ());
	getline (problem_file, line);
	p.grade_ = (problem_grade) stoi (line);
	getline (problem_file, line);
	sscanf (line.c_str (), "%d %d %d", &p.date_.year, &p.date_.month, &p.date_.day);

	unsigned i, num_holds;
	getline (problem_file, line);
	num_holds = stoi (line);
	for (i = 0; i < num_holds; i++) {
		getline (problem_file, line);
		p.holds_[i] = (hold_type) stoi (line);
	}
	problem_file.close ();

	return true;
}

bool database::add_problem (int &index)
{
	file_iterator it;
	it.reset ();

	// iterate all data files until we find one that's available
	index = 1;
	while (true) {
		ifstream problem_file;
		string full_name = string (data_dir_) + to_string (index);
		problem_file.open (full_name);
		if (problem_file.is_open ()) {
			problem_file.close ();
			index++;
		}
		else {
			break;
		}
	}

	problem p;
	p.id_ = index;
	strcpy (p.name_, "new problem");
	strcpy (p.author_, "new author");
	p.grade_ = VBm;

	time_t current_time = time (NULL);
	struct tm *local_time = localtime (&current_time);
	p.date_.year = local_time->tm_year + 1900;
	p.date_.month = local_time->tm_mon + 1;
	p.date_.day = local_time->tm_mday;

	for (unsigned i = 0; i < ARRAY_SIZE (p.holds_); i++)
		p.holds_[i] = hold_unused;

	save_problem (index, p);

	return true;
}

bool database::delete_problem (int id)
{
	string full_name = string (data_dir_) + to_string (id);

	return (remove (full_name.c_str ()) == 0);
}

bool database::load_problems ()
{
	srand (time (NULL));
	file_iterator it;
	it.reset ();
	char name[128];
	bool success = true;

	problems_.clear ();
	while (it.run (name)) {
		problem p;
		success &= load_problem (name, p);
		problems_.push_back (p);
	}

	return success;
}

bool database::save_problem (int problem_id, problem & p)
{
	char name[128];
	sprintf (name, "%d", problem_id);

	ofstream problem_file;
	string full_name = string (data_dir_) + string (name);
	problem_file.open (full_name);
	problem_file << p.id_ << endl;
	problem_file << p.name_ << endl;
	problem_file << p.author_ << endl;
	problem_file << p.grade_ << endl;
	problem_file << p.date_.year << " " << p.date_.month << " " << p.date_.day << endl;

	unsigned i;
	problem_file << ARRAY_SIZE (p.holds_) << endl;
	for (i = 0; i < ARRAY_SIZE (p.holds_); i++) {
		if (i < holds_.size ())
			problem_file << p.holds_[i] << endl;
		else
			problem_file << hold_unused << endl;
	}
	problem_file.close ();

	return true;
}

bool database::get_all_holds (list < hold > &h_list)
{
	for (unsigned i = 0; i < holds_.size (); i++)
		h_list.push_back (holds_[i]);
	return true;
}

bool database::edit_problem_hold (int problem_id, int hold_id, hold_type type)
{
	for (auto it = problems_.begin (); it != problems_.end (); ++it)
		if ((*it).id_ == problem_id)
			(*it).holds_[hold_id] = type;

	problem p;
	get_problem (problem_id, p);
	save_problem (problem_id, p);
	return true;
}

bool database::edit_problem_grade (int problem_id, problem_grade grade)
{
	for (auto it = problems_.begin (); it != problems_.end (); ++it)
		if ((*it).id_ == problem_id)
			(*it).grade_ = grade;

	problem p;
	get_problem (problem_id, p);
	save_problem (problem_id, p);
	return true;
}

bool database::get_problem (int problem_id, problem & p)
{
	for (auto it = problems_.begin (); it != problems_.end (); ++it) {
		if ((*it).id_ == problem_id) {
			p = (*it);
			return true;
		}
	}
	return false;
}

static bool compare (const problem & p1, const problem & p2)
{
	if (p1.grade_ == p2.grade_)
		return strcmp (p1.name_, p2.name_) < 0;
	return p1.grade_ < p2.grade_;
}

bool database::get_all_problems (list < problem > &p_list)
{
	p_list = problems_;
	p_list.sort (compare);

	return true;
}
