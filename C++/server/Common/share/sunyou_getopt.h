#ifndef _GETOPT_H
#define _GETOPT_H

/* getopt() wrapper */
#define sunyou_no_argument            0
#define sunyou_required_argument      1
#define sunyou_optional_argument      2
struct sunyou_option
{
	const char *name;
	int has_arg;
	int *flag;
	int val;
};
extern char sunyou_optarg[514];
int sunyou_getopt_long_only (int ___argc, char *const *___argv, const char *__shortopts, const struct sunyou_option *__longopts, int *__longind);

#endif
