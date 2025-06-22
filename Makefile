RELEASE_DIR := cmake-build-release
DEBUG_DIR := cmake-build-debug

.PHONY: all 

all:
	mkdir -p $(RELEASE_DIR) && cd $(RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ..
	mkdir -p $(DEBUG_DIR) && cd $(DEBUG_DIR) && cmake -DCMAKE_BUILD_TYPE=Debug ..

clean:
	rm -rf $(RELEASE_DIR) $(DEBUG_DIR)

debug: clean
	@echo "Building in Debug mode..."
	mkdir -p $(DEBUG_DIR) && cd $(DEBUG_DIR) && cmake -DCMAKE_BUILD_TYPE=Debug ..

release: clean
	@echo "Building in Release mode..."
	mkdir -p $(RELEASE_DIR) && cd $(RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ..

test: all
	@echo "running tests in debug..."
	cd $(DEBUG_DIR) && make aul_test && ctest

	@echo "running tests in release..."
	cd $(RELEASE_DIR) && make aul_test && ctest

install: release
	@echo "installing..."
	cd $(RELEASE_DIR) && make install
