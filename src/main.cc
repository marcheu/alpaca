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
		fi = formData.getElement ("problem_id");
		if (!fi->isEmpty ()) {
			if (!std::string (**fi).compare ("all")) {
				g.output_head();
				g.generate_all_problems ();
			} else if (!std::string (**fi).compare ("new")) {
				g.add_problem ();
			} else {
				g.output_head();
				int problem_id = atoi (std::string (**fi).c_str ());
				form_iterator fi = formData.getElement ("edit_hold");
				if (!fi->isEmpty ()) {
					g.edit_problem_hold(problem_id, std::string (**fi));
					cout << "DID A HOLD EDIT " << std::string (**fi) << endl;
				}
				fi = formData.getElement ("edit_grade");
				if (!fi->isEmpty ()) {
					g.edit_problem_grade(problem_id, std::string (**fi));
					cout << "DID A GRADE EDIT " << std::string (**fi) << endl;
				}
				g.generate_problem (problem_id);
			}
		}

		cout << "<br/>\n";
		fi = formData.getElement ("sort");
		if (!fi->isEmpty () && fi != (*formData).end ()) {
			cout << "Sort: " << **fi << endl;
		}
		else {
			//cout << "No text entered for sort" << endl;
		}
	}

	cout << "</body>\n";
	cout << "</html>\n";

	return 0;
}
