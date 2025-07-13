#pragma once
#include <vector>

namespace aul {
    template<typename T>
    fast_circ_buf<T>::fast_circ_buf(int Size)
        : m_bufsize(Size), m_occupation(0), m_override(false)
    {

    }

    template<typename T>
    bool fast_circ_buf<T>::push_back(T Element) {
        bool success = false;
        // there is no space anymore
        if (m_occupation >= m_bufsize) {
            // override flag is set, so start overwriting
            if (m_override) {
                m_buf.at(m_currentelementindex) = Element;
                m_currentelementindex++;
                success = true;
            }else {
                success = false;
            }
        }else {
            // there is still space for a new element
            m_buf.push_back(Element);
            m_occupation++;
            success = true;
        }
        return success;
    };

    template<typename T>
    T fast_circ_buf<T>::at(int Index) {
        while (Index >= m_bufsize) {
            Index = m_bufsize % Index;
        }
        return m_buf.at(Index);
    }

    template<typename T>
    void fast_circ_buf<T>::set_override(bool override) {
        m_override = override;
    };

    template<typename T>
    void fast_circ_buf<T>::clear() {
        m_occupation = 0;
    };

    template<typename T>
    void fast_circ_buf<T>::resize(int size) {
        // new buffer size so that .at works correctly
        m_bufsize = size;
    };

    template<typename T>
    int fast_circ_buf<T>::size(){
        return m_bufsize;
    }
}