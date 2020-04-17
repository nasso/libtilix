##
## EPITECH PROJECT, 2020
## libtiled
## File description:
## Makefile to build libraries
##

REPO_PREFIX	=	git@github.com:nasso

makelib		=	$(MAKE) -sC $(1) $(2) NAME=$(abspath ./$(1).a);

cpheader	=	mkdir -p ./include/$(1:lib%=%); \
				cp -rf ./$(1)/include/* ./include/$(1:lib%=%);

buildlib	=	$(call makelib,$(1),all) \

cleanlib	=	$(call makelib,$(1),clean) \

fcleanlib	=	$(call makelib,$(1),fclean) \

ifeq ($(NAME),)
	$(error must specify a value for NAME)
endif

ifeq ($(BRANCH),)
	$(error must specify a value for BRANCH)
endif

all: $(NAME).a

$(NAME).a: $(NAME)
	@$(call buildlib,$(NAME))
	@$(call cpheader,$(NAME))

$(NAME):
	@printf '\r  \033[K\033[0;35m Fetching\033[0m `$@` ($(BRANCH))\n'
	@git clone -q $(REPO_PREFIX)/$(NAME) --branch=$(BRANCH)
	@rm -rf $(NAME)/.git

clean:
	@$(call cleanlib,$(NAME))

fclean:
	@rm -rf ./include/$(NAME:lib%:%)
	@$(call fcleanlib,$(NAME))

.PHONY: all clean fclean
