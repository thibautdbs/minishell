# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    env.test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 13:59:30 by ffeaugas          #+#    #+#              #
#    Updated: 2023/01/16 17:20:06 by ffeaugas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

declare -r RUNNER=${1};

run()
{
	valgrind --quiet --leak-check=full --show-reachable=yes "${RUNNER}" "${@}";
}

test_equality()
{
	assertEquals 0 0;
}

shift ${#};
source "$(dirname $0)"/include/shunit2
