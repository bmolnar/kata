#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([kata], [1.0.0], [brian.molnar@gmail.com])

AC_CONFIG_AUX_DIR([config-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign -Wall -Werror])

# Checks for programs.
AC_PROG_CC
AM_PROG_AR
LT_INIT

AM_PATH_CHECK(,[have_check="yes"],
  AC_MSG_WARN([Check not found; cannot run unit tests!])
  [have_check="no"])
AM_CONDITIONAL(HAVE_CHECK, test x"$have_check" = "xyes")

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([src/Makefile tests/Makefile Makefile])
AC_CONFIG_SUBDIRS([src tests])
AC_OUTPUT
