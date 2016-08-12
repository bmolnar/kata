TESTS = check_kata
check_PROGRAMS = check_kata
check_kata_SOURCES = check_kata.c $(top_builddir)/src/kata.h
check_kata_CFLAGS = @CHECK_CFLAGS@
check_kata_LDADD = $(top_builddir)/src/libkata.la @CHECK_LIBS@ -lm -lrt -lpthread
