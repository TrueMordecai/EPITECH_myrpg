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
				physic_add_tile.c \
				physic_add_zone_border.c \
				\
				player_create.c \
				player_init_physic.c \
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
				zone_add_special.c \
				zone_compute_battle_layer.c \
				\
				layer_create.c \
				layer_init.c \
				layer_cst.c \
				layer_place_tile.c \
				layer_draw.c \
				layer_destroy.c \
				\
				\
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
CFLAGS := -Wall -Werror --pedantic -O1
CFLAGS_LIB :=  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -L./lib/ -lcontainer -lm -lmy -lphysics
CFLAGS_INCLUDE := -I./include/
MAKE_LIB := make -C lib/my/
MAKE_CONTAINERS := make -C lib/my_containers/
MAKE_PHYSICS := make -C lib/my_physics/
DATAS_DIR = datas

all: make_libs $(DATAS_DIR) $(OBJ_PATH) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CFLAGS_LIB)

clean: clean_rpg clean_libs

clean_rpg:
	rm -rf $(OBJ_PATH)

clean_libs:
	$(MAKE_LIB) clean
	$(MAKE_CONTAINERS) clean
	$(MAKE_PHYSICS) clean

fclean: clean fclean_rpg fclean_libs

fclean_rpg: clean_rpg
	rm -f $(TARGET)
	rm -rf $(DATAS_DIR)

fclean_libs:
	$(MAKE_LIB) fclean
	$(MAKE_CONTAINERS) fclean
	$(MAKE_PHYSICS) fclean

re: fclean all

re_rpg: fclean_rpg all

re_libs: fclean_libs all


make_libs:
	$(MAKE_LIB)
	$(MAKE_CONTAINERS)
	$(MAKE_PHYSICS)

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
$(OBJ_PATH)/%.o: ./srcs/Rpg/Map/Physic/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Rpg/Map/Zone/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Rpg/Map/Zone/Layer/%.c
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
