#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "src/date.h"
#include "src/hold.h"

typedef enum problem_grade
{
	VBm,
	VB,
	VBp,
	V0,
	V0p,
	V1,
	V2,
	V3,
	V3p,
	V4,
	V4p,
	V5,
	V5p,
	V6,
	V7,
	V8,
	V9,
	V10,
	V11,
	V12,
	V13,
	V14,
	V15,
	V16,
	V17, // I can dream!
	VLAST
} problem_grade;

enum hold_type 
{
	start,
	stop,
	hand,
	foot
};

struct hold_use
{
	int hold_id;
	enum hold_type type;
};

struct problem
{
	int id_;
	char author_[128];
	char name_[128];
	problem_grade grade_;
	hold_use holds_[128];
	date date_;
};

#endif
