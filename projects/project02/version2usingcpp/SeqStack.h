#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <stdexcept>
template<typename T> 
class SeqStack {
    public:
        SeqStack();
        bool stackEmpty();
        bool stackFull();
        void overFlow();
        void Push(T x);
        T Pop();
        T getTop();
        T *elem;
        int top, maxSize;
};

#endif

