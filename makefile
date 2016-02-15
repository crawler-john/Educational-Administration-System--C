
obj = main.o student.o teacher.o menu.o manager.o list/list.o
goal = sms
CFLAGS = -c -I./ -Ilist/

all : $(goal)
$(goal) : $(obj)
	gcc $^ -o $@

%.o : %.c
	gcc $(CFLAGS) $^ -o $@

clean :
		rm -rf $(obj) $(goal)
