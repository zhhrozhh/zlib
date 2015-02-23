CPPFLAG	=	-std=c++11 -Wall
OB		=	zObjs/
MA		=	zMath/
PRQ		=	zPreq.h
a		:	test.o zMath.o zCX.o zTRI.o zOFU.o zFUN.o zFUNC.o zMAT.o zEXINT.o
	g++ $(CPPFLAG) -o a test.o zMath.o zCX.o zTRI.o zOFU.o zFUN.o zFUNC.o zMAT.o zEXINT.o
test.o	:	test.cpp
	g++ $(CPPFLAG) -c test.cpp
zMath.o	:	$(MA)zMath.cpp $(MA)zCX.h $(MA)zTRI.h $(MA)zOFU.h $(MA)zFUNC.h $(MA)zMAT.h $(MA)zEXINT.h
	g++ $(CPPFLAG) -c $(MA)zMath.cpp
zCX.o	:	$(MA)zCX.cpp zPreq.h
	g++ $(CPPFLAG) -c $(MA)zCX.cpp
zTRI.o	:	$(MA)zTRI.cpp
	g++ $(CPPFLAG) -c $(MA)zTRI.cpp
zOFU.o	:	$(MA)zOFU.cpp
	g++ $(CPPFLAG) -c $(MA)zOFU.cpp
zFUN.o	:	$(MA)zFUN.cpp $(MA)zFUN.h
	g++ $(CPPFLAG) -c $(MA)zFUN.cpp
zFUNC.o	:	$(MA)zFUNC.cpp $(MA)zFUNC.h
	g++ $(CPPFLAG) -c $(MA)zFUNC.cpp
zMAT.o	:	$(MA)zMAT.cpp $(MA)zMAT.h
	g++ $(CPPFLAG) -c $(MA)zMAT.cpp
zEXINT.o:	$(MA)zEXINT.cpp $(MA)zEXINT.h
	g++ $(CPPFLAG) -c $(MA)zEXINT.cpp
