# Project Name
TARGET = wave_looper

# Sources
CPP_SOURCES = ./src/main.cpp 
CPP_SOURCES += ./src/waveLooper.cpp

LDFLAGS += -u _printf_float

# Library Locations
LIBDAISY_DIR = ./lib/libDaisy
DAISYSP_DIR = ./lib/DaisySP

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

