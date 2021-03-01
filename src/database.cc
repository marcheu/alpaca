
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
	add_hold (1, 15.f, 17.f, 13.f, holds_);
	add_hold (2, 51.f, 9.f, 21.f, holds_);
	add_hold (3, 100.f, 12.f, 14.f, holds_);
	add_hold (4, 148.f, 17.f, 13.f, holds_);
	add_hold (5, 192.f, 15.f, 14.f, holds_);
	add_hold (6, 240.f, 11.f, 16.f, holds_);

	add_hold (7, 288.f, 15.f, 12.f, holds_);
	add_hold (8, 333.f, 13.f, 15.f, holds_);
	add_hold (9, 375.f, 13.f, 17.f, holds_);
	add_hold (10, 427.f, 10.f, 15.f, holds_);
	add_hold (11, 473.f, 9.f, 15.f, holds_);

	// Row 2
	add_hold (12, 15.f, 62.f, 13.f, holds_);
	add_hold (13, 60.f, 65.f, 13.f, holds_);
	add_hold (14, 103.f, 57.f, 14.f, holds_);
	add_hold (15, 149.f, 62.f, 12.f, holds_);
	add_hold (16, 192.f, 60.f, 14.f, holds_);
	add_hold (17, 236.f, 60.f, 16.f, holds_);

	add_hold (18, 288.f, 60.f, 12.f, holds_);
	add_hold (19, 326.f, 58.f, 20.f, holds_);
	add_hold (20, 373.f, 58.f, 15.f, holds_);
	add_hold (21, 423.f, 57.f, 15.f, holds_);
	add_hold (22, 464.f, 58.f, 20.f, holds_);

	// Row 2.5
	add_hold (23, 125.f, 85.f, 15.f, holds_);
	add_hold (24, 216.f, 85.f, 14.f, holds_);
	add_hold (25, 312.f, 88.f, 11.f, holds_);
	add_hold (26, 400.f, 88.f, 13.f, holds_);

	// Row 3
	add_hold (27, 17.f, 112.f, 13.f, holds_);
	add_hold (28, 65.f, 115.f, 12.f, holds_);
	add_hold (29, 105.f, 112.f, 14.f, holds_);
	add_hold (30, 150.f, 112.f, 13.f, holds_);
	add_hold (31, 194.f, 114.f, 14.f, holds_);
	add_hold (32, 238.f, 110.f, 13.f, holds_);

	add_hold (33, 286.f, 114.f, 11.f, holds_);
	add_hold (34, 330.f, 113.f, 12.f, holds_);
	add_hold (35, 375.f, 114.f, 11.f, holds_);
	add_hold (36, 418.f, 110.f, 14.f, holds_);
	add_hold (37, 466.f, 112.f, 11.f, holds_);

	// Row 3.5
	add_hold (38, 132.f, 137.f, 10.f, holds_);
	add_hold (39, 304.f, 137.f, 12.f, holds_);

	// Row 4
	add_hold (40, 24.f, 158.f, 13.f, holds_);
	add_hold (41, 68.f, 158.f, 12.f, holds_);
	add_hold (42, 110.f, 158.f, 12.f, holds_);
	add_hold (43, 150.f, 152.f, 18.f, holds_);
	add_hold (44, 197.f, 160.f, 12.f, holds_);
	add_hold (45, 232.f, 146.f, 13.f, holds_);
	add_hold (46, 242.f, 170.f, 13.f, holds_);

	add_hold (47, 288.f, 164.f, 11.f, holds_);
	add_hold (48, 324.f, 156.f, 15.f, holds_);
	add_hold (49, 365.f, 155.f, 18.f, holds_);
	add_hold (50, 417.f, 160.f, 12.f, holds_);
	add_hold (51, 463.f, 162.f, 11.f, holds_);
	add_hold (52, 507.f, 162.f, 11.f, holds_);

	// Row 4.5
	add_hold (53, 135.f, 187.f, 10.f, holds_);
	add_hold (54, 222.f, 186.f, 8.f, holds_);
	add_hold (55, 308.f, 189.f, 10.f, holds_);

	// Row 5
	add_hold (56, 27.f, 200.f, 13.f, holds_);
	add_hold (57, 72.f, 202.f, 10.f, holds_);
	add_hold (58, 113.f, 204.f, 11.f, holds_);
	add_hold (59, 154.f, 206.f, 16.f, holds_);
	add_hold (60, 192.f, 202.f, 17.f, holds_);
	add_hold (61, 242.f, 204.f, 12.f, holds_);

	add_hold (62, 284.f, 206.f, 11.f, holds_);
	add_hold (63, 324.f, 206.f, 13.f, holds_);
	add_hold (64, 370.f, 205.f, 14.f, holds_);
	add_hold (65, 410.f, 200.f, 18.f, holds_);
	add_hold (66, 460.f, 204.f, 11.f, holds_);
	add_hold (67, 502.f, 205.f, 11.f, holds_);

	// Row 6
	add_hold (68, 34.f, 244.f, 12.f, holds_);
	add_hold (69, 75.f, 248.f, 10.f, holds_);
	add_hold (70, 114.f, 246.f, 11.f, holds_);
	add_hold (71, 137.f, 230.f, 15.f, holds_);
	add_hold (72, 200.f, 249.f, 13.f, holds_);
	add_hold (73, 254.f, 228.f, 9.f, holds_);
	add_hold (74, 252.f, 250.f, 9.f, holds_);

	add_hold (75, 276.f, 254.f, 7.f, holds_);
	add_hold (76, 278.f, 232.f, 7.f, holds_);
	add_hold (77, 294.f, 248.f, 7.f, holds_);
	add_hold (78, 328.f, 251.f, 9.f, holds_);
	add_hold (79, 456.f, 250.f, 11.f, holds_);
	add_hold (80, 500.f, 251.f, 12.f, holds_);

	// Row 7
	add_hold (81, 37.f, 286.f, 11.f, holds_);
	add_hold (82, 80.f, 290.f, 10.f, holds_);
	add_hold (83, 118.f, 292.f, 11.f, holds_);
	add_hold (84, 158.f, 280.f, 14.f, holds_);
	add_hold (85, 205.f, 294.f, 11.f, holds_);
	add_hold (86, 238.f, 268.f, 8.f, holds_);
	add_hold (87, 248.f, 295.f, 7.f, holds_);
	add_hold (88, 256.f, 280.f, 7.f, holds_);

	add_hold (89, 276.f, 274.f, 6.f, holds_);
	add_hold (90, 280.f, 288.f, 6.f, holds_);
	add_hold (91, 289.f, 275.f, 6.f, holds_);
	add_hold (92, 290.f, 298.f, 6.f, holds_);
	add_hold (93, 324.f, 292.f, 14.f, holds_);
	add_hold (94, 451.f, 290.f, 11.f, holds_);
	add_hold (95, 495.f, 290.f, 12.f, holds_);

	// Row 7.5
	add_hold (96, 142.f, 304.f, 11.f, holds_);
	add_hold (97, 225.f, 309.f, 11.f, holds_);
	add_hold (98, 310.f, 316.f, 7.f, holds_);

	// Row 8
	add_hold (99, 42.f, 325.f, 11.f, holds_);
	add_hold (100, 80.f, 325.f, 10.f, holds_);
	add_hold (101, 122.f, 328.f, 11.f, holds_);
	add_hold (102, 164.f, 326.f, 10.f, holds_);
	add_hold (103, 205.f, 330.f, 11.f, holds_);
	add_hold (104, 240.f, 327.f, 16.f, holds_);

	add_hold (105, 290.f, 333.f, 8.f, holds_);
	add_hold (106, 324.f, 328.f, 13.f, holds_);
	add_hold (107, 448.f, 330.f, 11.f, holds_);
	add_hold (108, 490.f, 330.f, 12.f, holds_);

	// Row 8.5
	add_hold (109, 144.f, 345.f, 10.f, holds_);

	// Row 9
	add_hold (110, 46.f, 365.f, 11.f, holds_);
	add_hold (111, 86.f, 362.f, 15.f, holds_);
	add_hold (112, 124.f, 366.f, 11.f, holds_);
	add_hold (113, 162.f, 366.f, 15.f, holds_);
	add_hold (114, 205.f, 369.f, 8.f, holds_);
	add_hold (115, 246.f, 366.f, 9.f, holds_);

	add_hold (116, 276.f, 360.f, 18.f, holds_);
	add_hold (117, 325.f, 371.f, 8.f, holds_);
	add_hold (118, 445.f, 370.f, 11.f, holds_);
	add_hold (119, 486.f, 368.f, 12.f, holds_);

	// Row 9.5
	add_hold (120, 150.f, 390.f, 8.f, holds_);
	add_hold (121, 217.f, 383.f, 7.f, holds_);
	add_hold (122, 215.f, 395.f, 7.f, holds_);
	add_hold (123, 228.f, 389.f, 8.f, holds_);
	add_hold (124, 305.f, 391.f, 8.f, holds_);

	// Row 10
	add_hold (125, 46.f, 405.f, 11.f, holds_);
	add_hold (126, 86.f, 396.f, 13.f, holds_);
	add_hold (127, 127.f, 403.f, 11.f, holds_);
	add_hold (128, 164.f, 404.f, 11.f, holds_);
	add_hold (129, 208.f, 409.f, 10.f, holds_);
	add_hold (130, 248.f, 406.f, 10.f, holds_);

	add_hold (131, 286.f, 406.f, 8.f, holds_);
	add_hold (132, 323.f, 411.f, 12.f, holds_);
	add_hold (133, 364.f, 407.f, 11.f, holds_);
	add_hold (134, 403.f, 407.f, 10.f, holds_);
	add_hold (135, 445.f, 408.f, 11.f, holds_);
	add_hold (136, 482.f, 408.f, 10.f, holds_);

	// Row 10.5
	add_hold (137, 150.f, 425.f, 8.f, holds_);
	add_hold (138, 228.f, 425.f, 8.f, holds_);
	add_hold (139, 305.f, 429.f, 8.f, holds_);
	add_hold (140, 385.f, 429.f, 8.f, holds_);

	// Row 11
	add_hold (141, 50.f, 440.f, 9.f, holds_);
	add_hold (142, 87.f, 440.f, 12.f, holds_);
	add_hold (143, 127.f, 439.f, 12.f, holds_);
	add_hold (144, 168.f, 444.f, 10.f, holds_);
	add_hold (145, 202.f, 439.f, 15.f, holds_);
	add_hold (146, 248.f, 440.f, 9.f, holds_);

	add_hold (147, 280.f, 440.f, 13.f, holds_);
	add_hold (148, 323.f, 447.f, 12.f, holds_);
	add_hold (149, 361.f, 443.f, 11.f, holds_);
	add_hold (150, 403.f, 447.f, 10.f, holds_);
	add_hold (151, 442.f, 446.f, 9.f, holds_);
	add_hold (152, 480.f, 444.f, 9.f, holds_);

	// Row 11.5
	add_hold (153, 150.f, 459.f, 8.f, holds_);
	add_hold (154, 230.f, 460.f, 8.f, holds_);
	add_hold (155, 384.f, 463.f, 8.f, holds_);

	// Row 12
	add_hold (156, 53.f, 476.f, 9.f, holds_);
	add_hold (157, 90.f, 476.f, 10.f, holds_);
	add_hold (158, 129.f, 478.f, 11.f, holds_);
	add_hold (159, 168.f, 476.f, 10.f, holds_);
	add_hold (160, 204.f, 473.f, 12.f, holds_);
	add_hold (161, 248.f, 476.f, 10.f, holds_);

	add_hold (162, 280.f, 473.f, 16.f, holds_);
	add_hold (163, 320.f, 477.f, 11.f, holds_);
	add_hold (164, 361.f, 476.f, 10.f, holds_);
	add_hold (165, 400.f, 480.f, 10.f, holds_);
	add_hold (166, 442.f, 476.f, 12.f, holds_);
	add_hold (167, 480.f, 481.f, 9.f, holds_);

	// Row 13
	add_hold (168, 56.f, 509.f, 9.f, holds_);
	add_hold (169, 94.f, 510.f, 10.f, holds_);
	add_hold (170, 134.f, 510.f, 9.f, holds_);
	add_hold (171, 170.f, 512.f, 11.f, holds_);
	add_hold (172, 204.f, 510.f, 12.f, holds_);
	add_hold (173, 248.f, 512.f, 10.f, holds_);

	add_hold (174, 284.f, 512.f, 9.f, holds_);
	add_hold (175, 320.f, 512.f, 11.f, holds_);
	add_hold (176, 361.f, 512.f, 10.f, holds_);
	add_hold (177, 396.f, 512.f, 10.f, holds_);
	add_hold (178, 438.f, 514.f, 10.f, holds_);
	add_hold (179, 474.f, 512.f, 11.f, holds_);

	// Row 14
	add_hold (180, 59.f, 544.f, 9.f, holds_);
	add_hold (181, 96.f, 543.f, 10.f, holds_);
	add_hold (182, 134.f, 544.f, 9.f, holds_);
	add_hold (183, 170.f, 542.f, 11.f, holds_);
	add_hold (184, 208.f, 542.f, 12.f, holds_);
	add_hold (185, 245.f, 542.f, 11.f, holds_);

	add_hold (186, 285.f, 547.f, 9.f, holds_);
	add_hold (187, 318.f, 548.f, 14.f, holds_);
	add_hold (188, 360.f, 546.f, 10.f, holds_);
	add_hold (189, 396.f, 546.f, 10.f, holds_);
	add_hold (190, 435.f, 548.f, 10.f, holds_);
	add_hold (191, 470.f, 546.f, 11.f, holds_);

	// Row 15
	add_hold (192, 62.f, 576.f, 9.f, holds_);
	add_hold (193, 96.f, 576.f, 10.f, holds_);
	add_hold (194, 134.f, 577.f, 9.f, holds_);
	add_hold (195, 170.f, 574.f, 11.f, holds_);
	add_hold (196, 205.f, 573.f, 15.f, holds_);
	add_hold (197, 243.f, 577.f, 14.f, holds_);

	add_hold (198, 282.f, 580.f, 9.f, holds_);
	add_hold (199, 318.f, 580.f, 10.f, holds_);
	add_hold (200, 360.f, 580.f, 10.f, holds_);
	add_hold (201, 396.f, 580.f, 10.f, holds_);
	add_hold (202, 432.f, 580.f, 10.f, holds_);
	add_hold (203, 469.f, 580.f, 11.f, holds_);

	// Row 16
	add_hold (204, 65.f, 609.f, 9.f, holds_);
	add_hold (205, 100.f, 609.f, 10.f, holds_);
	add_hold (206, 138.f, 610.f, 9.f, holds_);
	add_hold (207, 173.f, 607.f, 10.f, holds_);
	add_hold (208, 210.f, 605.f, 10.f, holds_);
	add_hold (209, 246.f, 607.f, 10.f, holds_);

	add_hold (210, 282.f, 610.f, 9.f, holds_);
	add_hold (211, 318.f, 610.f, 10.f, holds_);
	add_hold (212, 356.f, 610.f, 10.f, holds_);
	add_hold (213, 392.f, 610.f, 10.f, holds_);
	add_hold (214, 428.f, 610.f, 10.f, holds_);
	add_hold (215, 462.f, 610.f, 11.f, holds_);

	// Row 17
	add_hold (216, 68.f, 638.f, 9.f, holds_);
	add_hold (217, 100.f, 638.f, 10.f, holds_);
	add_hold (218, 138.f, 639.f, 9.f, holds_);
	add_hold (219, 174.f, 637.f, 11.f, holds_);
	add_hold (220, 208.f, 638.f, 10.f, holds_);
	add_hold (221, 243.f, 637.f, 10.f, holds_);

	add_hold (222, 282.f, 640.f, 9.f, holds_);
	add_hold (223, 318.f, 640.f, 10.f, holds_);
	add_hold (224, 353.f, 640.f, 10.f, holds_);
	add_hold (225, 392.f, 642.f, 10.f, holds_);
	add_hold (226, 426.f, 644.f, 10.f, holds_);
	add_hold (227, 460.f, 642.f, 11.f, holds_);

	return true;
}

bool database::load_problem (const char *name, problem & p)
{
	p.id_ = atoi (name);
	strcpy (p.author_, "胖胖");
	strcpy (p.name_, "Black sabbath");
	p.grade_ = (problem_grade) (rand () % (int) VLAST);

	unsigned i;
	for (i = 0; i < holds_.size (); i++) {
		p.holds_[i].hold_id = holds_[i].id;
		p.holds_[i].type = hand;
	}
	p.holds_[i].hold_id = 0;
	p.holds_[i].type = start;
	p.date_.day = 10;
	p.date_.month = 15;
	p.date_.year = 2020;

	return true;
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
		success |= load_problem (name, p);
		problems_.push_back (p);
	}

	return success;
}

bool database::get_all_holds (list < hold > &h_list)
{
	for (unsigned i = 0; i < holds_.size (); i++)
		h_list.push_back (holds_[i]);
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
	return p1.grade_ < p2.grade_;
}

bool database::get_all_problems (list < problem > &p_list)
{
	p_list = problems_;
	p_list.sort (compare);

	return true;
}
