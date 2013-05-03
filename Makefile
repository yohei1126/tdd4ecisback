#This makefile makes all the main book code with CppUTest test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = LightScheduler

#--- Inputs ----#
CPPUTEST_HOME = CppUTest
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = \

TEST_SRC_DIRS = \
	.\

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\

MOCKS_SRC_DIRS = \
	mocks\

CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror 
#CPPUTEST_CFLAGS = -std=c89 
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic
LD_LIBRARIES = -lpthread

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
