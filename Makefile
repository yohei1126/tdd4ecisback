all: LightScheduler

clean: cleanLightScheduler

cleanAll: cleanLightScheduler cleanCppUTest cleanCppUTest

LightScheduler: CppUTest CppUTestExt
	make -i -f Makefile_LightScheduler

cleanLightScheduler:
	make -i -f Makefile_LightScheduler clean

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
