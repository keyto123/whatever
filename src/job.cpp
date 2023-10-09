#include "job.h"
#include "utils.h"

const char* JOB_STATS_PATH = "job_stats.txt";
const char* JOB_NAMES_PATH = "job_names.txt";

Job::Job() {}

Job::Job(int job) {
	set_name(job);
}

int Job::set_name(int job) {
	name = Utils::get_file_line(JOB_NAMES_PATH, job);
	return 0;
}

int Job::change_job(int job) {
	set_name(job);
	return 0;
}
