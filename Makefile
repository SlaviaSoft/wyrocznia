CC=g++
OBJDIR=obj
vpath %.cpp src
vpath %.h src

objects= $(addprefix $(OBJDIR)/, main.o Game.o Console.o )


wyrocznia: $(objects)
	g++ -o wyrocznia $(objects) -lsfml-graphics -lsfml-window -lsfml-system


$(OBJDIR)/%.o: %.cpp
	$(CC) -c $< -o $@


.PHONY : clean
clean :
	rm $(objects)
