PROJECT = base-practica-c
OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
WFLAGS = -Wall
SRC = main.c
OBJ = main.o
INPC = input.c
INPH = input.h
INPO = input.o
MENUC = menu.c
MENUH = menu.h
MENUO = menu.o
ALUMNOC = alumno.c
ALUMNOH = alumno.h
ALUMNOO = alumno.o
ARRC = arrays.c
ARRH = arrays.h
ARRO = arrays.o

debug: $(PROJECT)
	./$(EXEDIR)$^
$(PROJECT): $(OBJDIR)$(INPO) $(OBJDIR)$(ARRO) $(OBJDIR)$(ALUMNOO) $(OBJDIR)$(MENUO) $(OBJDIR)$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(EXEDIR)$@
$(OBJDIR)$(OBJ): $(MENUH) $(SRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC)
$(OBJDIR)$(MENUO): $(MENUC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(ALUMNOO): $(ALUMNOC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(ARRO): $(ARRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(INPO): $(INPC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
clean:
	$(RM) $(PROJECT).layout $(PROJECT).depend $(OBJDIR)*.o $(EXEDIR)$(PROJECT)