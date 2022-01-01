all: flow.so io.so fs.so os.so

uwu_include_path=../uwulang/

%.so: %.c
	gcc -g -I${uwu_include_path} -shared -fpic $< -o $@ -D_GNU_SOURCE -Wall -Wextra

clean:
	rm -rf *.so
