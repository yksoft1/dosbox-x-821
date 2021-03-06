# makefile for arm-linux
#   gcc version 4

CC		=	gcc
CXX		=   g++
WINDRES =	windres
STRIP	=	strip
RM		=	rm -f

DBX_PATH	= ..

DYNREC = 1

OPENGL = 1

MT32 = 1

CXXFLAGS = -O3  -DNDEBUG \
			-std=gnu++98 -Wstrict-overflow=0 -Wstrict-aliasing=0 -fomit-frame-pointer  -mno-ms-bitfields  -I. \
			-I$(DBX_PATH) \
			-I$(DBX_PATH)/include \
			-I$(DBX_PATH)/src \
			-I$(DBX_PATH)/src/aviwriter \
			-I$(DBX_PATH)/src/hardware/snd_pc98/sound \
			-I$(DBX_PATH)/src/hardware/snd_pc98/common \
			-I$(DBX_PATH)/src/hardware/snd_pc98/generic \
			-I$(DBX_PATH)/src/hardware/snd_pc98/sound/getsnd \
			-I$(DBX_PATH)/src/hardware/snd_pc98/x11 \
			-I$(DBX_PATH)/src/hardware/snd_pc98/cbus 
			
ifeq ($(DYNREC), 1)
	CXXFLAGS	+=  -DC_DYNREC=1
endif

CFLAGS	=	-O3 -DNDEBUG -Wstrict-overflow=0 -Wstrict-aliasing=0 -fomit-frame-pointer  -mno-ms-bitfields  -I. \
			-I$(DBX_PATH) \
			-I$(DBX_PATH)/include \
			-I$(DBX_PATH)/src \
			-I$(DBX_PATH)/src/aviwriter \
			-I$(DBX_PATH)/src/hardware/snd_pc98/sound \
			-I$(DBX_PATH)/src/hardware/snd_pc98/common \
			-I$(DBX_PATH)/src/hardware/snd_pc98/generic \
			-I$(DBX_PATH)/src/hardware/snd_pc98/sound/getsnd \
			-I$(DBX_PATH)/src/hardware/snd_pc98/x11 \
			-I$(DBX_PATH)/src/hardware/snd_pc98/cbus 
			
ifeq ($(SDL1), 1)
	CFLAGS	+=  $(shell sdl-config --cflags)
	CXXFLAGS += $(shell sdl-config --cflags)
else
	CFLAGS	+=	-DC_SDL2=1 $(shell sdl2-config --cflags)
	CXXFLAGS += -DC_SDL2=1 $(shell sdl2-config --cflags)
endif

ifeq ($(OPENGL), 1)
	CFLAGS	+= -DC_OPENGL=1
	CXXFLAGS += -DC_OPENGL=1
endif
	
LFLAGS	=

TARGET	=	dosbox-x.exe

CPPSRCS	=	$(DBX_PATH)/src/dosbox.cpp \
			$(wildcard $(DBX_PATH)/src/aviwriter/*.cpp) \
			$(wildcard $(DBX_PATH)/src/builtin/*.cpp) \
			$(wildcard $(DBX_PATH)/src/cpu/*.cpp) \
			$(wildcard $(DBX_PATH)/src/debug/*.cpp) \
			$(wildcard $(DBX_PATH)/src/dos/*.cpp) \
			$(wildcard $(DBX_PATH)/src/fpu/*.cpp) \
			$(wildcard $(DBX_PATH)/src/gui/*.cpp) \
			$(wildcard $(DBX_PATH)/src/gui/*.c) \
			$(wildcard $(DBX_PATH)/src/hardware/*.cpp) \
			$(wildcard $(DBX_PATH)/src/hardware/parport/*.cpp) \
			$(wildcard $(DBX_PATH)/src/hardware/reSID/*.cpp) \
			$(wildcard $(DBX_PATH)/src/hardware/serialport/*.cpp) \
			$(wildcard $(DBX_PATH)/src/hardware/mame/*.cpp) \
			$(DBX_PATH)/src/hardware/snd_pc98/cbus/board86.c \
			$(DBX_PATH)/src/hardware/snd_pc98/cbus/board26k.c \
			$(wildcard $(DBX_PATH)/src/hardware/snd_pc98/common/*.c) \
			$(wildcard $(DBX_PATH)/src/hardware/snd_pc98/generic/*.c) \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/opngeng.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/opngenc.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/pcm86g.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/pcm86c.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/tms3631g.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/tms3631c.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/psggeng.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/psggenc.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/adpcmg.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/adpcmc.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/rhythmc.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/fmboard.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/fmtimer.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/sound.c \
			$(DBX_PATH)/src/hardware/snd_pc98/sound/soundrom.c \
			$(wildcard $(DBX_PATH)/src/hardware/snd_pc98/sound/getsnd/*.c) \
			$(wildcard $(DBX_PATH)/src/hardware/snd_pc98/x11/*.c) \
			$(wildcard $(DBX_PATH)/src/ints/*.cpp) \
			$(wildcard $(DBX_PATH)/src/libs/gui_tk/*.cpp) \
			$(wildcard $(DBX_PATH)/src/misc/*.cpp) \
			$(wildcard $(DBX_PATH)/src/shell/*.cpp) 

CPPSRCS_MT32 = $(wildcard $(DBX_PATH)/src/mt32/*.cpp) \
			$(wildcard $(DBX_PATH)/src/mt32/freeverb/*.cpp) \
			$(wildcard $(DBX_PATH)/src/mt32/sha1/*.cpp)

CPPSRCS_MT32V23 = $(wildcard $(DBX_PATH)/src/mt32-v2.3/*.cpp) \
			$(wildcard $(DBX_PATH)/src/mt32-v2.3/sha1/*.cpp)
			
OBJS_MT32 = $(addsuffix .o,$(basename $(CPPSRCS_MT32)))

OBJS_MT32V23 = $(addsuffix .o,$(basename $(CPPSRCS_MT32V23)))

CXXFLAGS_MT32 = -DC_MT32=1 -I$(DBX_PATH)/src/mt32 -I$(DBX_PATH)/src/mt32/freeverb -I$(DBX_PATH)/src/mt32/sha1

CXXFLAGS_MT32V23 = -DC_MT32=1 -I$(DBX_PATH)/src/mt32-v2.3 -I$(DBX_PATH)/src/mt32-v2.3/sha1

CXXFLAGS_SYNTH = -DC_FLUIDSYNTH=1

OBJS = $(addsuffix .o,$(basename $(CPPSRCS)))
LIBS = -static -lz -lpng -lm -lstdc++ 

SDLSOUND_EXTRALIBS = -lmikmod -lpthread -lvorbisfile -lvorbis -logg

ifeq ($(SDL1), 1) 
	LIBS += $(shell sdl-config --libs)
	ifdef WINDIR
		OBJS += $(DBX_PATH)/src/winres.rc.o
		LIBS += -limm32
	endif
	
	ifeq ($(SDLSOUND), 1)
		CXXFLAGS += -DC_SDL_SOUND=1
		LIBS += -lSDL_sound $(SDLSOUND_EXTRALIBS)
	endif
else
	LIBS += $(shell sdl2-config --libs)
endif

ifeq ($(OPENGL), 1)
	ifdef WINDIR
		LIBS += -lopengl32
	else
		LIBS += -lGL
	endif
endif

ifeq ($(MT32V23),1)
	MT32 = 0
	CPPSRCS += $(CPPSRCS_MT32V23)
	CXXFLAGS += $(CXXFLAGS_MT32V23)
#	OBJS += $(OBJS_MT32)
endif

ifeq ($(MT32),1)
	CPPSRCS += $(CPPSRCS_MT32)
	CXXFLAGS += $(CXXFLAGS_MT32)
#	OBJS += $(OBJS_MT32)
endif

ifeq ($(SYNTH),1)
	CXXFLAGS += $(CXXFLAGS_SYNTH)
	LIBS += -lfluidsynth
endif

.SUFFIXES: .c.o
.SUFFIXES: .cpp.o

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(LFLAGS) -g -o $@ $(OBJS) $(LIBS)
	$(STRIP) $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(DBX_PATH)/src/winres.rc.o: $(DBX_PATH)/src/winres.rc
	$(WINDRES) -i $< -o $@
	
clean:
	rm -f $(TARGET) $(OBJS) $(OBJS_MT32) $(OBJS_MT32V23)
