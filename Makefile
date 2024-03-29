all: flow.so io.so fs.so os.so random.so

uwu_include_path=../uwu-lang/

%.so: %.c
	gcc -g -I${uwu_include_path} -shared -fpic $< -o $@ -D_GNU_SOURCE -Wall -Wextra

clean:
	rm -rf *.so
