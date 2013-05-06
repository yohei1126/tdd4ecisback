all: tdd4ec

clean: cleantdd4ec

cleanAll: cleantdd4ec cleanCppUTest cleanCppUTest

tdd4ec: CppUTest CppUTestExt
	make -i -f Makefile_tdd4ec

cleantdd4ec:
	make -i -f Makefile_tdd4ec clean

CppUTest: CppUTest/lib/libCppUTest.a

cleanCppUTest:
	make -i -C CppUTest clean

CppUTestExt: CppUTest/lib/libCppUTestExt.a

cleanCppUTestExe:
	make -i -C CppUTest clean

CppUTest/lib/libCppUTest.a:
	pwd
	make -i -C CppUTest

CppUTest/lib/libCppUTestExt.a:
	pwd
	make -i -C CppUTest extensions
