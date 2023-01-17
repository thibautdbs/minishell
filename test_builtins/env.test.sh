# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    env.test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 13:59:30 by ffeaugas          #+#    #+#              #
#    Updated: 2023/01/17 13:28:42 by ffeaugas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

declare -r RUNNER=${1};

run()
{
	valgrind --quiet --leak-check=full --show-reachable=yes "${RUNNER}" "${@}";
}

test_equality()
{
	assertEquals env ;

}

shift ${#};
source "$(dirname $0)"/include/shunit2
