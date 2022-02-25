all: compile run

clean:
	@rm -rf build

compile:
	cd build && cmake --build .

configure:
	mkdir build
	cd build && cmake ../

run:
	./build/src/converter

run-tests:
	./build/test/converter-test
