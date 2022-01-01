#include <stdlib.h>
#include <stdio.h>
#include "common/err.h"
#include "api/vm.h"
#include "api/nil.h"
#include "api/str.h"
#include "api/util.h"

UwUVMValue uwu_linear(UwUVMArgs *args)
{
	uwuutil_require_min("flow:linear", args, 1);

	size_t return_arg = args->num - 1;

	for (size_t i = 0; i < return_arg; i++)
		uwuvm_get_arg(args, i);

	return uwuvm_clone_value(uwuvm_get_arg(args, return_arg));
}

UwUVMValue uwu_error(UwUVMArgs *args)
{
	uwuutil_require_exact("flow:error", args, 1);

	char *err = uwustr_get(uwuvm_get_arg(args, 0));
	fprintf(stderr, "%s\n", err);
	free(err);

	exit(1);

	return uwunil_create();
}
