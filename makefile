build_dir = build
lib_dir = src/lib
test_dir = src/test
proof_dir = src/proof

target: main clean

proof: $(proof_dir)/proof_of_concept.c
	gcc $< -o $(build_dir)/$@ -Wall -Wextra -Werror

random.o: $(lib_dir)/random.c $(lib_dir)/random.h
	gcc $< -c -o $(build_dir)/$@ -Wall -Wextra -Werror

main.o: $(test_dir)/main.c $(lib_dir)/random.h
	gcc $< -c -o $(build_dir)/$@ -Wall -Wextra -Werror

main: main.o random.o $(lib_dir)/random.h
	gcc $(build_dir)/main.o $(build_dir)/random.o -o $(build_dir)/$@

clean:
	rm $(build_dir)/*.o