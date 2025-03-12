# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:09:01 by dinepomu          #+#    #+#              #
#    Updated: 2025/03/12 15:22:35 by dinepomu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############################################################################ #
#                                 MAKEFILE                                     #
# ############################################################################ #

#1. DESCRIPTION:
#	This is make file for build either PROGRAM, LIBRARY, PROGRAM+LIBRARY 
#		with their dependecies connect.
#
# - This Makefile is a template for a project with the following structure:
#	1. Headers.h, files all them must be placed inside the folder "include".
#	2. Library.a, files all them must be inside of the folder "libs"
#	3. The library makefile must be inside of the folder "libs/mylib"

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                          VARIABLES INITIALIZATIONS                           #
# ############################################################################ #
# ************************************************************************ #
MAKEFLAGS :=

# *** Name Output *** #
NAME0 = checker

# *** ../ or ../../ or empty *** # Libraries autocmactly already have the ../
OUTPUT_PLACE = ../../

# ***Is? *** #
IS_PROGRAM_AND_NOT_LIB = 1
INCLUDE_LIB = 1
BUILD_LIBRARY = 1
BONUS = 0

# ************************************************************************ #
# *** Files source *.c *** #
SOURCE_MAIN =									\
					checker_bonus.c					\

SOURCE_FILES = 								\

#SOURCE_MAIN = $(wildcard src/*.c) $(wildcard src/*/*.c)

VPATH = src:							\

# *** Extra Rules (Bonus) *** #
CHECKER_BONUS_DIR =
CHECKER_BUILD = $(MAKE) -C $(CHECKER_BONUS_DIR)

# *** DEBUG MAKE? *** #
MAKEFLAGS += --silent

# ************************************************************************ #
# *** Library *.a (libraries to be included) THE ORDER MATTERS!!! *** #
LIBS_DIR = libs
LIB_2_NAME = mylibc
LIB_2_PATH = $(LIBS_DIR)/$(LIB_1_NAME)
LIB_1_NAME = push_swap
LIB_1_PATH = $(LIBS_DIR)/$(LIB_1_NAME)
LIB_1_BUILD_PATH = ../../

# *** Include or not a library (REMEBER TO MANAGE DEPENDECIES OF THE LIBRARIES, the root library comes after the child)
LDFLAGS +=
ifeq ($(INCLUDE_LIB), 1)
	LDFLAGS += -L$(LIBS_DIR) -l$(LIB_1_NAME)
	LDFLAGS += -l$(LIB_2_NAME)
endif

# *** Type of the Lib *** #
#IS_LIB_STATIC_AND_NOT_DYNAMIC = 1

# *** HEADERS *.h *** #
CFLAGS_INCL = -Iinc -Ilibs/$(LIB_1_NAME)/inc

# ************************************************************************ #
# *** Compiler, Make and Library compilers Declar *** #
MAKE = make -j#												# Number of jobs to run simultaneously amout of cores in the CPU wihtou the numbers it takes the max
MAKE += -O --no-print-directory
#MAKE += --trace all --warn-undefined-variables
#MAKE += --debug=b -j1 --warn-undefined-variables
#MAKE += --debug=v -j1 --warn-undefined-variables
#MAKE += --debug=t -j1 --warn-undefined-variables

COMPILER = clang
LIB_COMP_STATIC = ar rcs
#LIB_COMP_DYNAMIC_obj = fPIC
#LIB_COMP_DYNAMIC_lib = shared
RM = rm -rf
CFLAG_ASAN =
CFLAGS_DBG = -g3 -o0

# ############################################################################ #
#                                 HELPERS                                      #
# ############################################################################ #
# ************************************************************************ #
# *** Name definition *** #
NAME1 = $(OUTPUT_PLACE)$(NAME0)

ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	NAME = $(NAME1)
else
	NAME = ../lib$(NAME1).a
endif

# *** Source Files .c Definition path *** #
SOURCES = $(SOURCE_MAIN) $(SOURCE_FILES)


# ************************************************************************ #
#                         OBJECTS AND DEPENDENCIES                         #
# ************************************************************************ #
#Object Files and Dependency Files Definition path Main *** #
OBJECTS_MAIN =  $(patsubst %.c,objs/%.o,$(notdir $(SOURCE_MAIN)))
DEPS_MAIN = $(OBJECTS_MAIN:.o=.d)
DEPFLAGS = -MMD -MP#															# This will create the files(headers) as dependendcy and track them
-include $(DEPS_MAIN)

#Object Files and Dependency Files Definition path Lib *** #
OBJECTS_LIB =  $(patsubst %.c,objs/%.o,$(notdir $(SOURCE_FILES)))
DEPS_LIB = $(OBJECTS_LIB:.o=.d)
#DEPFLAGS = -MMD -MP#															# This will create the files(headers) as dependendcy and track them
-include $(DEPS_LIB)

OBJECTS = $(OBJECTS_MAIN) $(OBJECTS_LIB) 

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                 RULES/ALL                                    #
# ############################################################################ #
.DEFAULT_GOAL:= build

# *** Default rule *** #
build:
	$(MAKE) hello
	$(MAKE) folders_build
#	$(MAKE) folders_lns_build
	$(MAKE) libs_build
	$(MAKE) program_or_lib

# *** Compiling the source files into object files *** #
objs/%.o:	%.c
	mkdir -p objs
	$(COMPILER) $(CFLAGS_DBG) $(CFLAG_ASAN) $(CFLAGS_INCL) $(DEPFLAGS) -c $< -o $@
	@echo "$(GRAY)()و $@ $(NAME) Compiling Objects !$(RESET)"

program_or_lib:
	if [ ! -f "$(NAME)" ]; then \
		echo "$(RED)No binary found$(RESET)"; \
		touch src ; \
	fi;

# *** Build the library included (MAKEFLAGS="" this not inherit env variables from father*** #
libs_build:
ifeq ($(BUILD_LIBRARY), 1)
	$(MAKE) -C $(LIB_1_BUILD_PATH) MAKEFLAGS=""
#	$(MAKE) -C $(LIB_2_PATH) MAKEFLAGS=""
	@echo "$(YELLOW)(•̀ᴗ•́)و $@ Done!$(RESET)"
else
#	@echo "$(GRAY)Skipping library build$(RESET)"
endif

# *** Is program or a Lib? *** #
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	echo "  $(YELLOW)Linking a Program$(RESET)"
	$(MAKE) LIB_OUTPUT="libs/lib$(NAME0).a" lib
	$(MAKE) program
else
	echo "  $(YELLOW)Linking a Lib$(RESET)"
	$(MAKE) LIB_OUTPUT=$(NAME) lib
endif


# *** Linking the object files into a library *** #
lib:	$(OBJECTS_LIB)
	$(LIB_COMP_STATIC) $(LIB_OUTPUT) $(OBJECTS_LIB)
	@echo "  $(YELLOW)(•̀ᴗ•́)و lib$(NAME).a LIBRARY GENERATED!$(RESET)"

# *** Linking the object files into the program *** #
program:	$(OBJECTS)
	$(COMPILER) $(OBJECTS_MAIN) -Llibs -l$(NAME0) $(LDFLAGS) $(CFLAG_ASAN) -o $(NAME)
	@echo "  $(YELLOW)(•̀ᴗ•́)و $(NAME) Bin Generated!$(RESET)"
	$(MAKE) check_up_to_date

# *** Combine the program library with the included libraries *** #
combine_libs:
ifeq ($(INCLUDE_LIB), 1)
	$(MAKE) libs_build
	$(LIB_COMP_STATIC) lib$(NAME1)_c.a $(NAME) libs/lib$(LIB_1_NAME).a
	@echo "$(YELLOW)(•̀ᴗ•́)و $@ Done!$(RESET)"
else
	@echo "$(GRAY)Skipping library merge$(RESET)"
endif

# *** Phony *** #
.PHONY:		all build program_or_lib libs_build					\
			clean fclean fclean_all re 							\
			library_clean library_fclean library_re 			\
			folder_lns_builder folders_build check_up_to_date 	\
			hello debug 										\
			werror norm_1 norm_2 log_all werror_bonus			\
			testing_alles test_export 							\
			make_dbg create_bins								\
			leaks valgrind asan time_and_perfomance				\
			help bonus											\
			bonus bonus_re										\
			run_visualizer										\

#NOT PHONY:	program lib

# ############################################################################ #
#                                 RULES/RECLEAN                                #
# ############################################################################ #
# *** Clean Objects only *** #
clean:
	$(RM) objs
ifeq ($(BONUS),1)
	$(MAKE) clean -C $(CHECKER_BONUS_DIR)
endif
	@echo	"$(RED)	¯\_(ツ)_/¯ OBJECTS REMOVED!$(RESET)"

# *** Clean+Bins+Libs *** #
fclean:	clean
	$(RM) $(NAME)
	$(RM) libs/lib$(NAME1).a
	$(RM) testers
	$(RM) libs/lib$(NAME0)_g.a
	$(RM) libs/lib$(NAME0)_asan.a
	$(RM) libs/lib$(NAME0)_g3.a
ifeq ($(BONUS),1)
	$(MAKE) fclean -C $(CHECKER_BONUS_DIR)
endif
	@echo	"$(RED)	¯\_(ツ)_/¯ OBJECTS REMOVED!$(RESET)"
	@echo	"$(RED)		(╯°□°）╯︵ ┻━┻ FILE, OBJ REMOVED!$(RESET)"

# *** FClean+Build *** #
re: fclean build

# *** FClean+logs_folder *** #
fclean_all:	fclean
	$(RM) log
	if [ -f imgui.ini ]; then \
		rm imgui.ini; \
	fi
	@echo	"$(RED)			(╯°□°）╯︵ ┻━┻ FILE, OBJ AND LOG REMOVED!$(RESET)"

# *** Re_all *** #
re_all: fclean_all build

# ############################################################################ #
#                                EXTRAS		                                   #
# ############################################################################ #
# *** Bonus Rule *** #
bonus:
	$(MAKE)
	$(MAKE) -C $(CHECKER_BONUS_DIR)

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                LOG ALLES                                     #
# ############################################################################ #
# *** Log Alles *** #
log_alles:
	$(MAKE) || true
	$(MAKE) bonus || true
	$(MAKE) warning_linting || true
	$(MAKE) leaks || true
	$(MAKE) test_build || true
	$(MAKE) testing_alles || true
	$(MAKE) debuggers_info || true

#build:
#	$(MAKE) hello
#	$(MAKE) check_up_to_date
#	$(MAKE) folders_build
#	$(MAKE) libs_build
#	$(MAKE) program_or_lib

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                 LINTING                                      #
# ############################################################################ #
# *** Liting analyzer *** #
warning_linting:
	$(MAKE)
	$(MAKE) bonus
	$(MAKE) werror
	$(MAKE) norm
	$(MAKE) norm_bonus
	$(MAKE) werror_bonus
#	$(MAKE) clang_tidy_fix


# *** Wall Wextra *** #
werror:
	@echo "$(GREEN)\n·Clang Litings$(RESET)"
	echo "\n##Clang Wall Wextra - fsyntaxOnly"
	echo "############################################\n"
	$(MAKE) CFLAGS_DBG=" -Wall -Wextra" 2>&1 | sed 's/\x1b\[//g'| sed 's/\0;93m//g'| sed 's/\0;90m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' > log/1.Warning_Linting/clang_www.txt

	@echo "\n##Clang Fron-End Semantic Wcore - fsyntaxOnly"
	echo "############################################\n"
	$(MAKE) CFLAGS_DBG="-Wformat -Warray-bounds -Wnull-dereference -Wvla -ftrapv" 2>&1 | sed 's/\x1b\[//g' | sed 's/\0;93m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' > log/1.Warning_Linting/clang_wcore.txt

	@echo "\n##Clang Fron-End Semantic wEverything - fsyntaxOnly"
	echo "############################################\n"
	$(MAKE) CFLAGS_DBG="-Weverything" 2>&1 | sed 's/\x1b\[//g' | sed 's/\0;93m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' > log/1.Warning_Linting/clang_wevery.txt

	@echo "\n##Clang Fron-End Semantic Clang-Tidy - fsyntaxOnly"
	echo "############################################\n"
	clang-tidy $(SOURCE_MAIN) $(SOURCE_FILES) 2>&1 | sed 's/\x1b\[//g' | sed 's/\0;93m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' > log/1.Warning_Linting/clang_tidy.txt
	
	@echo "\n###Clang Static Analyzer Wcore"
	echo  "#########################\n"
	$(MAKE) CFLAGS_DBG="--analyze -Xanalyzer -analyzer-checker=core" 2>&1 | sed 's/\x1b\[//g' | sed 's/\0;93m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' | tee log/1.Warning_Linting/clang_analyzer.txt

# *** Norminette on Project*** #
norm:
	@echo "$(GREEN)\n····Running Norminette····$(RESET)"
	norminette src/push_swap > log/1.Warning_Linting/norminette.txt; \
	norminette inc >> log/1.Warning_Linting/norminette.txt ; cat log/1.Warning_Linting/norminette.txt

# *** Norminette on Bonus*** #
norm_bonus:
	@echo "$(GREEN)\n····Running Norminette····$(RESET)"
	norminette src/checker_bonus > log/1.Warning_Linting/norminette_bonus.txt ; cat log/1.Warning_Linting/norminette_bonus.txt \

werror_bonus:
	@echo "$(GREEN)\n·Clang Litings$(RESET)"
	echo "\n## BONUS Clang Wall Wextra - fsyntaxOnly"
	echo "############################################\n"
	$(CHECKER_BUILD) CFLAGS_DBG="-Wall -Wextra" || true > log/1.Warning_Linting/bonus_clang_www.txt
	@echo "\n## BONUS Clang Fron-End Semantic - fsyntaxOnly"
	echo "############################################\n"
	$(CHECKER_BUILD) CFLAGS_DBG="-Wformat -Warray-bounds -Wnull-dereference -Wvla -ftrapv" 2>&1 | sed 's/\x1b\[//g' | sed 's/\0;93m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' > log/1.Warning_Linting/bonus_clang_wevery.txt
	@echo "\n### BONUS Clang Static Analyzer"
	echo  "#########################\n"
	$(MAKE) CFLAGS_DBG="--analyze -Xanalyzer -analyzer-checker=core " 2>&1 | sed 's/\x1b\[//g' | sed 's/\0;93m//g'| sed 's/\0;92m//g'| sed 's/\0;39m//g' | tee log/1.Warning_Linting/bonus_clang_analyzer.txt

clang_tidy_fix:
		clang-tidy $(SOURCE_MAIN) $(SOURCE_FILES) --fix

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                 LEAKS                                        #
# ############################################################################ #
# *** Leaks analyzer *** #
leaks:
	mkdir -p log/4.Bins_folder
	$(MAKE) create_bins_leaks
	$(MAKE) valgrind
	$(MAKE) asan

# *** Create bins for the leaks analyzer *** #
.PHONY: create_bins_leaks
create_bins_leaks: log/4.Bins_folder/${NAME0}_g $(OBJECTS)
log/4.Bins_folder/$(NAME0)_g: $(OBJECTS)

# *** _g *** #
	$(MAKE) CFLAGS_DBG=" -g" OUTPUT_PLACE="log/4.Bins_folder/" NAME0=$(NAME0)_g

# *** Asan *** #
	$(MAKE) CFLAG_ASAN=" -g -fsanitize=address -fno-omit-frame-pointer" OUTPUT_PLACE="log/4.Bins_folder/" NAME0=$(NAME0)_asan

# *** BONUS _g *** #
	$(MAKE) CFLAGS_DBG=" -g" OUTPUT_PLACE="log/4.Bins_folder/" NAME0=$(NAME0)_g -C $(CHECKER_BONUS_DIR)


# *** Runing Valgrind *** #
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s
valgrind:
	$(MAKE) create_bins_leaks
	@echo "$(RED)\n# RUNNING VALGRIND: ERROR_HANDLING_INPUTS$(RESET)"
	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	@echo "$(BOLD)\n# RUNNING VALGRIND ARG_EMPTY$(RESET)"
	
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_empty.txt ./log/4.Bins_folder/push_swap_g $(ARG_EMPTY) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_empty.txt && echo "1. Empty: ok" > log/2.Memory_Check/Valgrind_Report.txt || true

	@echo "$(BOLD)\n# RUNNING VALGRIND ARG_ONE$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_one.txt ./log/4.Bins_folder/push_swap_g $(ARG_1) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_one.txt && echo "2. One: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	
	@echo "$(BOLD)\n# RUNNING VALGRIND INT_MAX$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_intmax.txt ./log/4.Bins_folder/push_swap_g $(ARG_INT_MAX) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_intmax.txt && echo "3. INT_MAX: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	
	@echo "$(BOLD)\n# RUNNING VALGRIND INT_MIN$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_min.txt ./log/4.Bins_folder/push_swap_g $(ARG_INT_MIN) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_min.txt && echo "4. INT_MIN: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	
	@echo "$(BOLD)\n# RUNNING VALGRIND ARG_SORTED$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_sort.txt ./log/4.Bins_folder/push_swap_g $(ARG_SORTED) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_sort.txt && echo "5: Sort: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	
	@echo "$(BOLD)\n# RUNNING VALGRIND ARG_DUPLICATED$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_dupl.txt ./log/4.Bins_folder/push_swap_g $(ARG_DUPLICATED) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_dupl.txt && echo "6. Dupl: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	
	@echo "$(BOLD)\n# RUNNING VALGRIND ARG_NON_NUMERIC$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_error_handling_nonnum.txt ./log/4.Bins_folder/push_swap_g $(ARG_NON_NUMERIC) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_error_handling_nonnum.txt && echo "7. Alpha: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	
	@echo "$(RED)\n# RUNNING VALGRIND: PERFORMANCE_CHECK$(RESET)"
	@echo "---------------------------------------------------------------------------------------------------------------------------"
	
	@echo "$(BOLD)\n# RUNNING VALGRIND 5 NUMBERS$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_5.txt ./log/4.Bins_folder/push_swap_g $(ARG_5)  2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_5.txt && echo "8. ARG_5: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true

	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	
	@echo "$(BOLD)\n# RUNNING VALGRIND 6 NUMBERS$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_6.txt ./log/4.Bins_folder/push_swap_g $(ARG_6) 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_6.txt && echo "9. ARG_6: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true
	
	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	
	@echo "$(BOLD)\n# RUNNING VALGRIND 6 NUMBERS_NO_SPLIT$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_6_not_split.txt ./log/4.Bins_folder/push_swap_g 0 9 1 8 2 6 2>&1 || true
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_push_6_not_split.txt && echo "10. ARG_6_Nsplit: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true

	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	
	@echo "$(BOLD)\n# RUNNING VALGRIND ON CHECKER$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_checker_6.txt ./log/4.Bins_folder/push_swap_g $(ARG_6) | ./log/4.Bins_folder/checker_g $(ARG_6)
	@grep -q "All heap blocks were freed -- no leaks are possible" log/2.Memory_Check/logs/valgrind_report_checker_6.txt && echo "11. ARG_6 Checker: ok" >> log/2.Memory_Check/Valgrind_Report.txt || true

	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	
	@echo "$(BOLD)\n# RUNNING VALGRIND MASSIF && CACHEGRIND && CALLGRIND$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"

# *** Massif Target  *** #
	valgrind --tool=massif --massif-out-file=log/2.Memory_Check/logs/val_massif.out ./log/4.Bins_folder/push_swap_g $(ARG_6)
	ms_print log/2.Memory_Check/logs/val_massif.out > log/2.Memory_Check/logs/val_massif_report.txt
# *** Cachegrind Target *** #
	valgrind --tool=cachegrind --cachegrind-out-file=log/2.Memory_Check/logs/val_cachegrind.out ./log/4.Bins_folder/push_swap_g $(ARG_6)
# *** Callgrind Target *** #
	valgrind --tool=callgrind --callgrind-out-file=log/2.Memory_Check/logs/val_callgrind.out ./log/4.Bins_folder/push_swap_g $(ARG_6)

#	@echo "";
#	ARG="50000000 400000000 -300000000 200000000 100000000 -42";\
#	echo "$(YELLOW)1. 6 numbers VALGRIND PUSH(ARG)$(GREEN)" ;
#	$(VALGRIND) --log-file=log/2.Memory_Check/logs/valgrind_report_push_6.txt ./log/4.Bins_folder/push_swap_g $$ARG > /dev/null ; \
	awk 'NR >= 8' log/2.Memory_Check/logs/valgrind_report_push_6.txt

# *** runing Asan *** #
asan:
	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	@echo "$(BOLD)\n# RUNNING ASAN$(RESET)"
	@for i in $(shell seq 1 100); do printf "$(GREEN)▓";sleep 0.0001; done; echo " ✓$(RESET)"
	export ASAN_OPTIONS="halt_on_error=0:log_path=log/2.Memory_Check/logs/Asan_report.txt";
	./log/4.Bins_folder/push_swap_asan $(ARG_6)
	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"
	export ASAN_OPTIONS="halt_on_error=0:log_path=log/2.Memory_Check/logs/Asan_report_2.txt";
	./log/4.Bins_folder/push_swap_asan "5 4 3 2 1 5"
	@echo "$(RESET)---------------------------------------------------------------------------------------------------------------------------"

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                DEBUGGERS                                     #
# ############################################################################ #
# *** Debuggers *** #
debuggers:
	$(MAKE) create_bins_dbg
	$(MAKE) debuggers_info

# ************************************************************************ #
#                                                                          #
# ************************************************************************ #
# *** Create the bin for G3 debugging *** #
create_bins_dbg: log/4.Bins_folder/$(NAME1)_g3
log/4.Bins_folder/$(NAME1)_g3: $(OBJECTS)
# *** debugging _g3 *** #
	$(MAKE) CFLAGS_DBG=" -g3" OUTPUT_PLACE="log/4.Bins_folder/" NAME0=$(NAME0)_g3
	cd log/4.Bins_folder
	ln -s ../../src/push_swap/main/push_swap.c log/4.Bins_folder/push_swap.c || true
	ln -s ../../src/checker_bonus/src/checker_bonus.c log/4.Bins_folder/checker_bonus.c || true

.PHONY: create_bins_dbg

# *** Librarys info and make=debug *** #
debuggers_info:
	$(MAKE) libs_nm_art
#	$(MAKE) make_dbg


libs_nm_art:
	nm libs/lib$(LIB_1_NAME).a > log/5.Libs_nmart/lib$(LIB_1_NAME)_nm.txt
	ar t libs/lib$(LIB_1_NAME).a > log/5.Libs_nmart/lib$(LIB_1_NAME)_art.txt
	nm libs/lib$(NAME1).a > log/5.Libs_nmart/lib$(NAME1)_nm.txt
	ar t libs/lib$(NAME1).a > log/5.Libs_nmart/lib$(NAME1)_art.txt

make_dbg:
	$(MAKE) -d > log/6.Make_dbg/make_d.txt
	$(MAKE) CFLAGS_DBG="-v" > log/6.Make_dbg/clang_v.txt
	$(MAKE) --debug=b -j1 re > log/6.Make_dbg/make_debug_b.txt
	$(MAKE) --debug=v -j1 re > log/6.Make_dbg/make_debug_v.txt

# ************************************************************************ #
#                                 RUN DEBUGGER                              #
# ************************************************************************ #
# *** Command to run especif debug *** #
ARG_DBG = "500 400 300 200 100 1000"
debug: $(MAKE) CFLAGS="$(CFLAGS) -g3" $(NAME)
	lldb ./$(NAME) -o "b main" -o run -o gui -o "run $(ARG_DBG)" 

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                             TESTING_ALLES                                    #
# ############################################################################ #
# *** Command to run all tests *** #
testing_alles:
	$(MAKE) testers_folder_build
	$(MAKE) bonus
	$(MAKE) tests_run
	$(MAKE) create_bins_dbg

# ************************************************************************ #
#                               TESTERS_FOLDER                             #
# ************************************************************************ #
# *** Folder builder testers *** #
testers/testers.tar.gz:
	pipx install gdown
	mkdir -p testers
	gdown 'https://drive.google.com/uc?id=10rQ0zUPZZFOO4epDa62sx_2kUUrl1EFo' -O $@
#https://drive.google.com/file/d/10rQ0zUPZZFOO4epDa62sx_2kUUrl1EFo/view?usp=sharing

testers: testers/testers.tar.gz
		tar -xzf $< -C .

checker_linux: testers
testers_folder_build: checker_linux
.PHONY: test_run

# ************************************************************************ #
#                                   TESTS RUN                              #
# ************************************************************************ #
# *** Inputs for the tests *** #
ARG_EMPTY=""
ARG_1="2147483647"
ARG_INT_MAX="2147483648 3 2 1"
ARG_INT_MIN="-2147483649 3 2 1"
ARG_SORTED="1 2 3 4 2147483647"
ARG_DUPLICATED=	"5 4 3 2 1 1"
ARG_NON_NUMERIC="a 1 3 4 5"
ARG_2="0 9"
ARG_3="0 9 2"
ARG_4="0 9 2 8"
ARG_5="0 9 2 8 3"
ARG_6="0 9 2 8 3"
ARG_6_=0 9 2 8 3
ARG_100="212710023 986781593 -696505162 -697772949 163158489 20730884 -974873791 433823587 -821700607 -577271177 -845816937 642872502 -38427609 379698130 542919419 94513872 802435190 256366261 -388868047 523305894 902033793 361493411 -312892761 238798632 -544395033 -916888931 857242650 -938149113 937859398 782299023 -152438703 105436742 484415778 -497421154 -965438810 275733505 -42903052 -283624876 -155530411 -584589099 248953144 267090942 249014822 709393969 -532736522 269785342 -626217395 558457329 -231801523 -745034309 -205138703 952480231 489930891 -837976400 193590696 902970108 -161884624 715769492 460247859 658382120 869373884 -345009361 166265788 -712307688 26099976 490666783 -897464550 -918369107 25978938 -580570130 -27390761 117409894 969627571 -473690591 -480042277 -57613226 -622657768 -274858784 -56062030 -927729186 -561021644 -234588375 -92249412 449515401 -187714857 -629146709 -29880497 -962559720 645723247 457172511 -987311436 -76781137 -646421526 765798094 -574146273 -330402836 475003585 48881686 971109339 -20600967"
ARG_500="161644880 79101196 -466814793 -136237612 289155967 -915290009 187996535 -620305300 768941090 209423567 406389564 339485405 -841947060 570422808 41725038 260838117 810165583 -251302402 -510877702 -587941708 -731803947 -627589912 -207929780 469299828 -479290036 -877960023 285774390 501117398 763026145 603420191 -507794776 176682860 -640954253 74234638 -15997564 -887983311 562140182 308118552 887848896 669538918 950093577 617068602 531847363 -792582653 -77040018 870451556 625283177 261351482 141129587 803633397 -330340165 667428520 785457292 571922187 -782794423 -802816722 -683026066 919309372 -623446542 355689038 427289389 -934507655 -38247998 367858134 -611462990 -597094177 -417149016 -482587791 324321748 626420042 -359407106 -407505611 -457866678 274628619 -841615865 609751077 474287630 -287111167 379504434 114257693 -834686866 -370125434 -394096303 423347718 -644901407 561020861 -143033136 -454635491 231991268 -664899721 494705719 82128013 -711388079 -966296234 -267829945 -819045949 -538880791 -703904929 -626692262 -860149272 -203633348 747525528 -969136087 259093531 -768944417 -945117429 -704982450 -746846007 347567388 249491699 -613443167 215268882 874177629 977470375 -4814957 577608043 968928427 462614235 862140293 683013595 -993205564 312581545 -113663522 758888883 -181131845 -924700952 -283977535 961691252 294330991 396189796 863513726 -3790587 -863582760 -809672150 -538591658 -917624912 272783698 -522947724 -478594890 -162813257 -101758788 -818309818 90074991 -48269407 755668349 -662672856 -420644362 892690322 853151450 126389795 125117456 -717414847 -920020012 -952011812 -415417376 -398364584 -52757598 -579410193 -352627123 137137703 -94299217 -888016985 133278824 -242142994 -904594645 -898836400 -172600279 -731044332 810794363 308939113 604576193 -714780899 959275933 46530445 -678372156 157774698 529914035 -673421674 267572305 -787174642 594091757 -176435755 662347888 216211021 801555595 204135619 827097079 333256900 -524176077 -17551780 -534471280 572635216 -250360985 406750389 643682476 192863096 -318342502 798439242 -644281906 171317597 887885292 834979650 416306247 122599091 -668792859 847067263 804303245 -166977681 -641795388 796859494 232540272 578959862 666421127 794519908 687983624 -223355753 -829597237 -429471023 -552889315 792634358 -924104340 709167110 -17990542 855203653 -361513174 235857788 -165481375 -702770858 -953907424 122781780 786147219 -473109184 -849788760 125390237 131636521 873211891 -608038749 552010333 666934094 -866475426 291525318 732597253 117311604 -880574080 278682430 -140673993 -512792166 809057277 250282902 714859944 896619495 615393842 -619146905 642557243 -446509263 -52791236 -580297002 -61922720 -448898118 608729523 649968030 191749510 -340687307 -13190096 250438328 480555808 215324645 452469709 -208001802 -868147633 437557168 -544444097 750346053 306354436 204733991 -643533635 632545180 639376495 -293347984 349476412 903934402 213901862 90315576 577616438 -155603111 962658096 -489333019 876820374 800425104 685357798 516821635 -710276879 119408617 198479358 551304105 -143482777 -707261683 -232121475 -515658696 878001821 -405920881 696358602 -110714173 860984306 -152511967 273112199 675065036 -893177813 -15248781 17560273 -106856378 313146529 890271551 -710897467 673229348 -961936766 302550309 588154609 821843516 714074481 126835627 -611444101 911564625 471747403 614879350 -986286370 83368884 611777120 -518272177 -297221486 809010932 -515975535 978191207 157252017 -548908080 9680354 855785387 845397903 95452042 863091565 963616016 -375712063 -678978176 283310827 -939975248 480888381 -583099335 -922229523 916914330 -321370203 -82876620 -612614569 -379969716 387010968 815131556 -800352553 755703986 961995648 877130545 -595342010 227378411 388108927 -39824946 582501825 708537734 -348470361 908414786 835924964 -913523673 226580451 382983683 -541850768 521324496 -367968827 -328193261 -374432175 -257512933 -767586852 -302926107 483870969 -1207662 -924413095 773774117 -449882153 -826294184 -42886208 -216963084 356375919 -606841392 -544416045 -230338449 -361498154 -583491160 -372938809 -221308582 -494253200 546852756 621050344 -444934934 546797973 -986490790 708414053 -495974651 77114442 362064023 -775901245 -447114026 -839057876 -735702703 909348641 -297248286 -389793416 -87550083 -429931665 189700273 864043299 804251865 693522198 528680720 5098703 -757755804 -218931420 -154608868 445169960 65197690 -319275534 804762641 104811235 -159637369 569981758 435801158 -853775772 -728310828 -578958528 45172399 988602854 -863555460 -662003754 950655992 560976427 -677902043 516242518 -797920541 500468548 -516094769 -655597739 782801784 969638197 651707831 989991387 996233440 -773647353 94601891 565515848 -110681027 -309856422 164339253 684791262 -46681030 645466380 64093137 -640453668 25310470 838191551 -723725662 -584957724 936461607 -377139041 -430318531 -61913054 -646140255 931367166 248910485 275065908 371527256 4182481 806519972 -996943141 -621961312 622612051 276310498 702294721 -431024372 323830662 -104745217 345693478 580516783 -570078232 -193873589 -595756840 842653932 798996585 -488184149 -316887408 665671629 -836836424 901437480 -472366489 -364515282 890372178"

# *** Run only the tests *** #
i=1
tests_run:
	@echo "$(RED)\n# RUNNING TESTS$(RESET)"
	@echo ""
	@echo "$(BOLD)### Milestones$(RESET)"
	@echo "Points for #5 numbers:"
	@echo "- less than 8: kudos"
	@echo "- less than 12: ok"
	@echo "- more than 12; FAIL!"
	@echo ""
	@echo "Points for #100 numbers:"
	@echo "- less than 700: 5"
	@echo "- less than 900: 4"
	@echo "- less than 1,100: 3"
	@echo "- less than 1,300: 2"
	@echo "- less than 1,500: 1"
	@echo ""
	@echo "Points for #500 numbers"
	@echo "- less than 5,500: 5"
	@echo "- less than 7,000: 4"
	@echo "- less than 8,500: 3"
	@echo "- less than 10,000: 2"
	@echo "- less than 11,500: 1"
	@echo ""
	@echo "Min Points: 8"
	@echo "---------------------------------------------------------------------------------------------------------------------------"
	echo"";
	-echo -n "$(GRAY)A ERROR_HANDLING_INPUTS $(RESET)"; echo"";
	-echo -n "$(YELLOW)a1. ARG_DUPLICATED$(GREEN): | " ; ./push_swap $(ARG_DUPLICATED) 2>&1  | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_DUPLICATED) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a2. ARG_NON_NUMERIC$(GREEN): | " ; ./push_swap $(ARG_NON_NUMERIC) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_NON_NUMERIC) 2>&1  | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a3. ARG_INT_MAX$(GREEN): | " ; ./push_swap $(ARG_INT_MAX) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_INT_MAX) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a4. ARG_INT_MIN$(GREEN): | " ; ./push_swap $(ARG_INT_MIN) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_INT_MIN) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(GRAY)A ERROR_HANDLING_INPUTS2 $(RESET)"; echo"";
	-echo -n "$(YELLOW)a5. ARG_EMPTY $(GREEN): | " ; ./push_swap $(ARG_EMPTY) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_EMPTY) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_EMPTY) 2>&1; echo "";
	-echo -n "$(YELLOW)a6. ARG_1$(GREEN): | " ; ./push_swap $(ARG_1) 2>&1 |  tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_1) | wc -l 2>&1 | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a7. ARG_SORTED$(GREEN): | " ; ./push_swap $(ARG_SORTED) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_SORTED) | wc -l | tr '\n' ' ' ; echo -n " | " ;  echo "";echo "";
	-echo -n "$(GRAY)A ERROR_HANDLING_INPUTS3 $(RESET)"; echo"";
	-echo -n "$(YELLOW)b1. ARG_5_NOT_SPLIT$(GREEN): | " ; ./push_swap 0 9 2 8 -3 2>&1 | ./testers/checker_linux 0 9 2 8 -3 | tr '\n' ' ' ; echo -n " | " ; ./push_swap 0 9 2 8 3 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)b1. ARG_6_NOT_SPLIT$(GREEN): | " ; ./push_swap 0 9 2 8 3 -42 2>&1 | ./testers/checker_linux 0 9 2 8 3 -42 | tr '\n' ' ' ; echo -n " | " ; ./push_swap 0 9 2 8 3 -42 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	echo"";
	-echo -n "$(GRAY)B PERFORMANCE_CHECK $(RESET)"; echo""
	-echo -n "$(YELLOW)b1. ARG_2$(BLUE): | " ; ./push_swap $(ARG_2) 2>&1 | ./testers/checker_linux $(ARG_2) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_2) | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_2) > log/3.Unit_Testing/moves_2.txt; echo "";
	-echo -n "$(YELLOW)b1. ARG_3$(BLUE): | " ; ./push_swap $(ARG_3) 2>&1 | ./testers/checker_linux $(ARG_3) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_3) | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_3) > log/3.Unit_Testing/moves_3.txt; echo "";
	-echo -n "$(YELLOW)b1. ARG_4$(BLUE): | " ; ./push_swap $(ARG_4) 2>&1 | ./testers/checker_linux $(ARG_4) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_4) | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_4) > log/3.Unit_Testing/moves_4.txt; echo "";
	-echo -n "$(YELLOW)b1. ARG_5$(BLUE): | " ; ./push_swap $(ARG_5) 2>&1 | ./testers/checker_linux $(ARG_5) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_5) | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_5) > log/3.Unit_Testing/moves_5.txt; echo "";
	-echo -n "$(YELLOW)b2. ARG_100$(BLUE): | " ; ./push_swap $(ARG_100) 2>&1 | ./testers/checker_linux $(ARG_100) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_100) | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_100) > log/3.Unit_Testing/moves_100.txt; echo "";
	-echo -n "$(YELLOW)b3. ARG_500$(BLUE): | " ; ./push_swap $(ARG_500) 2>&1 | ./testers/checker_linux $(ARG_500) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_500) | wc -l | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_500) > log/3.Unit_Testing/moves_500.txt; echo "";
	echo""
	-echo -n "$(GRAY)B PERFORMANCE_CHECK_BONUS $(RESET)"; echo""
	-echo -n "$(YELLOW)b3. ARG_500 && CHECKER_BONUS$(GREEN): | " ; ./push_swap $(ARG_500) | ./checker $(ARG_500) | tr '\n' ' ' ; echo -n " | " ; ./push_swap $(ARG_500) | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	echo"";
	-echo -n "$(GRAY)C ERROR_HANDLING_INPUTS_BONUS $(RESET)"; echo"";
	-echo -n "$(YELLOW)a1. ARG_INT_MAX$(GREEN): | " ; ./checker $(ARG_INT_MAX) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_INT_MAX) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | "  ; echo "";
	-echo -n "$(YELLOW)a2. ARG_INT_MIN$(GREEN): | " ; ./checker $(ARG_INT_MIN) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_INT_MIN) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a3. ARG_DUPLICATED$(GREEN): | " ; ./checker $(ARG_DUPLICATED) 2>&1  | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_DUPLICATED) 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a4. ARG_NON_NUMERIC$(GREEN): | " ; ./checker $(ARG_NON_NUMERIC) 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_NON_NUMERIC) 2>&1  | wc -l | tr '\n' ' ' ; echo -n " | "; echo "";
	-echo -n "$(GRAY)C ERROR_HANDLING_INPUTS_2_BONUS $(RESET)"; echo"";
	-echo -n "$(YELLOW)a5. ARG_EMPTY $(GREEN): | " ; ./checker $(ARG_EMPTY) <<EOF 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_EMPTY) <<EOF 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a6. ARG_1$(GREEN): | " ; ./checker $(ARG_1) <<EOF 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_1) <<EOF 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
	-echo -n "$(YELLOW)a7. ARG_SORTED$(GREEN): | " ; ./checker $(ARG_SORTED) <<EOF 2>&1 | tr '\n' ' ' ; echo -n " | " ; ./checker $(ARG_SORTED) <<EOF 2>&1 | wc -l | tr '\n' ' ' ; echo -n " | " ; echo "";
ifeq ($(i), 1)
	$(MAKE) test_export1
	$(MAKE) test_performance
endif

test_export1:
	$(MAKE) testing_alles i=0 2>&1 | sed 's/\x1b//g'| sed 's/\x1b\[0;92m//g'| sed 's/033//g'| sed 's/\[0;93m//g'| sed 's/\[0;92m//g'| sed 's/\[0;39m//g' | sed 's/\[0;39m//g' | sed 's/\[0;90m//g'| sed 's/\[0;91m//g'| sed 's/\[1m//g'| sed 's/\[0;91m//g'| sed 's/\[0;94m//g' > log/3.Unit_Testing/1.Unit_Testing.txt

test_performance:
	$(MAKE)
	/usr/bin/time -v ./push_swap $(ARG_500) 2> log/3.Unit_Testing/perfomance_time_push_ARG500.txt 1> /dev/null

perfomance:
	$(MAKE) fclean_all
	mkdir -p log/3.Unit_Testing
	/usr/bin/time -v $(MAKE) log_alles 2> log/3.Unit_Testing/perfomance_time_log_all.txt 1> /dev/null

# ************************************************************************ #
#                          TESTERS VISUALIZER                              #
# ************************************************************************ #
test_visualizer: testers/push_swap_visualizer/build/bin/visualizer

testers/push_swap_visualizer.tar.gz:
	pipx install gdown
	mkdir -p testers
	gdown 'https://drive.google.com/uc?id=1xvaDfFKfIPTeiwLLu0K37YzJdesab_kx' -O $@
#	file $@ | grep gzip > /dev/null
#	if [ $$? -ne 0 ]; then echo "Error: Downloaded file is not a gzip archive!"; exit 1; fi

testers/push_swap_visualizer: testers/push_swap_visualizer.tar.gz
		tar -xzf $< -C testers/

testers/push_swap_visualizer/build/bin/visualizer: testers/push_swap_visualizer

run_visualizer: testers/push_swap_visualizer/build/bin/visualizer
	./testers/push_swap_visualizer/build/bin/visualizer

.PHONY: run_visualizer

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                FOLDER BUILDER                                #
# ############################################################################ #
# *** Build folders *** #
folders_build:
	$(MAKE) folders_make_build
	$(MAKE) folders_log_build

# *** Build folders *** #
folders_make_build:
	mkdir -p inc
	mkdir -p libs
	mkdir -p objs

# *** Build folders *** #
folders_lns_build:
	@echo "Running folder_lns_builder..."
	@if [ -d "src/src_all" ]; then \
		echo "Deleting existing src/src_all directory..."; \
		rm -rf "src/src_all"; \
	fi
	@echo "Creating src/src_all directory..."
	@mkdir -p "src/src_all"
	@echo "Creating symbolic links for .c files..."
	@(find src/ -mindepth 1 -maxdepth 5 -type f -name "*.c" ! -path "*/.*" -print0 | \
		xargs -0 -I {} sh -c 'filename=$$(basename "{}"); \
			echo "Creating symbolic link for {} in src/src_all/$$filename"; \
			ln -s "$$(realpath --relative-to=src/src_all "{}")" "src/src_all/$$filename" || echo "Error creating symbolic link for {}";')
	@echo "Generating list_files_c.txt..."
	@(cd src/src_all; \
		find . -name "*.c" -print0 | xargs -0  printf "%s\t\t\\ \n"  > ../../log/list_files_c.txt)
	@echo "folder_lns_builder completed successfully."

# *** Build folders *** #
folders_log_build:
	mkdir -p log/1.Warning_Linting
	mkdir -p log/2.Memory_Check/logs
	mkdir -p log/2.Memory_Check/allocs
	mkdir -p log/3.Unit_Testing
	mkdir -p log/4.Bins_folder
	mkdir -p log/4.Bins_folder/log/5.bff
	mkdir -p log/5.Libs_nmart
	mkdir -p log/6.Make_dbg
#	mkdir -p log/5.bff

# ############################################################################ #
#                                HELPER                                        #
# ############################################################################ #
# *** Hello message *** #
hello:
	@echo "$(GRAY)\n################################################$(RESET)"
	@echo "$(GRAY)# Hello, $(USER)! $(shell date)$(RESET)"
	@echo "$(GRAY)# Welcome to Makefile for:$(BLUE) $(NAME)!$(RESET)"
	@echo "$(GRAY)################################################$(RESET)"
	$(MAKE) check_up_to_date
	echo "---"

# *** Build message of timestamps changes *** #
check_up_to_date:
ifeq ($(MAKECMDGOALS),all) # Only check if 'all' is the explicit goal
	@# Check if $(NAME) exists. If not, skip the up-to-date check.
	@if [ ! -f "$(NAME)" ]; then \
		echo "$(YELLOW)$(NAME) does not exist. Building...$(RESET)"; \
	else \
		# If $(NAME) exists, check if any source files are newer.
		@if find src/ inc/ -newer "$(NAME)" -print | grep -q .; then \
			echo "$(RED)$(NAME) Some files have changed. Rebuilding...$(RESET)"; \
		else \
			echo "$(GREEN)Everything up-to-date.$(RESET)"; \
			exit 0; \
		fi \
	fi
endif
ifeq ($(MAKECMDGOALS),check_up_to_date) # Special handling for 'make check_up_to_date'
	@if [ -f "$(NAME)" ] && find src/ inc/ -newer "$(NAME)" -print | grep -q .; then \
		echo "$(RED)$(NAME) Some files have changed. Run 'make all' to rebuild.$(RESET)"; \
	else \
		echo "$(GREEN)$(NAME) is up-to-date.$(RESET)"; \
		exit 0; \
	fi
endif

# *** help message *** #
help:
	@echo "$(GRAY)\n### 1.DESCRIPTION:$(RESET)"
	@echo "$(GREEN)	This is make file for build either PROGRAM, LIBRARY, PROGRAM+LIBRARY with their dependencies connect.$(RESET)"
	@echo "$(GREEN)	- This Makefile is a template for a project with the following structure:$(RESET)"
	@echo "$(GREEN)	1. Headers.h, files all them must be placed inside the folder 'include'.$(RESET)"
	@echo "$(GREEN)	2. Library.a, files all them must be inside of the folder 'libs'.$(RESET)"
	@echo "$(GREEN)	3. The library makefile must be inside of the folder 'libs/mylib'.$(RESET)"
	@echo "$(GRAY)	structure:$(RESET)"
	@echo "$(GREEN)my_project/$(RESET)"
	@echo "$(GREEN)├── include/$(RESET)"
	@echo "$(GREEN)│   ├── main.h$(RESET)"
	@echo "$(GREEN)│   └── mylib.h$(RESET)"
	@echo "$(GREEN)├── libs/$(RESET)"
	@echo "$(GREEN)│   ├── mylib/$(RESET)"
	@echo "$(GREEN)│   │   ├── src/$(RESET)"
	@echo "$(GREEN)│   │   │   └── mylib.c$(RESET)"
	@echo "$(GREEN)│   │   │── objs/$(RESET)"
	@echo "$(GREEN)│   │   │   └── mylib.o$(RESET)"
	@echo "$(GREEN)│   │   └── Makefile <-- (1) Sub-Makefile for the library$(RESET)"
	@echo "$(GREEN)│   └── libmylib.a <-- (2) Library file outside mylib directory$(RESET)"
	@echo "$(GREEN)├── objs/$(RESET)"
	@echo "$(GREEN)│   ├── main.o$(RESET)"
	@echo "$(GREEN)│   ├── main_utils.o$(RESET)"
	@echo "$(GREEN)│   ├── main_utils1.o$(RESET)"
	@echo "$(GREEN)│   └── main_utils2.o$(RESET)"
	@echo "$(GREEN)├── src/$(RESET)"
	@echo "$(GREEN)│   └── main.c$(RESET)"
	@echo "$(GREEN)│       ├── UtilsA/$(RESET)"
	@echo "$(GREEN)│       │   ├── main_utils.c$(RESET)"
	@echo "$(GREEN)│       │   └── main_utils1.c$(RESET)"
	@echo "$(GREEN)│       └── UtilsB/$(RESET)"
	@echo "$(GREEN)│          └── main_utils2.c$(RESET)"
	@echo "$(GREEN)└── Makefile$(RESET)"
	@echo "$(GRAY)\n### 2. USAGE:$(RESET)"
	@echo "$(GREEN)	make [option]$(RESET)"
	@echo "$(GRAY)\n### 3. OPTIONS:$(RESET)"
	@echo "$(GRAY) DEFAULT RULES:$(RESET)"
	@echo "$(GREEN)	1. all, clean, fclean, fclean_all, re$(RESET)"
	@echo "$(GRAY) FUNCTIONS BUILD:$(RESET)"
	@echo "$(GREEN)	2. program_or_lib, program, lib, libs_build $(RESET)"
	@echo "$(GREEN)	3. library_clean, library_fclean, library_re $(RESET)"
	@echo "$(GREEN)	4. hello, check_up_to_date, code_cleaner, files_lns_creator $(RESET)"
	@echo "$(GRAY) LINTING(static/Wflags):$(RESET)"
	@echo "$(GREEN)	5. liting: werror, norm_1, norm_2$(RESET)"
	@echo "$(GRAY) SANITIZATION(static/Asan) & RUNTIME ERROR(dynamic/Valgrind):$(RESET)"
	@echo "$(GREEN)	6. leaks: create_bins, valgrind, asan$(RESET)"
	@echo "$(GRAY) UNIT TESTS:$(RESET)"
	@echo "$(GREEN)	7. testing_alles: run_visualizer, time_and_perfomance$(RESET)"
	@echo "$(GRAY) DEBUGGERS:$(RESET)"
	@echo "$(GREEN)	8. make_dbg, libs_nm_art, debug, compile_debug_files$(RESET)"
	@echo "$(GRAY) HELPERS:$(RESET)"
	@echo "$(GREEN)	9. log_all, check_up_to_date, code_cleaner, folders_build, folder_lns_builder$(RESET)"
	@echo "$(GRAY) EXTRAS:$(RESET)"
	@echo "$(GREEN)	10. bonus\n$(RESET)"
	

# **************************************************************************** #
#                                DEFS/COLORS                               	   #
# **************************************************************************** #
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
RESET =			\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

# **************************************************************************** #
#                                TRASH		                               	   #
# **************************************************************************** #

#Name NO USE!
all: $(NAME)

$(NAME):	$(OBJECTS)
	echo "$(RED) _MAKE BUILD_ IS THE CORRECT!$(RESET)"
	$(COMPILER) $(OBJECTS) $(LDFLAGS) $(CFLAG_ASAN) -o $(NAME)
	@echo "$(YELLOW)(•̀ᴗ•́)و $(NAME) BIN GENERATED!$(RESET)"
	$(MAKE) check_up_to_date

program_or_lib1:
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	$(MAKE) check_up_to_date
	$(MAKE) libs_build
	$(MAKE) program
else
	$(MAKE) check_up_to_date
	$(MAKE) lib
	$(MAKE) combine_libs
endif




# ************************************************************************ #
# ************************************************************************ #
#1. DESCRIPTION:
#	This is make file for build either PROGRAM, LIBRARY, PROGRAM+LIBRARY 
#		with their dependecies connect.
#
# - This Makefile is a template for a project with the following structure:
#	1. Headers.h, files all them must be placed inside the folder "include".
#	2. Library.a, files all them must be inside of the folder "libs"
#	3. The library makefile must be inside of the folder "libs/mylib"

#	structure:
#		my_project/
#		├── include/
#		│   ├── main.h
#		│   └── mylib.h
#		│
#		├── libs/
#		│   ├── mylib/
#		│   │   ├── src/
#		│   │   │   └── mylib.c
#		│   │   │── objs/
#		│   │   │   └── mylib.o
#		│   │   └── Makefile		<-- (1) Sub-Makefile for the library
#		│   └── libmylib.a			<-- (2) Library file outside mylib directory
#		│
#		├── objs/
#		│   ├── main.o
#		│   ├── main_utils.o
#		│   ├── main_utils1.o
#		│   └── main_utils2.o
#		│
#		├── src/
#		│   └── main.c
#		│       ├── UtilsA/
#		│       │   ├── main_utils.c
#		│       │   └── main_utils1.c
#		│       └── UtilsB/
#		│          └── main_utils2.c
#		│
#		└── Makefile
#
#2. USAGE:
#	make [option]
#
#3. OPTIONS:
#	- DEFAULT:
#		1. help, all, clean, fclean, fclean_all, re
#
#	- FUNCTIONS BUILD:
#		2. program_or_lib, program, lib, libs_build, folders_build
#
#	- LINTING(static/Wflags) & SANITIZATION(static/Asan) & RUNTIME ERROR(dynamic/Valgrind) & UNIT_TESTING :
#		3. log_all: norm_1, norm_2, leaks: valgrind, asan
#		4. test, test5
#
#	- DEBUGGERS:
#		5. debug, compile_debug_files, make_dbg, create_bins
#
#	- HELPERS:
#		6. hello, check_up_to_date, code_cleaner, files_lns_creator
#		7. library_clean, library_fclean, library_re
#
#	- EXTRA:
#		8. bonus