CC=g++
OBJDIR=obj
vpath %.cpp src
vpath %.h src

objects= $(addprefix $(OBJDIR)/, main.o Game.o FpsTimer.o Console.o )


wyrocznia: $(objects)
	g++ -o wyrocznia $(objects) -lGL -lglut -lGLEW


$(OBJDIR)/%.o: %.cpp
	$(CC) -c $< -o $@


.PHONY : clean
clean :
	rm $(objects)
