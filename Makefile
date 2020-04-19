##
## EPITECH PROJECT, 2020
## libtiled
## File description:
## Makefile to build the project
##

CC		?=	gcc

SHELL	=	/bin/sh

MYFILE	=	Myfile.yml

define readcfg
$(strip $(shell sed -n '/^$(1):/,/^\S/s/^\s\+\-\|^$(1)://p' $(MYFILE)))
endef

dep2name = $(shell echo $(1) | sed -En 's/^@?([^=]+).*/\1/p')

dep2lib	= $(shell echo $(1) | sed -En 's/^@?lib([^=]+).*/-l\1/p')

dep2ar	= $(shell echo $(1) | sed -En 's/^@?([^=]+).*/\1.a/p')

dep2branch = $(shell echo $(1) | sed -En 's/^lib[^=]+=(.+)/\1/p')

ALLOWED ?=	$(call readcfg,allowed)

BINTYPE	:=	$(call readcfg,type)

DEPS	:=	$(call readcfg,dependencies)

MAINSRC	:=	$(call readcfg,main)

SRC		:=	$(call readcfg,src)

NAME	:=	$(call readcfg,name)

NAMESPC :=	$(call readcfg,namespace)

TESTSRC	:=	$(call readcfg,tests_src)

LIBDIR	?=	$(abspath ./lib)

INCLUDE =	-I$(OUTDIR)/include -I$(LIBDIR)/include

CFLAGS	=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra -pedantic \
			$(INCLUDE) $(if $(DEBUG),-g3) $(if $(COVERAGE),--coverage) \
			$(patsubst %,-DMY_ALLOW_FUN_%,$(strip \
				$(shell echo $(ALLOWED) | tr a-z A-Z)))

CPPFLAGS =	-MD -MP

LIBS	=	$(foreach dep,$(DEPS),$(call dep2lib,$(dep)))

TEST	=	unit-tests

OUTDIR	=	./target/$(if $(DEBUG),debug,release)

OUTNAME	=	$(OUTDIR)/$(notdir $(NAME))

OUTTEST	=	$(OUTDIR)/$(TEST)

CPPDEPS	=	$(SRC:%.c=$(OUTDIR)/%.d)

DEPSARC	=	$(foreach dep,$(DEPS),$(LIBDIR)/$(call dep2ar,$(dep)))

MAINOBJ	:=	$(MAINSRC:%.c=$(OUTDIR)/%.o)

OBJ		=	$(SRC:%.c=$(OUTDIR)/%.o)

TESTOBJ	=	$(TESTSRC:%.c=$(OUTDIR)/%.o)

COVREPS	=	$(SRC:%.c=$(OUTDIR)/%.gcda) $(SRC:.c=$(OUTDIR)/%.gcno) \
			$(MAINSRC:.c=$(OUTDIR)/%.gcda) $(MAINSRC:.c=$(OUTDIR)/%.gcno) \
			$(TESTSRC:.c=$(OUTDIR)/%.gcda) $(TESTSRC:.c=$(OUTDIR)/%.gcno)

define makelibs
	$(foreach dep,$(DEPS), \
		$(if $(call dep2branch,$(dep)), \
			$(MAKE) -sC $(LIBDIR) $(1) \
				NAME=$(call dep2name,$(dep)) \
				BRANCH=$(call dep2branch,$(dep)) \
				LIBDIR=$(LIBDIR); \
		) \
	)
endef

define info_deps_head
	@echo -n " ╭──────────────────────┬"
	@echo -n "──────────────────────┬"
	@echo "──────────────────────┬────────────╮"
	@printf " │ %-20s │ %-20s │ %-20s │ %-10s │\n" 'Definition' 'CC argument' \
		'File name' 'Branch'
	@echo -n " ├──────────────────────┼"
	@echo -n "──────────────────────┼"
	@echo "──────────────────────┼────────────┤"
endef

define info_dep_line
	@printf " │ %-20s │ %-20s │ %-20s │ %-10s │\n" '$(1)' \
		'$(call dep2lib,$(1))' '$(call dep2ar,$(1))' '$(call dep2branch,$(1))'

endef

define info_deps_end
	@echo -n " ╰──────────────────────┴"
	@echo -n "──────────────────────┴"
	@echo "──────────────────────┴────────────╯"
endef


export CC

export SHELL

export ALLOWED

export DEBUG

all: $(NAME)

info:
	@echo "\033[0;32mname:\033[0m" $(NAME)
	@echo "\033[0;32mtype:\033[0m" $(BINTYPE)
	@echo "\033[0;32mnamespace:\033[0m" $(NAMESPC)
	@echo -n "\033[0;32mallowed:\033[0m"
	@for fn in $(ALLOWED); do echo -n " $$fn"; done
	@echo
	@echo "\033[0;32mdependencies:\033[0m"
	$(call info_deps_head)
	$(foreach dep,$(DEPS),$(call info_dep_line,$(dep)))
	$(call info_deps_end)
	@echo "\033[0;32mlibs:\033[0m" $(LIBS)
	@echo "\033[0;32mmain:\033[0m" $(MAINSRC)
	@echo -n "\033[0;32msrc:\033[0m"
	@if [ '$(VERBOSE)' ]; then \
		for f in $(SRC); do echo -n "\n - $$f"; done; \
		echo; \
	else \
		echo '' $(shell echo $(SRC) | wc -w) 'file(s)'; \
	fi
	@echo -n "\033[0;32mtests:\033[0m"
	@if [ '$(VERBOSE)' ]; then \
		for f in $(TESTSRC); do echo -n "\n - $$f"; done; \
		echo; \
	else \
		echo '' $(shell echo $(TESTSRC) | wc -w) 'file(s)'; \
	fi

$(NAME): $(OUTNAME)
	@cp $< $@

$(OUTNAME): $(DEPSARC) $(OBJ) $(MAINOBJ)
	@if [ '$(BINTYPE)' = 'bin' ]; then \
		$(CC) $(CFLAGS) -o $@ $(OBJ) $(MAINOBJ) $(LIBDIR:%=-L%) $(LIBS); \
		printf '\r  \033[K\033[0;32m Finished\033[0m `%s` (binary)\n' "$@"; \
	fi
	@if [ '$(BINTYPE)' = 'lib' ]; then \
		ar -rc $@ $(OBJ); \
		printf '\r  \033[K\033[0;32m Finished\033[0m `%s` (library)\n' "$@"; \
	fi

$(DEPSARC):
	@$(call makelibs,all)

$(OUTDIR)/%.o: %.c | $(OUTDIR)
	@printf '\r  \033[K\033[0;32mCompiling\033[0m `$<`\n'
	@mkdir -p $(dir $@)
	@rm -f $(patsubst %.o,%.gcda,$@) $(patsubst %.o,%.gcno,$@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OUTDIR): $(abspath ./include)
	@mkdir -p $@/include
	@ln -Tfs $(abspath ./include) $@/include/$(NAMESPC)

$(TEST): $(OUTTEST)
	@cp $(OUTTEST) $(TEST)

$(OUTTEST): LIBS += -lcriterion
$(OUTTEST): $(DEPSARC) $(OBJ) $(TESTOBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(TESTOBJ) $(LIBDIR:%=-L%) $(LIBS)
	@printf '\r  \033[K\033[0;32m Finished\033[0m %s test build\n' \
		$(if $(DEBUG),'debug','release')

run: $(NAME)
	@printf '\r  \033[K\033[0;32m  Running\033[0m `$(strip $(NAME) $(ARGS))`\n'
	@./$(NAME) $(ARGS) || printf '\033[0;31mProgram exited with %d\033[0m\n' $$?

tests_run: $(TEST)
	@printf '\r  \033[K\033[0;32m  Running\033[0m `$(TEST)`\n'
	@./$(TEST)

clean:
	@$(call makelibs,clean)
	@printf '\r  \033[K\033[0;34m Cleaning\033[0m `$(NAME)`\n'
	@rm -f $(OBJ) $(TESTOBJ) $(MAINOBJ) $(COVREPS) $(CPPDEPS) $(OUTNAME) \
		$(OUTTEST)

fclean:
	@$(call makelibs,fclean)
	@printf '\r  \033[K\033[0;36m   Wiping\033[0m `$(NAME)`\n'
	@rm -f $(OBJ) $(TESTOBJ) $(MAINOBJ) $(COVREPS) $(CPPDEPS) $(OUTNAME) \
		$(OUTTEST)
	@rm -f $(NAME) $(TEST)
	@rm -rf $(OUTDIR)

re: fclean all

retest: fclean tests_run

rerun: re run

.PHONY: all info run tests_run clean fclean re retest rerun

-include $(CPPDEPS)
