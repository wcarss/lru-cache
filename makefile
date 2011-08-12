default: app
all: app tests

app:
	cd src/lib; make app

tests:
	cd src/lib; make tests

cleanall: clean
	rm -rf tests
	rm -rf app

clean:
	cd src/lib; make clean
