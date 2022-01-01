#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include "api/vm.h"
#include "api/util.h"
#include "api/int.h"
#include "api/nil.h"
#include "api/str.h"
#include "common/err.h"

UwUVMValue uwu_exit(UwUVMArgs *args)
{
	uwuutil_require_max("os.exit", args, 1);

	long exit_code = 0;

	if (args->num == 1)
		exit_code = uwuint_get(uwuvm_get_arg(args, 0));

	exit(exit_code);
	return uwunil_create();
}

UwUVMValue uwu_sleep(UwUVMArgs *args)
{
	uwuutil_require_exact("os.sleep", args, 1);

	UwUVMValue value = uwuvm_get_arg(args, 0);

	if (value.type != &uwuint_type)
		error("type error: os.sleep requires an integer as $1\n");

	long millis = uwuint_get(value);

	if (millis < 0)
		error("type error: os.sleep requires a positive value as $2\n");

	struct timespec ts = {
		.tv_sec = millis / 1000,
		.tv_nsec = 1000000 * (millis % 1000),
	};

	while (nanosleep(&ts, &ts) != 0)
		if (errno != EINTR)
			syserror("nanosleep", NULL);

	return uwunil_create();
}

UwUVMValue uwu_execute(UwUVMArgs *args)
{
	uwuutil_require_exact("os.execute", args, 1);

	char *command = uwustr_get(uwuvm_get_arg(args, 0));
	int ret = system(command);
	free(command);

	return uwuint_create(ret);
}

UwUVMValue uwu_time(UwUVMArgs *args)
{
	uwuutil_require_exact("os.time", args, 0);

	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);

	return uwuint_create(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}
