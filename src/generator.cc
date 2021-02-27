#include <fstream>
#include <iostream>

#include "src/generator.h"
#include "src/includes.h"

using namespace std;

static const char* grade_name(problem_grade g)
{
	const char *grades[VLAST] = { 
		"VB- / 1", "VB / 2", "VB+ / 3", "V0 / 4", "V0+ / 4+", "V1 / 5",
		"V2 / 5+", "V3 / 6A", "V3+ / 6A+", "V4 / 6B", "V4+ / 6B+",
		"V5 / 6C", "V5+ / 6C+", "V6 / 7A", "V7 / 7A+", "V8 / 7B",
		"V9 / 7C", "V10 / 7C+", "V11 / 8A", "V12 / 8A+", "V13 / 8B",
		"V14 / 8B+", "V15 / 8C", "V16 / 8C+", "V17 / 9A" };

	assert(g >= 0);
	assert(g < VLAST);
	return grades[g];
}

static const char* grade_div_name(problem_grade g)
{
	const char *grades[VLAST] = {
		"vb", "vb", "vb", "v0", "v0", "v1",
		"v2", "v3", "v3", "v4", "v4",
		"v5", "v5", "v6",  "v7", "v8",
		"v9", "v10", "v10", "v10",
		"v10", "v10", "v10", "v10", "v10" };

	assert(g >= 0);
	assert(g < VLAST);
	return grades[g];
}

void generator::generate_problem(int problem_id)
{
	problem p;
	cout << "PROBLEM " << problem_id;
	database_.get_problem(problem_id, p);

	cout << "<a href=\"/cgi-bin/mycgi?problem_id=" << p.id_ << "\">";
	cout << "<div class=\"big_problem_box\">";
	cout << "<div class=\"big_problem_box_image\"><img src=\"/template.jpg\"></div>";
	cout << "<br>";
	cout << "<div class=\"big_problem_box_text\">";
	switch(p.grade_) {
		case VB:
			cout << "<div class=\"grade_vb_box\">"; break;
		case V0:
			cout << "<div class=\"grade_v0_box\">"; break;
		case V0p ... V2:
			cout << "<div class=\"grade_v1_box\">"; break;
		case V3 ... V4:
			cout << "<div class=\"grade_v3_box\">"; break;
		case V5 ... V6:
			cout << "<div class=\"grade_v5_box\">"; break;
		case V7 ... V16:
		default:
			cout << "<div class=\"grade_v7_box\">"; break;
	}
	cout << "<b>" << grade_name(p.grade_) << "</b></div> ";
	cout << "<b>" << p.name_ << "</b>" << endl;
	cout << "<br>author: " << p.author_;
	cout << "  " << p.date_.year << "/" << p.date_.month << "/" << p.date_.day;
	cout << "</div>";
	cout << "</div>";
	cout << "</a>";
}

void generator::generate_all_problems()
{
	cout << "ALL PROBLEMS ";
	int num;
	list<problem> p_list;
	database_.get_all_problems(num, p_list);

	for(auto it = p_list.begin(); it != p_list.end(); ++it) {
		cout << "<a href=\"/cgi-bin/mycgi?problem_id=" << (*it).id_ << "\">";
		cout << "<div class=\"small_problem_box " << grade_div_name((*it).grade_);
		cout << "\">";
		cout << "<div class=\"small_problem_box_image\"><img src=\"/template.jpg\"></div>";
		cout << "<div class=\"title_box\"><b>" << (*it).name_ << "</b></div>" << endl;
		cout << "<div class=\"small_problem_box_text\">";
		cout << "<b>" << grade_name((*it).grade_) << "</b> ";
		cout << "<br>author: " << (*it).author_;
		cout << "  " << (*it).date_.year << "/" << (*it).date_.month << "/" << (*it).date_.day;
		cout << "</div>";
		cout << "</div>";
		cout << "</a>";
	}
}

void generator::output_css()
{
	string output;
	ifstream style_file("/home/pi/alpaca/html/style.txt");

	if (style_file.is_open())
		cout << style_file.rdbuf();
}
