#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linenoise/linenoise.h"
#include "common/err.h"
#include "api/vm.h"
#include "api/str.h"

UwUVMValue uwu_print(UwUVMArgs *args)
{
	if (args->num != 1)
		error("error: nolambda:io:print requires exactly one argument\n");

	UwUVMValue value = uwuvm_get_arg(args, 0);

	char *str = uwustr_get(value);
	printf("%s\n", str);
	free(str);

	return uwuvm_clone_value(value);
}

UwUVMValue uwu_scan(UwUVMArgs *args)
{
	char *prompt = NULL;

	if (args->num == 0)
		prompt = strdup("");
	else if (args->num == 1)
		prompt = uwustr_get(uwuvm_get_arg(args, 0));
	else
		error("error: nolambda:io:scan requires exactly one or zero arguments\n");

	char *return_string = linenoise(prompt);
	UwUVMValue return_value = uwustr_create(return_string);

	linenoiseFree(return_string);
	free(prompt);

	return return_value;
}

#include "linenoise/linenoise.c"
