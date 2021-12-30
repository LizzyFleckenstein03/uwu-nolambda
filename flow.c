#include <stdlib.h>
#include <stdio.h>
#include "common/err.h"
#include "api/vm.h"
#include "api/nil.h"
#include "api/str.h"

UwUVMValue uwu_linear(UwUVMArgs *args)
{
	if (args->num < 1)
		error("error: nolambda:flow:linear requires at least one argument");

	size_t return_arg = args->num - 1;

	for (size_t i = 0; i < return_arg; i++)
		uwuvm_get_arg(args, i);

	return uwuvm_clone_value(uwuvm_get_arg(args, return_arg));
}

UwUVMValue uwu_error(UwUVMArgs *args)
{
	if (args->num != 1)
		error("error: nolambda:flow:error exactly one argument");

	char *err = uwustr_get(uwuvm_get_arg(args, 0));
	fprintf(stderr, "%s\n", err);
	free(err);

	exit(1);

	return uwunil_create();
}
