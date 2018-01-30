2d_leap: 2d_leap.o f.o
	g++ -Wall -o 2d_leap 2d_leap.o f.o

2d_pw: 2d_leap.o f_pw.o
	g++ -Wall -o 2d_pw 2d_leap.o f_pw.o

2d_pc: 2d_leap.o f_pc.o
	g++ -Wall -o 2d_pc 2d_leap.o f_pc.o

2d_tun: 2d_leap.o f_tun.o
	g++ -Wall -o 2d_tun 2d_leap.o f_tun.o

2d_leap.o: 2d_leap.cpp header.h
	g++ -Wall -c 2d_leap.cpp

f.o: f.cpp header.h
	g++ -Wall -c f.cpp

f_pw.o: f_pw.cpp header.h
	g++ -Wall -c f_pw.cpp

f_pc.o: f_pc.cpp header.h
	g++ -Wall -c f_pc.cpp

f_tun.o: f_tun.cpp header.h
	g++ -Wall -c f_tun.cpp
