
lib_LTLIBRARIES = librnsHEAAN.la
librnsHEAAN_ladir = $(includedir)/rns-HEAAN
librnsHEAAN_la_HEADERS = Ciphertext.h Context.h EvaluatorUtils.h Key.h \
						Numb.h Plaintext.h Scheme.h SchemeAlgo.h \
						SecretKey.h StringUtils.h TimeUtils.h
librnsHEAAN_la_SOURCES = Ciphertext.cpp Context.cpp EvaluatorUtils.cpp Key.cpp \
						Numb.cpp Plaintext.cpp Scheme.cpp SchemeAlgo.cpp \
						SecretKey.cpp StringUtils.cpp TimeUtils.cpp
librnsHEAAN_la_CFLAGS =
librnsHEAAN_la_CPPFLAGS = -fPIC
librnsHEAAN_la_CXXFLAGS = -fPIC -std=c++11
librnsHEAAN_la_LDFLAGS = -version-info 0:0:0
librnsHEAAN_la_LIBADD =

bin_PROGRAMS = Test
Test_SOURCES = main.cpp TestScheme.cpp
Test_LDADD = librnsHEAAN.la
