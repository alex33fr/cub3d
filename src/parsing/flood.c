/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:00:00 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 17:00:00 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Counts the total characters in the map, an upper bound for the stack.
 * @param map NULL-terminated array of map rows.
 * @return The total character count.
 */
static int	count_capacity(char **map)
{
	int	cap;
	int	i;

	cap = 0;
	i = 0;
	while (map[i])
	{
		cap = cap + ft_strlen(map[i]);
		i++;
	}
	return (cap);
}

/**
 * @brief Pushes a cell if walkable and unvisited; out of the grid is a leak.
 * @param map Editable copy of the map, @param st Stack to push onto,
 * @param c Cell to check.
 * @return 1 if this cell is a leak, 0 otherwise.
 */
static int	try_push(char **map, t_stack *st, t_cell c)
{
	if (c.y < 0 || c.x < 0 || !map[c.y] || map[c.y][c.x] == '\0')
		return (1);
	if (map[c.y][c.x] == '1' || map[c.y][c.x] == 'F' || map[c.y][c.x] == ' ')
		return (0);
	map[c.y][c.x] = 'F';
	st->data[st->top] = c;
	st->top++;
	return (0);
}

/**
 * @brief Pushes the 4 neighbours of a cell, accumulating leaks into *leak.
 * @param map Editable copy of the map, @param st Stack to push onto,
 * @param cur Cell whose neighbours are checked, @param leak Leak accumulator.
 */
static void	push_neighbors(char **map, t_stack *st, t_cell cur, int *leak)
{
	t_cell	next;

	next.y = cur.y + 1;
	next.x = cur.x;
	*leak = *leak + try_push(map, st, next);
	next.y = cur.y - 1;
	next.x = cur.x;
	*leak = *leak + try_push(map, st, next);
	next.y = cur.y;
	next.x = cur.x + 1;
	*leak = *leak + try_push(map, st, next);
	next.y = cur.y;
	next.x = cur.x - 1;
	*leak = *leak + try_push(map, st, next);
}

/**
 * @brief Iteratively floods the map copy from one cell using a heap stack.
 * @param map Editable copy of the map (visited cells are marked 'F').
 * @param y Starting row, @param x Starting column.
 * @return 1 if a leak is detected, 0 if the area is closed.
 */
int	ft_flood_fill(char **map, int y, int x)
{
	t_stack	st;
	t_cell	cur;
	int		leak;

	st.data = malloc(sizeof(t_cell) * count_capacity(map));
	if (!st.data)
		return (1);
	st.top = 0;
	leak = 0;
	cur.y = y;
	cur.x = x;
	leak = leak + try_push(map, &st, cur);
	while (st.top > 0)
	{
		st.top--;
		cur = st.data[st.top];
		push_neighbors(map, &st, cur, &leak);
	}
	free(st.data);
	if (leak > 0)
		return (1);
	return (0);
}
