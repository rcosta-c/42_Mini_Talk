################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= mini-talk
USER	= rcosta-c
SERVER	= server
CLIENT	= client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC	= cc
FLAGS	= -Wall -Wextra -Werror 
FT_PRINTF	= lib/ft_printf/libftprintf.a
PRINTF	= lib/ft_printf

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f



all:            ${SERVER} ${CLIENT}


${CLIENT}:	${OBJS}
			make -C $(PRINTF)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(CLIENT) ${CLR_RMV}..."
			${CC} ${FLAGS} client.c $(FT_PRINTF) -o ${CLIENT}
			@echo "$(GREEN)$(CLIENT) created ✔️"


${SERVER}:	${OBJS}
			make -C $(PRINTF)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(SERVER) ${CLR_RMV}..."
			${CC} ${FLAGS} server.c $(FT_PRINTF) -o ${SERVER}
			@echo "$(GREEN)$(SERVER) created ✔️"


${CLIENT_BONUS}:	${OBJS}
			make -C $(PRINTF)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(CLIENT_BONUS) ${CLR_RMV}..."
			${CC} ${FLAGS} client_bonus.c $(FT_PRINTF) -o ${CLIENT_BONUS}
			@echo "$(GREEN)$(CLIENT_BONUS) created ✔️"


${SERVER_BONUS}:	${OBJS}
			make -C $(PRINTF)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(SERVER_BONUS) ${CLR_RMV}..."
			${CC} ${FLAGS} server_bonus.c $(FT_PRINTF) -o ${SERVER_BONUS}
			@echo "$(GREEN)$(SERVER_BONUS) created ✔️"


bonus:		${SERVER_BONUS} ${CLIENT_BONUS}


clean:
			@ make clean -s -C $(PRINTF)
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(SERVER)$(CLR_RMV) and $(CYAN)$(CLIENT) $(CLR_RMV)objs ✔️"


fclean:		clean
			@ make fclean -s -C $(PRINTF)
			@ ${RM} -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
			@ echo "$(RED)Deleting $(CYAN)$(SERVER)$(CLR_RMV) and $(CYAN)$(CLIENT) $(CLR_RMV)binary ✔️"


re:			fclean all

.PHONY:		all clean fclean re
