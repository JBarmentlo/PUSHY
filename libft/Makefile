NAME=libft.a
HEADER_FOLDER=./includes

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SOURCES_FOLDER=srcs
OBJ_FOLDER=out

SOURCES=$(shell find $(SOURCES_FOLDER) -type f -name '*.c')
OUT=$(addprefix $(OBJ_FOLDER)/,$(notdir $(SOURCES:.c=.o)))

TEST_NAME=test.out
TESTS=$(wildcard tests/*_test.c)

ifdef flags
	CC_OPTIONS=$(flags) -I $(HEADER_FOLDER)
else ifdef noflags
	CC_OPTIONS=-I $(HEADER_FOLDER)
else ifdef addflags
	CC_OPTIONS=$(CFLAGS) $(addflags) -I $(HEADER_FOLDER)
else
	CC_OPTIONS=$(CFLAGS) -I $(HEADER_FOLDER)
endif

########################################################################################
###################################### DESIGNING #######################################
########################################################################################
RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE    = \x1b[34m
MAGENTA    = \x1b[35m
CYAN    = \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   =Compiling

define run_and_test
	printf "%b" "$(2) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
    $(1) 2> $@.log; \
    RESULT=$$?; \
    if [ $$RESULT -ne 0 ]; then \
    printf "%-60b%b" "$(2)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
    elif [ -s $@.log ]; then \
    printf "%-60b%b" "$(2)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
    else  \
    printf "%-60b%b" "$(2)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
    fi; \
    cat $@.log; \
    rm -f $@.log; \
    exit $$RESULT
endef

ifdef m
	MESSAGE_COMMIT="$(m)"
else
	MESSAGE_COMMIT="Commited by Makefile"
endif
########################################################################################
########################################################################################
########################################################################################

all: $(NAME)

ifeq ($(patsubst %.a,,$(lastword $(NAME))),)
$(NAME): $(OUT)
	@$(call run_and_test, ar rc $(NAME) $(OUT),$(YELLOW)Compacting)
	@ranlib $(NAME)
else
$(NAME): $(OUT)
	@$(call run_and_test, $(CC) $(CC_OPTIONS) -o $(NAME) $(OUT),$(YELLOW)$(COM_STRING))
endif

$(OBJ_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(call run_and_test, $(CC) $(CC_OPTIONS) -o $@ -c $<,$(COM_COLOR)$(COM_STRING))

$(OBJ_FOLDER)/%.o: $(SOURCES_FOLDER)/*/%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(call run_and_test, $(CC) $(CC_OPTIONS) -o $@ -c $<,$(COM_COLOR)$(COM_STRING))

$(OBJ_FOLDER)/%.o: $(SOURCES_FOLDER)/*/*/%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(call run_and_test, $(CC) $(CC_OPTIONS) -o $@ -c $<,$(COM_COLOR)$(COM_STRING))

clean:
	@printf "%b" "$(RED)Remove folder $(MAGENTA)$(OBJ_FOLDER)$(NO_COLOR)\n";
	@printf "%b" "$(RED)Remove file   $(MAGENTA)$(TEST_NAME)$(NO_COLOR)\n";
	@rm -rf $(OBJ_FOLDER)
	@rm -f $(TEST_NAME)

fclean: clean
	@printf "%b" "$(RED)Remove file   $(MAGENTA)$(NAME)$(NO_COLOR)\n";
	@rm -rf $(NAME)

re: fclean all

git: fclean
	@printf "%b" "$(GREEN)Clean all .DS_Store$(NO_COLOR)\n";
	@find . -name ".DS_Store" -delete
	@git add -A
	@git status
	@git commit -a -m $(MESSAGE_COMMIT)
	@git push origin master

test:
	make all
	gcc $(CC_OPTIONS) -I . -o $(TEST_NAME) tests/ft_printf_test_.c $(NAME)
	./$(TEST_NAME)
