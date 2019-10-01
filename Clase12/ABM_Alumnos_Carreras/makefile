PROJECT = base-practica-c
OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
RMFLAGS = -rf
WFLAGS = -Wall
SRC = main.c
OBJ = main.o
MENUC = menu.c
MENUH = menu.h
MENUO = menu.o
COMC = comidas.c
COMH = comidas.h
COMO = comidas.o
ALUC = alumnos.c
ALUH = alumnos.h
ALUO = alumnos.o
CARC = carreras.c
CARH = carreras.h
CARO = carreras.o
INPC = inputs.c
INPH = inputs.h
INPO = inputs.o
ARRC = arrays.c
ARRH = arrays.h
ARRO = arrays.o
STRC = structs.c
STRH = structs.h
STRO = structs.o

debug: $(PROJECT)
	./$(EXEDIR)$^
$(PROJECT): $(OBJDIR)$(STRO) $(OBJDIR)$(ARRO) $(OBJDIR)$(INPO) $(OBJDIR)$(CARO) $(OBJDIR)$(ALUO) $(OBJDIR)$(COMO) $(OBJDIR)$(MENUO) $(OBJDIR)$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(EXEDIR)$@
$(OBJDIR)$(OBJ): $(COMH) $(SRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC)
$(OBJDIR)$(COMO): $(COMC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(ALUO): $(ALUC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(CARO): $(CARC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(MENUO): $(MENUC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(INPO): $(INPC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(ARRO): $(ARRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(STRO): $(STRC)
	mkdir -p $(OBJDIR) \
	&& mkdir -p $(EXEDIR) \
	&& cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
clean:
	$(RM) *.layout *.depend \
	&& $(RM) $(RMFLAGS) bin/ obj/
