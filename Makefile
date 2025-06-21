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

test: 	release
	@echo "running tests..."
	cd $(RELEASE_DIR) && make templ_test && ctest

install: release
	@echo "installing..."
	cd $(RELEASE_DIR) && make install
