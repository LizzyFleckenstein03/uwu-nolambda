all: flow.so io.so

uwu_include_path=../uwulang/

%.so: %.c
	gcc -g -I${uwu_include_path} -shared -fpic $< -o $@ -D_GNU_SOURCE

clean:
	rm -rf *.so
