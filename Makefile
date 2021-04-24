TARGET := my_rpg

OBJ_PATH := bin
SRCS_BASE := 	main.c \
				\
				create_drawable.c \
				\
				\
				my_map_cmp.c \
				is_in_bounds.c \
				get_rand.c \
				center_mouse.c \
				\
				\
				rpg_create.c \
				rpg_handle_input.c \
				rpg_update.c \
				rpg_draw.c \
				rpg_destroy.c \
				\
				player_create.c \
				player_handle_input.c \
				player_update.c \
				player_draw.c \
				player_destroy.c \
				\
				map_create.c \
				map_move.c \
				map_zoom.c \
				map_update.c \
				map_draw.c \
				map_destroy.c \
				\
				zone_create.c \
				zone_sort_layer.c \
				zone_init.c \
				zone_open_file.c \
				zone_draw.c \
				zone_destroy.c \
				\
				layer_create.c \
				layer_init.c \
				layer_cst.c \
				layer_place_tile.c \
				layer_draw.c \
				layer_destroy.c \
				\
				\
				init_inventory.c            \
				inventory_draw_other.c		\
				utils.c            \
				inventory_index.c					\
				rpg_create_item.c            \
				inventory_input.c				\
				inventory_draw_items.c			\
				rpg_create_item_name_gen.c   \
				rpg_draw_item_tooltip.c		\
				drawable_list_fcts.c \
				drawable_list_fcts_texture.c \
				remove_drawable.c \
				\
				asset_manager.c \
				asset_manager_destroy.c \
				load_textures.c \
				\
				audio_manager_init.c \
				audio_manager_play.c \
				load_audio.c \
				audio_manager_update_volumes.c \
				\
				game_settings_init.c \
				game_settings_save.c \
				\
				game.c \
				states.c \
				\
				\
				game_create.c \
				game_cst.c \
				game_destroy.c \
				game_draw.c \
				game_handle_input.c \
				game_init.c \
				game_pause.c \
				game_resume.c \
				game_update.c \
				\
				menu_create.c \
				menu_cst.c \
				menu_destroy.c \
				menu_draw.c \
				menu_handle_input.c \
				menu_init.c \
				menu_pause.c \
				menu_resume.c \
				menu_update.c \
				\
				settings_create.c \
				settings_cst.c \
				settings_destroy.c \
				settings_draw.c \
				settings_init.c \
				settings_pause.c \
				settings_resume.c \
				settings_handle_input.c \
				settings_update.c

OBJS := $(addprefix $(OBJ_PATH)/, $(SRCS_BASE:.c=.o))
CC := gcc
CFLAGS := -Wall -Werror --pedantic -O1 -g
CFLAGS_LIB :=  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -L./lib/ -lcontainer -lm -lmy
CFLAGS_INCLUDE := -I./include/
MAKE_LIB := make -C lib/my/
MAKE_CONTAINERS := make -C lib/my_container/
DATAS_DIR = datas

all: make_libs $(DATAS_DIR) $(OBJ_PATH) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CFLAGS_LIB)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE_LIB) clean
	$(MAKE_CONTAINERS) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE_LIB) fclean
	$(MAKE_CONTAINERS) fclean
	rm -rf $(DATAS_DIR)

re: fclean all

make_libs:
	$(MAKE_LIB)
	$(MAKE_CONTAINERS)

$(OBJ_PATH)/%.o: ./srcs/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Drawables/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Functions/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Rpg/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Rpg/Entities/Player/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Rpg/Map/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Rpg/Map/Zone/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Rpg/Map/Zone/Layer/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Rpg/Interfarces/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/asset_manager/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/audio_manager/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/drawables/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/settings/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/States/Game/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/Menu/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/Settings/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH):
	mkdir $@

$(DATAS_DIR):
	mkdir $@

debug:
	echo $(OBJS)

.PHONY: clean fclean re all test make_libs tests_run create_datas
