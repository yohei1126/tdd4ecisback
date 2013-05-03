# CppUTest Examples Makefile

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
CPPUTEST_HOME = ./CppUTest

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

SRC_DIRS = \
	platform/win\
	src\


TEST_SRC_DIRS = \
	test\


INCLUDE_DIRS =\
	.\
	src\
	test\
	include\


include $(CPPUTEST_HOME)/build/MakefileWorker.mk