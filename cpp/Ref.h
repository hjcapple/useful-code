#ifndef __CLOVER_REF_H__
#define __CLOVER_REF_H__

#include <atomic>
#include "intrusive_ptr.h"

namespace clover {

    template <typename DerivedT, typename RefCounterT = std::atomic<int32_t>>
    class Ref {
    public:
        typedef intrusive_ptr<DerivedT> Ptr;

        Ref(const Ref &) = delete;
        Ref &operator=(const Ref &) = delete;

        Ref() : _refCount(1) {
        }

        virtual ~Ref() {
        }

        void retain() {
            _refCount++;
        }

        void release() {
            if (--_refCount == 0) {
                delete this;
            }
        }

        bool isUnique() const {
            return _refCount == 1;
        }

    private:
        RefCounterT _refCount;
    };

    template <typename DerivedT>
    inline void intrusive_ptr_add_ref(DerivedT *obj) {
        obj->retain();
    }

    template <typename DerivedT>
    inline void intrusive_ptr_release(DerivedT *obj) {
        obj->release();
    }

    template <typename T, typename... Args>
    inline intrusive_ptr<T> makeRef(Args &&... args) {
        return intrusive_ptr<T>(new T(std::forward<Args>(args)...), false);
    }
} // namespace clover

#endif
