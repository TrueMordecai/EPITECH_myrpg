TARGET := libphysics.a
BUILD_DIR := build

CONFIG_FLAGS := -G"Unix Makefiles" -B$(BUILD_DIR) -DBUILD_SHARED_LIBS=TRUE

CONFIG_FLAGS_RELEASE := -DCMAKE_BUILD_TYPE=Release $(CONFIG_FLAGS)
CONFIG_FLAGS_DEBUG := -DCMAKE_BUILD_TYPE=Debug $(CONFIG_FLAGS)

BUILD_FLAGS_RELEASE := --config Release -j
BUILD_FLAGS_DEBUG := --config Debug -j

all: $(TARGET)

$(TARGET):
	cmake $(CONFIG_FLAGS_RELEASE)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_RELEASE)

clean:
	rm -rf $(BUILD_DIR)/CMakeFiles
	rm -rf $(BUILD_DIR)/src/CMakeFiles
	rm -rf $(BUILD_DIR)/lib/my/src

fclean: clean
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)

debug:
	cmake $(CONFIG_FLAGS_DEBUG)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_DEBUG)

re: fclean all

.PHONY: all $(TARGET) clean fclean debug re
