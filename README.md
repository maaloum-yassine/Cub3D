<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/cub3de.png" alt="Cub3D 42 project badge"/>
</p>

Cub3D is a 42 school team project aimed at creating a dynamic 3D maze exploration experience. Using the [MiniLibX library](https://github.com/42Paris/minilibx-linux), we implement raycasting in the style of the classic [Wolfenstein 3D](http://users.atw.hu/wolf3d/), the first true FPS in video game history.

## 🛠 Clone the Repository

Clone the repository, including the MiniLibX submodule:

```bash
git clone git@github.com:maaloum-yassine/Cub3D.git
cd Cub3D
```

## 🔧 Compile and Run

### Mandatory Version
To compile the mandatory version:

```bash
make
```

### Bonus Version
The bonus version adds features such as wall collision, a minimap, and mouse-based view rotation. Compile it with:

```bash
make bonus
```

> **Note:** You may need to run `make fclean` before switching between the mandatory and bonus versions.

### Run the Program

```bash
./cub3d <path/to/map.cub>
```

Example:

```bash
./cub3d maps/good/library.cub  # Should run successfully
./cub3d maps/bad/filetype_wrong.buc  # Should print an error
```

## 🎮 Controls

- **W** - Move forward  
- **S** - Move backward  
- **A** - Strafe left  
- **D** - Strafe right  
- **Left Arrow** - Rotate left  
- **Right Arrow** - Rotate right  
- **Mouse** - Rotate view (bonus only)  

## 🎥 Demo Video

Click below to watch a demo of the Cub3D project:  

➡️ **[Watch my 3D Game Demo on Vimeo](https://vimeo.com/970580684)** ⬅️  

## 📚 Useful Resources

- **MiniLibX**: [Hsmits MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)  
- **MiniLibX**: [Gontjarow's MiniLibX tutorial](https://gontjarow.github.io/MiniLibX/)  
- **Xlib (for MLX events)**: [The Xlib Manual](https://tronche.com/gui/x/xlib/)  
- **Raycasting**: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)  
- **Raycasting**: [Permadi's Raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)  
- **Movement Calculations**: [Calculating heading in 2D games](http://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/)  

---

