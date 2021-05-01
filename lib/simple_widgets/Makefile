BUILD_DIR := build

CONFIG_FLAGS := -G"Unix Makefiles" -B$(BUILD_DIR) -DSW_BUILD_DOC=TRUE

CONFIG_FLAGS_RELEASE := -DCMAKE_BUILD_TYPE=Release $(CONFIG_FLAGS)
CONFIG_FLAGS_DEBUG := -DCMAKE_BUILD_TYPE=Debug $(CONFIG_FLAGS)

BUILD_FLAGS_RELEASE := --config Release -j
BUILD_FLAGS_DEBUG := --config Debug -j

all:
	cmake $(CONFIG_FLAGS_RELEASE)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_RELEASE)

clean:
	rm -rf $(BUILD_DIR)/CMakeFiles
	rm -rf $(BUILD_DIR)/src

fclean: clean
	rm -rf $(BUILD_DIR)
	rm -rf doc/html doc/Doxyfile

debug:
	cmake $(CONFIG_FLAGS_DEBUG)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_DEBUG)

re: fclean all

docs: all
	(cd $(BUILD_DIR) && cmake --build . --target simple-widgets-doc)

open_docs:
	xdg-open doc/html/index.html > /dev/null
docs_open: open_docs

.PHONY: all clean fclean debug re docs open_docs docs_open
