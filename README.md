*This project has been created as part of the 42 curriculum by jjeannea, aprivalo*.

# cub3D

A first-person 3D maze renderer built with **MiniLibX** and the
**raycasting** technique (the same idea behind Wolfenstein 3D). The program
reads a `.cub` scene description, builds a 2D map, and renders a realistic
3D view from the player's point of view.

## Description

The program parses a `.cub` configuration file containing:
- the **4 wall textures** (`NO`, `SO`, `WE`, `EA`),
- the **floor** (`F`) and **ceiling** (`C`) colors in `R,G,B`,
- the **map**, made of walls (`1`), empty space (`0`) and a single
  start position (`N`, `S`, `E` or `W`) giving the player's orientation.

The map must be **closed/surrounded by walls** and contain **exactly one**
player. Once validated, the scene is rendered in real time with raycasting.

## Instruction

```sh
make
```

Produces `./cub3D`, compiled with `-Wall -Wextra -Werror`.
`make clean`, `make fclean` and `make re` are also available.

> The **libft** is kept in the repository and is only (re)built, never removed.
> The **MiniLibX** is downloaded and compiled automatically on the first build
> and is ignored by git.

```sh
./cub3D maps/map.cub
```

Controls (QWERTY)

- Move: `W` `A` `S` `D`
- Look left / right: `←` `→`
- Quit: `ESC` or the window close button


## Resources

- https://ibon-ira-cub3d.mintlify.app/introduction
- Lode Vandevenne Raycasting (untextured, textured, movement): https://lodev.org/cgtutor/raycasting.html
- MiniLibX (42 docs / Harm Smits guide, gontjarow MiniLibX reference)
- man 3 open/read/close, man 3 malloc, man 3 perror
- Wolfenstein 3D / F. Permadi — raycasting background theory
- AI was used throughout as a pair-programming aid.
