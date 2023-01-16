# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 23:22:23 by tdubois           #+#    #+#              #
#    Updated: 2023/01/16 23:30:11 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test: fclean test.unit test.builtins
.PHONY: test

test.unit: fclean
	$(MAKE) -C ./tests/unit
.PHONY: test.unit

test.builtins: fclean
	$(MAKE) -C ./tests/builtins
.PHONY: test.builtins
