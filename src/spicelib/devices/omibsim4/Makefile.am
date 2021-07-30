## Process this file with automake to produce Makefile.in

noinst_LTLIBRARIES = libomibsim4.la

libomibsim4_la_SOURCES =	\
	omib4.c		\
	omib4acld.c	\
	omib4ask.c		\
	omib4check.c	\
	omib4cvtest.c	\
	omib4geo.c		\
	omib4getic.c	\
	omib4ld.c		\
	omib4mask.c	\
	omib4mdel.c	\
	omib4mpar.c	\
	omib4noi.c		\
	omib4par.c		\
	omib4pzld.c	\
	omib4set.c		\
	omib4soachk.c	\
	omib4temp.c	\
	omib4trunc.c	\
	omibsim4def.h	\
	omibsim4ext.h	\
	omibsim4init.c	\
	omibsim4init.h	\
	omib4getmparam.c \
	omib4getparam.c \
	omibsim4itf.h



AM_CPPFLAGS = @AM_CPPFLAGS@ -I$(top_srcdir)/src/include
AM_CFLAGS = $(STATIC)

MAINTAINERCLEANFILES = Makefile.in

EXTRA_DIST = B4TERMS_OF_USE
