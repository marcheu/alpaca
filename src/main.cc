#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>


#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include <src/generator.h>

using namespace std;
using namespace cgicc;

int main (int argc, char *argv[])
{
	bool action = false;
	Cgicc formData;

	generator g;
	cout << "Content-type: text/html; charset=\"utf-8\"\r\n\r\n";
	cout << "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n";
	cout << "<html>\n";

	if (argc > 1) {
		// for testing
		printf ("TEST MODE\n");
		g.add_problem ();
	}
	else {
		// real thing
		form_iterator fi;
		fi = formData.getElement ("view");
		if (!fi->isEmpty ()) {
			if (!std::string (**fi).compare ("all")) {
				g.generate_view_all_problems ();
				action = true;
			}
			else {
				int problem_id = atoi (std::string (**fi).c_str ());
				g.generate_view_problem (problem_id);
				action = true;
			}
		}
		fi = formData.getElement ("edit");
		if (!fi->isEmpty ()) {
			if (!std::string (**fi).compare ("new")) {
				g.add_problem ();
				action = true;
			}
			else {
				int problem_id = atoi (std::string (**fi).c_str ());
				form_iterator fi = formData.getElement ("edit_hold");
				if (!fi->isEmpty ())
					g.edit_problem_hold (problem_id, std::string (**fi));

				fi = formData.getElement ("edit_grade");
				if (!fi->isEmpty ())
					g.edit_problem_grade (problem_id, std::string (**fi));

				g.generate_edit_problem (problem_id);
				action = true;
			}
		}

		fi = formData.getElement ("delete");
		if (!fi->isEmpty ()) {
			int problem_id = atoi (std::string (**fi).c_str ());
			g.delete_problem (problem_id);
		}

		if (!action)
			g.generate_main_redirect ();
		cout << "<br/>\n";

#if 0
		fi = formData.getElement ("sort");
		if (!fi->isEmpty () && fi != (*formData).end ()) {
			cout << "Sort: " << **fi << endl;
		}
		else {
			//cout << "No text entered for sort" << endl;
		}
#endif
	}

	cout << "</body>\n";
	cout << "</html>\n";

	return 0;
}
