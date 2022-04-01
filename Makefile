NAME := hotrace

SHELL := /bin/bash
CC := cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I$(INCLUDES) #-O3
INCLUDES = .

SRCDIR := .
OBJDIR := objs
SRCFILE := $(shell find -name "*.c" -type f)
OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.o))
DEPS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.d))

# ==== Align length to format compile message ==== #
#ALIGN := $(shell tr ' ' '\n' <<<"$(SRCFILE)" | awk -v len=0 -F "" 'NF>len{len=NF}END{print len}')
ALIGN := $(shell tr ' ' '\n' <<<"$(SRCFILE)" | while read line; do echo \
	$$((`echo $$line | wc -m`)); done | awk 'm<$$1{ m=$$1} END{print m}')

all: $(NAME)
-include $(DEPS)

dict:
	cat /usr/share/dict/words | awk '{printf "%s\n%s\n", $1,NR}' > dict.txt

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo -e "flags  : $(YLW)$(CFLAGS)$(NC)\nbuild  : $(GRN)$^$(NC)\n=> $(BLU)$@$(NC)" 

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(*D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "compile: $(MGN)$<$(NC)\
	$$(yes ' ' | head -n $$(expr $(ALIGN) - $$((`echo $< | wc -m` - 1))) | tr -d '\n') -> \
	$(GRN)$@$(NC)"

run: all
	./$(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -DDEBUG
debug: re

.PHONY: all clean fclean re debug run dict

# ==== Color define ==== #
YLW := \033[33m
GRN := \033[32m
YLW := \033[33m
BLU := \033[34m
MGN := \033[35m
CYN := \033[36m
NC := \033[m

# ==== suggest 'j' option of make command ==== #
ifeq ($(shell uname), Linux)
	procs := $$(expr $$(grep cpu.cores /proc/cpuinfo | sort -u | sed 's/[^0-9]//g') + 1)
else
	procs := $$(expr $$(system_profiler SPHardwareDataType | grep Total | sed 's/[^0-9]//g') + 1)
endif

.PHONY: proc
proc:
	@echo -e "please do $(CYN)export MAKEFLAGS=-j$(procs)$(NC)"
