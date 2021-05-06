#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "src/date.h"
#include "src/hold.h"

typedef enum problem_grade {
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
	V8p,
	V9,
	V10,
	V11,
	V12,
	V13,
	V14,
	V15,
	V16,
	V17,			// I can dream!
	VLAST
} problem_grade;

enum hold_type {
	hold_unused,
	hold_start,
	hold_end,
	hold_hand,
	hold_foot
};

typedef enum problem_rating {
	rating_0_star,
	rating_1_star,
	rating_2_star,
	rating_3_star,
	rating_4_star,
	rating_last
} problem_rating;

struct problem {
	int id_;
	char name_[128];
	char author_[128];
	problem_grade grade_;
	problem_rating rating_;
	date date_;
	hold_type holds_[256];
};

#endif
