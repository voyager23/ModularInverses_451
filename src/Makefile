# Makefile for ModularInverses_451

UNAME := $(shell uname)
FLAGS = -std=c++20 -O3 -g

.PHONEY: run db

mygcd : mygcd.cxx
	g++ mygcd.cxx $(FLAGS) -o ../bin/mygcd
	
qxgcd : query_xgcd.cxx makefile
	g++ query_xgcd.cxx -O2 -o ../bin/qxgcd
run:
	../bin/qxgcd
db:
	lldb ../bin/qxgcd
	

cpt : coprimetree.cxx makefile
	g++ coprimetree.cxx --std=c++20 -o ./cpt

gxd : gmpxgcd.cxx makefile
	g++ gmpxgcd.cxx --std=c++20 -I/usr/local/include -L/usr/local/lib -lgmpxx -lgmp -o ./gxd

query : queries.cxx
	g++ queries.cxx $(FLAGS) -o ../bin/query
	
sqrs : squares.cxx
	g++ squares.cxx $(FLAGS) -o ./sqrs
	
	


#~ tfib:
#~ ifeq ($(UNAME),Darwin)
#~ 	@echo "Macbook"
#~ 	gcc a_dev.c -I/opt/homebrew/include  -L/opt/homebrew/lib  -g -lgmp -o tfib
#~ else
#~ 	@echo "?Linux?
#~ 	gcc a_dev.c -lgmp -o tfib
#~ endif
