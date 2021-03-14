#include "src/generator.h"
#include "src/includes.h"

using namespace std;

static const char *grade_name (problem_grade g)
{
	const char *grades[VLAST] = {
		"VB- / 1", "VB / 2", "VB+ / 3", "V0 / 4", "V0+ / 4+", "V1 / 5",
		"V2 / 5+", "V3 / 6A", "V3+ / 6A+", "V4 / 6B", "V4+ / 6B+",
		"V5 / 6C", "V5+ / 6C+", "V6 / 7A", "V7 / 7A+", "V8 / 7B",
		"V9 / 7C", "V10 / 7C+", "V11 / 8A", "V12 / 8A+", "V13 / 8B",
		"V14 / 8B+", "V15 / 8C", "V16 / 8C+", "V17 / 9A"
	};

	assert (g >= 0);
	assert (g < VLAST);
	return grades[g];
}

static const char *grade_div_name (problem_grade g)
{
	const char *grades[VLAST] = {
		"vb", "vb", "vb", "v0", "v0", "v1",
		"v2", "v3", "v3", "v4", "v4",
		"v5", "v5", "v6", "v7", "v8",
		"v9", "v10", "v10", "v10",
		"v10", "v10", "v10", "v10", "v10"
	};

	assert (g >= 0);
	assert (g < VLAST);
	return grades[g];
}

generator::generator ()
{
	cout.precision (3);
}

void generator::generate_header ()
{
	cout << "<div class=\"page_header\"><b> Alpaca </b><a href=\"/cgi-bin/mycgi?problem_id=new\"><img src=\"/icon-edit.png\" width=10\%></a>  <a href=\"/cgi-bin/mycgi?problem_id=all\"><img src=\"/icon-list.png\" width=10\%></a>  <img src=\"/icon-stats.png\" width=10\%>  <img src=\"/icon-light.png\" width=10\%></div>" << endl;
}

void generator::generate_problem (int problem_id)
{
	generate_header ();

	problem p;
	database_.get_problem (problem_id, p);

	list < hold > h_list;
	database_.get_all_holds (h_list);

	cout << "<div class=\"big_problem_box " << grade_div_name (p.grade_) << "\">";
	cout << "<div class=\"big_problem_box_image\"><img src=\"/template.jpg\" width=100\% height=100\%>";

	for (auto it = h_list.begin (); it != h_list.end (); ++it) {
		int id = (*it).id;

		if (p.holds_[id] == hold_unused) {
			cout << "<form id=\"form-id" << id << "\" method=\"post\" action=\"/cgi-bin/mycgi?problem_id=" << problem_id << "\"><input type=\"hidden\" name=\"edit_hold\" value=";
			cout << id << "h>";
			cout << "<div class=\"hold_unused_" << id << "\" onclick=\"document.getElementById('form-id" << id << "').submit();\"> </div>";
		}
		else {
			cout << "<form id=\"form-id" << id << "\" method=\"post\" action=\"/cgi-bin/mycgi?problem_id=" << problem_id << "\"><input type=\"hidden\" name=\"edit_hold\" value=";
			cout << id << "u>";
			cout << "<div class=\"hold_" << id << "\" onclick=\"document.getElementById('form-id" << id << "').submit();\"> </div>";
		}
		cout << "</form>\n\n";
	}

	cout << "</div>";
	cout << "<br>";
	cout << "<div class=\"title_box\"><b>" << p.name_ << "</b></div>" << endl;
	cout << "<div class=\"big_problem_box_text\">";

	cout << "<form method=\"POST\" action=\"/cgi-bin/mycgi?problem_id=" << problem_id << "\">";
	cout << "<select id=\"grade\" name=\"edit_grade\" onchange='if(this.value != 0) { this.form.submit(); }'>" << endl;
	for (unsigned i = 0; i < VLAST; i++)
		if (i == p.grade_)
			cout << "<option value=\"" << grade_name ((problem_grade) i) << "\" selected=\"selected\">" << grade_name ((problem_grade) i) << "</option>" << endl;
		else
			cout << "<option value=\"" << grade_name ((problem_grade) i) << "\">" << grade_name ((problem_grade) i) << "</option>" << endl;
	cout << "</select>" << endl;
	cout << "</form>" << endl;

	cout << "<b>" << grade_name (p.grade_) << "</b><br>";
	cout << "<br>author: " << p.author_;
	cout << "  " << p.date_.year << "/" << p.date_.month << "/" << p.date_.day;
	cout << "</div>";
	cout << "</div>";
}

void generator::edit_problem_hold (int problem_id, string change)
{
	char c = change[change.length () - 1];
	hold_type type;
	switch (c) {
	case 'u':
		type = hold_unused;
		break;
	case 's':
		type = hold_start;
		break;
	case 'e':
		type = hold_end;
		break;
	case 'h':
		type = hold_hand;
		break;
	case 'f':
		type = hold_foot;
		break;
	default:
		assert (0);
	}

	change.pop_back ();
	int hold_id = stoi (change);

	database_.edit_problem_hold (problem_id, hold_id, type);
}

void generator::edit_problem_grade (int problem_id, string change)
{
	int i;
	for (i = VBm; i < VLAST; i++)
		if (!strcmp (grade_name ((problem_grade) i), change.c_str ()))
			break;

	if (i != VLAST)
		database_.edit_problem_grade (problem_id, (problem_grade) i);
}

void generator::generate_all_problems ()
{
	generate_header ();

	list < problem > p_list;
	database_.get_all_problems (p_list);

	list < hold > h_list;
	database_.get_all_holds (h_list);

	for (auto it = p_list.begin (); it != p_list.end (); ++it) {
		cout << "<a href=\"/cgi-bin/mycgi?problem_id=" << (*it).id_ << "\">";
		cout << "<div class=\"small_problem_box " << grade_div_name ((*it).grade_);
		cout << "\">";
		cout << "<div class=\"small_problem_box_image\"><img src=\"/template.jpg\">";

		for (auto h = h_list.begin (); h != h_list.end (); ++h) {
			int id = (*h).id;
			if ((*it).holds_[id] != hold_unused)
				cout << "<div class=\"hold_" << id << "\"> </div>";
		}

		cout << "</div>";
		cout << "<div class=\"title_box\"><b>" << (*it).name_ << "</b></div>" << endl;
		cout << "<div class=\"small_problem_box_text\">";
		cout << "<b>" << grade_name ((*it).grade_) << "</b> ";
		cout << "<br>author: " << (*it).author_;
		cout << "  " << (*it).date_.year << "/" << (*it).date_.month << "/" << (*it).date_.day;
		cout << "</div>";
		cout << "</div>";
		cout << "</a>";
	}
}

void generator::output_head ()
{
	cout << "<head>\n";
	cout << "<title>Alpaca Climbing 🦙</title>\n";
	output_css ();
	cout << "</head>\n";
}

void generator::add_problem ()
{
	int index;
	database_.add_problem (index);

	cout << "<head>\n";
	cout << "<title>Alpaca Climbing</title>\n";
	cout << "</head>\n";

	cout << "<head>\n";
	cout << "<meta http-equiv=\"refresh\" content=\"0; url=/cgi-bin/mycgi?problem_id=" << index << "\" />\n";
	cout << "</head>\n";
	cout << "<body>\n";
}

void generator::output_css ()
{
	string output;
	ifstream style_file ("/home/pi/alpaca/html/style.txt");

	cout << "<style>";
	if (style_file.is_open ())
		cout << style_file.rdbuf ();


	list < hold > h_list;
	database_.get_all_holds (h_list);

	for (auto it = h_list.begin (); it != h_list.end (); ++it) {
		cout << ".hold_" << (*it).id << " {\n";
		cout << "	position: absolute;\n";
		cout << "	border: 2px solid red;\n";
		cout << "	border-radius: 50%;\n";
		cout << "	top: " << (*it).ypos / 7.15f << "%;\n";
		cout << "	left: " << (*it).xpos / 5.66f << "%;\n";
		cout << "	width: " << (*it).radius / 2.7f << "%;\n";
		cout << "	height: " << (*it).radius / 3.3f << "%;\n";
		cout << "}\n";
	}

	for (auto it = h_list.begin (); it != h_list.end (); ++it) {
		cout << ".hold_unused_" << (*it).id << " {\n";
		cout << "	position: absolute;\n";
		cout << "       background-color: rgb(255, 255, 255, 0.2);\n";
		cout << "	border-radius: 50%;\n";
		cout << "	top: " << (*it).ypos / 7.15f << "%;\n";
		cout << "	left: " << (*it).xpos / 5.66f << "%;\n";
		cout << "	width: " << (*it).radius / 2.7f << "%;\n";
		cout << "	height: " << (*it).radius / 3.3f << "%;\n";
		cout << "}\n";
	}

	cout << "</style>";

}
