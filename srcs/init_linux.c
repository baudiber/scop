/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:21:24 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 19:21:58 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void	init_gl_version(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}
