TARGET := my_rpg

BUILD_DIR := build
BUILD_DIR_RELEASE := $(BUILD_DIR)/release
BUILD_DIR_DEBUG := $(BUILD_DIR)/debug

CONFIG_FLAGS := -G"Unix Makefiles" 

CONFIG_FLAGS_RELEASE := \
	-DCMAKE_BUILD_TYPE=Release -DBUILD_TEST_SUITE=TRUE \
	-DLIBMY_BUILD_DOC=TRUE -DSW_BUILD_DOC=TRUE \
	$(CONFIG_FLAGS) -B$(BUILD_DIR_RELEASE) \

CONFIG_FLAGS_DEBUG := \
	-DCMAKE_BUILD_TYPE=Debug -DBUILD_TEST_SUITE=TRUE \
	-DUSE_GCOV=TRUE \
	$(CONFIG_FLAGS) -B$(BUILD_DIR_DEBUG) \

BUILD_FLAGS_RELEASE := --build $(BUILD_DIR_RELEASE) --config Release -j
BUILD_FLAGS_DEBUG := --build $(BUILD_DIR_DEBUG) --config Debug -j

# Build Targets
all: $(TARGET)
$(TARGET):
	cmake $(CONFIG_FLAGS_RELEASE)
	cmake $(BUILD_FLAGS_RELEASE)

# Remove Target's Build Files
clean:
	rm -rf $(BUILD_DIR_RELEASE)/CMakeFiles $(BUILD_DIR_RELEASE)/src/CMakeFiles
	rm -rf $(BUILD_DIR_DEBUG)/CMakeFiles $(BUILD_DIR_DEBUG)/src/CMakeFiles

# Remove Target
fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)

# Recompile all
re: fclean all

# Debug Target
debug:
	cmake $(CONFIG_FLAGS_DEBUG)
	cmake $(BUILD_FLAGS_DEBUG)

# Run Target
run_tests: fclean debug
	(cd $(BUILD_DIR_DEBUG) && ctest --verbose) || true
run_test: run_tests
tests_run: run_tests
test_run: run_test

# Display Code Coverage
coverage:
	gcovr .
	gcovr --branch .

.PHONY: \
	all $(TARGET) \
	clean fclean re \
	debug \
	run_tests run_test tests_run test_run coverage
