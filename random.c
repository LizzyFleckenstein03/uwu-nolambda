#include <stdlib.h>
#include "api/vm.h"
#include "api/util.h"
#include "api/int.h"
#include "api/nil.h"
#include "common/err.h"

UwUVMValue uwu_random(UwUVMArgs *args)
{
	uwuutil_require_exact("random.random", args, 2);

	UwUVMValue value0 = uwuvm_get_arg(args, 0);

	if (value0.type != &uwuint_type)
		error("type error: random.random requires an integer as $1\n");

	UwUVMValue value1 = uwuvm_get_arg(args, 1);

	if (value1.type != &uwuint_type)
		error("type error: random.random requires an integer as $2\n");

	long min = uwuint_get(value0);
	long max = uwuint_get(value1) + 1;

	long range = max - min;

	if (range < 0)
		error("type error: range passed to random.random is empty\n");

	if (range > RAND_MAX)
		error("type error: range passed to random.random is bigger than random.max");

	return uwuint_create(min + rand() % range);
}

UwUVMValue uwu_max(UwUVMArgs *args)
{
	uwuutil_require_exact("random.max", args, 0);
	return uwuint_create(RAND_MAX);
}

UwUVMValue uwu_seed(UwUVMArgs *args)
{
	uwuutil_require_exact("random.seed", args, 1);

	UwUVMValue value = uwuvm_get_arg(args, 0);

	if (value.type != &uwuint_type)
		error("type error: random.seed requires an integer as $1\n");

	srand(uwuint_get(value) % RAND_MAX);
	return uwunil_create();
}
