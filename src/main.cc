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


	cout << "<head>\n";
	cout << "<title>Alpaca Climbing 🦙</title>\n";
	g.output_css ();
	cout << "</head>\n";
	cout << "<body>\n";


	if (argc > 1) {
		// for testing
		printf ("TEST MODE\n");
		g.generate_all_problems ();
	}
	else {
		// real thing
		form_iterator fi = formData.getElement ("problem_id");
		if (!fi->isEmpty ()) {
			if (!std::string (**fi).compare ("all")) {
				g.generate_all_problems ();
			}
			else {
				int id = atoi (std::string (**fi).c_str ());
				if (id)
					g.generate_problem (id);
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
