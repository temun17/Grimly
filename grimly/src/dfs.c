/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:32:56 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/22 22:32:59 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/grimly.h"

/*
 ** Recursive Function called DFS selecting an arbitrary node as the root
 ** in the case of the graph and explores as far as possible along each
 ** branch before backtracking.
 */

int	dfs(int row, int col) {
	int* current = &visited[row][col];

	if (*current == goal) {
		return 1;
	}

	if (*current == empty) {
		*current = wall;

		if (dfs(row + 1, col)) {
			*current = steps;
			return 1;
		}
		if (dfs(row, col - 1)) {
			*current = steps;
			return 1;
		}
		if (dfs(row, col + 1)) {
			*current = steps;
			return 1;
		}
		if (dfs(row - 1, col)) {
			*current = steps;
			return 1;
		}
	}
	return 0;
}
