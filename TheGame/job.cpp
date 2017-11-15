#include "job.h"
#include "utils.h"

Job::Job() {}

Job::Job(int job) {
	set_name(job);
}

int Job::set_name(int job) {
	name = get_file_line(JOB_NAMES_PATH, job);
}

int Job::change_job(int job) {
	set_name(job);
}
