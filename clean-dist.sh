#!/bin/sh

cd vs2015/sdl
	
make distclean
rm dosbox.pc

cd ../../
	
if test -f Makefile; then
	make distclean
fi

# Also remove the autotools cache directory.
rm -Rf autom4te.cache

# Remove rest of the generated files.
rm -rf Makefile.in
rm -f aclocal.m4 configure depcomp install-sh missing
rm *.exe