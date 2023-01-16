# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    env.test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 13:59:30 by ffeaugas          #+#    #+#              #
#    Updated: 2023/01/16 15:32:55 by ffeaugas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

declare -r RUNNER=${1};

run()
{
	valgrind --quiet --leak-check=full --show-reachable=yes "${RUNNER}" "${@}";
}

test_equality()
{
	assertEquals "$(env)" "$(run env)";
}



source include/shunit2
