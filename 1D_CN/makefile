1d_CN: 1d.o f.o
	g++ -Wall -o 1d_CN 1d.o f.o

1d_tun: 1d.o f_tun.o
	g++ -Wall -o 1d_tun 1d.o f_tun.o

1d_pc: 1d.o f_pc.o
	g++ -Wall -o 1d_pc 1d.o f_pc.o

1d_pw: 1d.o f_pw.o
	g++ -Wall -o 1d_pw 1d.o f_pw.o

1d.o: 1d.cpp header.h
	g++ -Wall -c 1d.cpp

f.o: f.cpp header.h
	g++ -Wall -c f.cpp

f_tun.o: f_tun.cpp header.h
	g++ -Wall -c f_tun.cpp

f_pc.o: f_pc.cpp header.h
	g++ -Wall -c f_pc.cpp

f_pw.o: f_pw.cpp header.h
	g++ -Wall -c f_pw.cpp


