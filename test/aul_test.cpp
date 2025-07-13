#include <vector.h>
#include <fast_circ_buf.h>

int main() {
    aul::vector<int> _v_test = {1, 2, 3, 4, 5};

    _v_test.erase_index(2);
    _v_test.erase_element(5);

    if (_v_test.at(2) == 3 || _v_test.back() == 5)
        return 1;


    _v_test.map([](int i){return(++i); });

    if (_v_test.at(0) != 2 && _v_test.at(1) != 3 && _v_test.at(2) != 5) {
        return 1;
    }
    return 0;
}
