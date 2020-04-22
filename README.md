# libtilix

C library to parse JSON files exported from [Tiled](https://www.mapeditor.org).

## Usage

The library tries its best to mirror the JSON it parses, with some useful type
mappings (e.g. using `enum`s when it is relevant).

```c
#include <stdio.h>
#include <stdlib.h>
#include "tilix/tilix.h"

int ghislegn(int ac, char **av)
{
  tl_map_t map;

  if (ac != 2) {
    printf("Usage: %s <map>\n", av[0]);
    return (1);
  }

  if (tl_map_load(av[1], &map)) {
    printf("Couldn't load the map!\n");
    return (1);
  }

  printf("Loaded map: '%s'\n", map.name);
  tl_map_deinit(&map);
  return (0);
}
```

## Building and testing

Pre-requisites:
  - GNU `make` (I don't know which version but I have 4.1).
  - `gcc` >= 7.5 or `clang` >= 6.0.0 (same as above, I only tested that)

This library has some dependencies that will be `git clone`d automatically when
calling `make`. Yes, I know git submodules are a thing. I just can't use it
because of many constraints described further down this readme.

```sh
git clone https://github.com/nasso/libtilix.git
cd libtilix
make
```

To run the tests (you'll need to have
[Criterion](https://github.com/Snaipe/Criterion.git) installed on your system).

```sh
make tests_run
```

## Scope

Some things to keep in mind about this library:
- It will only work on UNIX (it needs `unistd.h`).
- It only **parses** files. It cannot export.
- It was originally made for a school project. Since we are not allowed to use
  most of the libc, I've made [my own](https://github.com/nasso/libmy), and
  `libtilix` uses it. If some people are interested in using `libtilix`, some
  work would have to be done to port it to the libc (if needed).

## Coding style

The code follows a particular coding style enforced by my school. The most
important aspects are:
- No more than 5 functions in a `*.c` file.
- No more than 3 levels of branching.
- No more than 1 `else if` in a branching chain.
- No `typedef`s in `*.c` files.
- No structure arguments passed by value (always use a pointer).
- Functions must not exceed 20 lines.
- Variable declarations must always be done at the top of the function scope.
- The only empty line in functions is the one separating variable declarations
  with the rest of the function's body.
- Source files must start with some header containing the project name and file
  description.
