#!/bin/sh
export CFLAGS="-O3 -static-libgcc -flto -fno-use-linker-plugin"

export CXXFLAGS="-O3 -static-libgcc -static-libstdc++ -flto -fno-use-linker-plugin -DWINVER=0x0501 -D_WIN32_WINNT=0x0501"

cd vs2015/sdl
if test -f configure; then
	configure --prefix=/mingw --disable-shared --enable-static
else
	bash autogen.sh
	configure --prefix=/mingw --disable-shared --enable-static
fi

make -j4
make install

cd ../../
if test -f configure; then
	configure --disable-mt32
else
	bash autogen.sh
	configure --disable-mt32
fi
make -j4
cd src
strip dosbox-x.exe
mv dosbox-x.exe ../dosbox-x.exe
cd ..