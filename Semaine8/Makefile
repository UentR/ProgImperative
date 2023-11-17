LINK.o = $(LINK.cc)
CXX=clang++
CXXFLAGS=-std=c++17 -Wall -pedantic -Wno-sign-compare -Wno-unused-value -g # -fsanitize=address

ALL=cin damier fichier-ecriture fichier-ecriture-v2 degrade-circulaire degrade videoInverse manipulation-fichiers-correction

all: $(ALL)

test: all
	./manipulation-fichiers-correction

clean:
	-rm $(ALL) *.pbm *.pgm truc-copy.tex
