e# nolambda
nolambda is a collection of native [uwu](https://github.com/EliasFleckenstein03/uwulang) modules that break the lambda paradigm, such as linear execution, I/O, globals etc.

## Building

Make sure the submodules are checked out:

```sh
git submodule update --init
```

Build:

```sh
make uwu_include_path=/path/to/uwulang/repo
```

## Modules

Note: The module `global` is not implemented yet.

### `flow`

- `flow.linear`: Accepts an arbitrary number of arguments of arbitrary type, but at least one and evaulates all of them in order. Returns the last argument.
- `flow.error`: Accepts an arbitrary type as $0, prints it to stderr appending a newline and exits the program with failure. Returns `nil.nil` in theory.

### `io`

- `io.print`: Accepts an arbitrary type as $0 and prints it to stdout, followed by a newline. Returns $0.
- `io.scan`: Reads a line from stdin and returns it as a string, without the newline character at the end. If $0 is given, it is used as a prompt (after converting to string).

### `fs`

Note: all file paths are relative to the _directory the program was started from_.

- `fs.read`: Accepts a file name (arbirary value, converted to string) as $0 and returns it's contents as a string. Causes an error if the file does not exist.
- `fs.write`: Accepts a file name (arbirary value, converted to string) as $0 and overwrites it with the contents in $1 (arbirary value, converted to string). Causes an error if the file could not be written. Returns `nil.nil`.
- `fs.remove`: Accepts an arbitrary number of file names (arbirary type, converted to string), but at least one and unlinks them from the file system (the files can also be a directories). Causes an error if one of the file could not be removed, or if some or all of the files did not exist in the first place. Returns `nil.nil`.
- `fs.exists`: Accepts an arbitrary number of file names (arbirary type, converted to string), but at least one and returns `bool.true` if all of them exist, `bool.false` else.

### `os`

- `os.exit`: Optionally takes an exit code (integer) as $0 and exits the program with the given exit code, or 0 if no exit code was given. Returns `nil.nil` in theory.
- `os.sleep`: Takes an integer as $0 and pauses the execution of the program for $1 milliseconds. Returns `nil.nil`.
- `os.execute`: Takes a command (arbirary value, converted to string) as $0 and executes it as a shell command. Returns the exit code of the command as an integer.
- `os.time`: Returns the current unix millis as an integer.

### `global`

- `global.set`: Creates or overwrites a global variable named $0 (arbirary value, converted to string) and puts the contents of $1 (arbitrary type) into it. Returns `bool.false` if the variable existed previously and was updated, `bool.true` if it was created.
- `global.get`: Returns the global variable named $0 (arbirary value, converted to string). Causes an error if the variable does not exist.
- `global.exists`: Returns `bool.true` if the global variable named $0 (arbirary value, converted to string) exists, `bool.false` else.
- `global.delete`: Deletes the global variable named $0 (arbirary value, converted to string). Returns `bool.true` if the variable existed previously, `bool.false` else.

### `random`

- `random.random`: Returns a pseudorandom integer between $0 (integer) and $1 (integer). The range is inclusive on both boundse. Causes an error if the range is bigger than `random.max` or empty.
- `random.max`: Returns RAND_MAX.
- `random.seed`: Sets the random seed to $0 (integer) and returns `nil.nil`.
