/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:02:28 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/08 13:02:29 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != '\0'; j++)
            {
                std::cout << (char)toupper(argv[i][j]);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}