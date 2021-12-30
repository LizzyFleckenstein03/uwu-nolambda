# nolambda
nolambda is a collection of native [uwu](https://github.com/EliasFleckenstein03/uwulang) modules that break the lambda paradigm, such as linear execution, I/O, globals etc.

## Modules

### `nolambda:flow`

- `nolambda:flow:linear`: Accepts an arbitrary number of arguments of arbitrary type, but at least one and evaulates all of them in order. Returns the last argument.
- `nolambda:flow:error`: Accepts an arbitrary value as $0, prints it to stderr appending a newline and exits the program with failure. Returns `:nil:nil` in theory.

### `nolambda:io`

- `nolambda:io:print`: Accepts an arbitrary value as $0 and prints it to stdout, followed by a newline. Returns $0.
- `nolambda:io:scan`: Reads a line from stdin and returns it as a string, without the newline character at the end. If $0 is given, it is used as a prompt (after converting to string).

### `nolambda:fs`

Note: all file paths are relative to the _directory the program was started from_.

- `nolambda:fs:read`: Accepts a file name (arbirary value, used as string) as $0 and returns it's contents as a string. Causes an error if the file does not exist.
- `nolambda:fs:write`: Accepts a file name (arbirary value, used as string) as $0 and overwrites it with the contents in $1 (arbirary value, used as string). Causes an error if the file could not be written. Returns `:bool:true` if the file was freshly created, `:bool:false` if it was overwritten.
- `nolambda:fs:remove`: Accepts a file name (arbirary value, used as string) as $0 and removes it from the file system. Causes an error if the file could not be removed, but does not cause an error if the file does not exist. Returns `:bool:true` if the file existed and was removed, `:bool:false` otherwise.
- `nolambda:fs:exists`: Accepts a file name (arbirary value, used as string) as $0 and returns `:bool:true` if it exists, `:bool:fase` else.

### `nolambda:os`

- `nolambda:os:exit`: Optionally takes an exit code (integer) as $0 and exits the program with the given exit code, or 0 if no exit code was given. Returns `:nil:nil` in theory.
- `nolambda:os:sleep`: Takes an integer as $0 and pauses the execution of the program for $1 milliseconds. Returns `:nil:nil`.
- `nolambda:os:execute`: Takes a command (arbirary value, used as string) as $0 and executes it as a shell command. Returns the exit code of the command as an integer.
- `nolambda:os:time`: Returns the current unix time as an integer.

### `nolambda:global`

- `nolambda:global:set`: Creates or overwrites a global variable named $0 (arbirary value, used as string) and puts the contents of $1 (arbitrary type) into it. Returns `:bool:false` if the variable existed previously and was updated, `:bool:true` if it was created.
- `nolambda:global:get`: Returns the global variable named $0 (arbirary value, used as string). Causes an error if the variable does not exist.
- `nolambda:global:exists`: Returns `:bool:true` if the global variable named $0 (arbirary value, used as string) exists, `:bool:false` else.
- `nolambda:global:delete`: Deletes the global variable named $0 (arbirary value, used as string). Returns `:bool:true` if the variable existed previously, `:bool:false` else.

### `nolambda:random`

- `nolambda:random:random`: Returns a pseudorandom integer between $0 (integer) and $1 (integer). The upper bound is exclusive, the lower bound inclusive. Causes an error if the range is bigger than `nolambda:random:max`.
- `nolambda:random:max`: Returns RAND_MAX, which is usually 32767.
- `nolambda:random:seed`: Sets the random seed to $0 (integer) and returns `:nil:nil`.
