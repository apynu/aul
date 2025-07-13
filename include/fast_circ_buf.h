//
// Created by apynu on 7/13/25.
//
#pragma once
namespace aul {
    /// faster circular buffer implementation using a dynamic array
    template <class T> class fast_circ_buf {
    public:
        explicit fast_circ_buf(int Size);

        // adds one element to the circular buffer
        // returns false once the buffer is full, otherwise returns true
        // except if the override is set, then it'll always return true and override
        // elements
        bool push_back(T Element);

        // returns the element at the current index
        // index wraps around
        T at(int Index);

        // sets whether push_back should simply override the elements
        // when the buffer is full
        void set_override(bool override);

        // clears internal data array
        /// sort of a pseudo clear, simply releases all objects to be overwritten
        void clear();

        // allocate memory based on new size
        void resize(int size);

        // returns the current circbuf size
        int size();

    private:
        std::vector<T> m_buf;
        int m_bufsize; // semi constant size that can't be changed but with a call to .resize; indexed at 1
        int m_occupation;
        bool m_override;
        int m_currentelementindex = 0;
    };
}
#include "fast_circ_buf.tcc"