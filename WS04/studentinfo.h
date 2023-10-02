//Studene.h- Header file for the Employee information
#define MAX_STR 32
#define NUM_SUBJECTS 6

struct Subject{
	int mark;
	char name[MAX_STR];
};
struct StudentInfo {
	char lastname[MAX_STR];
	int studentId;
	struct Subject subject[NUM_SUBJECTS];
	int numsubjects;
};
void initializeinfo(struct StudentInfo studentinfo);
float averagemark(struct Subject* subject );
int max(struct Subject* subject);
int min(struct Subject* subject);
