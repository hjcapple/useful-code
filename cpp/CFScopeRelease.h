#ifndef __CF_SCOPERELEASE_H__
#define __CF_SCOPERELEASE_H__

#include <CoreFoundation/CFBase.h>

#define __CF_SCOPE_CONCATENATE_IMPL(s1, s2) s1##s2
#define __CF_SCOPE_CONCATENATE(s1, s2) __CF_SCOPE_CONCATENATE_IMPL(s1, s2)

static inline void CF_SafeRelease(CFTypeRef ref) {
    if (ref) {
        CFRelease(ref);
    }
}

static inline void CF_SafeRetain(CFTypeRef ref) {
    if (ref) {
        CFRetain(ref);
    }
}

inline static void CF_ExecuteCleanup(CFTypeRef *pref) {
    CF_SafeRelease(*pref);
}

#define CF_SCOPE_RELEASE(ref) \
    CFTypeRef __CF_SCOPE_CONCATENATE(RELEASE, __LINE__) __attribute__((cleanup(CF_ExecuteCleanup), unused)) = ref;

#endif
