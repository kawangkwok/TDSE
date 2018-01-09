1d_leap: 1d_leap.o f.o
	g++ -Wall -o 1d_leap 1d_leap.o f.o

1d_ltun: 1d_leap.o f_ltun.o
	g++ -Wall -o 1d_ltun 1d_leap.o f_ltun.o

1d_lpc: 1d_leap.o f_lpc.o
	g++ -Wall -o 1d_lpc 1d_leap.o f_lpc.o

1d_lpw: 1d_leap.o f_lpw.o
	g++ -Wall -o 1d_lpw 1d_leap.o f_lpw.o

1d_leap.o: 1d_leap.cpp header.h
	g++ -Wall -c 1d_leap.cpp

f_ltun.o: f_ltun.cpp header.h
	g++ -Wall -c f_ltun.cpp

f_lpc.o: f_lpc.cpp header.h
	g++ -Wall -c f_lpc.cpp

f_lpw.o: f_lpw.cpp header.h
	g++ -Wall -c f_lpw.cpp

f.o: f.cpp header.h
	g++ -Wall -c f.cpp

clean:
	rm 1d_leap.o f.o
