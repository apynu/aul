#include <vector.h>

int main() {
    aul::vector<int> _v_test = {1, 2, 3, 4, 5};

    _v_test.erase(2);

    if (_v_test.at(2) == 3)
        return 1;
    else
        return 0;
}
