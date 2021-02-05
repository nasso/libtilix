##
## EPITECH PROJECT, 2021
## libmy
## File description:
## Makefile automatically generated using Epine!
##

NAME = libmy.a

all: libmy.a
.PHONY: all

__NAME__SRCS := $(shell find -path './src/*.c')
__NAME__OBJS := $(filter %.c,$(__NAME__SRCS))
__NAME__OBJS := $(__NAME__OBJS:.c=.o)
__NAME__DEPS := $(__NAME__OBJS:.o=.d)
$(NAME): CPPFLAGS += -MD -MP
$(NAME): CPPFLAGS += -Iinclude
$(NAME): CPPFLAGS += -DMY_ALLOW_FUN_MALLOC
$(NAME): CPPFLAGS += -DMY_ALLOW_FUN_FREE
$(NAME): CPPFLAGS += -DMY_ALLOW_FUN_WRITE
$(NAME): CFLAGS += -Wall
$(NAME): CFLAGS += -Wextra
$(NAME): CFLAGS += $(if DEBUG,-g3)
$(NAME): LDFLAGS += -L.
$(NAME): LDFLAGS += -L./lib
$(NAME): LDFLAGS += -Wl,-rpath .
$(NAME): $(__NAME__OBJS)
	$(AR) rc $@ $(__NAME__OBJS)
-include $(__NAME__DEPS)

unit_tests_SRCS := $(shell find -path './tests/*.c')
unit_tests_OBJS := $(filter %.c,$(unit_tests_SRCS))
unit_tests_OBJS := $(unit_tests_OBJS:.c=.o)
unit_tests_DEPS := $(unit_tests_OBJS:.o=.d)
unit_tests: CPPFLAGS += -MD -MP
unit_tests: CPPFLAGS += -Iinclude
unit_tests: CFLAGS += -Wall
unit_tests: CFLAGS += -Wextra
unit_tests: CFLAGS += $(if DEBUG,-g3)
unit_tests: LDLIBS += -lmy
unit_tests: LDLIBS += -lcriterion
unit_tests: LDFLAGS += -L.
unit_tests: LDFLAGS += -L./lib
unit_tests: LDFLAGS += -Wl,-rpath .
unit_tests $(unit_tests_OBJS): libmy.a
unit_tests: $(unit_tests_OBJS)
	$(CC) -o $@ $(unit_tests_OBJS) $(LDFLAGS) $(LDLIBS)
-include $(unit_tests_DEPS)

tests_run: unit_tests
	./unit_tests $(ARGS)
.PHONY: tests_run

clean:
	$(RM) $(__NAME__DEPS) $(__NAME__OBJS) $(unit_tests_DEPS) $(unit_tests_OBJS)
.PHONY: clean

fclean:
	$(RM) $(__NAME__DEPS) $(__NAME__OBJS) $(unit_tests_DEPS) $(unit_tests_OBJS)
	$(RM) $(NAME) unit_tests
	$(RM) unit_tests
.PHONY: fclean

re: fclean all
.PHONY: re
