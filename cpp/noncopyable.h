#ifndef __CLOVER_NONCOPYABLE_H__
#define __CLOVER_NONCOPYABLE_H__

// from boost
namespace clover {
    class noncopyable {
    protected:
        noncopyable() = default;
        ~noncopyable() = default;

        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
    };
}

#endif
