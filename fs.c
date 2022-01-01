#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "common/err.h"
#include "common/file.h"
#include "api/vm.h"
#include "api/str.h"
#include "api/nil.h"
#include "api/bool.h"
#include "api/util.h"

UwUVMValue uwu_read(UwUVMArgs *args)
{
	uwuutil_require_exact("fs.read", args, 1);

	char *filename = uwustr_get(uwuvm_get_arg(args, 0));

	FILE *file = fopen(filename, "r");
	if (! file) syserror("fopen", file);
	if (fseek(file, 0, SEEK_END) == -1) syserror("fseek", file);

	size_t size = ftell(file);
	if (size == 1) syserror("ftell", file);
	if (fseek(file, 0, SEEK_SET) == -1) syserror("fseek", file);

	char contents[size + 1];
	if (fread(contents, 1, size, file) != size) syserror("fread", file);

	fclose(file);
	free(filename);

	contents[size] = '\0';

	return uwustr_create(contents);
}

UwUVMValue uwu_write(UwUVMArgs *args)
{
	uwuutil_require_exact("fs.write", args, 2);
	
	char *filename = uwustr_get(uwuvm_get_arg(args, 0));
	char *contents = uwustr_get(uwuvm_get_arg(args, 1));
	
	FILE *file = fopen(filename, "w");
	if (! file) syserror("fopen", file);

	size_t size = strlen(contents);
	if (fwrite(contents, 1, size, file) != size) syserror("fwrite", file);

	fclose(file);
	free(filename);
	free(contents);

	return uwunil_create();
}

UwUVMValue uwu_remove(UwUVMArgs *args)
{
	uwuutil_require_min("fs.remove", args, 1);

	for (size_t i = 0; i < args->num; i++) {
		char *filename = uwustr_get(uwuvm_get_arg(args, i));

		if (remove(filename) != 0) syserror("remove", NULL);

		free(filename);
	}

	return uwunil_create();
}

UwUVMValue uwu_exists(UwUVMArgs *args)
{
	uwuutil_require_min("fs.exists", args, 1);

	for (size_t i = 0; i < args->num; i++) {
		char *filename = uwustr_get(uwuvm_get_arg(args, i));
		bool exists = file_exists(filename);
		free(filename);

		if (! exists)
			return uwubool_create(false);
	}

	return uwubool_create(true);
}
