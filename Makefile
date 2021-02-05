##
## EPITECH PROJECT, 2021
## libtilix
## File description:
## Makefile automatically generated using Epine!
##

NAME = libtilix.a

all: libtilix.a
.PHONY: all

__NAME__SRCS := $(shell find -path './src/*.c')
__NAME__OBJS := $(filter %.c,$(__NAME__SRCS))
__NAME__OBJS := $(__NAME__OBJS:.c=.o)
__NAME__DEPS := $(__NAME__OBJS:.o=.d)
$(NAME) $(__NAME__OBJS): ./lib/libjzon ./lib/libmy
$(NAME): CPPFLAGS :=
$(NAME): CPPFLAGS += -MD -MP
$(NAME): CPPFLAGS += -I./include
$(NAME): CPPFLAGS += -I./lib/libjzon/include
$(NAME): CPPFLAGS += -I./lib/libmy/include
$(NAME): CFLAGS :=
$(NAME): CFLAGS += -Wall
$(NAME): CFLAGS += -Wextra
$(NAME): CFLAGS += $(if DEBUG,-g3)
$(NAME): $(__NAME__OBJS)
	$(AR) rc $@ $(__NAME__OBJS)
-include $(__NAME__DEPS)

unit_tests_SRCS := $(shell find -path './tests/*.c')
unit_tests_OBJS := $(filter %.c,$(unit_tests_SRCS))
unit_tests_OBJS := $(unit_tests_OBJS:.c=.o)
unit_tests_DEPS := $(unit_tests_OBJS:.o=.d)
unit_tests $(unit_tests_OBJS): libtilix.a ./lib/libjzon/libjzon.a ./lib/libmy/libmy.a
unit_tests: CPPFLAGS :=
unit_tests: CPPFLAGS += -MD -MP
unit_tests: CPPFLAGS += -I./include
unit_tests: CPPFLAGS += -I./lib/libjzon/include
unit_tests: CPPFLAGS += -I./lib/libmy/include
unit_tests: CFLAGS :=
unit_tests: CFLAGS += -Wall
unit_tests: CFLAGS += -Wextra
unit_tests: CFLAGS += $(if DEBUG,-g3)
unit_tests: LDLIBS :=
unit_tests: LDLIBS += -l:libtilix.a
unit_tests: LDLIBS += -l:./lib/libjzon/libjzon.a
unit_tests: LDLIBS += -l:./lib/libmy/libmy.a
unit_tests: LDLIBS += -lcriterion
unit_tests: LDFLAGS :=
unit_tests: LDFLAGS += -L.
unit_tests: LDFLAGS += -Wl,-rpath .
unit_tests: $(unit_tests_OBJS)
	$(CC) -o $@ $(unit_tests_OBJS) $(LDFLAGS) $(LDLIBS)
-include $(unit_tests_DEPS)

tests_run: ./unit_tests
	./unit_tests $(ARGS)
.PHONY: tests_run

clean:
	$(RM) $(__NAME__DEPS) $(__NAME__OBJS) $(unit_tests_DEPS) $(unit_tests_OBJS)
	$(MAKE) -C ./lib/libjzon fclean
	$(MAKE) -C ./lib/libmy fclean
.PHONY: clean

fclean: clean
	$(RM) $(NAME) unit_tests
	$(RM) ./unit_tests
.PHONY: fclean

re: fclean all
.PHONY: re

# libs
pull:
	$(RM) -r './lib/libjzon'
	git clone git@github.com:nasso/libjzon './lib/libjzon'
	$(RM) -r './lib/libjzon/.git'
	$(RM) -r './lib/libmy'
	git clone git@github.com:nasso/libmy './lib/libmy'
	$(RM) -r './lib/libmy/.git'
.PHONY: pull

./lib:
	mkdir -p $@

./lib/libjzon:
	$(error $@ wasn't found! don't forget to `make pull`)
./lib/libjzon/%: | ./lib/libjzon
	$(MAKE) -C ./lib/libjzon $*
	$(MAKE) -C ./lib/libjzon clean

./lib/libmy:
	$(error $@ wasn't found! don't forget to `make pull`)
./lib/libmy/%: | ./lib/libmy
	$(MAKE) -C ./lib/libmy $*
	$(MAKE) -C ./lib/libmy clean
