#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linenoise/linenoise.h"
#include "common/err.h"
#include "api/vm.h"
#include "api/str.h"
#include "api/util.h"

UwUVMValue uwu_print(UwUVMArgs *args)
{
	uwuutil_require_exact("nolambda:io:print", args, 1);

	UwUVMValue value = uwuvm_get_arg(args, 0);

	char *str = uwustr_get(value);
	printf("%s\n", str);
	free(str);

	return uwuvm_clone_value(value);
}

UwUVMValue uwu_scan(UwUVMArgs *args)
{
	uwuutil_require_max("nolambda:io:scan", args, 1);

	char *prompt = NULL;

	if (args->num == 0)
		prompt = strdup("");
	else
		prompt = uwustr_get(uwuvm_get_arg(args, 0));

	char *return_string = linenoise(prompt);

	if (! return_string)
		return_string = strdup("");

	UwUVMValue return_value = uwustr_create(return_string);

	linenoiseFree(return_string);
	free(prompt);

	return return_value;
}

#include "linenoise/linenoise.c"
