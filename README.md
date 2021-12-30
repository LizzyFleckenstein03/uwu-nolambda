# nolambda
nolambda is a collection of native [uwu](https://github.com/EliasFleckenstein03/uwulang) modules that break the lambda paradigm, such as linear execution, I/O, globals etc.

## Modules

### `nolambda:flow`

- `nolambda:flow:linear`: Accepts an arbitrary number of arguments of arbitrary type, but at least one and evaulates all of them in order. Returns the last argument.
- `nolambda:flow:error`: Accepts a string as $0, prints the string to stderr and exits the program with failure.

### `nolambda:io`

- `nolambda:io:print`: Accepts a string as $0 and prints it to stdout, followed by a newline.
- `nolambda:io:scan`: Reads a line from stdin and returns it as a string, without the newline character at the end. This is interally using readline.

### `nolambda:fs`

Note: all file paths are relative to the _directory the program was started from_.

- `nolambda:fs:read`: Accepts a file name (string) as $0 and returns it's contents as a string. Causes an error if the file does not exist.
- `nolambda:fs:write`: Accepts a file name (string) as $0 and overwrites it with the contents in $1 (string). Causes an error if the file could not be written.
- `nolambda:fs:remove`: Accepts a file name (string) as $0 and removes it from the file system. Causes an error if the file could not be removed, but does not cause an error if the file does not exist.
- `nolambda:fs:exists`: Accepts a file name (string) as $0 and returns `:bool:true` if it exists, `:bool:fase` else.

### `nolambda:os`

- `nolambda:os:exit`: Optionally takes an exit code (integer) as $0 and exits the program with the given exit code, or 0 if no exit code was given.
- `nolambda:os:sleep`: Takes an integer as $0 and pauses the execution of the program for $1 milliseconds.
- `nolambda:os:execute`: Takes a command (string) as $0 and executes it as a shell command. Returns the exit code of the command as an integer.

### `nolambda:global`

- `nolambda:global:set`: Creates or overwrites a global variable named $0 (string) and puts the contents of $1 (arbitrary type) into it.
- `nolambda:global:get`: Gets the global variable named $0 (string). Causes an error if the variable does not exist.
- `nolambda:global:exists`: Returns `:bool:true` if the global variable named $0 (string) exists, `:bool:false` else.
- `nolambda:global:delete`: Deletes the global variable named $0 (string). Does **not** cause an error if the variable does not exist.
